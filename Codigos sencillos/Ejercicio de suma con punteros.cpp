//Ejercicio de una suma usando punteros
#include<iostream>
#include<cstdlib>

using namespace std;

double *ptr1=NULL,*ptr2=NULL;
double * suma(double * n1, double * n2){
	double * res = (double*) malloc(sizeof(double));//malloc (asignacion de memoria) usarlo en los 3 archivos
	*res=*n1+*n2;
	
	return res;
}

double numero1=0,numero2=0;

int main(){
	system("cls");
	cout<<"Ingrese numero 1: "<<endl;
	cin>>numero1;
	cout<<"Ingrese numero 2: "<<endl;
	cin>>numero2;
	ptr1=&numero1;
	ptr2=&numero2;
	cout<<"Resultado: "<<*suma(ptr1,ptr2)<<endl;
	
	return 0;
}
