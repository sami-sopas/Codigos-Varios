#include"rectangulo.h"

void Rectangulo::CalcularArea(){
    this->area = (getBase()*getAltura());
}

double Rectangulo::getArea(){
    return this->area;
}
