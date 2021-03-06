#include "stdafx.h"
#include "Muspel.h"


Muspel::Muspel()
{
}


Muspel::~Muspel()
{
}

void Muspel::AttackUpdate(UINT atkNum)
{
	Player* player = PLAYER_MGR->GetPlayer();
	cBoundBox* pBox = &player->BoundBox;

	if (!animation->IsPlay())
	{
		_attackNum = 0;
	}

	switch (_attackNum)
	{
	case 2:
	{
		if (_atkTimer->Check(1, 0.6))
		{		
			PLAYER_MGR->MonsterCollision(this);
		}
		break;
	}
	case 1:
	{
		if (_atkTimer->Check(2, 0.3))
		{
			PLAYER_MGR->MonsterCollision(this);
		}
		else if (_atkTimer->Check(3, 0.5))
		{
			PLAYER_MGR->MonsterCollision(this);
		}
		else if (_atkTimer->Check(4, 1.1))
		{
			PLAYER_MGR->MonsterCollision(this);
		}
		break;
	
	}

	}
}
