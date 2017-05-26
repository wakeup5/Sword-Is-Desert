#pragma once
#include "UIWindow.h"
#include "UITextBox.h"
#include "UIButton.h"
#include "Inventory.h"
#include "Equipment.h"
#include "UISocket.h"

class UIInventory : public UIWindow
{
private:
	UITextBox* _textBox;
	UIButton* _buttonOk;
	Inventory* _inventory;
	
	UIDeligateDefault* defaulDeligate;
	
	UIWindow* content;

	UIInventorySocketDeligate* _inventorySocket;

	UITextBox* itemInfoBox;
	UITextBox* itemInfoNameBox;
	UITextBox* itemInfoDiscBox;
	UITextBox* itemInfoPrice1Box;
	UITextBox* itemInfoPrice2Box;
	UISocket* itemInfoSocket;
	UISocket* moneySocket;
	UITextBox* moneyQTY;

	Equipment* _equiped;

	bool _isOpenInventory = false;	

	float fTime = 0;
	float nowTime = 0;
public:
	UIInventory();
	virtual ~UIInventory();

	virtual void Setup(Inventory* inven, Equipment* equiped);
	virtual void Release();
	virtual void Update();
	virtual void Render(LPD3DXSPRITE sprite);
	// ����������â �ʱ�ȭ
	void RemoveText();
	// ������ ����
	void SetItemInfo(ItemInfo& info);
	// �κ��丮 ���� ����(�κ��丮 â ������ ���â �����)
	bool IsInventoryOpen(){
		return _isOpenInventory;
	}
	
	void InventorySellClick();
	void InventorySwap();
	void InventoryEquiped();
	void InventoryItemInfo();

	void AddInventory(std::string itemName);
	Inventory* GetInventory(){
		return _inventory;
	}

	void UseItem(int idx);

	void Toggle();
};

