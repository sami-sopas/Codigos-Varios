#include "Pila.h"

using namespace std;

///Nodo

Pila::Nodo::Nodo(const Pasajero& p){
    datoPtr = new Pasajero(p);
    siguiente = nullptr;

    if(datoPtr == nullptr){
        cout<<"No es posible crear el nodo."<<endl;
        exit(1);
    }
}

Pila::Nodo::~Nodo(){
    delete datoPtr;
}

void Pila::Nodo::setSiguiente(Nodo* p){
    siguiente = p;
}

void Pila::Nodo::setDatoPtr(Pasajero* p){
    datoPtr = p;
}

void Pila::Nodo::setDato(const Pasajero& e){
    if(datoPtr == nullptr){
        cout<<"El dato no existe."<<endl;
        exit(1);
    }

    *datoPtr = e;
}

typename Pila::Nodo* Pila::Nodo::getSiguiente() const{
    return siguiente;
}

Pasajero* Pila::Nodo::getDatoPtr() const{
    return datoPtr;
}

Pasajero Pila::Nodo::getDato() const{
    if(datoPtr == nullptr){
        cout<<"El dato no existe."<<endl;
        exit(1);
    }

    return *datoPtr;
}

///Pila

Pila::Pila(): ancla(nullptr){}

bool Pila::vacia() const{
    return ancla == nullptr;
}

void Pila::push(const Pasajero& e){
    Nodo* aux(new Nodo(e));

    if(aux == nullptr){
        cout<<"No hay memoria disponible para apilar mas elementos."<<endl;
        exit(1);
    }

    aux->setSiguiente(ancla);
    ancla = aux;
}

Pasajero Pila::pop(){
    if(vacia()){
        cout<<"No hay elementos apilados."<<endl;
        exit(1);
    }

    Pasajero resultado(ancla->getDato());
    Nodo* aux(ancla);

    ancla = ancla->getSiguiente();

    delete aux;

    return resultado;
}

Pasajero Pila::getTope() const{
    if(vacia()){
        cout<<"No hay elementos apilados."<<endl;
        exit(1);
    }

    return ancla->getDato();
}

string Pila::toString() const{
    string resultado;
    Nodo* aux(ancla);

    while(aux != nullptr){
        resultado += aux->getDato().toString() + "\n\n";
        aux = aux->getSiguiente();
    }

    return resultado;
}
