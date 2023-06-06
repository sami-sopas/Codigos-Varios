#include <iostream>
#include "Cancion.h"
#include "Lista.h"

using namespace std;

void generarCanciones(Lista<Cancion>&);
string imprimirLista(Lista<Cancion>&);
void nuevaCancion(Lista<Cancion>&);
void eliminarCancion(Lista<Cancion>&);
void editarCancion(Lista<Cancion>&);

int main(){
    Lista<Cancion> miLista;
    char op;

    generarCanciones(miLista);

    do{
        cout<<endl<<"CANCIONES."<<endl<<imprimirLista(miLista);
        cout<<endl<<"------------------------------"<<endl;
        cout<<"Elije opcion."<<endl<<endl<<"a. Insertar nueva cancion."<<endl<<"b. Eliminar cancion."<<endl<<"c. Ordenar ascendente."<<endl<<"d. Ordenar descendente."<<endl<<"e. Editar cancion."<<endl<<"f. Borrar primera cancion."<<endl<<"g. Borrar ultima cancion."<<endl<<"h. Salir.";
        cout<<endl<<"------------------------------"<<endl;
        fflush(stdin); cin>>op;

        switch(op){
            case 'a': nuevaCancion(miLista); break;
            case 'b': eliminarCancion(miLista); break;
            case 'c': miLista.ordenarASC(); break;
            case 'd': miLista.ordenarDEC(); break;
            case 'e': editarCancion(miLista); break;
            case 'f': miLista.eliminar(miLista.getPrimero()); break;
            case 'g': miLista.eliminar(miLista.getUltimo()); break;
            case 'h': break;
            default: cout<<"Opcion incorrecta. Vuelve a intentarlo..."<<endl;
        }
    }while(op != 'h');

    return 0;
}

void generarCanciones(Lista<Cancion>& miLista){
    Cancion aux;

    aux.setNombre("Energy Drink");
    aux.setArtista("Virtual Riot");
    aux.setAlbum("The Classics");
    aux.setGenero("Electro");
    aux.setId(118);
    miLista.insertar(miLista.getUltimo(), aux);

    aux.setNombre("Samsara");
    aux.setArtista("Tungevaag");
    aux.setAlbum("Samsara");
    aux.setGenero("Electro");
    aux.setId(121);
    miLista.insertar(miLista.getUltimo(), aux);

    aux.setNombre("Space Invaders");
    aux.setArtista("Terminite");
    aux.setAlbum("Space Invaders");
    aux.setGenero("Electro");
    aux.setId(135);
    miLista.insertar(miLista.getUltimo(), aux);

    aux.setNombre("Shine");
    aux.setArtista("Spektrem");
    aux.setAlbum("Enter the Spektrem");
    aux.setGenero("Electro");
    aux.setId(818);
    miLista.insertar(miLista.getUltimo(), aux);

    aux.setNombre("Party Hard - Lockyn Remix");
    aux.setArtista("Sundivine");
    aux.setAlbum("Electro House");
    aux.setGenero("Electro");
    aux.setId(205);
    miLista.insertar(miLista.getUltimo(), aux);
}

string imprimirLista(Lista<Cancion>& miLista){
    string resultado;
    Lista<Cancion>::Posicion pos(miLista.getPrimero());

    while(pos){
        resultado +=  pos->getDato().toString() + "\n";
        pos = pos->getSiguiente();
    }

    return resultado;
}

void nuevaCancion(Lista<Cancion>& miLista){
    Cancion aux;
    string auxString;
    int auxInt;

    cout<<endl<<"Insertando nueva cancion..."<<endl;

    cout<<"Teclea nombre: ";
    fflush(stdin); getline(cin, auxString);
    aux.setNombre(auxString);

    cout<<"Teclea artista: ";
    fflush(stdin); getline(cin, auxString);
    aux.setArtista(auxString);

    cout<<"Teclea album: ";
    fflush(stdin); getline(cin, auxString);
    aux.setAlbum(auxString);

    cout<<"Teclea genero: ";
    fflush(stdin); getline(cin, auxString);
    aux.setGenero(auxString);

    cout<<"Teclea id: ";
    cin>>auxInt;
    aux.setId(auxInt);

    miLista.insertar(miLista.getUltimo(), aux);
}

void eliminarCancion(Lista<Cancion>& miLista){
    Cancion aux;
    string auxString;
    Lista<Cancion>::Posicion pos;

    cout<<endl<<"Buscando cancion cancion..."<<endl;

    cout<<"Teclea nombre: ";
    fflush(stdin); getline(cin, auxString);
    aux.setNombre(auxString);

    cout<<"Teclea artista: ";
    fflush(stdin); getline(cin, auxString);
    aux.setArtista(auxString);

    pos = miLista.buscar(aux);

    if(pos == nullptr){
        cout<<"La cancion no fue encontrada. No es posible eliminar."<<endl;
    }else{
        miLista.eliminar(pos);
        cout<<"Cancion eliminada."<<endl;
    }
}

void editarCancion(Lista<Cancion>& miLista){
    Cancion aux;
    string auxString;
    int auxInt;
    Lista<Cancion>::Posicion pos;

    cout<<endl<<"Buscando cancion cancion..."<<endl;

    cout<<"Teclea nombre: ";
    fflush(stdin); getline(cin, auxString);
    aux.setNombre(auxString);

    cout<<"Teclea artista: ";
    fflush(stdin); getline(cin, auxString);
    aux.setArtista(auxString);

    pos = miLista.buscar(aux);

    if(pos == nullptr){
        cout<<"La cancion no fue encontrada. No es posible eliminar."<<endl;
    }else{
        cout<<endl<<"Editando datos de la cancion..."<<endl;
        cout<<"Teclea nuevo nombre: ";
        fflush(stdin); getline(cin, auxString);
        aux.setNombre(auxString);

        cout<<"Teclea nuevo artista: ";
        fflush(stdin); getline(cin, auxString);
        aux.setArtista(auxString);

        cout<<"Teclea nuevo album: ";
        fflush(stdin); getline(cin, auxString);
        aux.setAlbum(auxString);

        cout<<"Teclea nuevo genero: ";
        fflush(stdin); getline(cin, auxString);
        aux.setGenero(auxString);

        cout<<"Teclea nuevo id: ";
        cin>>auxInt;
        aux.setId(auxInt);

        miLista.eliminar(pos);
        miLista.insertar(miLista.getUltimo(), aux);
    }
}
