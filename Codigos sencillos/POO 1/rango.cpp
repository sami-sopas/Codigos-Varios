#include"rango.h" ///Incluimos el archivo de cabezera para poder programar la clase

using namespace std;

double Rango::getMaximoCaracterConSigno() /**Se accede a la clase rango, y llamamos al metodo get para
                                             que este retorne el valor que se encuentra asignado en privado**/
{
    return maximoCaracterConSigno;
}

double Rango::getMinimoCaracterConSigno()  /**Esto se hace con todos los demas datos, se usa su respectivo metodo getter
                                             para recuperar esa informacion**/
{
    return minimoCaracterConSigno;
}

double Rango::getMaximoCaracterSinSigno()
{
    return maximoCaracterSinSigno;
}

double Rango::getMinimoCaracterSinSigno()
{
    return minimoCaracterSinSigno;
}

double Rango::getMaximoEnteroCortoConSigno()
{
    return maximoEnteroCortoSinSigno;
}

double Rango::getMinimoEnteroCortoConSigno()
{
    return minimoEnteroCortoConSigno;
}

double Rango::getMaximoEnteroCortoSinSigno()
{
    return maximoEnteroCortoSinSigno;
}

double Rango::getMinimoEnteroCortoSinSigno()
{
    return minimoEnteroCortoSinSigno;
}

double Rango::getMaximoEnteroLargoConSigno()
{
    return maximoEnteroLargoConSigno;
}

double Rango::getMinimoEnteroLargoConSigno()
{
    return minimoEnteroLargoConSigno;
}

double Rango::getMaximoEnteroLargoSinSigno()
{
    return maximoEnteroLargoSinSigno;
}

double Rango::getMinimoEnteroLargoSinSigno()
{
    return minimoEnteroLargoSinSigno;
}
