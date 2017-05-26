#pragma once
#include "cLight.h"
class cLight_Spot : public cLight
{
public:
	float				inAngle;
	float				outAngle;
	float				minRange;			//���� �ּҰŸ� 
	float				maxRange;			//���� �ִ�Ÿ�
	float				distancePow;		//�Ÿ� ������

public:
	cLight_Spot();
	virtual ~cLight_Spot();

	virtual D3DXMATRIXA16 GetLightMatrix();

	virtual void RenderGizmo();
};

