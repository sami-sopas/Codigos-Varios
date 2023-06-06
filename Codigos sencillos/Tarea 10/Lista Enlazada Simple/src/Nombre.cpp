#include "Nombre.h"

using namespace std;

Nombre::Nombre(){}

void Nombre::setPrimero(string& f){
    primero = f;
}

void Nombre::setUltimo(string& l){
    ultimo = l;
}

string Nombre::getPrimero() const{
    return primero;
}

string Nombre::getUltimo() const{
    return ultimo;
}

string Nombre::toString() const{
    return "Apellido(s): " + ultimo + ".\nNombre(s): " + primero;
}

bool Nombre::operator == (const Nombre& n) const{
    return ultimo == n.ultimo;
}

bool Nombre::operator != (const Nombre& n) const{
    return ultimo != n.ultimo;
}

