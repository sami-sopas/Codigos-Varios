#include"figuras.h"
#include"math.h"

void Figuras::CalcularApotema(){
    double angulo,aux;
    angulo=360/(2*this->lados);
    aux=tan(angulo*3.1416/180);
    this->apotema=this->MedidaLados/(2*aux);
}

double Figuras::getApotema(){
    return this->apotema;
}

void Figuras::CalcularPerimetro(){
    this->perimetro = this->lados*this->MedidaLados;
}

double Figuras::getPerimetro(){
    return this->perimetro;
}

void Figuras::setMedidaLados(const double&m){
    this->MedidaLados=m;
}

double Figuras::getMedidaLados(){
    return this->MedidaLados;
}

void Figuras::setLados(const double&l){
    this->lados=l;
}

double Figuras::getLados(){
    return this->lados;
}

void Figuras::setLado(const double&l){
    this->lado=l;

}

double Figuras::getLado(){
    return this->lado;

}
void Figuras::setBase(const double&b)
{
    this->base=b;
}

double Figuras::getBase()
{
    return this->base;
}

void Figuras::setAltura(const double&a)
{
    this->altura=a;
}

double Figuras::getAltura()
{
    return this->altura;
}
