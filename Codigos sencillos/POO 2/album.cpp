#include"album.h"
///Definiendo el comportamiento de la clase
using namespace std;

void Album::setInterprete(Interprete& inter) /**Recibe un dato de tipo Interpetre por referencia (&)
                                                se accede a su informacion mediante el get y se iguala a una variable auxiliar
                                                y se setea en la instancia del objeto creada dentro de la clase Album **/
{
    string aux = inter.getSolista();
    creador.setSolista(aux);

    string aux2 = inter.getBanda();
    creador.setBanda(aux2);
}

void Album::setNombre(const string& n)
{
    nombre = n;
}

void Album::setAutor(const string& a)
{
    autor = a;
}

void Album::setAnio(const int& an)
{
    anio = an;
}
void Album::setCantidad(const int& c)
{
    cantidad = c;
}

void Album::setPrecio(const float& p)
{
    precio = p;
}

///Empiezan a regresar valores
Interprete Album::getInterprete()
{
    return creador;
}

string Album::getNombre()
{
    return nombre;
}

string Album::getAutor()
{
    return autor;
}

int Album::getAnio()
{
    return anio;
}
int Album::getCantidad()
{
    return cantidad;
}

float Album::getPrecio()
{
    return precio;
}


