#include "Fecha.h"

using namespace std;

///Privado

bool Fecha::esDiaValido() const{
    int limite;

    switch(mes){
        case 4: case 6: case 9: case 11: limite = 30; break;
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: limite = 31; break;
        case 2:
            if((anio % 4 == 0 and anio % 100 != 0) or anio % 400 == 0){
                limite = 29;
            }else{
                limite = 28;
            }
        break;
    }

    return dia <= limite;
}

bool Fecha::esMesValido() const{
    return mes >= 1 and mes <= 12;
}

///Público

Fecha::Fecha(){}

void Fecha::setDia(const int& d){
    dia = d;

    if(!esDiaValido()){
        cout<<"El dia ingresado no es valido..."<<endl;
        exit(1);
    }
}

void Fecha::setMes(const int& m){
    mes = m;

    if(!esMesValido()){
        cout<<"El mes ingresado no es valido..."<<endl;
        exit(1);
    }
}

void Fecha::setAnio(const int& a){
    anio = a;
}

int Fecha::getDia() const{
    return dia;
}

int Fecha::getMes() const{
    return mes;
}

int Fecha::getAnio() const{
    return anio;
}

string Fecha::toString() const{
    string resultado;

    if(dia < 10)
        resultado += "0";

    resultado += to_string(dia) + "/";

    if(mes < 10)
        resultado += "0";

    resultado += to_string(mes) + "/" + to_string(anio);

    return resultado;
}

int Fecha::toInt() const{
    return dia * 1000000 + mes * 10000 + anio;
}
