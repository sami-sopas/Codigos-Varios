/*La calificacion final de un estudiante es la media ponderada de tres notas. La nota de practicos que vale 30%, la de teorica que vale 60%
 y la de participacion que vale 10%. Escriba un programa que lea la entrada de las 3 notas de un alumno y escriba en la salida su nota final*/
 
 #include<iostream>
 
 using namespace std;
 
int main(){
    float practica,teorica,participacion,nota_final = 0;
 	
 	cout<<"Digite la nota de practica: ";cin>>practica;
 	cout<<"Digite la nota teorica: ";cin>>teorica;
 	cout<<"Digite la nota de participacion: ";cin>>participacion;
 	
 	practica = practica*0.30; //es lo mismo que practica*=0.30:
 	teorica*=0.60;
 	participacion*=0.10;
 	
 	nota_final= practica+teorica+participacion;
 	
 	cout<<"\nLa nota final es: "<<nota_final<<endl;
 	
 	return 0;
}
