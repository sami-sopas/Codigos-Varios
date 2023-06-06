#ifndef ARBOL_H
#define ARBOL_H

#include "Contacto.h"
#include <iostream>

template <class T>
    class Arbol{
    private:
        class Nodo{
            private:
                Nodo* izquierda;
                Nodo* derecha;
                T* datoPtr;
            public:
                Nodo(const T&);
                ~Nodo();

                void setIzquierda(Nodo*&);
                void setDerecha(Nodo*&);
                void setDatoPtr(T*);
                void setDato(const T&);

                Nodo*& getIzquierda();
                Nodo*& getDerecha();
                T* getDatoPtr() const;
                T getDato() const;
        };

        Nodo* raiz;

        ///Funciones que son llamadas desde el área pública.
        void insertar(Nodo*&, const T&);

        Nodo*& localiza(Nodo*&, const T&);

        Nodo*& getMasBajo(Nodo*&);
        Nodo*& getMasAlto(Nodo*&);

        void recorridoPreOrder(Nodo*&);
        void recorridoInOrder(Nodo*&);
        void recorridoPosOrder(Nodo*&);

        ///AVL
        int getFactordeEquilibrio(Nodo*&);

        void hacerBalanceo(Nodo*&);

        void rotacionSimpleIzquierda(Nodo*&);
        void rotacionSimpleDerecha(Nodo*&);
        void rotacionDobleIzquierda(Nodo*&);
        void rotacionDobleDerecha(Nodo*&);
    public:
        typedef Nodo* Posicion;

        Arbol();

        bool vacio() const;

        ///Funciones que llaman a otras del área privada.
        void insertar(const T&);

        Nodo*& localiza(const T&);

        Nodo*& getMasBajo();
        Nodo*& getMasAlto();

        void recorridoPreOrder();
        void recorridoInOrder();
        void recorridoPosOrder();

        ///Funciones que NO llaman a otras del área privada.
        void eliminar(Nodo*&);
        bool esHoja(Nodo*&);

        int getAltura();
        int getAltura(Nodo*&);

        T recupera(Nodo*&);

        Nodo*& getRaiz();
        Nodo*& getPadre(Nodo*&);
        Nodo*& getPadre(Nodo*&, Nodo*&);
        void remplazar(Nodo*&, Nodo*&);
};

using namespace std;

///Nodo
template <class T>
Arbol<T>::Nodo::Nodo(const T& e){
    datoPtr = new T(e);
    izquierda = nullptr;
    derecha = nullptr;

    if(datoPtr == nullptr){
        cout<<"No es posible crear un nuevo nodo."<<endl;
        exit(1);
    }
}

template <class T>
Arbol<T>::Nodo::~Nodo(){
    delete datoPtr;
}

template <class T>
void Arbol<T>::Nodo::setIzquierda(Nodo*& p){
    izquierda = p;
}

template <class T>
void Arbol<T>::Nodo::setDerecha(Nodo*& p){
    derecha = p;
}

template <class T>
void Arbol<T>::Nodo::setDatoPtr(T* p){
    datoPtr = p;
}

template <class T>
void Arbol<T>::Nodo::setDato(const T& e){
    if(datoPtr == nullptr){
        cout<<"No es posible guardar el dato."<<endl;
        exit(1);
    }

    *datoPtr = e;
}

template <class T>
typename Arbol<T>::Nodo*& Arbol<T>::Nodo::getIzquierda(){
    return izquierda;
}

template <class T>
typename Arbol<T>::Nodo*& Arbol<T>::Nodo::getDerecha(){
    return derecha;
}

template <class T>
T* Arbol<T>::Nodo::getDatoPtr() const{
    return datoPtr;
}

template <class T>
T Arbol<T>::Nodo::getDato() const{
    if(datoPtr == nullptr){
        cout<<"El dato no existe"<<endl;
        exit(1);
    }

    return *datoPtr;
}

///Arbol

///Privado

///Funciones que llaman a otras del área privada.
template <class T>
void Arbol<T>::insertar(Nodo*& r, const T& e){
    if(r == nullptr){
        r = new Nodo(e);

        if(r == nullptr){
            cout<<"No hay memoria suficiente para insertar el elemento."<<endl;
            exit(1);
        }
    }else{
        if(e < r->getDato()){
            insertar(r->getIzquierda(), e);
        }else{
            insertar(r->getDerecha(), e);
        }

        hacerBalanceo(r);
    }
}

template <class T>
typename Arbol<T>::Nodo*& Arbol<T>::localiza(Nodo*& r, const T& e){
    if(r == nullptr or e == r->getDato())
        return r;

    if(e < r->getDato())
        return localiza(r->getIzquierda(), e);

    return localiza(r->getDerecha(), e);
}

template <class T>
typename Arbol<T>::Nodo*& Arbol<T>::getMasBajo(Nodo*& r){
    if(r == nullptr or r->getIzquierda() == nullptr)
        return r;

    return getMasBajo(r->getIzquierda());
}

template <class T>
typename Arbol<T>::Nodo*& Arbol<T>::getMasAlto(Nodo*& r){
    if(r == nullptr or r->getDerecha() == nullptr)
        return r;

    return getMasAlto(r->getDerecha());
}

template <class T>
void Arbol<T>::recorridoPreOrder(Nodo*& r){
    if(r == nullptr)
        return;

    cout<<r->getDato().toString()<<endl;
    recorridoPreOrder(r->getIzquierda());
    recorridoPreOrder(r->getDerecha());
}

template <class T>
void Arbol<T>::recorridoInOrder(Nodo*& r){
    if(r == nullptr)
        return;

    recorridoInOrder(r->getIzquierda());
    cout<<r->getDato().toString()<<endl;
    recorridoInOrder(r->getDerecha());
}

template <class T>
void Arbol<T>::recorridoPosOrder(Nodo*& r){
    if(r == nullptr)
        return;

    recorridoPosOrder(r->getIzquierda());
    recorridoPosOrder(r->getDerecha());
    cout<<r->getDato().toString()<<endl;
}

///AVL
template <class T>
int Arbol<T>::getFactordeEquilibrio(Nodo*& r){
    return getAltura(r->getDerecha()) - getAltura(r->getIzquierda());
}

template <class T>
void Arbol<T>::hacerBalanceo(Nodo*& r){
    switch(getFactordeEquilibrio(r)){
        case -2:
            if(getFactordeEquilibrio(r->getIzquierda()) == -1){
                rotacionSimpleDerecha(r);
            }else{
                rotacionDobleDerecha(r);
            }
        break;
        case 2:
            if(getFactordeEquilibrio(r->getDerecha()) == 1){
                rotacionSimpleIzquierda(r);
            }else{
                rotacionDobleIzquierda(r);
            }
        break;
    }
}

template <class T>
void Arbol<T>::rotacionSimpleIzquierda(Nodo*& r){
    Nodo* aux1(r->getDerecha());
    Nodo* aux2(aux1->getIzquierda());

    r->setDerecha(aux2);
    aux1->setIzquierda(r);
    r = aux1;
}

template <class T>
void Arbol<T>::rotacionSimpleDerecha(Nodo*& r){
    Nodo* aux1(r->getIzquierda());
    Nodo* aux2(r->getDerecha());

    r->setIzquierda(aux2);
    aux1->setDerecha(r);
    r = aux1;
}

template <class T>
void Arbol<T>::rotacionDobleIzquierda(Nodo*& r){
    rotacionSimpleDerecha(r->getDerecha());
    rotacionSimpleIzquierda(r);
}

template <class T>
void Arbol<T>::rotacionDobleDerecha(Nodo*& r){
    rotacionDobleIzquierda(r->getIzquierda());
    rotacionSimpleDerecha(r);
}

///Público

template <class T>
Arbol<T>::Arbol(): raiz(nullptr){}

template <class T>
bool Arbol<T>::vacio() const{
    return raiz == nullptr;
}

///Funciones que llaman a otras del área privada.
template <class T>
void Arbol<T>::insertar(const T& e){
     insertar(raiz, e);
}

template <class T>
typename Arbol<T>::Nodo*& Arbol<T>::localiza(const T& e){
    return localiza(raiz, e);
}

template <class T>
typename Arbol<T>::Nodo*& Arbol<T>::getMasBajo(){
    return getMasBajo(raiz);
}

template <class T>
typename Arbol<T>::Nodo*& Arbol<T>::getMasAlto(){
    return getMasAlto(raiz);
}

template <class T>
void Arbol<T>::recorridoPreOrder(){
    recorridoPreOrder(raiz);
}

template <class T>
void Arbol<T>::recorridoInOrder(){
    recorridoInOrder(raiz);
}

template <class T>
void Arbol<T>::recorridoPosOrder(){
    recorridoPosOrder(raiz);
}

///Funciones que NO llaman a otras del área privada.
template <class T>
void Arbol<T>::eliminar(Nodo*& r){
    if(vacio()){
        cout<<"Este arbol no tiene elementos."<<endl;
        exit(1);
    }

    if(esHoja(r)){
        delete r;
    }else if(r->getIzquierda() == nullptr and r->getDerecha() != nullptr){///Tiene solo hijo derecho
        remplazar(r, r->getDerecha());
        delete r;
    }else if(r->getIzquierda() != nullptr and r->getDerecha() == nullptr){///Tiene solo hijo izquierdo
        remplazar(r, r->getIzquierda());
        delete r;
    }else{
        Nodo* aux(getMasBajo(r->getDerecha()));
        r->setDatoPtr(aux->getDatoPtr());
        eliminar(aux);
    }
}

template <class T>
bool Arbol<T>::esHoja(Nodo*& r){
    return r == nullptr and r->getDerecha() == r->getIzquierda();
}

template <class T>
int Arbol<T>::getAltura(){
    return getAltura(raiz);
}

template <class T>
int Arbol<T>::getAltura(Nodo*& r){
    if(r == nullptr)
        return 0;

    int alturaIzq(getAltura(r->getIzquierda()));
    int alturaDer(getAltura(r->getDerecha()));

    return (alturaIzq > alturaDer ? alturaIzq : alturaDer) + 1;
}

template <class T>
T Arbol<T>::recupera(Nodo*& r){
    return r->getDato();
}

template <class T>
typename Arbol<T>::Nodo*& Arbol<T>::getRaiz(){
    return raiz;
}

template <class T>
typename Arbol<T>::Nodo*& Arbol<T>::getPadre(Nodo*& r){
    return getPadre(raiz, r);
}

template <class T>
typename Arbol<T>::Nodo*& Arbol<T>::getPadre(Nodo*& f, Nodo*& r){
    if(f == nullptr or (f->getIzquierda() == r or f->getDerecha() == r))
        return f;

    if(r->getDato() < f->getDato())
        return getPadre(f->getIzquierda(), r);

    return getPadre(f->getDerecha(), r);
}

template <class T>
void Arbol<T>::remplazar(Nodo*& t, Nodo*& r){
    //Nodo* auxPadre(getPadre(t));

    if(getPadre(t) != nullptr){
        if(t->getDato() == getPadre(t)->getIzquierda()->getDato())
            getPadre(t)->setIzquierda(r);

        if(t->getDato() == getPadre(t)->getDerecha()->getDato())
            getPadre(t)->setDerecha(r);
    }else{
        raiz = nullptr;
    }
}

#endif // ARBOL_H
