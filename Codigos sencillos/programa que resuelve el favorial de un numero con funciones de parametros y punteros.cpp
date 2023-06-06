/*Programa que eleva un numero a una potencia con funciones de
parámetros y punteros*/
#include<cstdlib>
#include<iostream>

using namespace std;

float potencia(float*numero,float*pot){
	float *aux=numero,aux2=*numero;
	for(int u=0;u<*pot-1;u++)
	    *aux=*aux*(aux2);
	return *aux;
}

int main(int argc, char *argv[])
{    float numero=0,pot=0,*ptr,*ptr2;
     cout<<"ingrese un numero: "<<endl;
     cin>>numero;
     ptr=&numero;
     cout<<"ingrese una potencia: "<<endl;
     cin>>pot;
     ptr2=&pot;
     cout<<"Resultado: "<<potencia(ptr,ptr2)<<endl;
     system("PAUSE");
     return EXIT_SUCCESS;
}
