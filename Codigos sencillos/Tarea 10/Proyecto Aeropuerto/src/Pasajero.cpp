#include "Pasajero.h"

using namespace std;

Pasajero::Pasajero(){}

Pasajero::Pasajero(const Pasajero& p): nombre(p.nombre), destino(p.destino), id(p.id), miFecha(p.miFecha), numBoleto(p.numBoleto), asiento(p.asiento), pesoEquipaje(p.pesoEquipaje){}

Pasajero& Pasajero::operator = (const Pasajero& p){
    nombre = p.nombre;
    destino = p.destino;
    id = p.id;
    miFecha = p.miFecha;
    numBoleto = p.numBoleto;
    asiento = p.asiento;
    pesoEquipaje = p.pesoEquipaje;

    return *this;
}

void Pasajero::setNombre(const string& n){
    nombre = n;
}

void Pasajero::setDestino(const string& d){
    destino = d;
}

void Pasajero::setId(const int& i){
    id = i;
}

void Pasajero::setMiFecha(const Fecha& f){
    miFecha = f;
}

void Pasajero::setNumBoleto(const int& b){
    numBoleto = b;
}

void Pasajero::setAsiento(const string& a){
    asiento = a;
}

void Pasajero::setPesoEquipaje(const double& p){
    pesoEquipaje = p;
}

string Pasajero::getNombre() const{
    return nombre;
}

string Pasajero::getDestino() const{
    return destino;
}

int Pasajero::getId() const{
    return id;
}

Fecha Pasajero::getMiFecha() const{
    return miFecha;
}

int Pasajero::getNumBoleto() const{
    return numBoleto;
}

string Pasajero::getAsiento() const{
    return asiento;
}

double Pasajero::getPesoEquipaje() const{
    return pesoEquipaje;
}

string Pasajero::toString() const{
    string resultado;

    resultado += "-----------------------------------";
    resultado += "\nNombre: " + nombre + ".\nDestino: " + destino + ".\nID: " + to_string(id) + ".\nFecha: "+ miFecha.toString() + ".\nNo. Boleto: " + to_string(numBoleto) + ".\nAsiento: " + asiento + ".\nPeso de Equipaje: " + to_string(pesoEquipaje) + " kg.\n";
    resultado += "-----------------------------------";

    return resultado;
}
