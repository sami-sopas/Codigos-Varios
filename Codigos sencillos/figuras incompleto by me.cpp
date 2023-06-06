//Agregar menu que te pemita seleccionar: triangulo, cuadrado, rectangulo y poligonos de 5 a 10 lados
#include <iostream>
#include <cstdlib>
using namespace std;

class Triangulo{
	
	//Atributos o caracteristicas del objeto
	private:
		double base;
		double altura;
		double area;
	//Metodos o comportamiento del objeto
	public:
		void setBase(double);
		double getBase();
		void setAltura(double);
		double getAltura();
		void CalcularArea();
		double getArea();
};

void Triangulo::setBase(double base){
	this->base=base;
}

double Triangulo::getBase(){
	return this->base;
}

void Triangulo::setAltura(double altura){
	this->altura=altura;
}

double Triangulo::getAltura(){
	return this->altura;
}

void Triangulo::CalcularArea(){
	this->area=(this->base*this->altura)/2;
}
double Triangulo::getArea(){
	return this->area;
}

class Rectangulo{
	
	//Atributos o caracteristicas del objeto
	private:
		double base;
		double altura;
		double area;
	//Metodos o comportamiento del objeto
	public:
		void setBase(double);
		double getBase();
		void setAltura(double);
		double getAltura();
		void CalcularArea();
		double getArea();
};

void Rectangulo::setBase(double base){
	this->base=base;
}

double Rectangulo::getBase(){
	return this->base;
}

void Rectangulo::setAltura(double altura){
	this->altura=altura;
}

double Rectangulo::getAltura(){
	return this->altura;
}

void Rectangulo::CalcularArea(){
	this->area=(this->base*this->altura);
}
double Rectangulo::getArea(){
	return this->area;
}

class Cuadrado{
	
	//Atributos o caracteristicas del objeto
	private:
		double lado;
		double area;
	//Metodos o comportamiento del objeto
	public:
		void setLado(double);
		double getLado();
		void CalcularArea();
		double getArea();
};

void Cuadrado::setLado(double lado){
	this->lado=lado;
}

double Cuadrado::getLado(){
	return this->lado;
}

void Cuadrado::CalcularArea(){
	this->area=(this->lado*this->lado);
}

double Cuadrado::getArea(){
	return this->area;
}

class Poligono{
	//Atributos o caracteristicas del objeto
	private:
		double lado;
		double nlado;
		double perimetro;
	//Metodos 
	public:
		void setLado(double);
		double getLado();
		void getNlado(double);
		double getNlado();
		void CalcularPerimetro();
		double getPerimetro();
};

void Poligono::setLado(double lado){
	this->lado=lado;
}
double Poligono::getLado(){
	return this->lado;
}
void menu(){
	int opc=0;
	double base=0;double altura=0;double lado=0;
		system("cls");
		cout<<"MENU"<<endl;
		cout<<"Ingrese el numero de la figura de la que quiera saber el area: "<<endl;
		cout<<"1) Triangulo"<<endl;
		cout<<"2) Rectangulo"<<endl;
		cout<<"3) Cuadrado"<<endl;
		cout<<"4) Poligono"<<endl;
		cin>>opc;
		switch(opc){
			case 1:{
		Triangulo t;	
	    cout<<"Ingrese base: "<<endl;
		cin>>base;
		cout<<"Ingrese altura: "<<endl;
		cin>>altura;
		t.setBase(base);
		t.setAltura(altura);
		t.CalcularArea();
		cout<<"Area: "<<t.getArea()<<endl;
				break;
			}
			case 2:{
				Rectangulo r;
				cout<<"Ingrese base: "<<endl;
				cin>>base;
				cout<<"Ingrese altura: "<<endl;
				cin>>altura;
				r.setBase(base);
				r.setAltura(altura);
				r.CalcularArea();
				cout<<"Area: "<<r.getArea()	<<endl;		
				break;
				case 3:{
					Cuadrado c;
					cout<<"Ingrese lado: "<<endl;
					cin>>lado;
					c.setLado(lado);
					c.CalcularArea();
					cout<<"Area: "<<c.getArea()<<endl;
					break;
				}
				case 4: {

					break;
				}
				}
			}
		}
	
}

int main(int argc, char** argv) {
	int opc=0;
	do{
	menu();
	cout<<"Continuar 1-si\n2-no"<<endl;
	cin>>opc;
	}while(opc!=2);
	return 0;
}
