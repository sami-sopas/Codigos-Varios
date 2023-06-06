#ifndef CANDIDATO2_H_INCLUDED
#define CANDIDATO2_H_INCLUDED
#include"urna.h"


class Candidato2 : public Urna{
private:
    double porcentaje;
public:
    void CalcularPorcentaje(const int &,const int&,const int&);
    double getPorcentaje();
};


#endif // CANDIDATO2_H_INCLUDED
