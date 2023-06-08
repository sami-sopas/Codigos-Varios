#ifndef TAMANIO_H_INCLUDED
#define TAMANIO_H_INCLUDED

#include<limits.h> ///Liberia que permite conocer los valores para los datos primitivos

class Tamanio{

    private: //De igual manera. asignamos los atributos desde aqui con ayuda de la liberia
        double bitsCaracterConSigno = CHAR_BIT;
        double bitsCaracterSinSigno = CHAR_BIT;

        double bitsEnteroCortoConSigno = CHAR_BIT*2;
        double bitsEnteroCortoSinSigno = CHAR_BIT*2;

        double bitsEnteroLargoConSigno = CHAR_BIT*2;
        double bitsEnteroLargoSinSigno = CHAR_BIT*2;

    public: //Metodos publicos para poder acceder a la informacion anterior
        double getBitsCaracterConSigno();
        double getBitsCaracterSinSigno();

        double getBitsEnteroCortoConSigno();
        double getBitsEnteroCortoSinSigno();

        double getBitsEnteroLargoConSigno();
        double getBitsEnteroLargoSinSigno();

};

#endif // TAMANIO_H_INCLUDED
