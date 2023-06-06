#include"candidato1.h"

void Candidato1::CalcularPorcentaje(const int& p1, const int& p2, const int& p3){
    this->porcentaje=(getVoto()*100/(p1+p2+p3));
}

double Candidato1::getPorcentaje()
{
return this->porcentaje;
}
