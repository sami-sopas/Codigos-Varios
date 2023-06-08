#ifndef RANGO_H_INCLUDED
#define RANGO_H_INCLUDED
#include<limits.h>

class Rango{ ///Creacion de la clase rango

    private: ///Los atributos con ya valores asignados para solo acceder a ellos mediante los metodos
        double maximoCaracterConSigno = SCHAR_MAX;
        double minimoCaracterConSigno = SCHAR_MIN;
        double maximoCaracterSinSigno = UCHAR_MAX;
        double minimoCaracterSinSigno = 0;

        double maximoEnteroCortoConSigno = SHRT_MAX;
        double minimoEnteroCortoConSigno = SHRT_MIN;
        double maximoEnteroCortoSinSigno = USHRT_MAX;
        double minimoEnteroCortoSinSigno = 0;

        double maximoEnteroLargoConSigno = LONG_MAX;
        double minimoEnteroLargoConSigno = LONG_MIN;
        double maximoEnteroLargoSinSigno = ULONG_MAX;
        double minimoEnteroLargoSinSigno = -4.29497e+09;

    public:
        ///Getters: funciones que van a retornar el valor de los atributos en privado
        double getMaximoCaracterConSigno();
        double getMinimoCaracterConSigno();
        double getMaximoCaracterSinSigno();
        double getMinimoCaracterSinSigno();

        double getMaximoEnteroCortoConSigno();
        double getMinimoEnteroCortoConSigno();
        double getMaximoEnteroCortoSinSigno();
        double getMinimoEnteroCortoSinSigno();

        double getMaximoEnteroLargoConSigno();
        double getMinimoEnteroLargoConSigno();
        double getMaximoEnteroLargoSinSigno();
        double getMinimoEnteroLargoSinSigno();

};

#endif // RANGO_H_INCLUDED
