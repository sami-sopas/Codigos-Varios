#include <iostream>
#include "Pila.h"

using namespace std;

void insertar(Pila&);
bool validacionASCII(char&);

int main(){
    char op;
    Pila miPila;

    do{
        cout<<endl<<"-----------------"<<endl;
        cout<<"Elija una opcion."<<endl<<endl<<"a. Push."<<endl<<"b. Pop"<<endl<<"c. Tope."<<endl<<"d. Imprimir"<<endl<<"e. Salir.";
        cout<<endl<<"-----------------"<<endl;
        cin>>op;

        switch(op){
            case 'a': insertar(miPila); break;
            case 'b': cout<<miPila.pop()<<" ha sido eliminado."<<endl; break;
            case 'c': cout<<"Tope de la Pila: "<<miPila.getTope()<<endl; break;
            case 'd': cout<<miPila.imprimir()<<endl; break;
            case 'e': break;
            default: cout<<"Opcion incorrecta. Vuelve a intentarlo..."<<endl;
        }
    }while(op != 'e');

    return 0;
}

void insertar(Pila& miPila){
    char e;

    cout<<endl<<"Teclea un numero (0 - 9): ";
    cin>>e;

    if(!validacionASCII(e)){
        cout<<e<<" no es numero, no se puede insertar..."<<endl;
    }else{
        miPila.push(e - '0');
    }
}

bool validacionASCII(char& e){
    return int(e) >= 48 and int(e) <= 57;
}
