#pragma once
#include "Character.h"
#include "cSkinnedAnimation.h"
#include "NameTag.h"
#include "UIProgress.h"

class Monster : public Character
{
protected:

	RECT _Area;
	D3DXVECTOR3 _DestPos;
	//float _Speed;
	float _StandTime;
public:
	D3DXVECTOR3 _PrevPos;

	bool _isBoss = false;
	bool _isMiddleBoss = false;
protected:
	float _AttackTime;
	//float _AttackCoolTime;

	float _respawnTime;

	const static Transform* PlayerTrans;

	//�÷��̾� ���ȳ�? ���ݸ�� ������ �ٽ� false��.
	bool _isAtkPlayer;

	//���� ���� ��¿� �����±�
	NameTag _tag;
	NameTagTexture _tagTexture; //�̸��̶� �� �׸� �ؽ��� ������ ����
	UIProgress _hpProgress;

	std::string _name;

	UINT _attackNum;

	Timer* _atkTimer;
public:
	Monster();
	virtual ~Monster();

	EffectVector	_MonsterDamage;
	EffectVector	_MonsterDamage2;
	EffectVector	_MonsterDamage3;
	EffectVector	_MonsterDamage4;

	virtual void Setup(const char* path, RECT rect, CharacterInfo &info);

	virtual void BaseObjectEnable();						//BaseObject �� Ȱ��ȭ �ɶ� ����
	virtual void BaseObjectDisable();						//BaseObject �� ��Ȱ��ȭ �ɶ� ����
	virtual void BaseObjectUpdate(float timeDelta);			//BaseObject �� Update �� ����....
	virtual void BaseObjectNoActiveUpdate(float timeDelte);	//BaseObject �� ��Ȱ��ȭ�� ������Ʈ ����....
	virtual void BaseObjectRender();

	void SetArea(RECT rect);

	void SetName(std::string name) { _name = name; }
	std::string GetName(){ return _name; }
protected:
	virtual void AIUpdate(float timeDelta);
	void AINormalUpdate(float timeDelta);
	virtual void AIBattleUpdate(float timeDelta);
	void AIBackUpdate(float timeDelta);
	virtual void MoveUpdate(float timeDelta);

protected:
	D3DXVECTOR3 GetDeltaDestPos(float speed);
	void LookPosition(D3DXVECTOR3 pos);
	void MoveDestPosition(float speed);

	bool IsDestPos(float distance = 0.0f);
	bool IsPosInDistance(D3DXVECTOR3 destPos, float distance = 0.0f);

	virtual void AttackUpdate(UINT atkNum);
public:
	float GetPlayerDistance();

	static void SetPlayerTrans(const Transform* ptrans){ PlayerTrans = ptrans; }

	virtual bool GetAttackTransform(OUT Transform** transArr, OUT int* arrLength);
	virtual bool GetHitTransform(OUT Transform** transArr, OUT int* arrLength);

	Transform* GetAtkTrans() { return _hitTransform[0]; }

	virtual void Hit(float damage);
	void Down();
	virtual void Alive();

	void PrintNameTag();
};

