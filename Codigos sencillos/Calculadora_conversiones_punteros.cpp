#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

int Hexadecimal_Decimal(char*);
void *hexadecimal(int* );
void *octal(int* );
int numero=0;
int *suma(int*,int*);
int*ptr1=NULL,*ptr2=NULL,numero1=0,numero2=0,a=0, num[10], i,digito, posicion=0, resultado=0,oct=0,res=0,b=1,numeroO=0, numeroDecimal=0, exponente=0, residuo;
int vectr[]={1,2,4,8,16,32,64,128,256};
int digitoex[20];



//variable global
void *registro(){
        cout<<"ingrese primer numero: ";
        cin>>numero1;
        cout<<"ingrese segundo numero: ";
        cin>>numero2;
        ptr1=&numero1;
        ptr2=&numero2;
}

//Funciones
int *suma(int*pt1,int*pt2)
    {
        int *ptr=(int*)malloc(sizeof(int));
        *ptr=(*pt1+*pt2);
        return ptr;
    }

int *resta(int*pt1,int*pt2)
    {
        int *ptr=(int*)malloc(sizeof(int));
        *ptr=(*pt1-*pt2);
        return ptr;
    }
int *multiplicacion(int*pt1,int*pt2)
    {
        int *ptr=(int*)malloc(sizeof(int));
        *ptr=((*pt1)*(*pt2));
        return ptr;
    }

int *division(int*pt1,int*pt2)
    {
        int *ptr=(int*)malloc(sizeof(int));
        *ptr=((*pt1)/(*pt2));
        return ptr;
    }

    int *potencia(int *a, int *b){
        int *r= (int*)malloc(sizeof(int));
        *r=1;
        for(int i=0; i<*b; i++){
            *r *= (*a);
        }
    return r;
}

int *factorial(int *a)
{
int *r= (int*)malloc(sizeof(int));
*r=*a;
for(int i=1; i<*a; i++){
*r=(*r)*(i);
}
return r;
}

void *binario(int*numero){
    int cociente=0;
    int residuo=0;

    while(*numero/2>0){

    residuo=*numero%2;
    cociente=*numero/2;
    *numero=cociente;
    num[i]=residuo;
    i++;
}
    num[i]=cociente;

  if(*numero/2 == 0){
    for(i; i>=0; i--){
     cout<<num[i];
    }
  }else{
    for(i; i>=0; i++){
     cout<<num[i];
    }
  }

}


void *decimal(int* numero)
{

     while(*numero>0)
    {
     digito=*numero%10;
     if(digito==1)
        {
            resultado=resultado+vectr[posicion];
            posicion++;
            *numero=*numero/10;
        }
        posicion++;
        *numero=*numero/10;
    }
    cout<<"el resultado es"<<resultado;
    system("pause");
}

void *octal(int* a)
{
    int oct=0,res=0,b=1;
     while(*a!=0)
    {
        res=*a%8;
        oct=(res)*(b)+oct;
        b=b*10;
        *a=*a/8;
    }
    cout<<"El numerio es"<<oct<<endl;
    system("PAUSE");
}

void *octadecimal(int *numeroO)
{
    while(*numeroO>0)
    {
        numeroDecimal=numeroDecimal+(*numeroO%10*pow(8,exponente));
        *numeroO=*numeroO/10;
        exponente++;
    }
    cout<<"Resultado: "<<numeroDecimal<<endl;

}

void *hexadecimal(int *decimal)
{
     do
    {
        residuo = *decimal % 16;
        resultado = *decimal / 16;
        digitoex[i] = residuo;
        *decimal = resultado;
        i++;
    } while (resultado > 15);

    digitoex[i] = resultado;

    cout <<endl<< "El equivalente en hexadecimal es: ";


    for (int j = i; j >= 0; j--)
    {
        if (digitoex[j] == 10)
        {
            cout << "A";
        }
        else if (digitoex[j] == 11)
        {
            cout << "B";
        }
        else if (digitoex[j] == 12)
        {
            cout << "C";
        }
        else if (digitoex[j] == 13)
        {
            cout << "D";
        }
        else if (digitoex[j] == 14)
        {
            cout << "E";
        }
        else if (digitoex[j] == 15)
        {
            cout << "F";
        }
        else
        {
            cout << digitoex[j];
        }
    }
    cout << endl<<endl<<endl;
    system("PAUSE");
}


int Hexadecimal_Decimal(char *ptr){
        int dec=0,i=0,*ptr2=NULL;

        ptr2 = &dec;

        i=-1;
        for(int j=7;j>=0;j--){

        switch(ptr[j]){
                case '0':
                        i++;
                        *ptr2 += 0*pow(16,i);
                break;

                case '1':
                        i++;
                        *ptr2 += 1*pow(16,i);
                break;

                case '2':
                        i++;
                        *ptr2 += 2*pow(16,i);
                break;

                case '3':
                        i++;
                        *ptr2 += 3*pow(16,i);
                break;

                case '4':
                        i++;
                        *ptr2 += 4*pow(16,i);
                break;

                case '5':
                        i++;
                        *ptr2 += 5*pow(16,i);
                break;

                case '6':
                        i++;
                        *ptr2 += 6*pow(16,i);
                break;

                case '7':
                        i++;
                        *ptr2 += 7*pow(16,i);
                break;

                case '8':
                        i++;
                        *ptr2 += 8*pow(16,i);
                break;

                case '9':
                        i++;
                        *ptr2 += 9*pow(16,i);
                break;

                case 'A':
                        i++;
                        *ptr2 += 10*pow(16,i);
                break;

                case 'B':
                        i++;
                        *ptr2 += 11*pow(16,i);
                break;

                case 'C':
                        i++;
                        *ptr2 += 12*pow(16,i);
                break;

                case 'D':
                        i++;
                        *ptr2 += 13*pow(16,i);
                break;

                case 'E':
                        i++;
                        *ptr2 += 14*pow(16,i);
                break;

                case 'F':
                        i++;
                        *ptr2 += 15*pow(16,i);
                break;
    }
  }
  return *ptr2;
}



void menu(){
int opcion=0;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"|                                     Menu                                     |"<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"1) Suma "<<endl<<endl;
  cout<<"2) Resta "<<endl<<endl;
  cout<<"3) Multiplicacion "<<endl<<endl;
  cout<<"4) Division "<<endl<<endl;
  cout<<"5) Potencia "<<endl<<endl;
  cout<<"6) Factorial "<<endl<<endl;
  cout<<"7) Decimal - Binario "<<endl<<endl;
  cout<<"8) Binario - Decimal "<<endl<<endl;
  cout<<"9) Decimal - Octal"<<endl<<endl;
  cout<<"10) Octal- Decimal "<<endl<<endl;
  cout<<"11)Decimal - Hexadecimal"<<endl<<endl;
  cout<<"12)Hexadecimal- Decimal"<<endl<<endl;
  cout<<"0) salir "<<endl<<endl;
  cout<<"Opcion: ";
  cin>>opcion;
  switch(opcion){
      //Suma

  case 1: {
        system("cls");
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cout<<"|                                      Suma                                    |"<<endl;
        cout<<"--------------------------------------------------------------------------------"<<endl;
        registro();
        cout<<"Resultado suma:"<<*suma(ptr1,ptr2)<<endl;
        system("pause>>cls");  }break;
   //Resta
    case 2: {
        system("cls");
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cout<<"|                                     Resta                                    |"<<endl;
        cout<<"--------------------------------------------------------------------------------"<<endl;
        registro();
        cout<<"Resultado suma:"<<*resta(ptr1,ptr2)<<endl;
   }break;
   //Multiplicacion
     case 3: {
        system("cls");
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cout<<"|                                Multiplicacion                                |"<<endl;
        cout<<"--------------------------------------------------------------------------------"<<endl;
        registro();
        cout<<"Resultado suma:"<<*multiplicacion(ptr1,ptr2)<<endl;
   }break;
   //Division
     case 4: {
        system("cls");
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cout<<"|                                    Division                                  |"<<endl;
        cout<<"--------------------------------------------------------------------------------"<<endl;
        registro();
        cout<<"Resultado suma:"<<*division(ptr1,ptr2)<<endl;
   }break;
   case 5:
    {
        system("cls");
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cout<<"|                                 Potencia                                     |"<<endl;
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cout<<"Ingresa un numero: ";cin>>numero1;
        cout<<"Ingrese la potencia: ";cin>>numero2;
        ptr1= &numero1;
        ptr2= &numero2;
        cout<<*potencia(ptr1,ptr2)<<endl;
break;
   case 6:
    {
    system("cls");
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"|                             Factorizacion                                    |"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"Ingrese un numero: "<<endl;
    cin>>numero1;
    ptr1= &numero1;
    cout<<*factorial(ptr1)<<endl;
    break;
    }
    case 7:
        {
            system("cls");
            cout<<"--------------------------------------------------------------------------------"<<endl;
            cout<<"|                       Convertidor numeros binarios                           |"<<endl;
            cout<<"--------------------------------------------------------------------------------"<<endl;
            cout<<"ingrese un numero: ";
            cin>>a;
            ptr1=&a;
            cout<<endl<<endl<<"\n\nSu numero Binario es: ";
            binario(ptr1);
            cout<<endl<<endl<<endl<<endl;
        }
        break;
    case 8:
        {
            system("cls");
            cout<<"--------------------------------------------------------------------------------"<<endl;
            cout<<"|                              Binario - Decimal                               |"<<endl;
            cout<<"--------------------------------------------------------------------------------"<<endl;
            int numero;
            cout<<"Ingrese el numero";
            cin>>numero;
            ptr1=&numero;
            decimal(ptr1);
        }
        break;
    case 9:
        {
            system("cls");
            cout<<"--------------------------------------------------------------------------------"<<endl;
            cout<<"|                              Decimal - Octal                                 |"<<endl;
            cout<<"--------------------------------------------------------------------------------"<<endl;
            int a=0;
            cout<<"Digite un numero decimal: ";
            cin>>a;
            ptr1=&a;
            cout<<endl;
            octal(ptr1);
        }
        break;
    case 10:
        {
            system("cls");
            cout<<"--------------------------------------------------------------------------------"<<endl;
            cout<<"|                              Octal - Decimal                                 |"<<endl;
            cout<<"--------------------------------------------------------------------------------"<<endl;
            int numeroO, numeroDecimal=0, exponente=0;
            cout<<"Ingrese el numero en base 8(octal)"<<endl;
            cin>>numeroO;
            ptr1=&numeroO;
            octadecimal(ptr1);
        }
        break;
    case 11:
        {
            system("cls");
            int decimal, residuo, resultado, i = 0;
            cout<<"--------------------------------------------------------------------------------"<<endl;
            cout<<"|                     Convertidor numeros Hexadecimales                        |"<<endl;
            cout<<"--------------------------------------------------------------------------------"<<endl;
            cout << "Introduce el numero decimal a convertir: ";
            cin >> decimal;
            ptr1=&decimal;
            hexadecimal(ptr1);

        }
    case 12:
        system("cls");
         char hexadecimal[8],*ptro=NULL;

            for(int i=0;i<8;i++)
                {
                hexadecimal[i]=0;
                }
                cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"|                            Hexadecimal - Decimal                             |"<<endl;
                cout<<"--------------------------------------------------------------------------------"<<endl;

                cout<<"Numero en Hexadecimal: ";
                cin>>hexadecimal;

                ptro = hexadecimal;

                cout<<"\nEl Numero Decimal es: "<<Hexadecimal_Decimal(ptro)<<endl;


   }


  }

}

int opc=0;
int main(int argc, char** argv) {



do{
    system("cls");
    menu();
    cout<<endl<<endl<<endl<<endl<<"Desea continuar ejecutando 1[si] 0 [no]: ";
    cin>>opc;
    cout<<endl<<endl<<endl<<"Presione (Enter) para salir."<<endl;
}while(opc!=0);

system("pause>>cls");
return 0;
}
