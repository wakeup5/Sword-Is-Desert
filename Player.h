#pragma once
#include "Character.h"
#include "cSkinnedAnimation.h"
//#include "ActionPlayer.h"
#include "vehicle.h"
#include "HitRing.h"
#include "Storm.h"
#include "Uskill_DustFX.h"
#include "Around_Dust.h"
#include "Timer.h"
#include "StormDust.h"
#include "Stormpt.h"

class Skill;
class Monster;
class Equipment;

enum PLAYER_INPUT_KEY
{
	PIK_NONE,
	PIK_FRONT,
	PIK_BACK,
	PIK_LEFT,
	PIK_RIGHT,
	PIK_MAIN_ATTACK,
	PIK_SUB_ATTACK,
	PIK_JUMP,
	PIK_SPECIAL,
	PIK_ENUM_LENGTH
};

enum PLAYER_STATE
{
	PS_NONE,
	PS_STAND,
	PS_RUN,
	PS_SPRINT,
	PS_BACKWALK,
	PS_ROLLING,
	PS_JUMP,
	PS_ATTACK,
	PS_WALKATTACK,
	PS_SIDEATTACK,
	PS_SHIELDATTACK,
	PS_BOWATTACK,
	PS_KNOCKBACK,
	PS_KNOCKDOWN,
	PS_RIDE,
	PS_BLOCK
};

enum PLAYER_JUMP_STATE
{
	PJS_START,
	PJS_JUMPING,
	PJS_END
};

enum PLAYER_BUFF
{
	PB_NONE,
	PB_FIRE,
	PB_ICE,
	PB_THUNDER
};

typedef struct tagKeyTime
{
	PLAYER_INPUT_KEY	key;
	DOUBLE				time;
	UINT				downKey;
} KeyTime;

typedef struct tagKeyType
{
	PLAYER_INPUT_KEY	key;
	UINT				ons; //once = 0 and stay = 1;
	UINT				downKey;
} KeyType;

class Player : public Character
{
private:
	//������ ���� ���� �� ������
	float _height = 0;
	float _jumpHeight = 0;
	float _jumpSpeed = 0;
	float _jumpMoveSpeed = 0;
	float speed = 0;
	PLAYER_JUMP_STATE _jumpState = PJS_END;

public:
	//�̵� ��
	float _frontHeight;
	bool _isMove;
private:
	float _prevHeight;

	//Ű �Է� ����
	std::vector<KeyTime> _keyBuffer;
	const DOUBLE _keyDelay = 0.2f;

	std::map<PLAYER_INPUT_KEY, UINT> _keyOrder;

	//����
	PLAYER_STATE _state;

	UINT _attackNum;
	UINT _walkAttackNum;

	//ī�޶�
	float _dist;

	//��ų
	std::vector<Skill*> _skills;
		
public:
	std::set<Monster*> _hitMonster;


private:
	//���� ���� ����
	bool _isAttackTime = false;

	vehicle* _vehicle;

	//�̵� ����?
	bool _isMovable = true;

	//����
	//Equipment* _equip = NULL;

	float _atkRunTime;

	EffectVector _effects;
	EffectVector _RideFX;
	EffectVector _SwordFX;
	EffectVector _SwordFX2;
	EffectVector _SwordFX3;
	//EffectVector _JumpFX;
	EffectVector _BoosFXTest;

	cQuadParticleEmitter* _effect;
	Timer* _timer;

	Timer* _bowAttack;
	cBoundBox _bowBound;
	
public:
	//����!
	PLAYER_BUFF Buff = PB_NONE;
	cBoundBox _StormBound;
	cBoundBox _StormBound2;
public:
	Player();
	~Player();
	HitRing* _SideFX;
	EffectVector _UskillFX;
	EffectVector _Uskill02FX;
	EffectVector _Uskill03FX;
	EffectVector _Uskill05FX;

	EffectVector _SideAtkFX;
	EffectVector _SideAtkPtFX;
	EffectVector _MoveAtk01FX;
	EffectVector _RollingFX;
	EffectVector _ShiledAtkFX;
	EffectVector _Damage;
	EffectVector _Damage2;

	Storm* _Storm;
	Storm* _Storm2;
	Uskill_DustFX* _Uskill04FX;
	Around_Dust* _JumpFX;
	StormDust* _StormDust;
	StormDust* _StormDust2;
	StormPt* _StormPt;
	StormPt* _StormPt2;

	virtual void Setup();

	virtual void BaseObjectEnable();						//BaseObject �� Ȱ��ȭ �ɶ� ����
	virtual void BaseObjectDisable();						//BaseObject �� ��Ȱ��ȭ �ɶ� ����
	virtual void BaseObjectUpdate(float timeDelta);			//BaseObject �� Update �� ����....
	virtual void BaseObjectNoActiveUpdate(float timeDelte);	//BaseObject �� ��Ȱ��ȭ�� ������Ʈ ����....

	virtual void BaseObjectRender();

	//���� ��ġ
	void SetHeight(float height);

	//Ű �Է°� �ൿ
	void DetectKeyAction(const UINT key, PLAYER_INPUT_KEY action);
	void PopKeyBuffer();

	bool ActionToCommand(std::vector<KeyType> &command, Action* action);
private:
	bool ActionStay(KeyType &key);
	bool ActionOnce(KeyType &key, int num);
public:

	void BasicCommand();
	void JumpCommand();
	void RideJump();
	void AttackCommand();
	void MoveCommand();
	void RideMoveCommand();
	void BowAttackCommand();

	bool Command();

	//���� ��ȯ
	bool SetState(PLAYER_STATE state);
	bool IsState(PLAYER_STATE state);
	bool CanState(PLAYER_STATE state);

	void Stand(float fadeTime = 0.0f, bool mustly = false);
	void Run(float fadeTime = 0.0f);
	void Sprint(float fadeTime = 0.0f);
	void BackWalk(float fadeTime = 0.0f);
	void RollingLeft(float fadeTime = 0.0f);
	void RollingRight(float fadeTime = 0.0f);
	void RollingBack(float fadeTime = 0.0f);
	UINT Attack(float fadeTime = 0.0f);
	UINT AttackStop();
	UINT WalkAttack(float fadeTime = 0.0f);
	UINT WalkAttackStop();
	void SideAttackLeft(float fadeTime = 0.0f);
	void SideAttackRight(float fadeTime = 0.0f);
	void JumpStart(float fadeTime = 0.0f);
	void Jumping(float fadeTime = 0.0f);
	void JumpEnd(float fadeTime = 0.0f);
	void ShieldAttack(float fadeTime = 0.0f);
	void Ultimate(float fadeTime = 0.0f);
	void BowAttack(float fadeTime = 0.0f);
	void KnockBack(float fadeTime = 0.0f);
	void Down();
	void Ride();
	void Hit(float damage, float knockChance = 0.3f);
	void EffectSetup();
	void EffectUpdate(float timeDelta);
	void EffectRender();


	void ClearAttackNum() { _attackNum = 0; _walkAttackNum = 0; }

	PLAYER_JUMP_STATE GetJumpState(){ return _jumpState; }

	//�ִϸ��̼��� ���質?
	bool IsPlayAnimation();
	float GetPlayTime();

	void SetPositionByRoot();

	virtual bool GetAttackTransform(OUT Transform** transArr, OUT int* arrLength);
	virtual bool GetHitTransform(OUT Transform** transArr, OUT int* arrLength);

	virtual Transform* GetAttackBound();
	virtual Transform* GetHitBound();

	virtual Transform* GetSwordTransform() { return _attackTransform[0]; }
	virtual Transform* GetShieldTransform() { return _attackTransform[1]; }

	bool IsAttackMonster(Monster* mon);
	void ClearAttackMonster();

	bool IsAttackTime()
	{
		return _isAttackTime;
	}
	void SetAttackTimeState(bool is)
	{
		_isAttackTime = is;
	}

	UINT GetAttackNum() { return _attackNum; }
	UINT GetWalkAttackNum() { return _walkAttackNum; }

	void SetMovable(bool is)
	{
		_isMovable = is;
	}

	//void SetEquipment(Equipment* equip) { _equip = equip; }
	//Equipment* GetEquipment() { return _equip; }
	CharacterInfo& GetTotalStatus();
	void SetHp(int hp){
		_charInfo.Hp += hp;
	}
	void SetMp(int mp){
		_charInfo.Mp += mp;
	}
	float GetSpeed(){ return speed; }
	
	////test
	Transform * gethand(){ return 0; };

	void AddExp(int monLevel) 
	{
		_charInfo.Exp += ((float)monLevel / (float)_charInfo.Level) / 2.0f;

		if (_charInfo.Exp >= 1)
		{
			_charInfo.Exp = 0;
			_charInfo.Level++;
		}
	}

	float GetSkillDamage();

	PLAYER_BUFF GetIsBuffState(){ return Buff; }
	
	friend class ActionPlayer;
	friend class ActionPlayerDeligate;
};

