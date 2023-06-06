#include "Cancion.h"

using namespace std;

Cancion::Cancion(){}

void Cancion::setNombre(const string& n){
    nombre = n;
}

void Cancion::setArtista(const string& a){
    artista = a;
}

void Cancion::setAlbum(const string& d){
    album = d;
}

void Cancion::setGenero(const string& g){
    genero = g;
}

void Cancion::setId(const int& i){
    id = i;
}

string Cancion::getNombre() const{
    return nombre;
}

string Cancion::getArtista() const{
    return artista;
}

string Cancion::getAlbum() const{
    return album;
}

string Cancion::getGenero() const{
    return genero;
}

int Cancion::getId() const{
    return id;
}

string Cancion::toString() const{
    return to_string(id) + " | " + artista + " -> " + nombre + " / " + album + " - " + genero;
}

bool Cancion::operator == (const Cancion& e) const{
    return artista == e.artista and nombre == e.nombre;
}

bool Cancion::operator != (const Cancion& e) const{
    return artista != e.artista and nombre != e.nombre;
}

bool Cancion::operator < (const Cancion& e) const{
    return id < e.id;
}

bool Cancion::operator <= (const Cancion& e) const{
    return id <= e.id;
}

bool Cancion::operator > (const Cancion& e) const{
    return id > e.id;
}

bool Cancion::operator >= (const Cancion& e) const{
    return id >= e.id;
}
