#ifndef FECHA_H
#define FECHA_H

#include <iostream>
#include <string>

class Fecha{
    private:
        int dia;
        int mes;
        int anio;

        bool esDiaValido() const;
        bool esMesValido() const;
    public:
        Fecha();

        void setDia(const int&);
        void setMes(const int&);
        void setAnio(const int&);

        int getDia() const;
        int getMes() const;
        int getAnio() const;

        int toInt() const;
        std::string toString() const;
};

#endif // FECHA_H
