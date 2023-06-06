#ifndef PASAJERO_H
#define PASAJERO_H

#include <iostream>
#include <string>
#include "Fecha.h"

class Pasajero{
    private:
        std::string nombre;
        std::string destino;
        int id;
        Fecha miFecha;
        int numBoleto;
        std::string asiento;
        double pesoEquipaje;
    public:
        Pasajero();
        Pasajero(const Pasajero&);
        Pasajero& operator = (const Pasajero&);

        void setNombre(const std::string&);
        void setDestino(const std::string&);
        void setId(const int&);
        void setMiFecha(const Fecha&);
        void setNumBoleto(const int&);
        void setAsiento(const std::string&);
        void setPesoEquipaje(const double&);

        std::string getNombre() const;
        std::string getDestino() const;
        int getId() const;
        Fecha getMiFecha() const;
        int getNumBoleto() const;
        std::string getAsiento() const;
        double getPesoEquipaje() const;

        std::string toString() const;
};

#endif // PASAJERO_H
