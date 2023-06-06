//sentencia do while
#include<iostream>
#include<stdlib.h>//libreria para la funcion system

using namespace std;

int main(){
	int i;
	i=1;
	
	do{
		cout<<i<<endl;
		i++; //Esto hace que el entero amumente de 1 en 1
	}while(i<=10);
	system("pause");
	return 0;
}
