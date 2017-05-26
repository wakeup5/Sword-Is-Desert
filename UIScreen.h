#pragma once
#include "UICommon.h"
#include "UIWindow.h"
#include "UIButton.h"
#include "UIProgress.h"
#include "Player.h"
#include "UISocket.h"
#include "UIMiniMap.h"

class UIInventory;
class UILevel;

class UIScreenIconDeligate;
class UIScreen : public UIWindow
{
private:
	Player* _player;

	//���� �ϴ� UI������ ��ư
	UIButton* _uiIconInventory;
	UIButton* _uiIconQuest;
	UIButton* _uiIconSkill;
	UIButton* _uiIconExit;
	UIScreenIconDeligate* _uiIconDeligate;

	//���� ���
	UIProgress* _uiExp;
	UIDeligate* _defualtDeligate;

	//��� �ϴ�
	UIProgress* _uiHpBar;
	UIProgress* _uiMpBar;

	//��� �ϴ� ��ų ���
	UISocket* _skillSocket[10];

	// �κ��丮 ��ü
	UIInventory* _uiInven;

	// ���� ��ü
	UILevel* _uiLevel;

	//�̴ϸ� ����
	UITextBox* _miniMapInfo;
	
	//�̴ϸ�
	UIMiniMap* _minimap;

public:
	UIScreen();
	virtual ~UIScreen();

	void Setup(Player* player);
	void SetInventory(UIInventory* inven);
	void Update();

	void ActiveSocket(UINT num);

	void Render(LPD3DXSPRITE sprite);

	void SetMapInfo(std::string areaName, float time);
};

class UIScreenIconDeligate : public UIDeligate
{
public:
	inline virtual UINT OnClickDown(UIWindow* caller, UIWindow* root) override
	{
		switch (caller->GetTagNum())
		{
		case UITag::UI_SCREEN_ICON_EXIT:
			PostQuitMessage(0);
			break;
		case UITag::UI_SCREEN_ICON_INVENTORY:
			root->GetWindowByTag(UITag::UI_INVENTORY)->Toggle();
			break;
		case UITag::UI_SCREEN_ICON_QUEST:

			break;
		case UITag::UI_SCREEN_ICON_SKILL:
			root->GetWindowByTag(UITag::UI_SKILL)->Toggle();
			break;
		default:
			break;
		}

		return RETURN_OK;
	}
};

class UIScreenSocketDeligate : public UISocketDeligate
{
public:
	inline virtual UINT OnClickDown(UIWindow* caller, UIWindow* root) override
	{
		UISocket* mouseSocket = (UISocket*)root->GetWindowByTag(UITag::UI_MOUSE_SOCKET);
		UISocket* socket = (UISocket*)caller;

		SocketObject* mo = mouseSocket->GetSocketObject();
		SocketObject* so = socket->GetSocketObject();

		/*
		LOG_MGR->AddLog("�Ӵɰ�");
		SocketObject* t1;
		SocketObject* t2;
		SocketObject* t3;
		t1 = socket->GetSocketObject();
		t2 = mouseSocket->GetSocketObject();
		Item* temp;
		LOG_MGR->AddLog("���콺 ���Ϲ�ȣ : %d", mouseSocket->GetTagNum());
		LOG_MGR->AddLog("t1 ���Ϲ�ȣ : %d", mouseSocket->GetTagNum());

		if (t2 != NULL)temp = static_cast<Item*>(t2);

		if (temp == NULL)return RETURN_NO;

		t3 = t1;
		t1 = temp;
		t2 = t3;
		*/
		/**/
		
		int socketIndex = socket->GetTagNum();
		if (socketIndex >= 150 && socketIndex <= 159){
			switch (socketIndex)
			{
				case 150:
					UIShopButton::GetInstance()->screenItemArray[0] = UIShopButton::GetInstance()->screenTagNum;
					break;
				case 151:
					UIShopButton::GetInstance()->screenItemArray[1] = UIShopButton::GetInstance()->screenTagNum;
					break;
				case 152:
					UIShopButton::GetInstance()->screenItemArray[2] = UIShopButton::GetInstance()->screenTagNum;
					break;
				case 153:
					UIShopButton::GetInstance()->screenItemArray[3] = UIShopButton::GetInstance()->screenTagNum;
					break;
				case 154:
					UIShopButton::GetInstance()->screenItemArray[4] = UIShopButton::GetInstance()->screenTagNum;
					break;
				case 155:
					UIShopButton::GetInstance()->screenItemArray[5] = UIShopButton::GetInstance()->screenTagNum;
					break;
				case 156:
					UIShopButton::GetInstance()->screenItemArray[6] = UIShopButton::GetInstance()->screenTagNum;
					break;
				case 157:
					UIShopButton::GetInstance()->screenItemArray[7] = UIShopButton::GetInstance()->screenTagNum;
					break;
				case 158:
					UIShopButton::GetInstance()->screenItemArray[8] = UIShopButton::GetInstance()->screenTagNum;
					break;
				case 159:
					UIShopButton::GetInstance()->screenItemArray[9] = UIShopButton::GetInstance()->screenTagNum;
					break;
			}
		}


		if (mo == NULL && so == NULL)
		{
			return RETURN_OK;
		}
		else if (mo != NULL)
		{
			mouseSocket->SetSocketObject(NULL);
			socket->SetSocketObject(mo);
		}
		else if (so != NULL && mo == NULL)
		{
			mouseSocket->SetSocketObject(so);
			socket->SetSocketObject(mo);
		}
		
		return RETURN_OK;
	}
};