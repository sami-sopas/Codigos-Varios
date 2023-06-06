#ifndef CANDIDATO3_H_INCLUDED
#define CANDIDATO3_H_INCLUDED
#include"urna.h"


class Candidato3 : public Urna{
private:
    double porcentaje;
public:
    void CalcularPorcentaje(const int &,const int&,const int&);
    double getPorcentaje();
};


#endif // CANDIDATO3_H_INCLUDED
