#include"urna.h"

Urna::Urna()
{

}

Urna::Urna(const Urna&)
{

}

void Urna::setVoto(const int& v)
{
    this->voto=v;
}

int Urna::getVoto(){
return this->voto;
}
