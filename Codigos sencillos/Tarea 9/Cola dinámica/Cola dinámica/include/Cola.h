#ifndef COLA_H
#define COLA_H

#include <iostream>
#include <string>

class Cola{
    private:
        class Nodo{
            private:
                Nodo* siguiente;
                int dato;
            public:
                Nodo(const int&);

                void setSiguiente(Nodo*);
                void setDato(const int&);

                Nodo* getSiguiente() const;
                int getDato() const;
        };

        Nodo* posFrente;
        Nodo* posFinal;
    public:
        Cola();

        bool vacia(Nodo*) const;

        void encolar(const int&);
        int desencolar();
        int getFrente();

        int getFinal();
        std::string Imprimir() const;
};

#endif // COLA_H
