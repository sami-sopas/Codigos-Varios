#include <iostream>
#include"Lista.h"

using namespace std;

    Lista<int> miLista;
    int opc;
    int auxiliar;

int main()
{
    do{
        cout <<"1)Insertar"<<endl;
        cout <<"2)Eliminar primera pos"<<endl;
        cout<<"3)Eliminar ultima pos"<<endl;
        cout<<"4)Recorrido"<<endl;
        cin>>opc;

         switch(opc){
        case 1:{
        cout<<"Ingrese numero"<<endl;
        cin>>auxiliar;

        miLista.insertar(miLista.getUltimo(),auxiliar);
        cout<<miLista.toString()<<endl;
        break;
        }

        case 2:{
            cout<<"Eliminar primera posicion"<<endl;
            miLista.eliminar(miLista.getPrimero());
            cout<<miLista.toString()<<endl;
        break;
        }
        case 3:{
            cout<<"Eliminar ultima posicion"<<endl;
            miLista.eliminar(miLista.getUltimo());
            cout<<miLista.toString()<<endl;
        break;
        }

        case 4:{
            cout<<"Recorrido "; cout<<miLista.getSize()<<endl;
            break;
        }
    }

    }while(opc!=5);


    cout << "Hello world!" << endl;
    return 0;
}

