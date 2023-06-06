#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <string>

class Pila{
    private:
        class Nodo{
            private:
                Nodo* siguiente;
                int dato;
            public:
                Nodo();
                Nodo(const int&);

                void setSiguiente(Nodo*);
                void setDato(const int&);

                Nodo* getSiguiente() const;
                int getDato() const;
        };

        Nodo* ancla;
    public:
        Pila();

        bool vacia() const;
        void push(const int&);
        int pop();
        int getTope() const;

        std::string imprimir() const;
};

#endif // PILA_H
