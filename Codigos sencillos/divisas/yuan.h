#ifndef YUAN_H_INCLUDED
#define YUAN_H_INCLUDED
#include"moneda.h"

class Yuan : public Moneda{
    private:
        float yuan;
    public:
        float CalcularYuanPeso();
};


#endif // YUAN_H_INCLUDED
