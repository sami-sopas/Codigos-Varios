#ifndef NOMBRE_H
#define NOMBRE_H

#include <iostream>

class Nombre{
    private:
        std::string primero;///Nombre(s)
        std::string ultimo;///Apellido(s)
    public:
        Nombre();

        void setPrimero(std::string&);
        void setUltimo(std::string&);

        std::string getPrimero() const;
        std::string getUltimo() const;

        std::string toString() const;

        bool operator == (const Nombre&) const;
        bool operator != (const Nombre&) const;
};

#endif // NOMBRE_H
