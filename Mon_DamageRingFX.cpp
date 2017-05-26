#include "stdafx.h"
#include "Mon_DamageRingFX.h"


Mon_DamageRingFX::Mon_DamageRingFX()
{
}


Mon_DamageRingFX::~Mon_DamageRingFX()
{
}

void Mon_DamageRingFX::Setup()
{

	VEC_COLOR colors;
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.7f));
	//	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));

	VEC_SCALE scales;
	scales.push_back(0.1f);
	scales.push_back(8.0f);

	cQuadParticleEmitter::Init(
		3,
		3,
		0.2f,
		0.2f,
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
		1.0, 1.0f,
		RESOURCE_TEXTURE->GetResource("../Resources/FX/Test/outside.jpg"),
		true);

	//StartEmission();

	//ī�޶� ����
	SetCameraSort(CAMERA, true);
}