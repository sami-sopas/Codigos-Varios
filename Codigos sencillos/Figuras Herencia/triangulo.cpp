#include"triangulo.h"

void Triangulo::CalcularArea(){
    this->area = (getBase()*getAltura())/2;
}

double Triangulo::getArea(){
    return this->area;
}
