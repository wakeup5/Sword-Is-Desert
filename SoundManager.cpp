#include "stdafx.h"
#include "SoundManager.h"



SoundManager::~SoundManager()
{
}

HRESULT SoundManager::initialize(void)
{
	//���� �ý��� ����
	System_Create(&_system);

	//ä�μ�
	_system->init(TOTALSOUNDBUFFER, FMOD_INIT_NORMAL, 0);

	//����� ä�� �����Ҵ�
	//_sound = new Sound*[TOTALSOUNDBUFFER];
	//_channel = new Channel*[TOTALSOUNDBUFFER];

	//���~~
	//memset(_sound, 0, sizeof(Sound*) * (TOTALSOUNDBUFFER));
	//memset(_channel, 0, sizeof(Channel*) * (TOTALSOUNDBUFFER));

	_soundMap.clear();
	_channelMap.clear();

	return S_OK;
}

void SoundManager::release(void)
{
	//���� �����Ѵ�~
	/*
	if (_channel != NULL || _sound != NULL)
	{
		for (int i = 0; i < TOTALSOUNDBUFFER; i++)
		{
			if (_channel != NULL)
			{
				if (_channel[i]) _channel[i]->stop();
			}
			if (_sound != NULL)
			{
				if (_sound != NULL) _sound[i]->release();
			}
		}
	}

	//�޸� �����
	SAFE_DELETE_ARRAY(_channel);
	SAFE_DELETE_ARRAY(_sound);
	*/

	for (SoundMapIter i = _soundMap.begin(); i != _soundMap.end();)
	{
		i->second->release();
		i = _soundMap.erase(i);
	}

	for (ChannelMapIter i = _channelMap.begin(); i != _channelMap.end();)
	{
		i->second->stop();
		i = _channelMap.erase(i);
	}

	//�ý��� �ݴ´�
	if (_system != NULL)
	{
		_system->release();
		_system->close();
	}

	_soundMap.clear();
	_channelMap.clear();
}


void SoundManager::loadDefaultSound(){
	// �κ��丮
	addSound("ring", "../Resources/bgm/inventory_sound_effects/ring_inventory.wav", false, false);
	addSound("armor", "../Resources/bgm/inventory_sound_effects/cloth-inventory.wav", false, false);
	addSound("weapon", "../Resources/bgm/inventory_sound_effects/leather_inventory.wav", false, false);
	addSound("sell_buy_item", "../Resources/bgm/inventory_sound_effects/sell_buy_item.wav", false, false);
	addSound("inventory_open", "../Resources/bgm/inventory_sound_effects/Inventory_Open_00.wav", false, false);

	// Ÿ��
	addSound("sword_hit1", "../Resources/bgm/hit/Socapex - new_hits_1.wav", false, false);
	addSound("sword_hit2", "../Resources/bgm/hit/Socapex - new_hits_2.wav", false, false);
	addSound("sword_hit3", "../Resources/bgm/hit/Socapex - new_hits_3.wav", false, false);
	addSound("sword_hit4", "../Resources/bgm/hit/Socapex - new_hits_4.wav", false, false);

	// Ÿ����(����)
	addSound("hit_leather01", "../Resources/bgm/Ÿ����/����/Be Attack Leather_01.mp3", false, false);
	addSound("hit_leather02", "../Resources/bgm/Ÿ����/����/Be Attack Leather_02.mp3", false, false);
	addSound("hit_leather03", "../Resources/bgm/Ÿ����/����/Be Attack Leather_03.mp3", false, false);

	// Ÿ����(�ݼ�)
	addSound("hit_metal01", "../Resources/bgm/Ÿ����/�ݼ�/Be Attack Metal_01.mp3", false, false);
	addSound("hit_metal02", "../Resources/bgm/Ÿ����/�ݼ�/Be Attack Metal_02.mp3", false, false);
	addSound("hit_metal03", "../Resources/bgm/Ÿ����/�ݼ�/Be Attack Metal_03.mp3", false, false);
	addSound("hit_metal04", "../Resources/bgm/Ÿ����/�ݼ�/Be Attack Metal_04.mp3", false, false);

	// ���� ���� ����
	addSound("Attack_Ground_01", "../Resources/bgm/�����������/ultimate_ground.mp3", false, false);
	addSound("Attack_Ground_03", "../Resources/bgm/�����������/Attack_Ground_03.mp3", false, false);

	// ���н�ų
	addSound("shield_hit", "../Resources/bgm/skil/����/04_riven_skin05_feint_shield_oc_.wav", false, false);

	// ��
	addSound("fire01", "../Resources/bgm/skil/��/Great_Straight_02_Fire.mp3", false, false);
	addSound("fire02", "../Resources/bgm/skil/��/Great_Straight_03_Fire.mp3", false, false);
	addSound("fire03", "../Resources/bgm/skil/��/Great_Straight_04_Fire.mp3", false, false);
	addSound("fire04", "../Resources/bgm/skil/��/Great_Straight_05_Fire.mp3", false, false);
	addSound("swordFire", "../Resources/bgm/skil/��/swordFire.mp3", false, false);

	// ������
	addSound("sand", "../Resources/bgm/skil/������/sand.mp3", false, false);
	addSound("thumble", "../Resources/bgm/skil/������/thumble.mp3", false, false);

	// ��
	addSound("poison", "../Resources/bgm/skil/��/poison_spell.mp3", false, false);

	// ��ũ �´� �Ҹ�
	addSound("orc_hit", "../Resources/bgm/middle_boss/orc_hit.mp3", false, false);
	// ��ũ ���ݽ� ���̽�
	addSound("orc_voice", "../Resources/bgm/middle_boss/Boss_1_05_OrcWarrior_Melee_V_Atk_01.mp3", false, false);

	// ����
	addSound("swing", "../Resources/bgm/skil/����/swing.mp3", false, false);

	// Ȱ
	addSound("bow", "../Resources/bgm/bow/bow.mp3", false, false);

	//����
	addSound("buff", "../Resources/bgm/skil/buff/buff.mp3", false, false);

	// ������
	addSound("levelUp", "../Resources/bgm/levelup/levelup.wav", false, false);

	// ����Ʈ �Ϸ�
	addSound("questComplete", "../Resources/bgm/quest/questComplete.mp3", false, false);
	// ����Ʈ ����
	addSound("quest", "../Resources/bgm/quest/quest.mp3", false, false);
	// ����Ʈ �� �ѱ��
	addSound("questNext", "../Resources/bgm/quest/bookNext.mp3", false, false);

	// ���� ������
	addSound("boss_shooting", "../Resources/bgm/boss/boss_shooting.mp3", false, false);

	// �÷��̾� ���̽�
	addSound("���̽�1", "../Resources/bgm/�÷��̾�̽�/Bango_V_Atk_Long_Shot_03.mp3", false, false);
	addSound("���̽�2", "../Resources/bgm/�÷��̾�̽�/Bango_V_Atk_Long_Shot_05.mp3", false, false);
	addSound("���̽�3", "../Resources/bgm/�÷��̾�̽�/Bango_V_Atk_Long_Shot_06.mp3", false, false);

	// �̵�
	addSound("foot_step01", "../Resources/bgm/footStep/Footstep_Dirt_00.wav", false, false);
	addSound("foot_step01", "../Resources/bgm/footStep/Footstep_Dirt_00.wav", false, false);
	addSound("foot_step01", "../Resources/bgm/footStep/Footstep_Dirt_00.wav", false, false);
	addSound("foot_step01", "../Resources/bgm/footStep/Footstep_Dirt_00.wav", false, false);
	addSound("foot_step01", "../Resources/bgm/footStep/Footstep_Dirt_00.wav", false, false);
	addSound("foot_step01", "../Resources/bgm/footStep/Footstep_Dirt_00.wav", false, false);
	addSound("foot_step01", "../Resources/bgm/footStep/Footstep_Dirt_00.wav", false, false);
	addSound("foot_step01", "../Resources/bgm/footStep/Footstep_Dirt_00.wav", false, false);
	addSound("foot_step01", "../Resources/bgm/footStep/Footstep_Dirt_00.wav", false, false);

	// �Ϲ��̵�
	addSound("foot_step_normal01", "../Resources/bgm/footStep/normal/FootStep_01.wav", false, false);
	addSound("foot_step_normal02", "../Resources/bgm/footStep/normal/FootStep_02.wav", false, false);
	addSound("foot_step_normal03", "../Resources/bgm/footStep/normal/FootStep_03.wav", false, false);
	addSound("foot_step_normal04", "../Resources/bgm/footStep/normal/FootStep_04.wav", false, false);

	// ����̵�
	addSound("FootStep_Dash_01", "../Resources/bgm/footStep/dash/FootStep_Dash_01.wav", false, false);
	addSound("foot_step_normal02", "../Resources/bgm/footStep/normal/FootStep_02.wav", false, false);
	addSound("foot_step_normal03", "../Resources/bgm/footStep/normal/FootStep_03.wav", false, false);
	addSound("foot_step_normal04", "../Resources/bgm/footStep/normal/FootStep_04.wav", false, false);

	// Ż��
	addSound("horseRiding", "../Resources/bgm/riding/horseRiding.mp3", false, false);
	addSound("move", "../Resources/bgm/riding/move.mp3", false, false);

	// ������
	addSound("weather rain", "../Resources/bgm/������/rainning.mp3", false, false);
	addSound("weather thunder", "../Resources/bgm/������/Thunderstorm+sound+effect+-+close.mp3", false, false);
	//addSound("thunder_strong_effect_close", "../Resources/bgm/������/Thunderstorm+sound+effect+-+close.mp3", false, false);

	// bgm
	addSound("bgm", "../Resources/bgm/Black+Desert+Online+OST+-+���ö�++Keplan.mp3", true, true);
	addSound("bossBgm", "../Resources/bgm/�����縷+BGM002.mp3", true, true);
	addSound("ridingBgm", "../Resources/bgm/hh.mp3", true, true);
	//addSound("middleBossBgm", "../Resources/bgm/�����縷+BGM002.mp3", true, true);
}


//���� �߰��Ѵ�
void SoundManager::addSound(string keyName, string soundName,
	bool background, bool loop)
{
	//���R�̳�?
	if (loop)
	{
		//����̳�?
		if (background)
		{
			_system->createStream(soundName.c_str(), FMOD_LOOP_NORMAL, 0, &_sound);
		}
		else
		{
			_system->createSound(soundName.c_str(), FMOD_LOOP_NORMAL, 0, &_sound);
		}
	}
	else //�����̰� �ƴϸ�..
	{
		_system->createSound(soundName.c_str(), FMOD_DEFAULT, 0, &_sound);
	}

	//�ʿ� ���带 Ű���� �Բ� �־��ش�
	_soundMap.insert(make_pair(keyName, _sound));
}

//���� �÷���~~
void SoundManager::play(string keyName, float volume)
{
	SoundMapIter iter = _soundMap.find(keyName);
	ChannelMapIter cIter = _channelMap.find(keyName);

	if (iter != _soundMap.end())
	{
		{
			_system->playSound(FMOD_CHANNEL_FREE, iter->second, false, &_channel);

			_channelMap.insert(make_pair(keyName, _channel));
		}
		_channel->setVolume(volume);
	}

}

//���� ������� ���带 �Ͻ����� ��Ŵ
void SoundManager::pause(string keyName)
{
	ChannelMapIter iter = _channelMap.find(keyName);

	if (iter != _channelMap.end())
	{
		iter->second->setPaused(true);
	}

}

//�Ͻ������� ���带 �ٽ� ����Ѵ�..
void SoundManager::resume(string keyName)
{
	ChannelMapIter iter = _channelMap.find(keyName);

	if (iter != _channelMap.end())
	{
		iter->second->setPaused(false);
	}

}

void SoundManager::stop(string keyName)
{
	ChannelMapIter iter = _channelMap.find(keyName);

	if (iter != _channelMap.end())
	{
		iter->second->stop();
		_channelMap.erase(iter);
	}

}

void SoundManager::update(void)
{
	//���� �ý����� ��� ������Ʈ�Ѵ�..
	_system->update();

	bool isPlay;
	for (ChannelMapIter i = _channelMap.begin(); i != _channelMap.end();)
	{
		isPlay = false;
		i->second->isPlaying(&isPlay);

		if (!isPlay)
		{
			i = _channelMap.erase(i);
		}
		else
		{
			i++;
		}
	}
}


bool SoundManager::isPlay(string keyName){
	bool isPlay = false;
	ChannelMapIter iter = _channelMap.find(keyName);

	if (iter != _channelMap.end())
	{
		iter->second->isPlaying(&isPlay);
		//_channelMap.erase(iter);
	}
	else{
		play(keyName, 0.2f);
	}

	return isPlay;
}


bool SoundManager::isPlay(string keyName, float volume){
	bool isPlay = false;
	ChannelMapIter iter = _channelMap.find(keyName);

	if (iter != _channelMap.end())
	{
		iter->second->isPlaying(&isPlay);
		//_channelMap.erase(iter);
	}
	else{
		play(keyName, volume);
	}

	return isPlay;
}



bool SoundManager::isBossBgm(){
	bool isPlay = false;
	ChannelMapIter iter = _channelMap.find("bossBgm");

	if (iter != _channelMap.end())
	{
		iter->second->isPlaying(&isPlay);
		isPlay = true;
		//_channelMap.erase(iter);
	}


	return isPlay;
}