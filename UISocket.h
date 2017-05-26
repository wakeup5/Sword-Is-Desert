#pragma once
#include "UITextBox.h"

class UISocket : public UITextBox
{
private:
	SocketObject* _obj;
public:
	UISocket();
	virtual ~UISocket();

	void Render(LPD3DXSPRITE sprite);

	void SetSocketObject(SocketObject* obj) { _obj = obj; }
	void removeS(){ _obj = NULL; }
	SocketObject* GetSocketObject() { return _obj; }
};



class UISocketDeligate : public UIDeligate
{
public:
	inline virtual UINT OnClickDown(UIWindow* caller, UIWindow* root) override
	{
		//root->GetWindowByTag(UITag::UI_SCREEN)->SetHiddenState(true);
		//caller->GetTop()->SetHiddenState(true);
		UISocket* cs = (UISocket*)caller;
		UISocket* ms = (UISocket*)root->GetWindowByTag(UITag::UI_MOUSE_SOCKET);
		
		if (!ms) return RETURN_NO;
		
		ms->SetSocketObject(cs->GetSocketObject());

		return RETURN_DEFAULT;
	}
};





#include "UIShopButton.h"
#define NULL_STATE 10000
class UIInventorySocketDeligate : public UIDeligate
{
private:
	UINT _clickIndex;
	UINT _dragEndIndex;
	UINT _mouseOverIndex;
	UINT _useItemIndex;
	bool _isFirstClick = false;
	bool _isMouseOver = false;
	bool _isInventoryOpen = false;
	std::vector<int> _nullCheck;
	POINT _pt;
	UISocket* _UiMousePoint = NULL;
public:
	void init(){
		_clickIndex = NULL_STATE;
		_dragEndIndex = NULL_STATE;
		_mouseOverIndex = NULL_STATE;
		_useItemIndex = NULL_STATE;
		_isFirstClick = false;
		_isMouseOver = false;
		_pt.x = 0; 
		_pt.y = 0;
		if (_UiMousePoint!=NULL)(_UiMousePoint)->SetSocketObject(NULL);
		else _UiMousePoint = NULL;
	}
	inline virtual UINT OnClickDown(UIWindow* caller, UIWindow* root) override
	{
		//root->GetWindowByTag(UITag::UI_SCREEN)->SetHiddenState(true);
		//caller->GetTop()->SetHiddenState(true);
		UISocket* cs = (UISocket*)caller;
		UISocket* ms = (UISocket*)root->GetWindowByTag(UITag::UI_MOUSE_SOCKET);
		_UiMousePoint = ms;
		_pt = ms->GetPosition();
		if (!_isInventoryOpen)return RETURN_DEFAULT;

		// �Ǹ� ��� Ȯ�� â
		if (_isFirstClick && isSellMode){
			return RETURN_NO;
		}
		
		if (!_isFirstClick){

			for (auto i = _nullCheck.begin(); i != _nullCheck.end(); ++i){
				if ((*i) == caller->GetTagNum()){
					return RETURN_DEFAULT;
				}
			}
			_clickIndex = caller->GetTagNum(); // �ش� ��ȣ ����
			_isFirstClick = true;
			// �Ǹ� ����
			if (isSellMode){
				//this->SetPosition(WINSIZE_X - 428, 100);
				POINT pt;
				pt.x = ms->GetPosition().x; //- ((WINSIZE_X / 2) - 208);
				pt.y = ms->GetPosition().y; //- 95;
				UIShopButton::GetInstance()->_isShowBtn = true;
				UIShopButton::GetInstance()->SetButtonPosition(pt);
				return RETURN_NO;
			}
		}
		else{
			// ���� ���Ϲ�ȣ Ŭ��
			if (_clickIndex == caller->GetTagNum() && !isSellMode){
				init();
				return RETURN_NO;
			}


			_dragEndIndex = caller->GetTagNum(); // �ش� ��ȣ ����
			_isFirstClick = false;

		}
		if (!ms) return RETURN_NO;

		ms->SetSocketObject(cs->GetSocketObject());

		UIShopButton::GetInstance()->screenTagNum = cs->GetTagNum();

		return RETURN_DEFAULT;
	}

	inline virtual UINT OnMouseOver(UIWindow* caller, UIWindow* root) override
	{
		//root->GetWindowByTag(UITag::UI_SCREEN)->SetHiddenState(true);
		//caller->GetTop()->SetHiddenState(true);
		UISocket* cs = (UISocket*)caller;
		UISocket* ms = (UISocket*)root->GetWindowByTag(UITag::UI_MOUSE_SOCKET);

		int sdf = cs->GetTagNum();
		
		UINT itemIndex = caller->GetTagNum();
		if (itemIndex >= 350 && itemIndex <= 414){
			_isMouseOver = true;
			_mouseOverIndex = itemIndex;
		}
		else{
			_isMouseOver = false;
		}

		if (!ms) return RETURN_NO;

		//ms->SetSocketObject(cs->GetSocketObject());

		return RETURN_DEFAULT;
	}

	inline virtual UINT OnRightClickDown(UIWindow* caller, UIWindow* root) override
	{
		UISocket* cs = (UISocket*)caller;
		UISocket* ms = (UISocket*)root->GetWindowByTag(UITag::UI_MOUSE_SOCKET);
		if (!ms) return RETURN_NO;
		int f = 0;

		
		_useItemIndex = caller->GetTagNum() - 350;

		return RETURN_DEFAULT;
	}


	UINT GetIndex(){ return _clickIndex; }
	UINT GetDragIndex(){ return _dragEndIndex; }
	UINT GetMouseOverIndex(){ return _mouseOverIndex; }
	UINT GetUseItemIndex(){ return _useItemIndex; }

	bool	 IsClick(){ return _isFirstClick; }
	bool IsMouseOver(){ return _isMouseOver; }
	void SetClickState(bool mClick){ _isFirstClick = mClick; }
	void SetNullCheckVector(std::vector<int> vec){
		_nullCheck = vec;
	}
	void IsInventoryOpen(bool isOpen){
		_isInventoryOpen = isOpen;
	}

	POINT GetPoint(){
		return _pt;
	}
};




#include "UIShopButton.h"
#include "UIButton.h"
#define NULL_STATE 10000
class UIShopSocketDeligate : public UIDeligate
{
private:
	UINT _clickIndex;
	UINT _dragEndIndex;
	UINT _mouseOverIndex;
	UINT _useItemIndex;
	bool _isFirstClick = false;
	bool _isMouseOver = false;
	bool _isInventoryOpen = false;
	bool _isButtonOpen = false;
	POINT _mousePt;
	std::vector<int> _nullCheck;

public:
	void init(){
		_clickIndex = NULL_STATE;
		_dragEndIndex = NULL_STATE;
		_mouseOverIndex = NULL_STATE;
		_useItemIndex = NULL_STATE;
		_isButtonOpen = false;
		_isFirstClick = false;
		_isMouseOver = false;
		_isInventoryOpen = false;
		_mousePt.x = 0;
		_mousePt.y = 0;
	}
	inline virtual UINT OnClickDown(UIWindow* caller, UIWindow* root) override
	{
		//root->GetWindowByTag(UITag::UI_SCREEN)->SetHiddenState(true);
		//caller->GetTop()->SetHiddenState(true);
		UISocket* cs = (UISocket*)caller;
		UISocket* ms = (UISocket*)root->GetWindowByTag(UITag::UI_MOUSE_SOCKET);
		
		if (!_isInventoryOpen)return RETURN_DEFAULT;

		
		if (!ms) return RETURN_NO;

	

		ms->SetSocketObject(cs->GetSocketObject());

		return RETURN_DEFAULT;
	}

	inline virtual UINT OnMouseOver(UIWindow* caller, UIWindow* root) override
	{
		//root->GetWindowByTag(UITag::UI_SCREEN)->SetHiddenState(true);
		//caller->GetTop()->SetHiddenState(true);
		UISocket* cs = (UISocket*)caller;
		UISocket* ms = (UISocket*)root->GetWindowByTag(UITag::UI_MOUSE_SOCKET);

		int sdf = cs->GetTagNum();
		UINT itemIndex = caller->GetTagNum();
		if ((itemIndex >= 1730 && itemIndex <= 1794) || itemIndex == 0){
			_isMouseOver = true;
			_mouseOverIndex = itemIndex;
		}
		else{
			_isMouseOver = false;
		}

		if (!ms) return RETURN_NO;

		//ms->SetSocketObject(cs->GetSocketObject());

		return RETURN_DEFAULT;
	}

	inline virtual UINT OnRightClickDown(UIWindow* caller, UIWindow* root) override
	{
		UISocket* cs = (UISocket*)caller;
		UISocket* ms = (UISocket*)root->GetWindowByTag(UITag::UI_MOUSE_SOCKET);
		if (!ms) return RETURN_NO;
		int f = 0;

		_useItemIndex = caller->GetTagNum() - 350;
		_mousePt.x = ms->GetPosition().x;
		_mousePt.y = ms->GetPosition().y;
		// �� ���� ���� 
		LOG_MGR->AddLog("%d", _useItemIndex);
		if (_useItemIndex == -350){
			this->init();
			UIShopButton::GetInstance()->_isShowBtn = false;
			return RETURN_DEFAULT;
		}

		UIShopButton::GetInstance()->_isShowBtn = true;
		// ������
		POINT pt;
		pt.x = ms->GetPosition().x;// - ((WINSIZE_X / 2) - 190);
		pt.y = ms->GetPosition().y;// - 110;
		UIShopButton::GetInstance()->SetButtonPosition(pt);
		return RETURN_DEFAULT;
	}


	UINT GetIndex(){ return _clickIndex; }
	UINT GetDragIndex(){ return _dragEndIndex; }
	UINT GetMouseOverIndex(){ return _mouseOverIndex; }
	UINT GetUseItemIndex(){ return _useItemIndex; }
	POINT GetMousePt(){
		return _mousePt;
	}

	bool	 IsClick(){ return _isFirstClick; }
	bool IsMouseOver(){ return _isMouseOver; }
	void SetClickState(bool mClick){ _isFirstClick = mClick; }
	void SetNullCheckVector(std::vector<int> vec){
		_nullCheck = vec;
	}
	void IsInventoryOpen(bool isOpen){
		_isInventoryOpen = isOpen;
	}



};
