#ifndef LISTA_H
#define LISTA_H

#include <iostream>

template <class T>
class Lista{
    private:
        class Nodo{
            private:
                Nodo* siguiente;
                T* datoPtr;
            public:
                Nodo(const T&);

                void setSiguiente(Nodo*);
                void setDatoPtr(T*);
                void setDato(const T&);

                Nodo* getSiguiente() const;
                T* getDatoPtr() const;
                T getDato() const;
        };

        Nodo* ancla;

        bool esPosicionValida(Nodo*) const;

        void borrarTODO();
    public:
        typedef Nodo* Posicion;

        Lista();
        ~Lista();

        bool vacia() const;

        void insertar(Nodo*, const T&);
        void eliminar(Nodo*);
        void anular();

        Nodo* buscar(const T&) const;

        Nodo* getPrimero() const;
        Nodo* getUltimo() const;
        Nodo* getAnteriorPos(Nodo*) const;
        Nodo* getSiguientePos(Nodo*) const;

        T recuperar(Nodo*) const;
};

using namespace std;

///Nodo

template <class T>
Lista<T>::Nodo::Nodo(const T& e){
    datoPtr = new T(e);
    siguiente = nullptr;

    if(datoPtr == nullptr){
        cout<<"No hay memoria suficiente para crear un nuevo nodo."<<endl;
        exit(1);
    }
}

template <class T>
void Lista<T>::Nodo::setSiguiente(Nodo* p){
    siguiente = p;
}

template <class T>
void Lista<T>::Nodo::setDatoPtr(T* p){
    datoPtr = p;
}

template <class T>
void Lista<T>::Nodo::setDato(const T& e){
    if(datoPtr == nullptr){
        cout<<"No hay memoria suficiente para guardar elemento. setDato"<<endl;
        exit(1);
    }

    *datoPtr = e;
}

template <class T>
typename Lista<T>::Nodo* Lista<T>::Nodo::getSiguiente() const{
    return siguiente;
}

template <class T>
T* Lista<T>::Nodo::getDatoPtr() const{
    return datoPtr;
}

template <class T>
T Lista<T>::Nodo::getDato() const{
    if(datoPtr == nullptr){
        cout<<"El dato no existe. getDato"<<endl;
        exit(1);
    }

    return *datoPtr;
}

///Lista
template <class T>
bool Lista<T>::esPosicionValida(Nodo* p) const{
    Nodo* aux(ancla);

    while(aux != nullptr){
        if(aux == p)
            return true;

        aux = aux->getSiguiente();
    }

    return false;
}

template <class T>
Lista<T>::Lista(): ancla(nullptr){}

template <class T>
Lista<T>::~Lista(){
    anular();
}

template <class T>
bool Lista<T>::vacia() const{
    return ancla == nullptr;
}

template <class T>
void Lista<T>::insertar(Nodo* p, const T& e){
    if(p != nullptr and !esPosicionValida(p)){
        cout<<"Posicion invalida para insertar."<<endl;
        exit(1);
    }

    Nodo* aux(new Nodo(e));

    if(aux == nullptr){
        cout<<"No hay memoria suficiente para insertar mas elementos."<<endl;
        exit(1);
    }

    if(p == ancla){
        aux->setSiguiente(ancla);
        ancla = aux;
    }else{
        aux->setSiguiente(p->getSiguiente());
        p->setSiguiente(aux);
    }
}

template <class T>
void Lista<T>::eliminar(Nodo* p){
    if(vacia()){
        cout<<"La lista esta vacia."<<endl;
        exit(1);
    }else if(!esPosicionValida(p)){
        cout<<"Posicion invalida para eliminar."<<endl;
        exit(1);
    }

    if(p == ancla){
        ancla = ancla->getSiguiente();
    }else{
        getAnteriorPos(p)->setSiguiente(p->getSiguiente());
    }

    delete p;
}

template <class T>
void Lista<T>::anular(){
    Nodo* aux;

    while(ancla != nullptr){
        aux = ancla;
        ancla = ancla->getSiguiente();
        delete aux;
    }
}

template <class T>
typename Lista<T>::Nodo* Lista<T>::buscar(const T& e) const{
    Nodo* aux(ancla);

    while(aux != nullptr and aux->getDato() != e){
        aux = aux->getSiguiente();
    }

    return aux;
}

template <class T>
typename Lista<T>::Nodo* Lista<T>::getPrimero() const{
    return ancla;
}

template <class T>
typename Lista<T>::Nodo* Lista<T>::getUltimo() const{
    if(vacia())
        return nullptr;

    Nodo* aux(ancla);

    while(aux->getSiguiente() != nullptr){
        aux = aux->getSiguiente();
    }

    return aux;
}

template <class T>
typename Lista<T>::Nodo* Lista<T>::getAnteriorPos(Nodo* p) const{
    if(p == ancla)
        return nullptr;

    Nodo* aux(ancla);

    while(aux != nullptr and aux->getSiguiente() != p){
        aux = aux->getSiguiente();
    }

    return aux;
}

template <class T>
typename Lista<T>::Nodo* Lista<T>::getSiguientePos(Nodo* p) const{
    if(!esPosicionValida(p))
        return nullptr;

    return p->getSiguiente();
}

template <class T>
T Lista<T>::recuperar(Nodo* p) const{
    if(!esPosicionValida(p)){
        cout<<"La posicion no es valida para recuperar."<<endl;
        exit(1);
    }

    return p->getDato();
}

#endif // LISTA_H
