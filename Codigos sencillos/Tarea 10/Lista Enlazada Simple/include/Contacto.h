#ifndef CONTACTO_H
#define CONTACTO_H

#include <iostream>
#include <string>
#include "Nombre.h"

class Contacto{
    private:
        Nombre miNombre;
        int edad;
        std::string id;
        std::string telefono;
    public:
        Contacto();

        void setMiNombre(const Nombre&);
        void setEdad(const int&);
        void setId(const std::string&);
        void setTelefono(const std::string&);

        Nombre getMiNombre() const;
        int getEdad() const;
        std::string getId() const;
        std::string getTelefono() const;

        std::string toString() const;

        bool operator == (const Contacto&) const;
        bool operator != (const Contacto&) const;
};

#endif // CONTACTO_H
