#include <iostream>
#include "Lista.h"

using namespace std;

int pedirNumero();
void busqueda(Lista<int>&);
void eliminar(Lista<int>&);
void modificar(Lista<int>&);
bool validacionASCII(char&);

int main(){
    Lista<int> miLista;
    char op;

    do{
        cout<<endl<<"-----------------"<<endl;
        cout<<"Elija una opcion."<<endl<<endl<<"a. Insertar al principio."<<endl<<"b. Insertar al final."<<endl<<"c. Buscar por posicion."<<endl<<"d. Modificar."<<endl<<"e. Remover"<<endl<<"f. Imprimir"<<endl<<"g. Salir";
        cout<<endl<<"-----------------"<<endl;
        cin>>op;

        switch(op){
            case 'a': miLista.insertar(miLista.getPrimero(), pedirNumero()); break;
            case 'b': miLista.insertar(miLista.getUltimo(), pedirNumero()); break;
            case 'c': busqueda(miLista); break;
            case 'd': modificar(miLista); break;
            case 'e': eliminar(miLista); break;
            case 'f': cout<<miLista.toString()<<endl; break;
            case 'g': break;
            default: cout<<"Opcion incorrecta. Vuelve a intentarlo..."<<endl;
        }
    }while(op != 'g');

    return 0;
}

int pedirNumero(){
    char num;

    cout<<endl<<"Teclea numero: ";
    cin>>num;

    if(!validacionASCII(num)){
        cout<<num<<" no es un elemento valido para ser insertado."<<endl;
        exit(1);
    }

    return num - '0';
}

void busqueda(Lista<int>& miLista){
    Lista<int>::Posicion pos;

    pos = miLista.buscar(pedirNumero());

    if(pos == nullptr){
        cout<<"Este elemento no existe en la lista."<<endl;
    }else{
        cout<<"Buscando usando la posicion: "<<pos<<endl;
        cout<<"Elemento encontrado: "<<miLista.recuperar(pos)<<endl;///Aquí se hace la búsqueda por posición
    }
}

void eliminar(Lista<int>& miLista){
    Lista<int>::Posicion pos;

    pos = miLista.buscar(pedirNumero());

    if(pos == nullptr){
        cout<<"El elemento no ha sido encontrado."<<endl;
    }else{
        miLista.eliminar(pos);
    }
}

void modificar(Lista<int>& miLista){
    eliminar(miLista);

    cout<<"MODIFICANDO..."<<endl;
    miLista.insertar(miLista.getUltimo(), pedirNumero());
}

bool validacionASCII(char& e){
    return int(e) >= 48 and int(e) <= 57;
}
