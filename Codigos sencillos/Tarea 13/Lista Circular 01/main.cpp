#include <iostream>
#include "Lista.h"

using namespace std;

bool validacionASCII(char&);
void insertar(Lista<int>&);
void eliminar(Lista<int>&);

int main(){
    Lista<int> miLista;

    miLista.insertar(miLista.getPrimero(), 1);
    miLista.insertar(miLista.getPrimero(), 2);
    miLista.insertar(miLista.getPrimero(), 3);

    cout<<"Elementos insertados: "<<miLista.toString()<<endl;

    miLista.insertar(miLista.getUltimo(), 4);
    miLista.insertar(miLista.getUltimo(), 5);
    miLista.insertar(miLista.getUltimo(), 6);

    cout<<"Elementos insertados: "<<miLista.toString()<<endl;
    cout<<"Recorrido: "<<miLista.getSize()<<endl;

    cout<<endl<<"Removiendo la primera posicion..."<<endl;
    miLista.eliminar(miLista.getPrimero());
    cout<<miLista.toString()<<endl;

    char op;

    do{
        cout<<endl<<"-----------------"<<endl;
        cout<<"Elija una opcion."<<endl<<endl<<"a. Insertar."<<endl<<"b. Eliminar."<<endl<<"c. Imprimir."<<endl<<"d. Salir.";
        cout<<endl<<"-----------------"<<endl;
        cin>>op;

        switch(op){
            case 'a': insertar(miLista); break;
            case 'b': eliminar(miLista); break;
            case 'c': cout<<miLista.toString()<<endl; break;
            case 'd': break;
            default: cout<<"Opcion incorrecta. Vuelve a intentarlo."<<endl;
        }
    }while(op != 'd');

    return 0;
}

bool validacionASCII(char& e){
    return int(e) >= 48 and int(e) <= 57;
}

void insertar(Lista<int>& miLista){
    char num;
    cout<<endl<<"Teclea numero: ";
    cin>>num;

    if(!validacionASCII(num)){
        cout<<"El numero no es valido para ser insertado."<<endl;
    }else{
        miLista.insertar(miLista.getUltimo(), num - '0');
    }
}

void eliminar(Lista<int>& miLista){
    int aux;
    Lista<int>::Posicion pos;

    cout<<endl<<"Teclea numero: ";
    cin>>aux;

    pos = miLista.buscar(aux);

    if(pos == nullptr){
        cout<<"El elemento no ha sido encontrado."<<endl;
    }else{
        miLista.eliminar(pos);
    }
}
