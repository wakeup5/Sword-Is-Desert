#include "StdAfx.h"
#include "TimeMgr.h"
#include <stdio.h>

//timeGetTime �� �̿��ϱ����� ����� ���̺귯��
#include <MMSystem.h>
#pragma comment( lib, "winmm.lib" )		//winmm.lib �߰�

TimeMgr::TimeMgr(void)
{
}

TimeMgr::~TimeMgr(void)
{
}

HRESULT TimeMgr::Setup(void)
{
	//���� Ÿ�̸� ���� ����
	//QueryPerformanceFrequency �Լ��� �ʴ� ī��Ʈ ������ ���� ��´�.
	//���� Ÿ�̸� ���� �ȴٸ� TRUE �ȵȴٸ� FALSE
	if (QueryPerformanceFrequency((LARGE_INTEGER*)&m_nPreriodTime))
	{
		//���� Ÿ�̸Ӹ� �����Ѵٸ�...
		m_bHardWare = true;

		//1 ī��Ʈ�� �ʰ� �󸶳� �Ǵ���?
		m_TimeScaleSec = 1.0 / m_nPreriodTime;

		//�ʱ�ȭ ������ �ð��� LastTime ����...
		QueryPerformanceCounter((LARGE_INTEGER*)&m_nLastTime);
	}

	else
	{
		//���� Ÿ�̸Ӹ� �������� �ʴ´ٸ�...
		m_bHardWare = false;

		//1000 �и������� ������ �ð����� ��´�.
		//timeGetTime �� GetTickCount ���� ���� �����ϴ�.
		m_nLastTime = timeGetTime();

		//1 ī��Ʈ�� �ʰ� �󸶳� �Ǵ���?
		m_TimeScaleSec = 1.0 / 1000.0;

	}

	m_TotalSec = 0.0f;
	m_FrameCountSec = 0.0f;
	m_FramePerSec = 0;
	m_FrameCount = 0;

	return S_OK;
}

void TimeMgr::Release(void)
{
}

//�ž�����Ʈ �����ش�.
void TimeMgr::UpdateTime(float frameLock)
{
	//���� �ð��� ��´�.
	if (m_bHardWare)
		QueryPerformanceCounter((LARGE_INTEGER*)&m_nCurTime);
	else
		m_nCurTime = timeGetTime();

	//���� �ð����� ������ ���
	m_nDeltaTime = m_nCurTime - m_nLastTime;


	//�������� ������ ���� �ʽð� ���
	m_FrameDeltaSec = m_nDeltaTime * m_TimeScaleSec;

	//������ ���� �����Ѵٸ�...( ������ ��Ű�� )
	if (frameLock > 0.0f) {

		//������ �ð�.
		float fLockTime = (1.0f / frameLock);

		while (m_FrameDeltaSec < fLockTime)
		{
			//���� �ð��� ��´�.
			if (m_bHardWare)
				QueryPerformanceCounter((LARGE_INTEGER*)&m_nCurTime);
			else
				m_nCurTime = timeGetTime();

			//���� �ð����� �ݸ� ���
			m_nDeltaTime = m_nCurTime - m_nLastTime;

			//�������� ������ ���� �ʽð� ���
			m_FrameDeltaSec = m_nDeltaTime * m_TimeScaleSec;
		}
	}

	//���� �ð� ����
	m_nLastTime = m_nCurTime;

	//������ �ð� ����
	m_TotalSec += m_FrameDeltaSec;

	//������ �� ����
	m_FrameCountSec += m_FrameDeltaSec;

	//1�ʰ� �����ٸ�....
	if (m_FrameCountSec >= 1.0) {
		m_FramePerSec = m_FrameCount;
		m_FrameCount = 0;
		m_FrameCountSec -= 1.0;
	}
	m_FrameCount++;
}

void TimeMgr::Update(float timeDelta)
{
	//Ÿ�̸� ������Ʈ
	for (auto i = _timers.begin(); i != _timers.end(); i++)
	{
		i->second->Update(timeDelta);
	}
}

//Ÿ�������� ����Ѵ�
void TimeMgr::DrawTimeInfo()
{
	char szTemp[128];
	wsprintf(szTemp, "FPS : %d", m_FramePerSec);
	DXFONT_MGR->PrintTextOutline(szTemp, 10, 100, 0xffffff00, 0xff000000);

	sprintf(szTemp, "FrameDeltaSec : %.10f", m_FrameDeltaSec);
	DXFONT_MGR->PrintTextOutline(szTemp, 10, 130, 0xffffff00, 0xff000000);

	sprintf(szTemp, "TotalDeltaSec : %.2f", m_TotalSec);
	DXFONT_MGR->PrintTextOutline(szTemp, 10, 160, 0xffffff00, 0xff000000);
}

Timer* TimeMgr::GetTimer(std::string name)
{
	auto iter = _timers.find(name);

	if (iter == _timers.end())
	{
		return NULL;
	}

	return iter->second;
}

Timer * TimeMgr::CreateTimer(std::string name)
{
	static UINT num = 0;

	if (name == "") name = "timer name - " + num++;

	Timer* result = GetTimer(name);

	if (result == NULL)
	{
		result = new Timer;
		_timers.insert(std::make_pair(name, result));
	}

	return result;
}
