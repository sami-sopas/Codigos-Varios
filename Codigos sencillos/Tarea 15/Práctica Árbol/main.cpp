#include <iostream>
#include "Arbol.h"
#include "Contacto.h"

using namespace std;

void insertarContacto(Arbol<Contacto>&);
bool validacionASCII(char&);
void buscarContacto(Arbol<Contacto>&);
void modificarContacto(Arbol<Contacto>&);
void eliminarContacto(Arbol<Contacto>&);
void limiteMaximo(Arbol<Contacto>&);
void limiteMinimo(Arbol<Contacto>&);

int main(){
    Arbol<Contacto> miArbol;
    char op;

    do{
        cout<<endl<<"--------------------"<<endl;
        cout<<"Elije opcion."<<endl<<endl<<"a. Insertar."<<endl<<"b. PreOrder."<<endl<<"c. InOrder."<<endl<<"d. PosOrder."<<endl<<"e. Buscar."<<endl<<"f. Modificar."<<endl<<"g. Eliminar"<<endl<<"h. Mostrar minimo."<<endl<<"i. Mostrar maximo."<<endl<<"j. Salir.";
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
            case 'h': limiteMaximo(miArbol); break;
            case 'i': limiteMinimo(miArbol); break;
            case 'j': break;
            default: cout<<"Opcion incorrecta. Vuelve a intentarlo..."<<endl;
        }

    }while(op != 'j');

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

void limiteMaximo(Arbol<Contacto>& miArbol){
    Arbol<Contacto>::Posicion pos;

    pos = miArbol.getMasAlto();

    if(pos == nullptr){
        cout<<"No hay un nodo maximo aun..."<<endl;
    }else{
        Arbol<Contacto>::Posicion aux;

        cout<<"El nodo maximo esta en la posicion: "<<pos<<"."<<endl<<pos->getDato().toString()<<endl;
        aux = miArbol.getPadre(pos);

        if(aux == nullptr){
            cout<<"Este nodo no tiene antecesor..."<<endl;
        }else{
            cout<<"El antecesor de este nodo esta en la posicion: "<<aux<<endl<<aux->getDato().toString()<<endl;
        }
    }
}

void limiteMinimo(Arbol<Contacto>& miArbol){
    Arbol<Contacto>::Posicion pos;

    pos = miArbol.getMasBajo();

    if(pos == nullptr){
        cout<<"No hay un nodo maximo aun..."<<endl;
    }else{
        Arbol<Contacto>::Posicion aux;

        cout<<"El nodo minimo esta en la posicion: "<<pos<<"."<<endl<<pos->getDato().toString()<<endl;
        aux = miArbol.getPadre(pos);

        if(aux == nullptr){
            cout<<"Este nodo no tiene antecesor..."<<endl;
        }else{
            cout<<"El antecesor de este nodo esta en la posicion: "<<aux<<endl<<aux->getDato().toString()<<endl;
        }
    }
}
