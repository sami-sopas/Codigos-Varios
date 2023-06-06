#include<iostream>
#include<cstdlib>
#include<math.h>

using namespace std;

class Celsius{ //Clase Celsius
    private:
        double celsius,kelvin,fahrenheit;
    public:
        void setCelsius(double);
        double getCelsius();
        
        void calcularKelvin();
        double getKelvin();

        void calcularFahrenheit();
        double getFahrenheit();

};

void Celsius::setCelsius(double celsius){
    this->celsius=celsius;
}
double Celsius::getCelsius(){
    return this->celsius;
}
        
void Celsius::calcularKelvin(){
    this->kelvin=this->celsius+273.15;
}
double Celsius::getKelvin(){
    return this->kelvin; //Celsius-Kelvin
}
void Celsius::calcularFahrenheit(){
    this->fahrenheit=(this->celsius*1.8)+32;
}
double Celsius::getFahrenheit(){
    return this->fahrenheit; //Celsius-Fahrenheit
}

class Kelvin{ //Clase Kelvin
    private:
        double kelvin,celsius;
    public:
        void setKelvin(double);
        double getKelvin();
        
        void calcularCelsius();
        double getCelsius();
    
};
void Kelvin::setKelvin(double kelvin){
	this->kelvin=kelvin;
}
double Kelvin::getKelvin(){
	return this->kelvin;
}
        
void Kelvin::calcularCelsius(){
	this->celsius=(this->kelvin)-273.15;
}
double Kelvin::getCelsius(){
	return this->celsius;
}

class Fahrenheit{ //Clase Fahrenheit
    private:
        double fahrenheit,celsius;
    public:
        void setFarenheit(double);
        double getFahrenheit();
        
        void calcularCelsius();
        double getCelsius();
};
void Fahrenheit::setFarenheit(double fahrenheit){
	this->fahrenheit=fahrenheit;
}
double Fahrenheit::getFahrenheit(){
	return this->fahrenheit;
}
        
void Fahrenheit::calcularCelsius(){
	this->celsius=((this->fahrenheit)-32)/1.8;
}
double Fahrenheit::getCelsius(){
	return this->celsius;
}

double celsius=0,fahrenheit=0,kelvin,rep;
int main(){
    Celsius c;
    Kelvin k;
    Fahrenheit f;
    
    int opc;
	char opc1[10];
	char num1[10],num2[10];
	do
	{
	
		do{
			system("cls");
			cout<<" M E N U"<<endl
			<<"1)Celsius-Kelvin"<<endl
			<<"2)Kelvin-Celsius"<<endl
			<<"3)Celsius-Fahrenhei"<<endl
			<<"4)Fahrenheit-Celsius"<<endl
			<<"5)Salir"<<endl<<endl
			<<"El programa unicamente sirve con numeros enteros"<<endl<<endl;
				
				cout << "Introduce La opcion del Menu: " << endl;
		    	cin >> opc1;
			   	if(opc=atoi(opc1))
			    {
			    	
				}
				else
				{
					cout<<"no es un valor numerico entero"<<endl;
					cout<<""<<endl;
					system("pause");
					system("cls");
				}			
		   	}
			while(opc==0);
			switch(opc)	
			{
				case 1:
					cout<<"----Celsius-Kelvin-----:"<<endl<<endl;
					do{
						cout<<"Escriba los grados celcius: ";
		    			cin >> num1;
			   			if(celsius=atoi(num1))
				   			{
				   		 	
							}
						else
							{
							cout<<"no es un valor numerico entero"<<endl<<endl;
							}
	   				}
					while(celsius==0);
	        		c.setCelsius(celsius);
	        		c.calcularKelvin();
	        		cout<<"\n"<<celsius<<" C"<<" en Kelvin es: "<<c.getKelvin()<<endl;
	        		system("pause");
					break;
					case 2:
						cout<<"-----Kelvin-Celsius-----:"<<endl<<endl;
					do{
						cout<<"Escriba los grados Kelvin: ";
		    			cin >> num1;
			   			if(kelvin=atoi(num1))
				   			{
				   		 	
							}
						else
							{
							cout<<"no es un valor numerico entero"<<endl<<endl;
							}
	   				}
					while(kelvin==0);
					k.setKelvin(kelvin);
	        		k.calcularCelsius();
	        		cout<<"\n"<<kelvin<<" k"<<" en Celsius es: "<<k.getCelsius()<<endl;
	        		system("pause");
					break;
					
					case 3:
							cout<<"-----Celsius-Fahrenheit-----:"<<endl<<endl;
					do{
						cout<<"Escriba los grados celcius: ";
		    			cin >> num1;
			   			if(celsius=atoi(num1))
				   			{
				   		 	
							}
						else
							{
							cout<<"no es un valor numerico entero"<<endl<<endl;
							}
	   				}
					while(celsius==0);
					c.setCelsius(celsius);
		        	c.calcularFahrenheit();
		        	cout<<"\n"<<celsius<<" C"<<" en Fahrenheit es: "<<c.getFahrenheit()<<endl;
		        	system("pause");
					break;
					
					case 4:
						cout<<"-----Fahrenheit-Celsius-----:"<<endl<<endl;
					do{
						cout<<"Escriba los grados Fahrenheit: ";
		    			cin >> num1;
			   			if( fahrenheit=atoi(num1))
				   			{
				   		 	
							}
						else
							{
							cout<<"no es un valor numerico entero"<<endl<<endl;
							}
	   				}
					while(fahrenheit==0);
					f.setFarenheit(fahrenheit);
		        	f.calcularCelsius();
		        	cout<<"\n"<<fahrenheit<<" F"<<" en Celsius es: "<<f.getCelsius()<<endl;
		        	system("pause");
					break;
					
					case 5:
						cout<< "salir del programa"<<endl;
					break;
					default: 
					cout<<("\n  Opcion equivocada")<<endl;
					system("pause");
					system("cls");
			}
	
	}while(opc!=5);
	return 0;
}
