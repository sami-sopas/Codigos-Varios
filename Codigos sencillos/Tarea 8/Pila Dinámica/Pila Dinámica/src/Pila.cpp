#include "Pila.h"

using namespace std;

///Nodo

Pila::Nodo::Nodo(): siguiente(nullptr){}

Pila::Nodo::Nodo(const int& e): dato(e), siguiente(nullptr){}

void Pila::Nodo::setSiguiente(Nodo* p){
    siguiente = p;
}

void Pila::Nodo::setDato(const int& e){
    dato = e;
}

typename Pila::Nodo* Pila::Nodo::getSiguiente() const{
    return siguiente;
}

int Pila::Nodo::getDato() const{
    return dato;
}

///Pila

Pila::Pila(): ancla(nullptr){}

bool Pila::vacia() const{
    return ancla == nullptr;
}

void Pila::push(const int& e){
    Nodo* aux(new Nodo(e));

    if(aux == nullptr){
        cout<<"No es posible insertar mas elementos."<<endl;
        exit(1);
    }

    aux->setSiguiente(ancla);
    ancla = aux;
}

int Pila::pop(){
    if(vacia()){
        cout<<"La pila esta vacia."<<endl;
        exit(1);
    }

    int resultado(ancla->getDato());
    Nodo* aux(ancla);

    ancla = ancla->getSiguiente();

    delete aux;

    return resultado;
}

int Pila::getTope() const{
    if(vacia()){
        cout<<"La pila esta vacia."<<endl;
        exit(1);
    }

    return ancla->getDato();
}

std::string Pila::imprimir() const{
    string resuldato;
    Nodo *aux(ancla);

    while(aux != nullptr){
        resuldato += to_string(aux->getDato()) + "\n";
        aux = aux->getSiguiente();
    }

    return resuldato;
}
