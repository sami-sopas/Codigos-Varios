#include <iostream>
using namespace std;

class temperatura{
  private:
    double cantidad;
  public:
    temperatura();
    temperatura(const temperatura&);

    void setCantidad(const double&);
    double getCantidad();

    double CelciusKelvin();
    double KelvinCelcius();
    double CelciusFarenheit();
    double FarenheitCelcius();
};

temperatura::temperatura(){
}

temperatura::temperatura(const temperatura& T):cantidad(T.cantidad){}

void temperatura::setCantidad(const double& q){
    this->cantidad=q;
}

double temperatura::getCantidad(){
    return this->cantidad;
}

double temperatura::CelciusKelvin(){
    double kelvin;
    kelvin=this->cantidad+273.15;
    return kelvin;
}

double temperatura::KelvinCelcius(){
    double celcius;
    celcius=this->cantidad-273.15;
    return celcius;
}

double temperatura::CelciusFarenheit(){
    double farenheit;
    farenheit=(this->cantidad*1.8)+32;
    return farenheit;
}
double temperatura::FarenheitCelcius(){
    double celcius;
    celcius=(this->cantidad-32)/1.8;
    return celcius;
}

bool valido(double);
bool no_valido(int);

int main()
{
    int opc;
    float myFloat;
    temperatura temperatura2;


    while(opc!=5){
    system("cls");
    cout << "M E N U"<<endl;
    cout <<"1. Celcius a Kelvin"<<endl;
    cout <<"2. Kelvin a Celcius"<<endl;
    cout <<"3. Celcius a Farenheit"<<endl;
    cout <<"4. Farenheit a Celcius"<<endl;
    cout <<"5. Salir"<<endl;
    cin>>opc;

    if(valido(opc)==true){
    switch(opc){

    case 1:{
    cout<<"Ingrese grados Celcius: "<<endl;
    cin>>myFloat; if(valido(myFloat)==true){
    temperatura2.setCantidad(myFloat);
    cout<<"La temperatura en grados Kelvin es: "<<temperatura2.CelciusKelvin()<<endl;
    system("pause");
    break;
    }
    }
    case 2:{
    cout<<"Ingrese grados Kelvin: "<<endl;
    cin>>myFloat; if(valido(myFloat)==true){
    temperatura2.setCantidad(myFloat);
    cout<<"La temperatura en grados Celcius es: "<<temperatura2.KelvinCelcius()<<endl;
    system("pause");
    break;
    }
    }
    case 3:{
    cout<<"Ingrese grados Celcius: "<<endl;
    cin>>myFloat; if(valido(myFloat)==true){
    temperatura2.setCantidad(myFloat);
    cout<<"La temperatura en grados Farenheit es: "<<temperatura2.CelciusFarenheit()<<endl;
    system("pause");
    break;
    }
    }
    case 4:{
    cout<<"Ingrese grados Farenheit: "<<endl;
    cin>>myFloat;if(valido(myFloat)==true){
    temperatura2.setCantidad(myFloat);
    cout<<"La temperatura en grados Celcius es: "<<temperatura2.FarenheitCelcius()<<endl;
    system("pause");
    break;
    }
    }
    case 5: {
    break;
	}
    default:
    cout<<"Por favor, ingrese un valor valido"<<endl;
    system("pause"); break;

    }
}
}
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
        cout<<"El programa se cerrara"<<endl;
        exit(1);
    }
    else
        return true;
}
