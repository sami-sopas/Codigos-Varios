/*Alumno: Néstor Leonel Nahuatlato Neri
Código: 216546402
Fecha: 24/03/2021

Materia: Seminario de Solución a Problemas de Estructuras de Datos I
NRC: 42656 / SEC: D21
Profesor: LUPERCIO CORONEL, RAMIRO
*/

#include <iostream>
#include <string>

using namespace std;

///Clase Cuadrado

class Cuadrado{
    private:
        int lado;
    public:
        void setLado(int);
        int getLado();

        string calcularArea();
};

void Cuadrado::setLado(int l){
    this->lado = l;
}

int Cuadrado::getLado(){
    return this->lado;
}

string Cuadrado::calcularArea(){
    return to_string(this->lado * this->lado);
}

///Clase Rectángulo

class Rectangulo{
    private:
        int base;
        int altura;
    public:
        void setBase(int);
        void setAltura(int);
        int getBase();
        int getAltura();

        string calcularArea();
};

void Rectangulo::setBase(int b){
    this->base = b;
}

void Rectangulo::setAltura(int h){
    this->altura = h;
}

int Rectangulo::getBase(){
    return this->base;
}

int Rectangulo::getAltura(){
    return this->altura;
}

string Rectangulo::calcularArea(){
    return to_string(this->base * this->altura);
}

///Main

int main(){
    int aux;
    Cuadrado square;
    Rectangulo rectangle;

    cout<<"Teclea lado del cuadrado: ";
    cin>>aux;
    square.setLado(aux);

    cout<<endl<<"Area: "<<square.calcularArea()<<endl;

    cout<<"Teclea base del rectangulo: ";
    fflush(stdin); cin>>aux;
    rectangle.setBase(aux);
    cout<<"Teclea altura del rectangulo: ";
    fflush(stdin); cin>>aux;
    rectangle.setAltura(aux);

    cout<<endl<<"Area del rectangulo: "<<rectangle.calcularArea()<<endl;

    return 0;
}

