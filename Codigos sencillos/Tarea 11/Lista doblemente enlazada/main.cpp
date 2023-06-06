#include <iostream>
#include <string>
#include "Lista.h"

using namespace std;

string imprimirLista(Lista<int>&);

int main(){
    Lista<int> miLista;

    miLista.insertar(miLista.getUltimo(), 10);
    miLista.insertar(miLista.getUltimo(), 20);
    miLista.insertar(miLista.getUltimo(), 30);
    miLista.insertar(miLista.getUltimo(), 40);

    cout<<"Lista"<<endl<<imprimirLista(miLista)<<endl;
    cout<<"Primero: "<<miLista.recuperar(miLista.getPrimero())<<endl;
    cout<<"Ultimo: "<<miLista.recuperar(miLista.getUltimo())<<endl;

    miLista.insertar(miLista.getUltimo(), 80);
    miLista.insertar(miLista.getUltimo(), 85);

    cout<<endl<<"Lista"<<endl<<imprimirLista(miLista)<<endl;
    cout<<"Primero: "<<miLista.recuperar(miLista.getPrimero())<<endl;
    cout<<"Ultimo: "<<miLista.recuperar(miLista.getUltimo())<<endl;

    miLista.eliminar(miLista.buscar(40));

    cout<<endl<<"Eliminando 40..."<<endl;
    cout<<"Lista"<<endl<<imprimirLista(miLista)<<endl;

    return 0;
}

string imprimirLista(Lista<int>& miLista){
    string resultado;
    Lista<int>::Posicion pos(miLista.getPrimero());

    while(pos){
        resultado +=  to_string(pos->getDato()) + " -> ";
        pos = pos->getSiguiente();
    }

    return resultado;
}
