#ifndef CONTACTO_H
#define CONTACTO_H

#include <iostream>
#include <string>

class Contacto{
    private:
        int id;
        std::string nombre;
        std::string direccion;
        std::string email;
    public:
        Contacto();

        void setId(const int&);
        void setNombre(const std::string&);
        void setDireccion(const std::string&);
        void setEmail(const std::string&);

        int getId() const;
        std::string getNombre() const;
        std::string getDireccion() const;
        std::string getEmail() const;

        std::string toString() const;

        bool operator == (const Contacto&) const;
        bool operator != (const Contacto&) const;
        bool operator < (const Contacto&) const;
        bool operator <= (const Contacto&) const;
        bool operator > (const Contacto&) const;
        bool operator >= (const Contacto&) const;
};

#endif // CONTACTO_H
