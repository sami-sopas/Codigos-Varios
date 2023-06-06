#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Nombre.h"
#include "Contacto.h"
#include "Lista.h"

using namespace std;

Contacto generarContacto();
string generarID();
Lista<Contacto>::Posicion buscar();
string imprimir();

Lista<Contacto> miLista;

int main(){
    char op;
    Lista<Contacto>::Posicion pos;

    do{
        cout<<endl<<"-------------------------"<<endl;
        cout<<"Elije proceso."<<endl<<endl<<"a. Insertar."<<endl<<"b. Buscar."<<endl<<"c. Eliminar."<<endl<<"d. Imprimir."<<endl<<"e. Salir.";
        cout<<endl<<"-------------------------"<<endl;
        fflush(stdin); cin>>op;

        switch(op){
            case 'a': miLista.insertar(miLista.getUltimo(), generarContacto()); break;
            case 'b':
                pos = buscar();

                cout<<endl<<"Elemento ";
                if(pos == nullptr){
                    cout<<"no encontrado."<<endl;
                }else{
                    cout<<"localizado en la posicion "<<pos<<"."<<endl<<"Imprimiendo.."<<endl<<pos->getDato().toString()<<endl;
                }
            break;
            case 'c': miLista.eliminar(buscar()); break;
            case 'd': cout<<"CONTACTOS"<<endl<<imprimir()<<endl; break;
            case 'e': break;
            default: cout<<"Opcion incorrecta. Vuelve a intentarlo..."<<endl;
        }

    }while(op != 'e');

    return 0;
}

Contacto generarContacto(){
    Nombre miNombre;
    Contacto miContacto;
    string auxString;

    cout<<endl<<"Teclea apellido(s): ";
    fflush(stdin); getline(cin, auxString);
    miNombre.setUltimo(auxString);

    cout<<"Teclea nombre(s): ";
    fflush(stdin); getline(cin, auxString);
    miNombre.setPrimero(auxString);

    miContacto.setMiNombre(miNombre);

    cout<<"Teclea edad: ";
    fflush(stdin); cin>>auxString;
    miContacto.setEdad(stoi(auxString));

    miContacto.setId(generarID());

    cout<<"Teclea telefono: ";
    fflush(stdin); cin>>auxString;
    miContacto.setTelefono(auxString);

    return miContacto;
}

string generarID(){
    srand((unsigned)time(0));

    return to_string(rand() % 300);
}

Lista<Contacto>::Posicion buscar(){
   return miLista.buscar(generarContacto());
}

string imprimir(){
    string resultado;
    Lista<Contacto>::Posicion aux(miLista.getPrimero());

    while(aux != nullptr){
        resultado += aux->getDato().toString() + "\n";
        aux = aux->getSiguiente();
    }

    return resultado;
}
