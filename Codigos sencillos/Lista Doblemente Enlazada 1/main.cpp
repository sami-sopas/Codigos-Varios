#include <iostream>
#include"Lista.h"

using namespace std;

string imprimirLista(Lista<int>&); //El toString

int main()
{
    Lista<int> lista;

    lista.insertar(lista.getUltimo(), 10);
    lista.insertar(lista.getUltimo(), 20);
    lista.insertar(lista.getUltimo(), 30);
    lista.insertar(lista.getUltimo(), 40);
    cout<<"---Lista---"<<endl<<endl;

    cout<<imprimirLista(lista)<<endl;
    cout<<"Primero: "<<lista.recuperar(lista.getPrimero())<<endl;
    cout<<"Ultimo: "<<lista.recuperar(lista.getUltimo())<<endl;

    lista.insertar(lista.getUltimo(), 80);
    lista.insertar(lista.getUltimo(), 85);

    cout<<endl<<"Lista"<<endl<<imprimirLista(lista)<<endl;
    cout<<"Primero: "<<lista.recuperar(lista.getPrimero())<<endl;
    cout<<"Ultimo: "<<lista.recuperar(lista.getUltimo())<<endl;

    lista.eliminar(lista.buscar(40));

    cout<<endl<<"Eliminando 40..."<<endl;
    cout<<"Lista"<<endl<<imprimirLista(lista)<<endl;
    cout<<"Primero: "<<lista.recuperar(lista.getPrimero())<<endl;
    cout<<"Ultimo: "<<lista.recuperar(lista.getUltimo())<<endl;

    return 0;
}

string imprimirLista(Lista<int>& lista){
    string resultado;
    Lista<int>::Posicion pos(lista.getPrimero());

    while(pos){
        resultado +=  to_string(pos->getDato()) + " -> ";
        pos = pos->getSiguiente();
    }

    return resultado;
}
