/*3.Realizar un programa que lea un arreglo de estructuras de los datos de N empleados de la empresa
 y que imprima los datos del empleado con mayor y menor salario*/
 
#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

//declarar estructura de empleado
struct Empleado{
	char nombre[20];
	float salario;
}emp[100]; //100 ya que no sabemos cuantos empleados seran

int main(){
	int n_empleados; //variable para saber cuantos empleados seran
	int posM=0,posm=0; //Variables de la posicion mayor a menor
	float mayor=0,menor=99999;
	
	cout<<"Digite el numero de empleados: ";
	cin>>n_empleados;
	
	//Pedir datos
	for(int i=0;i<n_empleados;i++){
		fflush(stdin); //Para refrescar el bufer
		cout<<i+1<<"Digite su nombre: ";
		cin.getline(emp[i].nombre,20,'\n');
		cout<<i+1<<"Digite su salario: ";
		cin>>emp[i].salario;
		cout<<"\n";
		
		//Determinar el mayor salario
		if(emp[i].salario > mayor){
			mayor = emp[i].salario;
			posM=i;
		}
		//Determinar el menor salario
		if(emp[i].salario < menor){
			menor = emp[i].salario;
			posm=i;
		}
		cout<<"\n";
	}
	cout<<"\nDatos del empleado con el mayor salario: \n";
	cout<<"Nombre: "<<emp[posM].nombre<<endl;
	cout<<"Salario: "<<emp[posM].salario<<endl;
	
	cout<<"\nDatos del empleado con el menor salario: \n";
	cout<<"Nombre: "<<emp[posm].nombre<<endl;
	cout<<"Salario: "<<emp[posm].salario<<endl;
	
	getch();
	return 0;
}



