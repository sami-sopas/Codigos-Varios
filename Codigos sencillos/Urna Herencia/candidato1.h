#ifndef CANDIDATO1_H_INCLUDED
#define CANDIDATO1_H_INCLUDED
#include"urna.h"

class Candidato1 : public Urna{
private:
    double porcentaje;
public:
    void CalcularPorcentaje(const int&, const int&, const int&);
    double getPorcentaje();
};


#endif // CANDIDATO1_H_INCLUDED
