//Busqueda secuencial de un arreglo
#include<iostream>
#include<conio.h>

using namespace std;

int main(){
	int a[]={3,4,2,1,5}; //Areglo
	int i,dato; //El entero dato es donde se almacenara el dato que quiero guardar
	char band = 'F';//Varuable bandera: sirve para darme cuenta si el numero existe o no en el arreglo
	
	dato=4;//dato a buscar
	
	//Busqueda secuencial
	
	i=0;
	while((band=='F') && (i<5)){
		if(a[i]==dato){
			band='V';
		}
		i++; //Para que el dato se siga sumando y lo siga viendo en el arrehglo
	}
	
	if(band=='F'){
		cout<<"El numero a buscar en el arreglo no existe";}
	else if(band=='V'){
				cout<<"El numero fue encontrado en la posicion: "<<i-1<<endl;}

	

	getch();
	return 0;
}

