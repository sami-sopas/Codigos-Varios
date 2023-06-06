#include "Contacto.h"

#include "Contacto.h"

using namespace std;

Contacto::Contacto(){}

void Contacto::setId(const int& i){
    id = i;
}

void Contacto::setNombre(const string& n){
    nombre = n;
}

void Contacto::setDireccion(const string& d){
    direccion = d;
}

void Contacto::setEmail(const string& e){
    email = e;
}

int Contacto::getId() const{
    return id;
}

string Contacto::getNombre() const{
    return nombre;
}

string Contacto::getDireccion() const{
    return direccion;
}

string Contacto::getEmail() const{
    return email;
}

string Contacto::toString() const{
    return to_string(id) + " | " + nombre + " - " + direccion + " - " + email;
}

bool Contacto::operator == (const Contacto& c) const{
    return id == c.id;
}

bool Contacto::operator != (const Contacto& c) const{
    return id != c.id;
}

bool Contacto::operator < (const Contacto& c) const{
    return id < c.id;
}

bool Contacto::operator <= (const Contacto& c) const{
    return id <= c.id;
}

bool Contacto::operator > (const Contacto& c) const{
    return id > c.id;
}

bool Contacto::operator >= (const Contacto& c) const{
    return id >= c.id;
}
