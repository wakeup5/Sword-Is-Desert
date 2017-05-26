// 3D Portfolio - Sword Is Desert.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "3D Portfolio - Sword Is Desert.h"
#include "GameMain.h"

#define MAX_LOADSTRING 100

// ���� ����:
HINSTANCE hInst;       
HWND hWnd;										// ���� �ν��Ͻ��Դϴ�.
TCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
TCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.

GameMain gm;

HCURSOR customCursor;
WNDCLASSEX wcex;

// �� �ڵ� ��⿡ ��� �ִ� �Լ��� ������ �����Դϴ�.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ���⿡ �ڵ带 �Է��մϴ�.

    // ���� ���ڿ��� �ʱ�ȭ�մϴ�.
    LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadString(hInstance, IDC_MY3DPORTFOLIOSWORDISDESERT, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // ���� ���α׷� �ʱ�ȭ�� �����մϴ�.
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY3DPORTFOLIOSWORDISDESERT));

	//�޽��� ����ü
	MSG Message;
	ZeroMemory(&Message, sizeof(MSG));

	//���� �ʱ�ȭ �����ߴٸ�.....
	if (SUCCEEDED(gm.Setup()))		//S_OK �� �����ߴٸ�...
	{

		//������ ���� �����츦 ȭ�鿡 ����.
		ShowWindow(hWnd, nCmdShow);

		//
		// �޽��� ����
		//
		/*
		while( GetMessage( &Message, NULL, NULL, NULL ) )
		{
		TranslateMessage( &Message ); //���� Ű���� �� ���ڸ� �����Ͽ� WM_CHAR �޽����� �߻���Ų��.
		DispatchMessage( &Message );  //�޾ƿ� �޽��� ������ ������ ���ν��� �Լ��� �����Ų��.
		}
		*/


		//�޽�ť���� ���� �޽����� ����޽����� �ƴϸ� ��� ����
		while (Message.message != WM_QUIT) {

			//�޽���ť�� �޽��������� 
			//������ �������� PM_REMOVE �ɼ��������� ���޽�����
			//�����.
			//���� Message �� ���ٸ� false �� �����Ѵ�.
			if (PeekMessage(&Message, NULL, NULL, NULL, PM_REMOVE)) {
				TranslateMessage(&Message); //���� Ű���� �� ���ڸ� �����Ͽ� WM_CHAR �޽����� �߻���Ų��.
				DispatchMessage(&Message);  //�޾ƿ� �޽��� ������ ������ ���ν��� �Լ��� �����Ų��.
			}

			//������Ʈ 
			gm.Update();

			//��ο�
			gm.Render();

		}

	}

	//����
	gm.Release();

	//��ϵ� ������ Ŭ���� ���� ( ���൵ �׸� �����൵ �׸�.. )
	UnregisterClass(WIN_CLASS, hInstance);

    return (int)Message.wParam;
}


void setWindowPositionAndSize(int x, int y, int width, int height)
{
	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;

	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, false);
	SetWindowPos(hWnd, NULL, x, y, rc.right - rc.left, rc.bottom - rc.top, SWP_NOZORDER | SWP_NOMOVE);
}


//
//  �Լ�: MyRegisterClass()
//
//  ����: â Ŭ������ ����մϴ�.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
   // WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY3DPORTFOLIOSWORDISDESERT));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName = NULL;// MAKEINTRESOURCEW(IDC_MY3DPORTFOLIOSWORDISDESERT);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	
	customCursor = LoadCursorFromFile("stand_mouse.cur");
	wcex.hCursor = customCursor;
    return RegisterClassEx(&wcex);
}

//
//   �Լ�: InitInstance(HINSTANCE, int)
//
//   ����: �ν��Ͻ� �ڵ��� �����ϰ� �� â�� ����ϴ�.
//
//   ����:
//
//        �� �Լ��� ���� �ν��Ͻ� �ڵ��� ���� ������ �����ϰ�
//        �� ���α׷� â�� ���� ���� ǥ���մϴ�.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.

   HWND h;
   /*
   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
   */
   h = CreateWindow(
	   szWindowClass,				//�����Ǵ� �������� Ŭ�����̸�
	   szTitle,				//������ Ÿ��Ʋ�ٿ� ��µǴ� �̸�
	   WIN_STYLE,				//������ ��Ÿ��
	   WINPOS_X,				//������ ���� ��ġ X 
	   WINPOS_Y,				//������ ���� ��ġ Y
	   WINSIZE_X,				//������ ���� ũ�� ( �۾������� ũ�Ⱑ �ƴ� )
	   WINSIZE_Y,				//������ ���� ũ�� ( �۾������� ũ�Ⱑ �ƴ� )
	   GetDesktopWindow(),		//�θ� ������ �ڵ� ( ���α׷����� �ֻ��� ������� NULL �Ǵ� GetDesktopWindow() )
	   NULL,					//�޴� ID ( �ڽ��� ��Ʈ�� ��ü�� �������ΰ�� ��Ʈ�� ID �� ��	
	   hInstance,				//�� �����찡 ���� ���α׷� �ν��Ͻ� �ڵ�
	   NULL					//�߰� ���� NULL ( �Ű���� )
	   );

   if (!h)
   {
      return FALSE;
   }

   ShowWindow(h, nCmdShow);
   UpdateWindow(h);

   hWnd = h;
   setWindowPositionAndSize(WINPOS_X, WINPOS_Y, WINSIZE_X, WINSIZE_Y);

   return TRUE;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����:  �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND  - ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT    - �� â�� �׸��ϴ�.
//  WM_DESTROY  - ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//
LRESULT CALLBACK WndProc(HWND h, UINT message, WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�.
            EndPaint(h, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
		return gm.WndProc(h, message, wParam, lParam);
    }
    return 0;
}