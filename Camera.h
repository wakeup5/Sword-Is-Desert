#pragma once

#include "Transform.h"
#include "Singleton.h"
#include "cFrustum.h"

class Camera : public Transform
{
protected:
	float fov;			//ī�޶� ȭ��
	float camNear;		//ī�޶� Near
	float camFar;		//ī�޶� Far

	D3DXMATRIXA16		matView;		//�����
	D3DXMATRIXA16		matProjection;	//�������
	D3DXMATRIXA16		matViewProjection;	//�� * �������

	bool bOrtho;		//������?
private:
	LPDIRECT3DTEXTURE9		m_pRenderTexture = NULL;		//�������� Texture
	LPDIRECT3DSURFACE9		m_pRenderSurface = NULL;		//���� Texture Deapth ���ۿ� Stencil ���۰� �ִ� Surface
	LPDIRECT3DSURFACE9		m_pDeviceTargetSurface;
	LPDIRECT3DSURFACE9		m_pDeviceDepthAndStencilSurface;

public:
	cFrustum			Frustum;

public:
	Camera(void);
	~Camera(void);

	//������İ� View ����� ������Ʈ
	void UpdateMatrix();

	//View ��İ� ���� ����� ����
	void UpdateCamToDevice( LPDIRECT3DDEVICE9 pDevice );



	//ī�޶� ���� ����� ��´�.
	D3DXMATRIXA16 GetViewMatrix() const{
		return this->matView;
	}

	D3DXMATRIXA16 GetProjectionMatrix() const{
		return this->matProjection;
	}

	D3DXMATRIXA16 GetViewProjectionMatrix() const{
		return this->matViewProjection;
	}

	//ȭ�� ����
	void SetFov( float fov ){
		this->fov = fov;
	}

	float GetFov(){
		return this->fov;
	}

	void OrthoToggle(){
		this->bOrtho = !this->bOrtho;
	}

	float GetFar() const { return camFar; }
	void SetFar(float f) { camFar = f; }
	float GetNear() const { return camNear; }

	//ȭ���� ��ġ�� ������ ī�޶��� ���� ���̸� ��´�
	void ComputeRay( LPRay pOutRay, const D3DXVECTOR2* screenPos ); 

	//���� ��ġ��  ȭ���� ��ġ�� ��´�.
	bool GetWorldPosToScreenPos( D3DXVECTOR2* pScreenPos, const D3DXVECTOR3* pWorldPos );

	//���� Texture �� �غ� �Ѵ�.
	void ReadyRenderToTexture(int width, int height);

	//Shadow Map Texture�� �غ��Ѵ�.
	void ReadyShadowTexture(int size);

	//���� Texture �� ������ ����
	void RenderTextureBegin(DWORD backColor);

	//���� Texture �� ������ ����
	void RenderTextureEnd();

	//���� Texture ��´�.
	LPDIRECT3DTEXTURE9 GetRenderTexture();
};