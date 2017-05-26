#pragma once
#include "Singleton.h"

#include <string>
#include <map>

typedef BOOL(WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);

//fmod.hpp �߰����ش�
#include "lib/inc/fmod.hpp"

#define libPath "lib/fmodex64_vc.lib"
//lib��ũ���ش�
//#pragma comment (lib, "lib/fmodex64_vc.lib")

//������ ä�� ���� (����~~)
#define EXTRACHANNELBUFFER 50
#define SOUNDBUFFER 50

//�� ���� ���� : ���۰� �۾Ƽ� ������
//������ �ذ��ϱ� ���� ������ ���� ä���� ����� �ش�
#define TOTALSOUNDBUFFER EXTRACHANNELBUFFER + SOUNDBUFFER

using namespace FMOD;
using namespace std;

class SoundManager : public Singleton< SoundManager >
{
private:
	typedef map<string, Sound*> SoundMap;
	typedef map<string, Sound*>::iterator SoundMapIter;
	typedef map<string, Channel*> ChannelMap;
	typedef map<string, Channel*>::iterator ChannelMapIter;
	
private:
	System* _system;
	Sound* _sound;
	Channel* _channel;

	SoundMap _soundMap;
	ChannelMap _channelMap;

public:
	HRESULT initialize();
	void release();
	void update();

	void addSound(string keyName, string soundName,
		bool background, bool loop);
	void play(string keyName, float volume);
	void pause(string keyName);
	void resume(string keyName);
	void stop(string keyName);
	void loadDefaultSound();
	bool isPlay(string keyName);
	bool isPlay(string keyName, float volume);
	bool isBossBgm();
public:
	SoundManager(){
	
		BOOL bIsWow64 = FALSE;

		//IsWow64Process is not available on all supported versions of Windows.
		//Use GetModuleHandle to get a handle to the DLL that contains the function
		//and GetProcAddress to get a pointer to the function if available.
		LPFN_ISWOW64PROCESS fnIsWow64Process;
		fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(
			GetModuleHandle(TEXT("kernel32")), "IsWow64Process");

		if (NULL != fnIsWow64Process)
		{
			if (!fnIsWow64Process(GetCurrentProcess(), &bIsWow64))
			{
				//handle error
			}
		}
		
		if (bIsWow64){
			#pragma comment (lib, "lib/fmodex64_vc.lib")
		}
		else{
			#pragma comment (lib, "lib/fmodex_vc.lib")
		}
	}
	~SoundManager();
};

#define SOUND_MGR		SoundManager::GetInstance()
//#define SOUND_MGR	SoundManager::GetInstance()