#include "Cola.h"

using namespace std;

///Nodo

Cola::Nodo::Nodo(const Pasajero& p){
    datoPtr = new Pasajero(p);
    siguiente = nullptr;

    if(datoPtr == nullptr){
        cout<<"No es posible crear el nodo."<<endl;
        exit(1);
    }
}

Cola::Nodo::~Nodo(){
    delete datoPtr;
}

void Cola::Nodo::setSiguiente(Nodo* p){
    siguiente = p;
}

void Cola::Nodo::setDatoPtr(Pasajero* p){
    datoPtr = p;
}

void Cola::Nodo::setDato(const Pasajero& e){
    if(datoPtr == nullptr){
        cout<<"El dato no existe."<<endl;
        exit(1);
    }

    *datoPtr = e;
}

typename Cola::Nodo* Cola::Nodo::getSiguiente() const{
    return siguiente;
}

Pasajero* Cola::Nodo::getDatoPtr() const{
    return datoPtr;
}

Pasajero Cola::Nodo::getDato() const{
    if(datoPtr == nullptr){
        cout<<"El dato no existe."<<endl;
        exit(1);
    }

    return *datoPtr;
}

///Cola

Cola::Cola(){
    posFrente = nullptr;
    posFinal = nullptr;
}

bool Cola::vacia(Nodo* p) const{
    return p == nullptr;
}

void Cola::encolar(const Pasajero& e){
    Nodo* aux(new Nodo(e));

    if(aux == nullptr){
        cout<<"No hay memoria disponible para encolar mas elementos."<<endl;
        exit(1);
    }

    if(vacia(posFrente)){
        posFrente = aux;
    }else{
        posFinal->setSiguiente(aux);
    }

    posFinal = aux;

}

Pasajero Cola::desencolar(){
    if(vacia(posFrente)){
        cout<<""<<endl;
        exit(1);
    }

    Nodo* aux(posFrente);
    Pasajero resultado(aux->getDato());

    if(posFrente == posFinal){
        posFrente = nullptr;
        posFinal = nullptr;
    }else{
        posFrente = posFrente->getSiguiente();
    }

    delete aux;

    return resultado;
}

Pasajero Cola::getFrente() const{
    if(vacia(posFrente)){
        cout<<"El dato no existe."<<endl;
        exit(1);
    }

    return posFrente->getDato();
}

typename Cola::Nodo* Cola::getFrentePos() const{
    return posFrente;
}

Pasajero Cola::getFinal() const{
    if(vacia(posFinal)){
        cout<<"El dato no existe."<<endl;
        exit(1);
    }

    return posFinal->getDato();
}

string Cola::toString() const{
    Nodo* aux(posFrente);
    string resultado;

    while(aux != nullptr){
        resultado += aux->getDato().toString() + "\n\n";
        aux = aux->getSiguiente();
    }

    return resultado;
}
