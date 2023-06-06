#include <iostream>
#include "Arbol.h"
#include "Contacto.h"

using namespace std;

void insertarContacto(Arbol<Contacto>&);
bool validacionASCII(char&);
void buscarContacto(Arbol<Contacto>&);
void modificarContacto(Arbol<Contacto>&);
void mostrarTodoElArbol(Arbol<Contacto>&);
void mostrarTodoElArbol(Arbol<Contacto>::Posicion, int);
void eliminarContacto(Arbol<Contacto>&);

int main(){
    Arbol<Contacto> miArbol;
    char op;

    do{
        cout<<endl<<"--------------------"<<endl;
        cout<<"Elije opcion."<<endl<<endl<<"a. Insertar."<<endl<<"b. PreOrder."<<endl<<"c. InOrder."<<endl<<"d. PosOrder."<<endl<<"e. Buscar."<<endl<<"f. Modificar."<<endl<<"g. Eliminar"<<endl<<"h. Mostrar arbol."<<endl<<"i. Salir.";
        cout<<endl<<"--------------------"<<endl;
        fflush(stdin); cin>>op;

        switch(op){
            case 'a': insertarContacto(miArbol); break;
            case 'b': miArbol.recorridoPreOrder(); break;
            case 'c': miArbol.recorridoInOrder(); break;
            case 'd': miArbol.recorridoPosOrder(); break;
            case 'e': buscarContacto(miArbol); break;
            case 'f': modificarContacto(miArbol); break;
            case 'g': eliminarContacto(miArbol); break;
            case 'h': mostrarTodoElArbol(miArbol); break;
            case 'i': break;
            default: cout<<"Opcion incorrecta. Vuelve a intentarlo..."<<endl;
        }

    }while(op != 'i');

    return 0;
}

void insertarContacto(Arbol<Contacto>& miArbol){
    char auxId;

    cout<<"Teclea ID: ";
    cin>>auxId;

    if(validacionASCII(auxId)){
        Contacto auxContacto;
        string auxString;

        auxContacto.setId(auxId - '0');

        cout<<"Teclea nombre: ";
        fflush(stdin); getline(cin, auxString);
        auxContacto.setNombre(auxString);

        cout<<"Teclea direccion: ";
        fflush(stdin); getline(cin, auxString);
        auxContacto.setDireccion(auxString);

        cout<<"Teclea email: ";
        fflush(stdin); getline(cin, auxString);
        auxContacto.setEmail(auxString);

        miArbol.insertar(auxContacto);
    }else{
        cout<<endl<<"El ID ingresado no es valido para ser insertado."<<endl;
    }
}

bool validacionASCII(char& e){
    return int(e) >= 48 and int(e) <= 57;
}

void buscarContacto(Arbol<Contacto>& miArbol){
    int auxId;
    Contacto auxContacto;
    Arbol<Contacto>::Posicion pos;

    cout<<"Teclea ID: ";
    cin>>auxId;
    auxContacto.setId(auxId);

    pos = miArbol.localiza(auxContacto);

    if(pos == nullptr){
        cout<<"El contacto no ha sido encontrado."<<endl;
    }else{
        cout<<"Contacto encontrado en la posicion "<<pos<<"."<<endl<<pos->getDato().toString()<<endl;
    }
}

void modificarContacto(Arbol<Contacto>& miArbol){
    int auxId;
    Contacto auxContacto;
    Arbol<Contacto>::Posicion pos;

    cout<<"Teclea ID: ";
    cin>>auxId;
    auxContacto.setId(auxId);

    pos = miArbol.localiza(auxContacto);

    if(pos == nullptr){
        cout<<"El contacto no ha sido encontrado."<<endl;
    }else{
        string auxString;

        cout<<endl<<"Contacto encontrado en la posicion "<<pos<<"."<<endl<<"Modificando datos..."<<endl;
        cout<<"Teclea nuevo nombre: ";
        fflush(stdin); getline(cin, auxString);
        auxContacto.setNombre(auxString);

        cout<<"Teclea nueva direccion: ";
        fflush(stdin); getline(cin, auxString);
        auxContacto.setDireccion(auxString);

        cout<<"Teclea nuevo email: ";
        fflush(stdin); getline(cin, auxString);
        auxContacto.setEmail(auxString);

        pos->setDatoPtr(&auxContacto);

        cout<<endl<<"Contacto modificado: "<<pos->getDato().toString()<<endl;
    }
}

void mostrarTodoElArbol(Arbol<Contacto>& miArbol){
    mostrarTodoElArbol(miArbol.getRaiz(), 0);
}

void mostrarTodoElArbol(Arbol<Contacto>::Posicion r, int n){
    if(r == nullptr)
        return;

    mostrarTodoElArbol(r->getDerecha(), n + 1);

    for(int i(0); i < n; i++)
        cout<<" ";

    cout<<r->getDato().getId()<<endl;

    mostrarTodoElArbol(r->getIzquierda(), n + 1);
}

void eliminarContacto(Arbol<Contacto>& miArbol){
    int auxId;
    Contacto auxContacto;
    Arbol<Contacto>::Posicion pos;

    cout<<"Teclea ID: ";
    cin>>auxId;
    auxContacto.setId(auxId);

    pos = miArbol.localiza(auxContacto);

    if(pos == nullptr){
        cout<<"El contacto no ha sido encontrado."<<endl;
    }else{
        miArbol.eliminar(pos);
    }
}
