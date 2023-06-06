#ifndef COLA_H
#define COLA_H

#include "Pasajero.h"
#include <iostream>

class Cola{
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

        Nodo* posFrente;
        Nodo* posFinal;
    public:
        Cola();

        bool vacia(Nodo*) const;
        void encolar(const Pasajero&);
        Pasajero desencolar();
        Pasajero getFrente() const;
        Nodo* getFrentePos() const;
        Pasajero getFinal() const;
        std::string toString() const;
};

#endif // COLA_H
