#pragma once
#include "Singleton.h"

class cTerrain;
class Pet;

class TerrainManager : public Singleton < TerrainManager >
{
private:
	std::map<std::string, cTerrain*> _mTerrain;
public:
	TerrainManager();
	virtual ~TerrainManager();

	HRESULT Setup();
	void Release();

	void Render(std::string name, Camera* cam);
	
	float GetHeight(std::string name, float x, float z);
	float GetHeight(std::string name, OUT Transform* trans);
	float GetHeight(std::string name, OUT D3DXVECTOR3* pos);
	void SetHeight(std::string name, Character* character);
	void SetHeight(std::string name, Pet* character);
	void SetHeight(std::string name, const D3DXVECTOR3* pos, OUT float* height);

	cTerrain* GetTerrain(std::string name);
	void Create(
		std::string name,
		const char* szHeightMapName,		//���̸� �̸�
		const char* szTile_0,				// Ÿ�� �̹��� 0
		const char* szTile_1,				// Ÿ�� �̹��� 1
		const char* szTile_2,				// Ÿ�� �̹��� 2
		const char* szTile_3,				// Ÿ�� �̹��� 3
		const char* szTileSplat,			// Ÿ�� �̹��� ��Ʈ�� ( RGB Black )
		float cellSize,						// �ϳ��� ��ũ��
		float heightScale,					// ���� ������
		int smoothLevel,					// ������ ó�� Ƚ�� 
		int tileNum							// Ÿ�ϸ� ����
		);
};

#define TERRAIN_MGR TerrainManager::GetInstance()