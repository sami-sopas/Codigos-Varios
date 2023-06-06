#include"yen.h"

float Yen::CalcularYenPeso()
{
    yen = (getCantidad()*0.18);
    return this->yen;
}
