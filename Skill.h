#pragma once
#include "Player.h"
#include "ActionPlayer.h"
#include "UISocket.h"


typedef struct tagSkillInfo
{
	//��ų ����
	char*			ActionName = "";
	PLAYER_STATE	State = PLAYER_STATE(0);

	char*			IconPath = "";

	//��ų ����
	char*			Name = ""; //��ų ��
	char*			Disc = ""; //��ų ����

	float			Damage = 0.0f; //��ų ������(�ۼ������� ǥ��)
} SkillInfo;

class Skill : public SocketObject
{
private:
	std::vector<KeyType> _command;
	ActionPlayer* _action;
	//PLAYER_STATE _state;

	SkillInfo _info;
public:
	Skill();
	Skill(std::vector<KeyType>& command, std::string name, PLAYER_STATE state);
	Skill(std::vector<KeyType>& command, SkillInfo &info);
	virtual ~Skill();

	void Setup(std::vector<KeyType>& command, std::string name, PLAYER_STATE state);
	void Setup(std::vector<KeyType>& command, SkillInfo &info);

	std::vector<KeyType> GetCommand() { return _command; }
	ActionPlayer* GetAction() { return _action; }
	PLAYER_STATE GetState() { return _info.State; }

	SkillInfo GetInfo() { return _info; }

	void Active(Player* player)
	{
		player->SetAction(this->_action);
		_action->Start();
	}
};

