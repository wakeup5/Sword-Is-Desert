#pragma once


class Transform;

class cBoundSphere
{
public: 
	D3DXVECTOR3 localCenter;
	float radius;
	D3DXVECTOR3 halfSize;

public:
	cBoundSphere(void);
	~cBoundSphere(void);

	//���� ������ ���Ϳ� �������� ��´�.
	void GetWorldCenterRadius( const Transform* pTrans, D3DXVECTOR3* center, float* raidus );

	//���� ������ �׷�����.
	virtual void RenderGizmo( const Transform* pTrans, DWORD color = 0xffffff00);

	virtual void SetBound( const D3DXVECTOR3* pCenter, const D3DXVECTOR3* pHalfSize );

};

