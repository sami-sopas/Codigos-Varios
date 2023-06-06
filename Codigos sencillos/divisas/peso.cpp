#include"peso.h"

float Peso::CalcularPesoDolar(){
    peso = (getCantidad()/20.28);
    return this->peso;
}

float Peso::CalcularPesoEuro(){
    peso = (getCantidad()/22.97);
    return this->peso;
}

float Peso::CalcularPesoYen(){
    peso = (getCantidad()*5.67);
    return this->peso;
}

float Peso::CalcularPesoYuan(){
    peso = (getCantidad()*0.31);
    return this->peso;
}

