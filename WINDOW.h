#include <string>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "DataBase.cpp"

using namespace std;
LRESULT CALLBACK WindowProc(HWND hWnd,UINT uMsg, WPARAM wParam,LPARAM lParam);

class WINDOW{
public:
    WINDOW();
    WINDOW(const WINDOW&) = delete;
    WINDOW& operator =(const WINDOW&) = delete;
    ~WINDOW();
    bool ProcessMessages();
    //TEXTAI + NEWMESSANGE
    //NOTE FOR ME: No igualar Este string a si mismo, ya que el valor entrara en bucle.
private:

    HINSTANCE m_hinstance;
    HWND m_hWnd;

};
