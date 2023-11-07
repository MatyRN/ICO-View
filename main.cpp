#include <iostream>
#include "Window.cpp"

int main(){
        WINDOW* PWI = new WINDOW();
        bool running = true;
    while(running){
        if(!PWI->ProcessMessages())running = false;
        ///Renderizar
        Sleep(10);
    }
    delete PWI;
    return 0;
}
