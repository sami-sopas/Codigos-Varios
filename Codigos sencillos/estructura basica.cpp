//Estructura basica que pide y muestra datos al usuario
#include<iostream>
#include<conio.h>

using namespace std;

struct Persona{
	char nombre[20];
	int edad;
}persona1;

int main(){
	cout<<"Ingrese el nombre: ";
	cin.getline(persona1.nombre,20,'\n');
	
	cout<<"Ingrese su edad: ";
	cin>>persona1.edad;
	
	cout<<"\nImprimiendo datos\n";
	cout<<"Nombre: "<<persona1.nombre<<endl;
	cout<<"Edad: "<<persona1.edad<<endl;
	
	getch();
	return 0;
}
