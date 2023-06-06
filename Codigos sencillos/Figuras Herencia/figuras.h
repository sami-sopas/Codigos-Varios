#ifndef FIGURAS_H_INCLUDED
#define FIGURAS_H_INCLUDED

class Figuras{
    private:
        double base;
        double altura;
        double lado;
        double lados;
        double MedidaLados;
        double perimetro;
        double apotema;
    public:
        void setBase(const double&);
        double getBase();
        void setAltura(const double&);
        double getAltura();
        void setLado(const double&);
        double getLado();
        void setLados(const double&);
        double getLados();
        void setMedidaLados(const double&);
        double getMedidaLados();
        void CalcularPerimetro();
        double getPerimetro();
        void CalcularApotema();
        double getApotema();
};

#endif // FIGURAS_H_INCLUDED
