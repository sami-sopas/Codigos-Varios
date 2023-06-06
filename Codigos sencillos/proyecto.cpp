#include<iostream>
#include<cstdlib>
#include<math.h>
#include<string.h>
//olo

using namespace std;

int*ptr1,*ptr2=NULL,*P;
void decimal_hexadecimal(int*);
void decimal_octal(int*);
void decimal_binario(int*);
void binario_decimal(int*);
void octal_decimal(int*);
void hexadecimal_decimal(int*);
int*factorial(int*);
int*potencia(int*a,int*b);
void Menu();
int a=0;

int hexadecimal_decimal(int*a{//falta
}

void decimal_hexadecimal(int*a){
	int decimal=*a,i=0,aux;
	char hexa[50];
	while(decimal!=0){
		aux=decimal%16;
		if(aux<10)
		   aux=aux+48;
		else
		   aux=aux+55;
		hexa[i]=aux;
		i++;
		decimal=decimal/16;
	}
	cout<<"Resultado: ";
	for(i=i-1;i>=0;i--)
	    cout<<hexa[i];
	cout<<endl;
}

void octal_decimal(int*a){
	int octal=*a,decimal=0,i=0,aux;
	while(octal!=0){
		aux=octal%10;
			decimal=decimal+(aux*pow(8,i));
			i++;
			octal=octal/10;
	}
	cout<<decimal;
}

void decimal_octal(int*a){
	int decimal=*a,octal[50],i=0;
	while(decimal!=0){
		octal[i]=decimal%8;
		i++;
		decimal=decimal/8;
	}
	cout<<"Resultado: ";
	for(i=(i-1); i>=0;i--)
		cout<<octal[i];
	cout<<endl;
}

void binario_decimal(int*a){
	int decimal=0,i=1,aux;
   while(*a!=0){
   	aux=*a%10;
   	decimal=decimal+(aux*i);
   	i=i*2;
   	*a=*a/10;}
   	cout<<decimal;  
}

void decimal_binario(int*a){
	int*cociente=(int*)malloc(sizeof(int));
	int*residuo=(int*)malloc(sizeof(int));
	 while(*a/2>0){
	 	*cociente=*a/2;
	 	    *residuo=*a%2;
	 	      *a=*cociente;
	 	    cout<<*residuo;
	 }
   cout<<*cociente;
}

int *factorial(int*a){
	int*r=(int*)malloc(sizeof(int));
	*r=*a;
	for(int i=1;i<*a;i++){
		*r=(*r)*(i);
	}
	return r;
}

int *potencia(int*a,int*b){
	int*r=(int*)malloc(sizeof(int));
	
	*r=1;
	for(int i=0;i<*b;i++){
		*r*=(*a);
	}
	return r;
}

int *suma(int*a,int*b){
	int*r=(int*)malloc(sizeof(double));
	*r=*a+*b;
	
	return r;
}

int *resta(int*a,int*b){
	int*r=(int*)malloc(sizeof(double));
	*r=*a-*b;
	
	return r;
}

int *multiplicacion(int*a,int*b){
	int*r=(int*)malloc(sizeof(double));
	*r=*a**b;
	
	return r;
}

int *division(int*a,int*b){
	int*r=(int*)malloc(sizeof(double));
	*r=*a / *b;
	
	return r;
}

void Menu(){
	int opc=0,n1=0,n2=0;
cout<<" MENU "<<endl
<<"1)Suma"<<endl
<<"2)Resta"<<endl
<<"3)Multiplicacion"<<endl
<<"4)Division"<<endl
<<"5)Potencia"<<endl
<<"6)Factorial"<<endl
<<"7)Decimal- Binario"<<endl
<<"8)Binario- Decimal"<<endl
<<"9)Decimal- Octal"<<endl
<<"10)Octal- Decimal"<<endl
<<"11)Decimal- Hexadecimal"<<endl
<<"12)Hexadecimal- Decimal"<<endl;
cin>>opc;


switch(opc){
	case 1:
		cout<<"Ingrese numero 1: "<<endl;
		cin>>n1;
		cout<<"Ingrese numero 2: "<<endl;
		cin>>n2;
		ptr1=&n1;
		ptr2=&n2;
		
		cout<<"Resultado: "<<*suma(ptr1,ptr2)<<endl;
		break;
	case 2:
		cout<<"Ingrese numero 1: "<<endl;
		cin>>n1;
		cout<<"Ingrese numero 2: "<<endl;
		cin>>n2;
		ptr1=&n1;
		ptr2=&n2;
		
		cout<<"Resultado: "<<*resta(ptr1,ptr2)<<endl;
		break;
	case 3:
		cout<<"Ingrese numero 1: "<<endl;
		cin>>n1;
		cout<<"Ingrese numero 2: "<<endl;
		cin>>n2;
		ptr1=&n1;
		ptr2=&n2;
		
		cout<<"Resultado: "<<*multiplicacion(ptr1,ptr2)<<endl;
		break;
	case 4:
		cout<<"Ingrese numero 1: "<<endl;
		cin>>n1;
		cout<<"Ingrese numero 2: "<<endl;
		cin>>n2;
		ptr1=&n1;
		ptr2=&n2;
		
		cout<<"Resultado: "<<*division(ptr1,ptr2)<<endl;
		break;
	case 5:
		cout<<"Ingrese un numero: "<<endl;
		cin>>n1;
		cout<<"Ingrese la potencia: "<<endl;
		cin>>n2;
		ptr1=&n1;
		ptr2=&n2;
		
		cout<<"Resultado: "<<*potencia(ptr1,ptr2)<<endl;
		break;
	case 6:
		cout<<"Ingrese un numero: "<<endl;
		cin>>n1;
		ptr1=&n1;
		
		cout<<"Resultado: "<<*factorial(ptr1)<<endl;
		break;
	case 7:
		cout<<"Ingrese un numero: "<<endl;
		cin>>n1;
		ptr1=&n1;
		
		decimal_binario(ptr1);
		break;
	case 8:
		cout<<"Ingrese un numero binario: "<<endl;
		cin>>n1;
		ptr1=&n1;
		
		binario_decimal(ptr1);
		break;
	case 9:
		cout<<"Ingrese un numero: "<<endl;
		cin>>n1;
		ptr1=&n1;
		
		decimal_octal(ptr1);
		break;
	case 10:
		cout<<"Ingrese un numero octal: "<<endl;
		cin>>n1;
		ptr1=&n1;
		
		octal_decimal(ptr1);
		break;
	case 11:
		cout<<"Ingrese un numero: "<<endl;
		cin>>n1;
		ptr1=&n1;
		
		decimal_hexadecimal(ptr1);
		break;
	case 12:
		cout<<"Ingrese un numero hexadecimal: "<<endl;
		cin>>n1;
		ptr1=&n1;
			
		hexadecimal_decimal(ptr1);
		break;
	}
}

int main(int argc,char** argv){
	system("cls");
	
	Menu();
	system("pause>>cls");
	return 0;
}
