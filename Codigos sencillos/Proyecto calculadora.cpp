//Samuel Osvaldo Ramirez Cuenca Proyecto
#include<iostream>
#include<math.h>
#include<string.h>

using namespace std;

float operaciones(float n1, float n2, int r, float *dir_respu){
	switch(r){
		case 1:{ *dir_respu = n1 +n2;
			break;}
		case 2:{ *dir_respu = n1- n2;
			break;}
		case 3:{ *dir_respu = n1* n2;
			break;}
		case 4:{ *dir_respu = n1 / n2;
			break;}
		case 5:{
			float numero=0;
			int contador = 0;
			numero = n1;
			while (contador < n2-1){
					numero = n1 * numero;
					contador++;
			} *dir_respu = numero;
			break;}
		case 6:{
			int lim=0, res=0;
				n1 = n1+1;
				lim = 1;
				res=1;	
				do{
					res = res*(n1-1);
					n1--;
					}while (n1>lim);
					*dir_respu = res;
			break;
		}
	}
}
char ver_num(char letra){
	char letras;
	switch(letra){
		case 10:
			letras = 65;
			break;
		case 11:
			letras = 66;
			break;
		case 12:
			letras = 67;
			break;
		case 13:
			letras = 68;
			break;
		case 14:
			letras = 69;
			break;
		case 15:
			letras = 70;
			break;
		default:
			letras = letras;
			break;}
		if(letra<10){
			letras = letra + '0';}
				return(letras);}
char ver_letra(char letra){
		int letras;
			if(letra){
				switch(letra){
					case 'A':
					case 'a':
						letras = 10;
						break;
					case 'B':
					case 'b':
						letras = 11;
						break;
					case 'C':
					case 'c':
						letras = 12;
						break;
					case 'D':
					case 'd':
						letras = 13;
						break;
					case 'E':
					case 'e':
						letras = 14;
						break;
					case 'F':
					case 'f':
						letras = 15;
						break;
					default:
						letras  = letra;
						break;}
			}if(letras > 15 && letras<58){
				letras = letra-'0';}
			return(letras);}
char conv_base(int base, int numero, int *dir_w, char *dir_resp){
		int separado[100],suma[100],tam,i=0,w=-1,x=0;
		char texto[100];
		i=0;
		while(numero!=0){
			suma[i]= numero%base;
			numero = numero/base;
			w++;
			i++;} 
			*dir_w = w;
		for(w=w; w>=0; w--){
		dir_resp[x] = ver_num(suma[w]);
		x++;}
    }

char conv_dc(int base, char numero[100],int *dir_res){
		
		int separado[100],entero[100],i=0,suma=0,tam,x=0;
		tam = strlen(numero);
		for(i=0; i<tam; i++){
			numero[i] = ver_letra(numero[i]);
			separado[i] = numero[i];}
		suma=0;
		int w=tam-1;
		for(int z=0; z<tam; z++){
			if(separado[z]>=base){
				cout<<"El numero que ingresaste no es valido para la base elegida"<<endl;
				x=1;}
				else{
			if(separado[z]==0){
			}else{ suma = (pow(base,w) * separado[z] ) + suma;	
			}}w--;}
		if(x==1){
			}else{ *dir_res = suma;}
	}
void Menu(){
	int op=0,nume=0,res=0,w,i,*dir_res,*dir_w,lim=1;
	char resp[100],num[100],*dir_resp,*dir_num;	
	int r;
	float n1=0,n2=0,respu,*dir_respu;
	dir_w= &w;
	dir_resp = resp;
	dir_num = num;
	dir_res = &res;
	dir_respu = &respu;
	cout<<" M E N U "<<endl;
	cout<<"1)Suma"<<endl;
	cout<<"2)Resta"<<endl;
	cout<<"3)Multiplicacion"<<endl;
	cout<<"4)Division"<<endl;
	cout<<"5)Potencia"<<endl;
	cout<<"6)Factorial"<<endl;
	cout<<"7)Decimal-Bianrio"<<endl;
	cout<<"8)Binario-Decimal"<<endl;
	cout<<"9)Decimal-Octal"<<endl;
	cout<<"10)Octal-Decimal"<<endl;
	cout<<"11)Decimal-Hexadecimal"<<endl;
	cout<<"12)Hexadecimal-Decimal"<<endl;
	cin>>op;
	int opc=0;
	switch(op){
		case 1:{ //Suma
				cout<<"Ingrese el primer numero a sumar"<<endl;
				cin>>n1;
				cout<<"Ingrese el segundo numero a sumar"<<endl;
				cin>>n2;
				r=1;
				operaciones(n1,n2,r, dir_respu);
				cout<<"La suma de "<<n1<<" + "<<n2<<" es: "<<respu<<endl;
			    if (n1== false, n2==false)
				{
					cout<<"El dato ingresado no es nu numero"<<endl;
				}
				else
				{
					cout<<"\nPara continuar escriba 1\nPara salir escriba 2\n";
					cin>>opc;
					if(opc!=2){
						system("cls");
						return Menu();
					}
				}		
			break;
		}
		case 2:{ //Resta
				cout<<"Ingrese el primer numero"<<endl;
				cin>>n1;
				cout<<"Ingrese el numero a restar"<<endl;
				cin>>n2;
				r=2;
				
				operaciones(n1,n2,r,dir_respu);
				cout<<"La resta de "<<n1<<" - "<<n2<<" es: "<<respu<<endl;
				if (n1== false, n2==false)
				{
					cout<<"El dato ingresado no es un numero";
				}
				else
				{
					cout<<"\nPara continuar escriba 1\nPara salir escriba 2\n";
					cin>>opc;
					if(opc!=2){
						system("cls");
						return Menu();
					}
				}		
			break;
		}
		case 3:{ //Multiplicacion
				cout<<"Ingrese el numero a multiplicar"<<endl;
				cin>>n1;
				cout<<"Ingrese por cuanto se va a multiplicar"<<endl;
				cin>>n2;
				r=3;
				
				operaciones(n1,n2,r,dir_respu);
				cout<<"La multiplicacion de "<<n1<<" * "<<n2<<" es: "<<respu<<endl;	
				if (n1== false, n2==false)
				{
					cout<<"El dato ingresado no es un numero";
				}
				else
				{
					cout<<"\nPara continuar escriba 1\nPara salir escriba 2\n";
					cin>>opc;
					if(opc!=2){
						system("cls");
						return Menu();
					}
				}		
			break;
		}
		case 4:{ //Division
				cout<<"Ingrese el numero a dividir"<<endl;
				cin>>n1;
				cout<<"Ingrese por cuanto se va a dividir"<<endl;
				cin>>n2;
				r=4;
				
				operaciones(n1,n2,r,dir_respu);
				cout<<"La division de "<<n1<<" / "<<n2<<" es: "<<respu<<endl;	
				if (n1== false, n2==false)
				{
					cout<<"El dato ingresado no es un numero";
				}
				else
				{
					cout<<"\nPara continuar escriba 1\nPara salir escriba 2\n";
					cin>>opc;
					if(opc!=2){
						system("cls");
						return Menu();
					}
				}		
			break;
		}
		case 5:{ //Potencia
				cout<<"A que numero desea sacarle potencia?"<<endl;
				cin>>n1;
				cout<<"A que potencia desea hacerlo?"<<endl;
				cin>>n2;
				r=5;
				
				operaciones(n1,n2,r,dir_respu);
				cout<<"El resultado es: "<<respu<<endl;
				if (n1== false, n2==false)
				{
					cout<<"El dato ingresado no es un numero";
				}
				else
				{
					cout<<"\nPara continuar escriba 1\nPara salir escriba 2\n";
					cin>>opc;
					if(opc!=2){
						system("cls");
						return Menu();
					}
				}		
			break;
		}
		case 6:{ //Factorial
				cout<<"Ingrese el numero del que desee saber el factorial: "<<endl;
				cin>>n1;
				r=6;
				
				operaciones(n1,n2,r, dir_respu);
				cout<<"El factorial de: ";
				do{
					res = res*(n1-1);
					cout<<n1<<" * ";
					n1--;
				}while (n1>lim);
				cout<<"1";
				cout<<" es: "<<respu<<endl;
				if (n1==false)
				{
					cout<<"El dato ingresado no es un numero";
				}
				else
				{
					cout<<"\nPara continuar escriba 1\nPara salir escriba 2\n";
					cin>>opc;
					if(opc!=2){
						system("cls");
						return Menu();
					}
				}		
			break;
		}
		case 7: //Decimal-Binario
				cout<<"Ingrese el numero a convertir"<<endl;
				cin>>nume;
				res = 0;
				
				conv_base(2,nume,dir_w,dir_resp);
				cout<<"El resultado de la conversion es: ";
				for(i=0; i<=w; i++){
					cout<<resp[i];
					}
				cout<<endl;
				if (nume== false)
				{
					cout<<"El dato ingresado no es un numero";
				}
				else
					{
					cout<<"\nPara continuar escriba 1\nPara salir escriba 2\n";
					cin>>opc;
					if(opc!=2){
						system("cls");
						return Menu();
					}
				}		
			break;
		case 8:{ //Binario-Decimal
				cout<<"Ingrese el numero a convertir"<<endl;
				cin>>num;
			
				conv_dc(2,num,dir_res);
				cout<<"El resultado de la conversion es:"<<res<<endl;	
				if (num==false)
				{
					cout<<"El dato ingresado no es un numero";
				}
				else
				{
					cout<<"\nPara continuar escriba 1\nPara salir escriba 2\n";
					cin>>opc;
					if(opc!=2){
						system("cls");
						return Menu();
					}
				}		
			break;
		}
		case 9:{ //Decimal-Octal
				cout<<"Ingrese el numero a convertir"<<endl;
				cin>>nume;
				dir_res = &nume;
				res = 0;
				if (nume==false)
				{
					cout<<"El dato ingresado no es un numero\n";
				}
				else
				{
					cout<<"";
				}
				conv_base(8,nume,dir_w,dir_resp);
				cout<<"El resultado de la conversion es: ";
				for(i=0; i<=w; i++){
					cout<<resp[i];
					}
				if (nume==false)
				{
					cout<<"";
				}
				else
				{
					cout<<"\nPara continuar escriba 1\nPara salir escriba 2\n";
					cin>>opc;
					if(opc!=2){
						system("cls");
						return Menu();
					}
				}		
			break;
		}
		case 10:{ //Octal-Decimal
				cout<<"Ingrese el numero a convertir"<<endl;
				cin>>num;
				conv_dc(8,num,dir_res);
				cout<<"El resultado de la conversion es: "<<res<<endl;
				if (num==false)
				{
					cout<<"El dato ingresado no es un numero";
				}
				else
				{
					cout<<"\nPara continuar escriba 1\nPara salir escriba 2\n";
					cin>>opc;
					if(opc!=2){
						system("cls");
						return Menu();
					}
				}		
			break;
		}
		case 11:{ //Decimal-Hexadecimal
				cout<<"Ingrese el numero a convertir"<<endl;
				cin>>nume;
				dir_res = &nume;
				res = 0;
				conv_base(16,nume,dir_w,dir_resp);
				cout<<"El resultado de la conversion es: ";
				for(i=0; i<=w; i++){
					cout<<resp[i];
					}
				if (num==false)
				{
					cout<<"El dato ingresado no es un numero";
				}
				else
				{
					cout<<"\nPara continuar escriba 1\nPara salir escriba 2\n";
					cin>>opc;
					if(opc!=2){
						system("cls");
						return Menu();
					}
				}		
			break;
		}
		case 12:{ //Hexadecimal-Decimal
				cout<<"Ingrese el numero a convertir"<<endl;
				cin>>num;
				conv_dc(16,num,dir_res);
				cout<<"El resultado de la conversion es:"<<res<<endl;
				{
					cout<<"\nPara continuar escriba 1\nPara salir escriba 2\n";
					cin>>opc;
					if(opc!=2){
						system("cls");
						return Menu();
					}
				}		
			break;
			default:{
				if(isdigit(opc))
				cout<<""<<endl;
				else
				cout<<"Esta opcion no existe"<<endl;
				{
					cout<<"\nPara continuar escriba 1\nPara salir escriba 2\n";
					cin>>opc;
					if(opc!=2){
						system("cls");
						return Menu();
					}
				}		
				break;
			}
		}
	}
}
int main(int argc, char** argv){
		system("cls");
		Menu();
	return 0;
}

