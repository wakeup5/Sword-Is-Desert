#pragma once
#include "Singleton.h"


//�α� ��� Ÿ��
#define LOG_NONE		0x00000000
#define LOG_CONSOLE		0x00000001
#define LOG_FILE		0x00000002
#define LOG_WINDOW		0x00000004
#define LOG_ALL			( LOG_CONSOLE | LOG_FILE | LOG_WINDOW )

#define LOG_WINDOW_TITLE	"Log..."		//�α� â ������ Ÿ��Ʋ
#define LOG_WINDOW_CX		250				//�α� â ������ ���� ũ��
#define LOG_WINDOW_CY		600				//�α� â ������ ���� ũ��


//
// �α� �Ŵ���
//

class LogMgr : public Singleton < LogMgr >
{
private:
	unsigned int		m_nTarget;
	char				m_szFileName[MAX_PATH];		//�α� ���� ������ ���� �̸�
	HWND				m_hWndLog;					//�α�â ������ �ڵ�
	HWND				m_hWndListBox;				//�α�â ����Ʈ �ڽ�

protected:
	LogMgr(void);

public:
	~LogMgr(void);


public:

	//BaseSingleton ģ�� ���
	friend LogMgr* Singleton<LogMgr>::GetInstance(void);

	//�α�â ����
	HRESULT			Setup(unsigned int nTarget, HWND hParentWnd, const char* pszFileName = NULL);

	//�α� ���
	VOID			AddLog(char* strmsg, ...);

	//���Ϸ� �α� ����
	VOID			LogFile(char* strmsg, ...);

	//����
	VOID			Release(VOID) override;


private:
	//�α� ���������
	VOID			CreateLogWindow(HWND hWnd);

	//�α� ������ �޼��� ���ν���
	static LRESULT CALLBACK WndLogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};
#define LOG_MGR LogMgr::GetInstance()

#define LOG_V(vector) LOG_MGR->AddLog("%.2f, %.2f, %.2f", vector.x, vector.y, vector.z)
#define LOG(text) LOG_MGR->AddLog(text)
#define LOG_F(f) LOG_MGR->AddLog("%f", f)
#define LOG_I(i) LOG_MGR->AddLog("%d", i)