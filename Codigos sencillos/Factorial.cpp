//Calcular factorial de un numero usando funciones,parametros y punteros
//Samuel Osvaldo Ramirez Cuenca

#include <iostream>
#include <conio.h>

using namespace std;

int factorial(int, int *); 
int main()
{
    int i,fact,numero; //Declaracion de variables
    cout<<"Ingresa un numero: "<<endl; cin>>numero;
    factorial(numero, &fact);
    cout<<"El factorial de " <<numero<< " es: "<<fact;
    
    getch();
    return 0;
}

//Funcion con parametro
int factorial(int numero, int *fact){
int i;
*fact=1;
for(i=1; i<=numero; i++){
*fact=*fact*i;
}
}
