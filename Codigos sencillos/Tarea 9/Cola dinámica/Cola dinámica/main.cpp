#include <iostream>
#include <windows.h>
#include "Cola.h"

using namespace std;

void insertar(Cola&);
bool validacionASCII(char&);
void gotoxy(int, int);

int main(){
    char op;
    Cola miCola;

    gotoxy(10, 1);
    cout<<"COLA DINAMICA"<<endl;

    do{
        cout<<endl<<"-----------------"<<endl;
        cout<<"Elija una opcion."<<endl<<endl<<"a. Encolar."<<endl<<"b. Desencolar."<<endl<<"c. Frente."<<endl<<"d. Final."<<endl<<"e. Imprimir."<<endl<<"f. Salir.";
        cout<<endl<<"-----------------"<<endl;
        cin>>op;

        switch(op){
            case 'a': insertar(miCola); break;
            case 'b': cout<<miCola.desencolar()<<" ha sido eliminado."<<endl; break;
            case 'c': cout<<"Frente de la cola: "<<miCola.getFrente()<<endl; break;
            case 'd': cout<<"Final de la cola: "<<miCola.getFinal()<<endl; break;
            case 'e': cout<<miCola.Imprimir()<<endl; break;
            case 'f': break;
            default: cout<<"Opcion incorrecta. Vuelve a intentarlo..."<<endl;
        }
    }while(op != 'f');

    return 0;
}

void insertar(Cola& miCola){
    char e;

    cout<<endl<<"Teclea un numero (0 - 9): ";
    cin>>e;

    if(!validacionASCII(e)){
        cout<<e<<" no es numero, no se puede insertar..."<<endl;
    }else{
        miCola.encolar(e - '0');
    }
}

bool validacionASCII(char& e){
    return int(e) >= 48 and int(e) <= 57;
}

void gotoxy(int x, int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon,dwPos);
}
