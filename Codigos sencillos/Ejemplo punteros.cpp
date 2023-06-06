#include<iostream>

using namespace std;

int main(){
	int numero, *direccion;
	
	cout<<"Escriba un numero: ";cin>>numero;
	
	direccion= &numero;
	
	cout<<"El valor que escribiste fue: "<<*direccion<<endl;
	cout<<"Direccion del valor: "<<direccion<<endl;
	
	return 0;	
}
