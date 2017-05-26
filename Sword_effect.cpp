#include "stdafx.h"
#include "Sword_effect.h"


Sword_effect::Sword_effect()
{
}


Sword_effect::~Sword_effect()
{
}

void Sword_effect::Setup()
{
	//�迭�� 2 ���̻� 
	VEC_COLOR colors;
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.01f));

	VEC_SCALE scales;
	scales.push_back(0.2f);
	scales.push_back(0.1f);


	LPDIRECT3DTEXTURE9 pTex = RESOURCE_TEXTURE->GetResource(
		"../Resources/FX/Test/Sword.png");

	cPartcleEmitter::Init(
		5000,				//�ִ� ��ƼŬ ��
		300,				//�ʴ� ��ƼŬ �߻� ��
		0.6,					//�ϳ��� ��ƼŬ ���� ������ �ּҰ�
		0.7,					//�ϳ��� ��ƼŬ ���� ������ �ִ밪
		D3DXVECTOR3(-3, -3, -3),	//��ƼŬ ���� �ӵ� �ּҰ� ( ���ñ��� )
		D3DXVECTOR3(3, 3, 3),	//��ƼŬ ���� �ӵ� �ִ밪 ( ���ñ��� )
		D3DXVECTOR3(-2, -2, -2),	//��ƼŬ ���� ���� �ּҰ� ( ���ñ��� )
		D3DXVECTOR3(2, 2, 2), //��ƼŬ ���� ���� �ִ밪 ( ���ñ��� )
		colors,				//�÷� �迭
		scales,				//������ �迭
		0.2,				//����ũ�� �ּҰ�
		0.3,				//�ִ밪
		pTex,				//�ؽ���
		false);


	EmissionType = PATICLE_EMISSION_TYPE::SPHERE;
	SphereEmissionRange = 0.0f;
	//StartEmission();
}