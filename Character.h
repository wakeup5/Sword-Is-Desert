#pragma once
#include "Action.h"

typedef struct tagCharacterInfo
{
	//�⺻ ����
	UINT Level = 1;
	float Exp = 0.0f;//�ۼ��������� ����. ����ġ ���� (�� ���� + ���� ����) / (���� ���� * 5)

	//�ɷ�ġ ����
	float MaxHp = 0.0f;
	float Hp = 0.0f;
	float MaxMp = 0.0f;
	float Mp = 0.0f;
	float Atk = 0.0f;
	float Def = 0.0f;

	//�÷��̾� ��
	UINT Price = 0;

	//���� ����
	float AtkSpeed = 1.0f;
	float WalkSpeed = 2.0f;
	float RunSpeed = 3.0f;
	float RespwanTime = 15.0f;
	float AtkRange = 2.0f;
	float AtkScale = 1.5f;

	//tagCharacterInfo() {}
	tagCharacterInfo(
		float mhp = 0, 
		float mmp = 0, 
		float atk = 0, 
		float def = 0, 
		float atkSpeed = 1.0f,
		float walkSpeed = 2.0f,
		float runSpeed = 3.0f,
		float atkRange = 2.0f)
	{
		MaxHp = Hp = mhp;
		MaxMp = Mp = mmp;
		Atk = atk;
		Def = def;
		AtkSpeed = atkSpeed;
		WalkSpeed = walkSpeed;
		RunSpeed = runSpeed;
		AtkRange = atkRange;
	}

} CharacterInfo;

class Character : public ActionObject
{
public:
	typedef enum
	{
		CS_NONE,
		CS_STAND,
		CS_RUN,
		CS_ATTACK,
		CS_KNOCK,
		CS_DOWN
	} State;

	typedef enum
	{
		CBS_NORMAL,
		CBS_BATTLE,
		CBS_BACK
	} BattleState;

	State _state;
	BattleState _battleState;

	cSkinnedAnimation* animation;
	Transform* rootBoneTransform;

protected:
	CharacterInfo _charInfo;
	Transform* _attackTransform[10];
	Transform* _hitTransform[10];

	int AtkTransLength;
	int hitTransLength;

	float _hitStopTime = 0;
public:
	Character();
	virtual ~Character();

	virtual void Setup();
	virtual void Release();

	virtual void BaseObjectEnable();						//BaseObject �� Ȱ��ȭ �ɶ� ����
	virtual void BaseObjectDisable();						//BaseObject �� ��Ȱ��ȭ �ɶ� ����
	virtual void BaseObjectUpdate(float timeDelta);			//BaseObject �� Update �� ����....
	virtual void BaseObjectNoActiveUpdate(float timeDelte);	//BaseObject �� ��Ȱ��ȭ�� ������Ʈ ����....

	virtual void BaseObjectRender();

public:
	bool IsState(Character::State state); //���� ���� ��
	bool CanState(Character::State state); //���� ���� ����
	bool SetState(Character::State state); //���� ����(���� ��� true, �ٲ��� false)

	BattleState GetBattleState() { return _battleState; }

	void ActionState(const char* animationName, Character::State state, float fadeTime = 0.0f, bool isOnce = false);

	virtual void SetHeight(float height);

	virtual bool GetAttackTransform(OUT Transform** transArr, OUT int* arrLength) { *arrLength = 0; return false; }
	virtual bool GetHitTransform(OUT Transform** transArr, OUT int* arrLength) { *arrLength = 0; return false; }
		
	virtual bool GetAttackBound(Transform*** TransArr, int* num);
	virtual bool GetHitBound(Transform*** TransArr, int* num);
public:
	void SetCharacterInfo(CharacterInfo &info);
	CharacterInfo& GetCharacterInfo();
};

