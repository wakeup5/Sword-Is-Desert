#include "stdafx.h"
#include "Boss_Around_Dust.h"


Boss_Around_Dust::Boss_Around_Dust()
{
}


Boss_Around_Dust::~Boss_Around_Dust()
{
}

void Boss_Around_Dust::Setup()
{
	//�迭�� 2 ���̻� 
	VEC_COLOR colors;
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.2f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.2f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.2f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.1f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));

	VEC_SCALE scales;
	scales.push_back(1.0f);
	scales.push_back(0.2f);

	LPDIRECT3DTEXTURE9 pTex = RESOURCE_TEXTURE->GetResource(
		"../Resources/FX/Test/dust.png");

	//��ƼŬ ������ ����
	cPartcleEmitter::Init(
		1000,				//�ִ� ��ƼŬ ��
		200,				//�ʴ� ��ƼŬ �߻� ��
		0.7,					//�ϳ��� ��ƼŬ ���� ������ �ִ밪
		0.8,					//�ϳ��� ��ƼŬ ���� ������ �ּҰ�
		D3DXVECTOR3(-8, 0, -8),	//��ƼŬ ���� �ӵ� �ּҰ� ( ���ñ��� )
		D3DXVECTOR3(8, 0, 8),	//��ƼŬ ���� �ӵ� �ִ밪 ( ���ñ��� )
		D3DXVECTOR3(3, 0, 3),	//��ƼŬ ���� ���� �ּҰ� ( ���ñ��� )
		D3DXVECTOR3(5, 0, 5), //��ƼŬ ���� ���� �ִ밪 ( ���ñ��� )
		colors,				//�÷� �迭
		scales,				//������ �迭
		2.0f,				//����ũ�� �ּҰ�
		2.5f,				//�ִ밪
		pTex,				//�ؽ���
		false);


	EmissionType = PATICLE_EMISSION_TYPE::SPHERE;
	SphereEmissionRange = 0.0f;
	//	StartEmission();
}
