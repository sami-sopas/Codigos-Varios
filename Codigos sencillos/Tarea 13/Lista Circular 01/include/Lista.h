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
                Nodo();
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

        Nodo* encabezado;

        bool esPosicionValida(Nodo*) const;

        int numElementosActuales;
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

        string toString() const;

        int getSize();
};

///Nodo
template <class T>
Lista<T>::Nodo::Nodo(){
    datoPtr = nullptr;
    anterior = nullptr;
    siguiente = nullptr;
}

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
    Nodo* aux(encabezado->getSiguiente());

    while(aux != encabezado){
        if(aux == p)
            return true;

        aux = aux->getSiguiente();
    }

    return false;
}

///Público

template <class T>
Lista<T>::Lista(){
    encabezado = new Nodo;

    if(encabezado == nullptr){
        cout<<"No hay memoria disponible para crear la lista."<<endl;
        exit(1);
    }

    encabezado->setAnterior(encabezado);
    encabezado->setSiguiente(encabezado);

    numElementosActuales = 0;
}

template <class T>
Lista<T>::~Lista(){
    anular();

    delete encabezado;
}

template <class T>
bool Lista<T>::vacia() const{
    return encabezado->getSiguiente() == encabezado;
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

    if(p == nullptr)
        p = encabezado;

    aux->setAnterior(p);
    aux->setSiguiente(p->getSiguiente());

    p->getSiguiente()->setAnterior(aux);
    p->setSiguiente(aux);

    numElementosActuales++;
}

template <class T>
void Lista<T>::eliminar(Nodo* p){
    if(!esPosicionValida(p)){
        cout<<"La posicion no es valida para eliminar."<<endl;
        exit(1);
    }

    p->getAnterior()->setSiguiente(p->getSiguiente());
    p->getSiguiente()->setAnterior(p->getAnterior());

    delete p;

    numElementosActuales--;
}

template <class T>
void Lista<T>::anular(){
    Nodo* aux;

    while(encabezado->getSiguiente() != encabezado){
        aux = encabezado->getSiguiente();
        encabezado->setSiguiente(aux->getSiguiente());
        delete aux;
    }

    encabezado->setAnterior(encabezado);
    numElementosActuales = 0;
}

template <class T>
typename Lista<T>::Nodo* Lista<T>::buscar(const T& e) const{
    Nodo* aux(encabezado->getSiguiente());
    while(aux != encabezado){
        if(aux->getDato() == e)
            return aux;

        aux = aux->getSiguiente();
    }

    return nullptr;
}

template <class T>
typename Lista<T>::Nodo* Lista<T>::getPrimero() const{
    if(vacia())
        return nullptr;

    return encabezado->getSiguiente();
}

template <class T>
typename Lista<T>::Nodo* Lista<T>::getUltimo() const{
    if(vacia())
        return nullptr;

    return encabezado->getAnterior();
}

template <class T>
typename Lista<T>::Nodo* Lista<T>::getAnteriorPos(Nodo* p) const{
    if(!esPosicionValida(p) or p == encabezado->getSiguiente())
        return nullptr;

    return p->getAnterior();
}

template <class T>
typename Lista<T>::Nodo* Lista<T>::getSiguientePos(Nodo* p) const{
    if(!esPosicionValida(p) or p == encabezado->getAnterior())
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
int Lista<T>::getSize(){
    return numElementosActuales;
}

template <class T>
string Lista<T>::toString() const{
    string resultado;
    Nodo* aux(encabezado->getSiguiente());

    while(aux != encabezado){
        resultado += to_string(aux->getDato()) + " -> ";
        aux = aux->getSiguiente();
    }

    return resultado;
}

#endif // LISTA_H
