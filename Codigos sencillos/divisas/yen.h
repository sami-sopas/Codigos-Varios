#ifndef YEN_H_INCLUDED
#define YEN_H_INCLUDED
#include"moneda.h"

class Yen : public Moneda{
    private:
        float yen;
    public:
        float CalcularYenPeso();

};


#endif // YEN_H_INCLUDED
