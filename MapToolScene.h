#pragma once
#include "Scene.h"
#include "cTerrain.h"
#include "Day.h"
#include "cBaseObject.h"
#include "MapDataSaveLoad.h"

class UIMapToolWIndow;

class MapToolScene :
	public Scene
{
private:
	//�⺻
	cTerrain* _map;
	Day* _day;

	//�� �̵�
	Transform* _mapViewPoint;
	float _dist;

	POINT prev;

	float _rx, _ry;

	//�� Ŭ��
	Transform* _lastClickTrans;
	Ray	_lastClickRay;

	//������Ʈ
	std::vector<std::pair<std::string, cBaseObject*>> _vecObj; //��ġ�� ������Ʈ
	std::vector<std::string> _vecObjName; //�ε� �� ������Ʈ �̸���

	//�÷��̾�
	cBaseObject* _player;
	std::string _playerName;

	//����
	std::vector<std::pair<std::string, cBaseObject*>> _vecMon;
	std::vector<std::string> _vecMonName;

	//NPC
	std::vector<std::pair<std::string, cBaseObject*>> _vecNpc;
	std::vector<std::string> _vecNpcName;

	//���õ� ������Ʈ
	enum { PLAYER, MONSTER, OBJECT, NPC, NONE } _selectType = NONE;
	cBaseObject* _selectObject;
	bool _isPlayerSelect; //�÷��̾ ���õǸ� ������ �Ұ��� �ؾ� �Ѵ�.

	//�� ���� ����, �ε�
	MapDataSaveLoad _mapDataSL;

	//ui
	UIMapToolWIndow* _ui;

	//���̺� �ε� �۾���?
	bool _isSavingLoading = false;
public:
	MapToolScene();
	virtual ~MapToolScene();

	virtual HRESULT Setup();
	virtual void Release();
	virtual void Update(float timeDelta);
	virtual void Render();

	void LoadResources();

	void MapMoveUpdate();
	void RayClickUpdate();
	void SelectUpdate();

	void CreateObject(std::string name);
	void CreateMonster(std::string name);
	void CreateNPC(std::string name);
	void Delete();

	std::string GetObjectName(UINT idx);
	std::string GetMonsterName(UINT idx);
	std::string GetNPCName(UINT idx);

	void SaveData();
	void LoadData();
	void Clear();

	virtual LRESULT CALLBACK WndProc(HWND h, UINT iMessage, WPARAM wParam, LPARAM lParam);

	friend class UIMapToolDeligate;
};

#include "UIWindow.h"
#include "UITextBox.h"

class UIMapToolWIndow : public UIWindow
{
public:
	MapToolScene* _scene;
public:
	virtual void Setup();
	virtual void Release();
	virtual void Update();
	virtual void Render(LPD3DXSPRITE sprite);
};

class UIMapToolDeligate : public UIDeligate
{
public:
	MapToolScene* _scene;
public:
	virtual UINT OnClickDown(UIWindow* caller, UIWindow* root) override;
};