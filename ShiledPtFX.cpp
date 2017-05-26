#include "stdafx.h"
#include "ShiledPtFX.h"


ShiledPtFX::ShiledPtFX()
{
}


ShiledPtFX::~ShiledPtFX()
{
}


void ShiledPtFX::Setup()
{
	//�迭�� 2 ���̻� 
	VEC_COLOR colors;
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));


	VEC_SCALE scales;
	scales.push_back(0.0f);
	scales.push_back(0.7f);
	scales.push_back(0.5f);
	scales.push_back(0.2f);
	scales.push_back(0.0f);

	LPDIRECT3DTEXTURE9 pTex = RESOURCE_TEXTURE->GetResource(
		"../Resources/FX/Test/Sword02.png");

	//��ƼŬ ������ ����
	cPartcleEmitter::Init(
		1000,				//�ִ� ��ƼŬ ��
		500,				//�ʴ� ��ƼŬ �߻� ��
		0.5,					//�ϳ��� ��ƼŬ ���� ������ �ִ밪
		0.6,					//�ϳ��� ��ƼŬ ���� ������ �ּҰ�
		D3DXVECTOR3(-5, -5, -5),	//��ƼŬ ���� �ӵ� �ּҰ� ( ���ñ��� )
		D3DXVECTOR3(5, 5, 5),	//��ƼŬ ���� �ӵ� �ִ밪 ( ���ñ��� )
		D3DXVECTOR3(-3, -3, -3),	//��ƼŬ ���� ���� �ּҰ� ( ���ñ��� )
		D3DXVECTOR3(3, 3, 3), //��ƼŬ ���� ���� �ִ밪 ( ���ñ��� )
		colors,				//�÷� �迭
		scales,				//������ �迭
		0.1f,				//����ũ�� �ּҰ�
		0.2f,				//�ִ밪
		pTex,				//�ؽ���
		false);


	EmissionType = PATICLE_EMISSION_TYPE::SPHERE;
	SphereEmissionRange = 0.0f;
	StartEmission();
}