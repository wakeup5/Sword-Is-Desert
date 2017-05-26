#include "stdafx.h"
#include "Attack_Effect.h"


Attack_Effect::Attack_Effect()
{
}


Attack_Effect::~Attack_Effect()
{
}

void Attack_Effect::Setup()
{
	
	VEC_COLOR colors;
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.8f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));

	VEC_SCALE scales;
	scales.push_back(3.0);
	scales.push_back(3.0);

	cQuadParticleEmitter::Init(
		100,
		1,
		0.5f,
		0.5f,
		D3DXVECTOR3(0, 0, 0),
		D3DXVECTOR3(0, 0, 0),
		D3DXVECTOR3(0, 0, 0),
		D3DXVECTOR3(0, 0, 0),
		D3DXVECTOR3(0, 0, 0),		//�ʱ���۽� ȸ��Min
		D3DXVECTOR3(0, 0, 0),     //�ʱ���۽� ȸ��Max
		D3DXVECTOR3(0, 0, 0),				//�ʴ� ȸ���� ȸ�� �� Min
		D3DXVECTOR3(0, 0, 0),				//�ʴ� ȸ���� ȭ�� �� Max
		D3DXVECTOR3(0, 0, 0),				//�ʴ� ȸ�� ���� Min
		D3DXVECTOR3(0, 0, 0),				//�ʴ� ȸ�� ���� Max
		colors, scales,
		1.0f, 1.0f,
		RESOURCE_TEXTURE->GetResource("../Resources/FX/Test/Attack.png"),
		true);

	StartEmission();

	//ī�޶� ����
	SetCameraSort(CAMERA, true);
}