#include "stdafx.h"
#include "StormPt.h"


StormPt::StormPt()
{
}


StormPt::~StormPt()
{
}

void StormPt::Setup()
{
	//�迭�� 2 ���̻� 
	VEC_COLOR colors;
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.01f));

	VEC_SCALE scales;
	scales.push_back(1.0f);
	scales.push_back(0.0f);


	LPDIRECT3DTEXTURE9 pTex = RESOURCE_TEXTURE->GetResource(
		"../Resources/FX/Test/Sword.png");

	cPartcleEmitter::Init(
		5000,				//�ִ� ��ƼŬ ��
		100,				//�ʴ� ��ƼŬ �߻� ��
		1.0,					//�ϳ��� ��ƼŬ ���� ������ �ּҰ�
		1.5,					//�ϳ��� ��ƼŬ ���� ������ �ִ밪
		D3DXVECTOR3(-3, 4, -3),	//��ƼŬ ���� �ӵ� �ּҰ� ( ���ñ��� )
		D3DXVECTOR3(3, 5, 3),	//��ƼŬ ���� �ӵ� �ִ밪 ( ���ñ��� )
		D3DXVECTOR3(0, 0, 0),	//��ƼŬ ���� ���� �ּҰ� ( ���ñ��� )
		D3DXVECTOR3(0, 0, 0), //��ƼŬ ���� ���� �ִ밪 ( ���ñ��� )
		colors,				//�÷� �迭
		scales,				//������ �迭
		0.05,				//����ũ�� �ּҰ�
		0.1,				//�ִ밪
		pTex,				//�ؽ���
		false);


	EmissionType = PATICLE_EMISSION_TYPE::SPHERE;
	SphereEmissionRange = 0.0f;
}