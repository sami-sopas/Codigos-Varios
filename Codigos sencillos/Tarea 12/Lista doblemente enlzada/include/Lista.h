#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using namespace std;

template <class T>
class Lista{
    private:
        class Nodo{
            private:
                Nodo* anterior;
                Nodo* siguiente;
                T* datoPtr;
            public:
                Nodo(const T&);
                ~Nodo();

                void setAnterior(Nodo*);
                void setSiguiente(Nodo*);
                void setDatoPtr(T*);
                void setDato(const T&);

                Nodo* getAnterior() const;
                Nodo* getSiguiente() const;
                T* getDatoPtr() const;
                T getDato() const;
        };

        Nodo* ancla;

        bool esPosicionValida(Nodo*) const;
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

        void ordenarASC();
        void ordenarDEC();
};

///Nodo

template <class T>
Lista<T>::Nodo::Nodo(const T& e){
    datoPtr = new T(e);
    anterior = nullptr;
    siguiente = nullptr;

    if(datoPtr == nullptr){
        cout<<"No hay memoria suficiente para crear un nuevo nodo."<<endl;
        exit(1);
    }
}

template <class T>
Lista<T>::Nodo::~Nodo(){
    delete datoPtr;
}

template <class T>
void Lista<T>::Nodo::setAnterior(Nodo* p){
    anterior = p;
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
typename Lista<T>::Nodo* Lista<T>::Nodo::getAnterior() const{
    return anterior;
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

///Privado

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

///Público

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
        cout<<"La posicion no es valida para insertar."<<endl;
        exit(1);
    }

    Nodo* aux(new Nodo(e));

    if(aux == nullptr){
        cout<<"Ya no hay espacio disponible en la memoria para insertar."<<endl;
        exit(1);
    }

    if(p == nullptr){///Insertar al principio
        aux->setSiguiente(ancla);

        if(ancla != nullptr)
            ancla->setAnterior(aux);

        ancla = aux;
    }else{///Insertar en cualquier otro lugar
        aux->setAnterior(p);
        aux->setSiguiente(p->getSiguiente());

        if(p->getSiguiente() != nullptr)
            p->getSiguiente()->setAnterior(aux);

        p->setSiguiente(aux);
    }
}

template <class T>
void Lista<T>::eliminar(Nodo* p){
    if(!esPosicionValida(p)){
        cout<<"La posicion no es valida para eliminar."<<endl;
        exit(1);
    }

    if(p->getAnterior() != nullptr)
        p->getAnterior()->setSiguiente(p->getSiguiente());

    if(p->getSiguiente() != nullptr)
        p->getSiguiente()->setAnterior(p->getAnterior());

    if(p == ancla)
        ancla = ancla->getSiguiente();

    delete p;
}

template <class T>
void Lista<T>::anular(){
    Nodo* aux;

    while(aux != nullptr){
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
    if(!esPosicionValida(p))
        return nullptr;

    return p->getAnterior();
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
        cout<<"La posicion no es valida al recuperar."<<endl;
        exit(1);
    }

    return p->getDato();
}

template <class T>
void Lista<T>::ordenarASC(){
    Nodo* i(getUltimo()), *j;
    bool bandera;

    do{
        bandera = false;
        j = getPrimero();

        while(j != i){
            if(j->getDato() > j->getSiguiente()->getDato()){
                T* aux(j->getDatoPtr());
                j->setDatoPtr(j->getSiguiente()->getDatoPtr());
                j->getSiguiente()->setDatoPtr(aux);

                bandera = true;
            }

            j = j->getSiguiente();
        }

        i = i->getAnterior();
    }while(bandera);
}

template <class T>
void Lista<T>::ordenarDEC(){
    Nodo* i(getUltimo()), *j;
    bool bandera;

    do{
        bandera = false;
        j = getPrimero();

        while(j != i){
            if(j->getDato() < j->getSiguiente()->getDato()){
                T* aux(j->getDatoPtr());
                j->setDatoPtr(j->getSiguiente()->getDatoPtr());
                j->getSiguiente()->setDatoPtr(aux);

                bandera = true;
            }

            j = j->getSiguiente();
        }

        i = i->getAnterior();
    }while(bandera);
}

#endif // LISTA_H
