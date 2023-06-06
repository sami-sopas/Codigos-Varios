#include "Cola.h"

using namespace std;

///Nodo

Cola::Nodo::Nodo(const int& e){
    dato = e;
    siguiente = nullptr;
}

void Cola::Nodo::setSiguiente(Nodo* p){
    siguiente = p;
}

void Cola::Nodo::setDato(const int& e){
    dato = e;
}

typename Cola::Nodo* Cola::Nodo::getSiguiente() const{
    return siguiente;
}

int Cola::Nodo::getDato() const{
    return dato;
}

///Cola

Cola::Cola(): posFrente(nullptr), posFinal(nullptr){}

bool Cola::vacia(Nodo* p) const{
    return p == nullptr;
}

void Cola::encolar(const int& e){
    Nodo* aux(new Nodo(e));

    aux->setSiguiente(nullptr);

    if(vacia(posFrente)){
        posFrente = aux;
    }else{
    posFinal->setSiguiente(aux);
    }

    posFinal = aux;
}

int Cola::desencolar(){
    Nodo *aux(posFrente);

    int resultado(aux->getDato());

    if(posFrente == posFinal){
        posFrente = nullptr;
        posFinal = nullptr;
    }else{
        posFrente = posFrente->getSiguiente();
    }

    delete aux;

    return resultado;
}

int Cola::getFrente(){
    if(vacia(posFrente)){
        cout<<"Dato no disponible."<<endl;
        exit(1);
    }

    return posFrente->getDato();
}

int Cola::getFinal(){
    if(vacia(posFinal)){
        cout<<"Dato no disponible."<<endl;
        exit(1);
    }

    return posFinal->getDato();
}

string Cola::Imprimir() const{
    Nodo* aux(posFrente);
    string resultado;

    while(aux != nullptr){
        resultado += to_string(aux->getDato()) + " ";
        aux = aux->getSiguiente();
    }

    return resultado;
}
