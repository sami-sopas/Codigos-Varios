#include"poligono.h"

void Poligono::CalcularArea(){
    this->area = (this->getPerimetro()*this->getApotema())/2;
}

double Poligono::getArea(){
    return this->area;
}
