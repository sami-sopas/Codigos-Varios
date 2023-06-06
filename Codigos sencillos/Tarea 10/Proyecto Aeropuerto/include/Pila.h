#ifndef PILA_H
#define PILA_H

#include "Pasajero.h"
#include <iostream>

class Pila{
    private:
        class Nodo{
            private:
                Nodo* siguiente;
                Pasajero* datoPtr;
            public:
                Nodo(const Pasajero&);
                ~Nodo();

                void setSiguiente(Nodo*);
                void setDatoPtr(Pasajero*);
                void setDato(const Pasajero&);

                Nodo* getSiguiente() const;
                Pasajero* getDatoPtr() const;
                Pasajero getDato() const;
        };

        Nodo* ancla;
    public:
        Pila();

        bool vacia() const;

        void push(const Pasajero&);
        Pasajero pop();
        Pasajero getTope() const;
        std::string toString() const;
};

#endif // PILA_H
