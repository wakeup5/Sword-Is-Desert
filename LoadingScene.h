#pragma once
#include "Scene.h"
#include "UIProgress.h"
#include "UITextBox.h"
#include "MapView.h"

enum LOADING_TYPE
{
	LT_TEXTURE,
	LT_XMESH_STATIC,
	LT_XMESH_SKINNED
};

class Loading;

struct tagLoadingSceneThreadParameter
{
	Loading* loading;
	std::string nextScene;
	//std::promise<bool>* promise;
};

class LoadingScene : public Scene
{
private:
	Loading* _loading;

	cTerrain* _ter;

	D3DXVECTOR3 _playerPos;
	D3DXVECTOR3 _viewPos;
	D3DXVECTOR3 _camPos;

	const char* _nextScene;

	std::thread loadingThread;

	//∏  ø¿∫Í¡ß∆Æ
	std::vector<cBaseObject*> _mapObj;

	MapView _map;
public:
	LoadingScene(const char* next);
	virtual ~LoadingScene();

	virtual HRESULT Setup();
	virtual void Release();
	virtual void Update(float timeDelta);
	virtual void Render();

	void LoadList();
};

class Loading
{
private:
	std::vector<std::pair<LOADING_TYPE, std::string>> _vLoading;
	UINT _current;

	UIProgress* _progress;
	UITextBox* _textBox;
public:
	void Setup();
	void Release();
	void Render();

	void LoadTexture(std::string resourcePath);
	void LoadXMeshStatic(std::string resourcePath);
	void LoadXMeshSkinned(std::string resourcePath);	

	bool LoadNext();

	float GetPercent() { return (float)_current / (float)_vLoading.size(); }
};