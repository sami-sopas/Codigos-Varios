#ifndef COLA_H
#define COLA_H

#include <iostream>
#include <string>
#define MAXIMO 10

class Cola{
    private:
        int datos[MAXIMO];
        int posFrente;
        int posFinal;
    public:
        Cola();

        bool vacia() const;
        bool llena() const;

        void encolar(const int&);
        int desencolar();
        int getFrente();

        int getFinal();
        std::string Imprimir() const;
};

#endif // COLA_H
