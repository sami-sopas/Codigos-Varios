#include "Contacto.h"

using namespace std;

Contacto::Contacto(){}

void Contacto::setMiNombre(const Nombre& n){
    miNombre = n;
}

void Contacto::setEdad(const int& e){
    edad = e;
}

void Contacto::setId(const string& i){
    id = i;
}

void Contacto::setTelefono(const string& t){
    telefono = t;
}

Nombre Contacto::getMiNombre() const{
    return miNombre;
}

int Contacto::getEdad() const{
    return edad;
}

string Contacto::getId() const{
    return id;
}

string Contacto::getTelefono() const{
    return telefono;
}

string Contacto::toString() const{
    string resultado;

    resultado += "------------------------------";
    resultado += "\nID: " + id + ".\n" + miNombre.toString() + ".\nEdad: " + to_string(edad) + ".\nTelefono: " + telefono + ".\n";
    resultado += "------------------------------";

    return resultado;
}

bool Contacto::operator == (const Contacto& c) const{
    return miNombre == c.miNombre;
}

bool Contacto::operator != (const Contacto& c) const{
    return miNombre != c.miNombre;
}
