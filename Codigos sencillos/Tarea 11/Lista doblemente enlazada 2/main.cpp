#include <iostream>
#include "Lista.h"

using namespace std;

string imprimirLista(Lista<int>&);

int main(){
    Lista<int> miLista;
    int valor;
    Lista<int>::Posicion pos;
    int opc,op;
    int numero;

    do{
            system("cls");
        cout<<"Lista doblemente enlazada"<<endl;
        cout<<"1)Insertar numero"<<endl;
        cout<<"2)Buscar numero"<<endl;
        cout<<"3)Ordenar de forma ascendente"<<endl;
        cout<<"4)Ordenar de forma descendente"<<endl;
        cout<<"5)Remover ultimo nodo"<<endl;
        cout<<"6)Imprimir"<<endl;
        cin>>opc;

        switch(opc){
            case 1:{
                cout<<"Escriba el numero a insertar"<<endl;
                cin>>numero;

                miLista.insertar(miLista.getUltimo(),numero);
                break;
            }

            case 2:{
                cout<<endl<<"Numero a buscar: ";
                cin>>valor;

                pos = miLista.buscar(valor);

                if(pos == nullptr){
                    cout<<endl<<"Elemento no encontrado.";
                }else{
                   cout<<"Elemento encontrado en la posicion: "<<pos<<endl;
                  }
                break;
            }

            case 3:{
                cout << "Imprimiendo de manera ascendente" << endl;
                miLista.ordenarASC();
                cout << imprimirLista(miLista);

                break;
            }

            case 4:{
                cout << "Imprimiendo de manera descendente" << endl;
                miLista.ordenarDEC();
                cout << imprimirLista(miLista);
                break;
            }

            case 5:{
                cout << "Eliminando ultimo nodo" << endl;
                miLista.eliminar(miLista.getUltimo());
                cout << imprimirLista(miLista);
                break;
            }

            case 6:{
                cout << endl;
                cout << imprimirLista(miLista)<<endl;
                cout << "Primero: " << miLista.recuperar(miLista.getPrimero())<<endl;
                cout << "Ultimo: " << miLista.recuperar(miLista.getUltimo())<<endl;
                break;
            }
        }
        cout<<"\nQue desea hacer?"<<endl;
       cout<<"1)Regresar al menu\n2)Salir"<<endl;
       cin>>op;
    }while(opc!=2);

    /*miLista.insertar(miLista.getUltimo(), 20);
    miLista.insertar(miLista.getUltimo(), 10);
    miLista.insertar(miLista.getUltimo(), 40);
    miLista.insertar(miLista.getUltimo(), 30);

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

    cout<<endl<<"Teclea un numero a buscar: ";
    cin>>valor;

    pos = miLista.buscar(valor);

    if(pos == nullptr){
        cout<<endl<<"Elemento no encontrado.";
    }else{
        cout<<"Elemento encontrado en la posicion: "<<pos<<endl;
    }

    cout<<endl<<"Ordenando de forma ascendente..."<<endl;
    miLista.ordenarASC();
    cout<<imprimirLista(miLista)<<endl;

    cout<<endl<<"Ordenando de forma descendente..."<<endl;
    miLista.ordenarDEC();
    cout<<imprimirLista(miLista)<<endl;

    cout<<endl<<"Removiendo ultimo nodo..."<<endl;
    miLista.eliminar(miLista.getUltimo());
    cout<<imprimirLista(miLista)<<endl;*/


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
