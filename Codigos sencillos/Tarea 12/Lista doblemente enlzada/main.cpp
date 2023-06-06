#include <iostream>
#include "Lista.h"

using namespace std;

string imprimirLista(Lista<int>&);

int main(){
    Lista<int> miLista;

    for(int i(10); i > 0; i--)
        miLista.insertar(miLista.getUltimo(), i);

    cout<<"Lista: "<<imprimirLista(miLista)<<endl;

    cout<<endl<<"Borrando el primer nodo de la lista..."<<endl;
    miLista.eliminar(miLista.getPrimero());
    cout<<"Lista: "<<imprimirLista(miLista)<<endl;

    cout<<endl<<"Borrando el ultimo nodo de la lista..."<<endl;
    miLista.eliminar(miLista.getUltimo());
    cout<<"Lista: "<<imprimirLista(miLista)<<endl;

    miLista.ordenarASC();

    cout<<endl<<"Eliminando nodo de mayor valor..."<<endl;
    miLista.eliminar(miLista.getUltimo());
    cout<<"Lista: "<<imprimirLista(miLista)<<endl;

    return 0;
}

string imprimirLista(Lista<int>& miLista){
    string resultado;
    Lista<int>::Posicion pos(miLista.getPrimero());

    while(pos){
        resultado +=  to_string(pos->getDato()) + " <-> ";
        pos = pos->getSiguiente();
    }

    return resultado;
}
