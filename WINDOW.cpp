#include "WINDOW.h"
#define LOWORD
#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif
///////////////////////

//////////////////////////
///IMAGES PREFAPS///
HWND Hlogo;
HBITMAP HlogoImage;
OPENFILENAME ofn;
TCHAR szFile[MAX_PATH];
void DRAW();
///=======================/////
LRESULT CALLBACK WindowProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam){
 switch(uMsg){
case WM_CREATE:
    break;
case WM_CLOSE:
        DestroyWindow(hWnd);
    break;
case WM_DESTROY:
        PostQuitMessage(0);
    break;
case WM_COMMAND:{
    if(LOWORD(wParam) ==1){
    }
}
    return 0;
    }
    return DefWindowProc(hWnd,uMsg,wParam,lParam);
}

WINDOW::WINDOW(): m_hinstance(GetModuleHandle(nullptr)){
////////////////////////////////////////////
    const char* CLASS_NAME = "Ventanita";
///=====Window PRELOAD======///
    WNDCLASS wndclass = {};
    wndclass.lpszClassName = CLASS_NAME;
    wndclass.hInstance = m_hinstance;
    wndclass.hIcon = LoadIcon(NULL,IDI_WINLOGO);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpfnWndProc = WindowProc;
    wndclass.hbrBackground = (HBRUSH)(COLOR_WINDOW);

    RegisterClass(&wndclass);
    DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;
//WIDTH AND HEIGHT OF THE Window//
    int width = 200;
    int height = 200;
///==Window MEASUREMENTS===========////
    RECT rect;
    rect.left = 250;
    rect.top = 250;
    rect.right = rect.left + width;
    rect.bottom = rect.top + height;
///====================================///
    AdjustWindowRect(&rect, style, false);
///Window PROPERTIES
    m_hWnd = CreateWindowEx(0,CLASS_NAME,"Visor de Imagenes ICO",style,rect.left,rect.top,
                            rect.right - rect.left,rect.bottom - rect.top,
                            NULL,NULL,m_hinstance,NULL);
    ShowWindow(m_hWnd,SW_SHOW);

    ZeroMemory(&ofn, sizeof(ofn));

    ofn.lStructSize = sizeof(ofn);
    ofn.lpstrFile = szFile;
    ofn.lpstrFile[0] = '\0';
    ofn.hwndOwner = m_hWnd;
    ofn.nMaxFile = sizeof(szFile);
    ofn.lpstrFilter = TEXT("All files(*.ico*)\0*.ico*\0");
    ofn.nFilterIndex = 1;
    ofn.lpstrInitialDir = NULL;
    ofn.lpstrFileTitle = NULL;
    ofn.Flags = OFN_SHOWHELP | OFN_OVERWRITEPROMPT;

    GetOpenFileName(&ofn);
    printf(szFile);
// ofn.lpstrFile contiene el archivo seleccionado por el usuario
// lo mostramos como titulo de la ventana

///CREATE ITEMS WindowS
HWND hWndGIFAI = CreateWindow(
        ("Static"),
        (szFile),
        WS_CHILD | WS_VISIBLE | SS_LEFT,
        58,
        120,
        150,
        20,
        m_hWnd,
        NULL,
        NULL,
        NULL);
HWND hWndButton = CreateWindow(
        ("Button"),
        ("Algo"),
        WS_VISIBLE| WS_CHILD | WS_BORDER,
        65,
        145,
        60,
        50,
        m_hWnd,
        (HMENU) 1,
        NULL,
        NULL);
Hlogo = CreateWindowW(L"Static",
        NULL,WS_VISIBLE
        | WS_CHILD |
        SS_ICON,
        45,
        20,
        20,
        20,
        m_hWnd,
        NULL,
        NULL,
        NULL);
SendMessageW(Hlogo,STM_SETICON,IMAGE_ICON,(LPARAM)HlogoImage);
}

////DestroyWindow//////
WINDOW::~WINDOW(){
////////////////////////////////////////////
  const char* CLASS_NAME = "Ventanita";
  UnregisterClass(CLASS_NAME, m_hinstance);
////////////////////////////////////////////
}
///////////////
bool WINDOW::ProcessMessages(){
    MSG msg ={};
//////////////////////////////////////////////////
   while(PeekMessage(&msg,nullptr,0u,0u,PM_REMOVE)){
        if(msg.message == WM_QUIT){
            return false;
        }
///////////////////////////////
TranslateMessage(&msg);
DispatchMessage(&msg);
///////////////////////////
    }
    return true;
}
void DRAW(){
    //Esta guardando el valor pero el LoadImage no esta abriendo la imagen desde el directorio.
   HlogoImage = (HBITMAP)LoadImage(NULL,"Algo.ico",IMAGE_ICON,100,100,LR_LOADFROMFILE);
}
