#pragma once
#include "Monster.h"
class Golem :
	public Monster
{
public:
	Golem();
	~Golem();

	void AttackUpdate(UINT atkNum);
};

