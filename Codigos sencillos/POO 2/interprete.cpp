//Declaracion de clase
#include"interprete.h"

using namespace std;

void Interprete::setSolista(const string& s) /** s es el dato que recibe, este se iguala a solista (que
                                                 es el dato que se encuentra en privado) de esta manera se setea**/
{
    solista = s;
}

void Interprete::setBanda(const string& b)
{
    banda = b;
}

string Interprete::getSolista()
{
    return solista; ///Retornando el valor privado una vez seteado
}

string Interprete::getBanda()
{
    return banda;
}
