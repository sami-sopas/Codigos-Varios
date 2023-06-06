#include"cuadrado.h"

void Cuadrado::CalcularArea(){
    this->area = (getLado()*getLado());
}

double Cuadrado::getArea(){
    return this->area;

}
