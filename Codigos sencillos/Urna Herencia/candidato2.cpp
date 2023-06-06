#include"candidato2.h"

void Candidato2::CalcularPorcentaje(const int&p1,const int&p2,const int&p3)
{
this->porcentaje=(getVoto()*100/(p1+p2+p3));
}

double Candidato2::getPorcentaje()
{
return this->porcentaje;
}
