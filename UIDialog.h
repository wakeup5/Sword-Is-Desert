#pragma once
#include "UIWindow.h"
#include "UIButton.h"
#include "UIAlram.h"
// �̻��ϰ� ������ ���������� �������� ó��.. ȭ���� �Ⱥ��̴¿����� ��ġ
#define MOVE_NULL_WINDOW_X 2000
#define MOVE_NULL_WINDOW_Y 10000

class UIShop;
class UIInventory;

class UIDialog :
	public UIWindow
{
private:
	cBaseObject* _npc = NULL;

	UITextBox* _name;
	UITextBox* _answer;

	UIShop* _shop;
	UIInventory* _inven;
	
	int questTextIndex = 0;
	std::string _selectQuestName;
	std::vector<UIButton*> _vecQuestBtn;

	// �ش� UI NPC�� ������ �ִ� ����Ʈ ����
	NpcInfo::quest questInfo;
	UINT _questTextIndex = 0; // �ش� ����Ʈ �ؽ�Ʈ�� �ε��� ��ȣ(����Ʈ ����� ����)
	UINT _questIndex = 0; // �ش� ����Ʈ �ؽ�Ʈ�� �ε��� ��ȣ(����Ʈ ����� ����)
	UINT _uiUpdateIndex = 0;

	bool _isOpenShop = false;
	bool _isNpcSceneMode = false;


public:

	bool isSelect = false;

	UIDialog();
	virtual ~UIDialog();

	void Setup();
	void Update();
	void Render(LPD3DXSPRITE sprite);
	void SetShop(UIShop* shop);
	void SetInventory(UIInventory* inven);
	void SetNPC(cBaseObject* npc) 
	{
		_npc = npc;

		if (_npc != NULL && !_isNpcSceneMode)
		{
			_isNpcSceneMode = true;
			Enable();
		}
		else
		{
			_isNpcSceneMode = false;
			Disible();
		}
	}

	bool IsExistNPC() { return _npc != NULL; }

	void SetQuest();
	void SelectQuest(UINT idx);

	void Enable();
	void Disible();

	void SetUiUpdateIndex(UINT idx){
		_uiUpdateIndex = idx;
	}

	void NextQuestText(); // ����Ʈ ���
	void NoQuest(); // ����Ʈ ����
	void AcceptQuest(); // ����Ʈ ����
	void OpenShop(); //  ���� ����

};

class UIDialogDeligate : public UIDeligate
{
public:
	inline virtual UINT OnClickDown(UIWindow* caller, UIWindow* root) override
	{
		UINT t = caller->GetTagNum();
		int sdf = 0;

		if (caller->GetTagNum() >= 1150 && caller->GetTagNum() <= 1199){
			((UIDialog*)(caller->GetTop()))->SelectQuest(caller->GetTagNum());
			((UIDialog*)(caller->GetTop()))->isSelect = true;
			return RETURN_DEFAULT;
		}

		switch (caller->GetTagNum())
		{
		case UITag::UI_DIALOG_CLOSE:
			((UIDialog*)(caller->GetTop()))->SetNPC(NULL);
			break;
	
		case UITag::UI_DIALOG_BEGIN:
			LOG_MGR->AddLog("ó������");
			((UIDialog*)(caller->GetTop()))->NoQuest();
			break;

		case UITag::UI_DIALOG_QUEST:
			((UIDialog*)(caller->GetTop()))->SetQuest();
			break;

		case UITag::UI_DIALOG_QUEST_SOCKET :
			LOG_MGR->AddLog("����Ʈ ����Ʈ Ŭ�� ��");
			((UIDialog*)(caller->GetTop()))->SelectQuest(1);
			break;
		
		case UITag::UI_DIALOG_QUEST_NEXT :
			LOG_MGR->AddLog("�ؽ�Ʈ Ŭ�� ��");
			((UIDialog*)(caller->GetTop()))->NextQuestText();
			break;

		case UITag::UI_DIALOG_QUEST_ACCEPT:
			((UIDialog*)(caller->GetTop()))->AcceptQuest();
			break;

		case UITag::UI_DIALOG_QUEST_NO:
			((UIDialog*)(caller->GetTop()))->NoQuest();
			break;

		case UITag::UI_SHOP:{
			int dsfsd = 0;
			((UIDialog*)(caller->GetTop()))->OpenShop();
		}
			break;

		default:
			break;
		}

		return RETURN_DEFAULT;
	}
	inline virtual UINT OnMouseOver(UIWindow* caller, UIWindow* root) override
	{
		((UIDialog*)(caller->GetTop()))->SetUiUpdateIndex(caller->GetTagNum());

		return RETURN_DEFAULT;
	}
};