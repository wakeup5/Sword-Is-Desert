#include "stdafx.h"
#include "Effect_01.h"


Effect_01::Effect_01()
{
}


Effect_01::~Effect_01()
{
}

void Effect_01::Setup()
{
	//�迭�� 2 ���̻� 
	VEC_COLOR colors;
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	colors.push_back(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));


	VEC_SCALE scales;
	scales.push_back(0.0f);
	scales.push_back(0.7f);
	scales.push_back(0.5f);
	scales.push_back(0.2f);
	scales.push_back(0.0f);

	LPDIRECT3DTEXTURE9 pTex = RESOURCE_TEXTURE->GetResource(
		"../Resources/FX/Test/Sword.png");

	//��ƼŬ ������ ����
	cPartcleEmitter::Init(
		1000,				//�ִ� ��ƼŬ ��
		1000,				//�ʴ� ��ƼŬ �߻� ��
		1,					//�ϳ��� ��ƼŬ ���� ������ �ִ밪
		1.5,					//�ϳ��� ��ƼŬ ���� ������ �ּҰ�
		D3DXVECTOR3(-4, 6, -4),	//��ƼŬ ���� �ӵ� �ּҰ� ( ���ñ��� )
		D3DXVECTOR3(4, 8, 4),	//��ƼŬ ���� �ӵ� �ִ밪 ( ���ñ��� )
		D3DXVECTOR3(3, -10, 3),	//��ƼŬ ���� ���� �ּҰ� ( ���ñ��� )
		D3DXVECTOR3(3, -15, 3), //��ƼŬ ���� ���� �ִ밪 ( ���ñ��� )
		colors,				//�÷� �迭
		scales,				//������ �迭
		0.05f,				//����ũ�� �ּҰ�
		0.1f,				//�ִ밪
		pTex,				//�ؽ���
		false);


	EmissionType = PATICLE_EMISSION_TYPE::SPHERE;
	SphereEmissionRange = 0.0f;
	StartEmission();

}