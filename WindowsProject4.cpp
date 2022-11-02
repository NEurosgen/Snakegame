// WindowsProject4.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "WindowsProject4.h"
#include "Header.h"
#include <cstring>
#define MAX_LOADSTRING 20


// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
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

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSPROJECT4, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT4));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT4));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT4);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      100, 100,X+LOCALX, Y+LOCALY, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{

    
    static int x = 100, y = 100,h=0,flag=0,r=0,u=0,l=0,d=1,win=1,size=lon,speed=move,sizew=1,total=50;//Спавн змейки//
    //std::string num_str = std::to_string(total);
    static POint mas[lon*100];
    static Wall wal[COLWALL];
    int sx = 150;
    int sy = 125;
   
        
     for (int i = 0; i < COLWALL ; i++) {
         if (i > 0 && i % 6 == 0) { sy += 100; sx = 150; }
            wal[i].x = sx;
            wal[i].xk = sx + 50;
            wal[i].y = sy;
            wal[i].yk = sy + 50;
            sx += 100;

        }
        
    
    
    static POint ap = apple(x,wal);
    POint block;
    POint base;
    base.x = 100;
    base.y = 100;
    base.red = 150;
    base.green = 0;
    base.blue = 0;

    LPCWSTR ho = L"TOTAL";
    
    switch (message)
    {
   
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    
   
        
    
    case WM_KEYDOWN:
        if (wParam == VK_UP  && d!=1) { u = 1; d = 0; l = 0; r = 0; }
        if (wParam == VK_DOWN && u!=1) { u = 0; d = 1; l = 0; r = 0; }
        if (wParam == VK_RIGHT && l!=1) { u = 0; d = 0; l = 0; r = 1; }
        if (wParam == VK_LEFT && r!=1) { u = 0; d = 0; l = 1; r = 0; }

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        Phone(hdc);
        Rectangle(hdc, LOCALX, LOCALY, X, Y);
        if (l) { x -= speed; }
        if (u) { y -= speed; }
        if (d) { y += speed; }
        if (r) { x += speed; }

       

        if (flag == 0) {
            
              
            for (int i = 0; i < size; i++) {
                base.x = x + i * wheght;

                mas[i] = base;
            }
            flag++;
        }

        ap.hdc = hdc;
        Bline(ap);
        for (int i = 0; i < COLWALL; ++i) {
            wal[i].hdc = hdc;
            wall(wal[i]);
        }

        snake(hdc, x, y, mas, size,wal);
        //if (x<LOCALX || x>X || y<LOCALY || y>Y) { size = 0; }
        if (x < LOCALX) { x = X; }
        if (x > X) { x = LOCALX; } 
        if (y < LOCALY) {y = Y; }
        if (y > Y) { y = LOCALY; }

            if (if1(x,y,ap,mas)|| if2(x, y, ap, mas)|| if3(x, y, ap, mas)|| if4(x, y, ap, mas)) {
                add(mas, size);
                speed = speed+0;
                ap = apple(x,wal);
                
            }
            Sleep(15);
            if (win) {
                InvalidateRect(hWnd, NULL, 1);
            }
            
            

            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
