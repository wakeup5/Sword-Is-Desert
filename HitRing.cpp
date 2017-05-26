#include "stdafx.h"
#include "HitRing.h"


HitRing::HitRing()
{
}


HitRing::~HitRing()
{
}

void HitRing::Setup()
{
	

		VEC_COLOR colors;
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
//	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));

	VEC_SCALE scales;
	scales.push_back(0.1f);
	scales.push_back(8.0f);

	cQuadParticleEmitter::Init(
		100,
		2,
		0.6f,
		0.7f,
		D3DXVECTOR3(0, -1, 0),
		D3DXVECTOR3(0, -1, 0),
		D3DXVECTOR3(0, 5, 0),
		D3DXVECTOR3(0, 6, 0),
		D3DXVECTOR3(4.7, 0, 0),		//�ʱ���۽� ȸ��Min
		D3DXVECTOR3(4.7, 0, 0),     //�ʱ���۽� ȸ��Max
		D3DXVECTOR3(0, 0, 15),				//�ʴ� ȸ���� ȸ�� �� Min
		D3DXVECTOR3(0, 0, 15),				//�ʴ� ȸ���� ȭ�� �� Max
		D3DXVECTOR3(0, 0, 5),				//�ʴ� ȸ�� ���� Min
		D3DXVECTOR3(0, 0, 5),				//�ʴ� ȸ�� ���� Max
		colors, scales,
		1, 1, 
		RESOURCE_TEXTURE->GetResource("../Resources/FX/Test/SWeffect02.png"),
		true);

	//StartEmission();
	
	//ī�޶� ����
	SetCameraSort(CAMERA, true);
}