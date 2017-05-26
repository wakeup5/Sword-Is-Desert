#include "stdafx.h"
#include "SkillManager.h"
#include "Skill.h"

SkillManager::SkillManager()
{
}


SkillManager::~SkillManager()
{
}

void SkillManager::Setup()
{

}

void SkillManager::Release()
{
	for (auto iter = _vecSkill.begin(); iter != _vecSkill.end(); iter++)
	{
		delete *iter;
	}

	_skills.clear();
	_vecSkill.clear();
}

void SkillManager::AddSkill(const char* name, Skill * skill)
{
	if (skill == NULL) return;

	_skills.insert(std::make_pair(name, skill));
	_vecSkill.push_back(skill);
}

Skill* SkillManager::GetSkill(const char * name)
{
	auto i = _skills.find(name);
	if (i == _skills.end()) return NULL;

	return i->second;
}

void SkillManager::SkillSetting()
{
	Release();

	//��ų ����
	SkillInfo info;
	std::vector<KeyType> command;
	//�� ������
	command.push_back({ PIK_LEFT, 0 });
	command.push_back({ PIK_LEFT, 0 });

	info.Name = "�� ������";
	info.Disc = "�·� �ѹ� ���� ���� ������ ȸ���Ѵ�. \n 'A', 'A'";
	info.IconPath = "../Resources/Textures/icon/skill/rolling.png";
	info.ActionName = "RollingLeft";
	info.State = PS_ROLLING;

	AddSkill("RollingLeft", new Skill(command, info));
	command.clear();

	//�� ������
	command.push_back({ PIK_RIGHT, 0 });
	command.push_back({ PIK_RIGHT, 0 });

	info.Name = "�� ������";
	info.Disc = "��� �ѹ� ���� ���� ������ ȸ���Ѵ�. \n 'D', 'D'";
	info.IconPath = "../Resources/Textures/icon/skill/rolling.png";
	info.ActionName = "RollingRight";
	info.State = PS_ROLLING;

	AddSkill("RollingRight", new Skill(command, info));
	command.clear();

	//�� ������
	command.push_back({ PIK_BACK, 0 });
	command.push_back({ PIK_BACK, 0 });

	info.Name = "�� ������";
	info.Disc = "�ڷ� �ѹ� ���� ���� ������ ȸ���Ѵ�. \n 'S', 'S'";
	info.IconPath = "../Resources/Textures/icon/skill/rolling.png";
	info.ActionName = "RollingBack";
	info.State = PS_ROLLING;

	AddSkill("RollingBack", new Skill(command, info));
	command.clear();

	//�ñر�
	command.push_back({ PIK_BACK, 0 });
	command.push_back({ PIK_MAIN_ATTACK, 0 });

	info.Name = "���� ���";
	info.Disc = "���� ������ ũ�� ������ �� ������ ������ ���ϰ� ���� ��´�. \n 'S', Click";
	info.IconPath = "../Resources/Textures/icon/skill/attack_normal.png";
	info.ActionName = "Ultimate";
	info.State = PS_ATTACK;
	info.Damage = 20;

	AddSkill("Ultimate", new Skill(command, info));
	command.clear();

	//�⺻ ����
	command.push_back({ PIK_MAIN_ATTACK, 1 });

	info.Name = "�Ϲ� ����";
	info.Disc = "���� 4�� �������� �ֵθ��� �⺻ ����. \n Click";
	info.IconPath = "../Resources/Textures/icon/skill/Attack.png";
	info.ActionName = "Attack";
	info.State = PS_ATTACK;
	info.Damage = 1;

	AddSkill("Attack", new Skill(command, info));
	command.clear();

	//���� ����
	command.push_back({ PIK_FRONT, 1 });
	command.push_back({ PIK_MAIN_ATTACK, 1 });

	info.Name = "���� ����";
	info.Disc = "�����ϸ� �ι� ����. \n 'W', Click";
	info.IconPath = "../Resources/Textures/icon/skill/WalkAttack.png";
	info.ActionName = "WalkAttack";
	info.State = PS_WALKATTACK;
	info.Damage = 1.5;

	AddSkill("WalkAttack", new Skill(command, info));
	command.clear();

	//�� ���̵� ����
	command.push_back({ PIK_LEFT, 1 });
	command.push_back({ PIK_MAIN_ATTACK, 1 });

	info.Name = "�� �ֵθ���";
	info.Disc = "�������� ���� �ֵθ��� �����Ѵ�. \n 'A', Click";
	info.IconPath = "../Resources/Textures/icon/skill/SideAttackLeft.png";
	info.ActionName = "SideAttackLeft";
	info.State = PS_SIDEATTACK;
	info.Damage = 2;

	AddSkill("SideAttackLeft", new Skill(command, info));
	command.clear();

	//���� ���̵� ����
	command.push_back({ PIK_RIGHT, 1 });
	command.push_back({ PIK_MAIN_ATTACK, 1 });

	info.Name = "���� �ֵθ���";
	info.Disc = "���������� ���� �ֵθ��� �����Ѵ�. \n 'D', Click";
	info.IconPath = "../Resources/Textures/icon/skill/SideAttackRight.png";
	info.ActionName = "SideAttackRight";
	info.State = PS_SIDEATTACK;
	info.Damage = 2;

	AddSkill("SideAttackRight", new Skill(command, info));
	command.clear();

	//���� ����
	command.push_back({ PIK_SUB_ATTACK, 0 });

	info.Name = "���� ġ��";
	info.Disc = "���и� �ֵѷ� ���� �˹� ��Ų��. \n RClick";
	info.IconPath = "../Resources/Textures/icon/skill/sAttack.png";
	info.ActionName = "SheildAttack";
	info.State = PS_ATTACK;
	info.Damage = 2.5;

	AddSkill("SheildAttack", new Skill(command, info));
	command.clear();
}
