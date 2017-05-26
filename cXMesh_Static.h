#pragma once
#include "cxmesh.h"

class Camera;
class Transform;

class cXMesh_Static : public cXMesh
{
public:
	static LPD3DXEFFECT				sStaticMeshEffect;				//StaticMesh �� �׸��� Effect
	static LPDIRECT3DTEXTURE9		sDefaultDiffuseTex;
	static LPDIRECT3DTEXTURE9		sDefaultNormalTex;
	static LPDIRECT3DTEXTURE9		sDefaultSpecularTex;
	static LPDIRECT3DTEXTURE9		sDefaultEmissionTex;

protected:
	LPD3DXMESH							pMesh;
	
	DWORD								dwMaterialsNum;			//�ε��� �Ž��� ���� ����
	std::vector<LPDIRECT3DTEXTURE9>		vecDiffuseTex;			//�ε��� �޽����� ����ϴ� DiffuseTexture
	std::vector<LPDIRECT3DTEXTURE9>		vecNormalTex;			//�ε��� �޽����� ����ϴ� NormalTexture
	std::vector<LPDIRECT3DTEXTURE9>		vecSpecularTex;			//�ε��� �޽����� ����ϴ� SpecularTexture
	std::vector<LPDIRECT3DTEXTURE9>		vecEmissionTex;			//�ε��� �޽����� ����ϴ� EmissionTexture
	std::vector<D3DMATERIAL9>			vecMaterials;			//�ε��� �޽����� ����ϴ� ���͸���...

	

	std::vector<D3DXVECTOR3>			Vertices;				//������
	std::vector<D3DXVECTOR3>			Normals;				//���� �븻
	std::vector<DWORD>					Indices;				//�ε���
	DWORD								TriNum;					//�ﰢ���� ����

public:
	D3DXVECTOR3							Bound_Min;					//�ٿ���� �ּ� ��ġ 
	D3DXVECTOR3							Bound_Max;					//�ٿ���� �ִ� ��ġ 
	D3DXVECTOR3							Bound_Center;				//�ٿ���� ����	( ���� ���� �Ǻ��� �ƴϴ� )
	D3DXVECTOR3							Bound_Size;					//�ٿ���� ũ��
	D3DXVECTOR3							Bound_HalfSize;				//�ٿ���� ����ũ��
	float								Bound_Radius;				//�ٿ���� ������ ������


	//�����Ŵ����� ��ģ��.....
	friend class cPhysicManager;

public:
	cXMesh_Static(void);
	~cXMesh_Static(void);

	virtual HRESULT Init( std::string filePath, const D3DXMATRIXA16* matCorrection = NULL );

	virtual void Release();

	virtual void Render( const Transform* Trans );
	virtual void RenderShadow(const Transform* Trans, Camera* light);


private:
	//������Ĵ�� �޽��� �����Ѵ�.
	void MeshCorrection( const D3DXMATRIXA16* pmatCorrection );


public:
	static void SetCamera( const Camera* Camera );

	bool IntersectMap(float x, float &y, float z)
	{
		float u, v, d;
		for (int i = 0; i < Indices.size(); i += 3)
		{
			//if (D3DXVec3Length(&(Vertices[Indices[i]] - D3DXVECTOR3(x, y, z))) > 2) continue;

			if (D3DXIntersectTri(&Vertices[Indices[i]], &Vertices[Indices[i + 1]], &Vertices[Indices[i + 2]]
				, &D3DXVECTOR3(x, 1000, z), &D3DXVECTOR3(0, -1, 0), &u, &v, &d))
			{
				y = 1000 - d;

				return true;
			}
		}

		return false;
	}

	//technique ����
	static void SetTechniqueName(std::string name);
};

