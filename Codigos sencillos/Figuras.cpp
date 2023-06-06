#include<iostream>
#include<math.h>

using namespace std;
//DECLARACION CLASE TRIANGULO
class triangulo{
private:
    double base;
    double altura;
    double area;
public:
    triangulo();
    triangulo(const triangulo&);

    void setBase(const double&);
    void setAltura(const double&);
    void calcularArea();
    double getBase();
    double getAltura();
    double getArea();
};
//FUNCIONES TRIANGULO
triangulo::triangulo(){ }

triangulo::triangulo(const triangulo& T):base(T.base),altura(T.altura),area(T.area){}


void triangulo::setBase(const double& base){
    this->base=base;
}

void triangulo::setAltura(const double& altura){
    this->altura=altura;
}
void triangulo::calcularArea(){
    this->area=(this->base*this->altura)/2;
}
double triangulo::getAltura(){
return this->altura;
}

double triangulo::getBase(){
    return this->base;
}

double triangulo::getArea(){
    return this->area;
}
//DECLARACION CLASE RECTANGULO
class rectangulo{
private:
    double base;
    double altura;
    double area;
public:
    rectangulo();
    rectangulo(const rectangulo& );

    void setBase(const double&);
    void setAltura(const double&);
    void calcularArea();
    double getBase();
    double getAltura();
    double getArea();
};
//FUNCIONES RECTANGULO
rectangulo::rectangulo(){}

void rectangulo::setBase(const double& base){
    this->base=base;
}

void rectangulo::setAltura(const double& altura){
    this->altura=altura;
}
void rectangulo::calcularArea(){
    this->area=(this->base*this->altura);
}
double rectangulo::getAltura(){
return this->altura;
}

double rectangulo::getBase(){
    return this->base;
}

double rectangulo::getArea(){
    return this->area;
}
//DECLARACION CLASE CUADRADO
class cuadrado{
private:
    double lado;
    double area;
public:
    cuadrado();
    cuadrado(const cuadrado&);

    void setLado(const double&);
    void calcularArea();
    double getLado();
    double getArea();
};
//FUNCIONES CUADRADO
cuadrado::cuadrado(){}

void cuadrado::setLado(const double& l){
this->lado=l;
}

void cuadrado::calcularArea(){
this->area=(this->lado*this->lado);
}
double cuadrado::getLado(){
return this->lado;
}

double cuadrado::getArea(){
return this->area;
}
//DECLARACION CLASE POLIGONO
class poligono{
private:
    double NumeroLados;
    double MedidaLados;
    double perimetro;
    double apotema;
    double area;
public:
    poligono();
    poligono(const poligono&);

    void setNumeroLados(const double&);
    void setMedidaLados(const double&);
    void calcularApotema();
    void calcularPerimetro();
    void calcularArea();

    double getNumeroLados();
    double getMedidaLados();
    double getPerimetro();
    double getApotema();
    double getArea();
};
//FUNCIONES POLIGONO
poligono::poligono(){}

void poligono::setNumeroLados(const double& nos){
    this->NumeroLados=nos;
}

void poligono::setMedidaLados(const double& sl){
    this->MedidaLados=sl;
}

void poligono::calcularPerimetro(){
    this->perimetro=(this->NumeroLados*this->MedidaLados);
}

void poligono::calcularApotema()
{
    double angle,aux;
    angle=360/(2*this->NumeroLados);
    aux=tan(angle*3.1416/180);
    this->apotema=this->MedidaLados/(2*aux);
}

double poligono::getApotema(){
    return this->apotema;
}


void poligono::calcularArea(){
    this->area=(this->perimetro*this->apotema)/2;
}

double poligono::getNumeroLados(){
return this->NumeroLados;
}

double poligono::getMedidaLados(){
return this->MedidaLados;
}

double poligono::getPerimetro(){
return this->perimetro;
}

double poligono::getArea(){
return this->area;
}

bool valido(double);
bool no_valido(int);

int main()
{
    int opc;
    double numero;
    cuadrado c;
    triangulo t;
    rectangulo r;
    poligono p;

    do{
    system("cls");
    cout<<"Ingrese el numero de la figura que quiere: "<<endl;
    cout<<"1. Cuadrado"<<endl;
    cout<<"2. Rectangulo"<<endl;
    cout<<"3. Triangulo"<<endl;
    cout<<"4. Poligono"<<endl;
    cin>>opc;

    if(no_valido(opc)==true)
    {
    switch(opc){

    case 1:{
    cout<<"Ingrese el lado del cuadrado: ";
    cin>>numero;
    if(valido(numero)==true)
    {
    c.setLado(numero);
    c.calcularArea();
    cout<<"\nEl area del cuadrado es: "<<c.getArea()<<endl;
    break;
    }}
    case 2:{
    cout<<"Ingrese la base del rectangulo"<<endl;
    cin>>numero;  
	if(valido(numero)==true){
    r.setBase(numero);
    cout<<"Ingrese la altura del rectangulo"<<endl;
    cin>>numero; 
	if(valido(numero)==true){
    r.setAltura(numero);
    r.calcularArea();
    cout<<"El area del rectangulo es: "<<r.getArea()<<endl;
    break;
    }}}
    case 3:{
    cout<<"Ingrese la base del triangulo: "<<endl;
    cin>>numero; if(valido(numero)==true){
    t.setBase(numero);
    cout<<"Ingrese la altura del triangulo: "<<endl;
    cin>>numero; if(valido(numero)==true){
    t.setAltura(numero);
    t.calcularArea();
    cout<<"El area del triangulo es: "<<t.getArea()<<endl;
    break;
    }}}
    case 4:{
    cout<<"Ingrese el numero de lados de la figura: "<<endl;
    cin>>numero;  
	if(valido(numero)==true){
        p.setNumeroLados(numero);
    cout<<"Ingrese la medida de un lado: "<<endl;
    cin>>numero; 
	if(valido(numero)==true){
        p.setMedidaLados(numero);
    p.calcularPerimetro();
    p.calcularApotema();
    p.calcularArea();
    cout<<"El apotema del poligono es: "<<p.getApotema()<<endl;
    cout<<"\nEl area del poligono es: "<<p.getArea()<<endl;
    break;
    }}}
    default: cout<<"Ingrese un dato valido, por favor"<<endl;
    }
    }
    cout<<"\nDesea continuar? \n1. Si 2. No"<<endl;
    cin>>opc;
    }
    while(opc!=2);
}

bool valido(double num)
{
    if(num==false){
        cout<<"Caracter invalido"<<endl;
        exit(1);
    }
    else
        return true;
}

bool no_valido(int num)
{
    if(num==false){
        cout<<"Caracter invalido"<<endl;
        exit(1);
    }
    else
        return true;
}

