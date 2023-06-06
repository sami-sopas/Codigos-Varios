#include <iostream>
#include"moneda.h"
#include"peso.h"
#include"dolar.h"
#include"euro.h"
#include"yen.h"
#include"yuan.h"

using namespace std;

int main();

bool validacion(char *num){
    bool isValid=false;
    if(double(*num)>=48 &&(double)(*num)<=57){
        isValid=true;
    }
    return isValid;
}

menu(){
    int opc=0;
    char numero[1000];
    float num;
    Peso p;
    Dolar d;
    Euro e;
    Yen y;
    Yuan yu;

    cout<<"MENU"<<endl;
    cout<<"1)Peso - Dolar"<<endl;
    cout<<"2)Peso - Euro"<<endl;
    cout<<"3)Peso - Yen"<<endl;
    cout<<"4)Peso - Yuan"<<endl;
    cout<<"5)Dolar - Peso"<<endl;
    cout<<"6)Euro - Peso"<<endl;
    cout<<"7)Yen - Peso"<<endl;
    cout<<"8)Yuan - Peso"<<endl;
    cout<<"9)Salir"<<endl;
    cin>>numero;
    if(validacion(numero)){
       opc=atoi(numero);
       }
    switch(opc){
        case 1:{
            cout<<"Ingrese la cantidad de pesos"<<endl;
            cin>>numero;
            if(validacion(numero)){
                num=atof(numero);
                p.setCantidad(num);
            }else{
                cout<<"Ingrese solo numeros"<<endl;
                system("pause");
                return main();
            }
            cout<<"La cantidad de "<<num<<" pesos en dolares es: "<<p.CalcularPesoDolar()<<endl;
            break;
            }
        case 2:{
            cout<<"Ingrese la cantidad de pesos"<<endl;
            cin>>numero;
            if(validacion(numero)){
                num=atof(numero);
                p.setCantidad(num);
            }else{
                cout<<"Ingrese solo numeros"<<endl;
                system("pause");
                return main();
            }
            cout<<"La cantidad de "<<num<<" pesos en euros es: "<<p.CalcularPesoEuro()<<endl;
            break;
            }
        case 3:{
            cout<<"Ingrese la cantidad de pesos"<<endl;
            cin>>numero;
            if(validacion(numero)){
                num=atof(numero);
                p.setCantidad(num);
            }else{
                cout<<"Ingrese solo numeros"<<endl;
                system("pause");
                return main();
            }
            cout<<"La cantidad de "<<num<<" pesos en yenes es: "<<p.CalcularPesoYen()<<endl;
            break;
            }
        case 4:{
            cout<<"Ingrese la cantidad de pesos"<<endl;
            cin>>numero;
            if(validacion(numero)){
               num=atof(numero);
               p.setCantidad(num);
               }else{
                   cout<<"Ingresa solo numeros"<<endl;
                   system("pause");
                   return main();
               }
               cout<<"La cantidad de "<<num<<" pesos en yuanes es: "<<p.CalcularPesoYuan()<<endl;
               break;
        }
        case 5:{
            cout<<"Ingrese la cantidad de dolares"<<endl;
            cin>>numero;
            if(validacion(numero)){
                num=atof(numero);
                d.setCantidad(num);
            }else{
                cout<<"Ingresa solo numeros"<<endl;
                system("pause");
                return main();
            }
            cout<<"La cantidad de "<<num<<" dolares en pesos es: "<<d.CalcularDolarPeso()<<endl;
            break;
        }
        case 6:{
            cout<<"Ingrese la cantidad de euros"<<endl;
            cin>>numero;
            if(validacion(numero)){
                num=atof(numero);
                e.setCantidad(num);
            }else{
                cout<<"Ingresa solo numeros"<<endl;
                system("pause");
                return main();
            }
            cout<<"La cantidad de "<<num<<" euros en pesos es: "<<e.CalcularEuroPeso()<<endl;
            break;
        }
        case 7:{
            cout<<"Ingrese la cantidad de yenes"<<endl;
            cin>>numero;
            if(validacion(numero)){
               num=atof(numero);
               y.setCantidad(num);}
               else{
                cout<<"Ingresa solo numeros"<<endl;
                system("pause");
                return main();
               }
               cout<<"La cantidad de "<<num<<" yenes en pesos es: "<<y.CalcularYenPeso()<<endl;
               break;
        }
        case 8:{
            cout<<"Ingrese la cantidad de yuanes"<<endl;
            cin>>numero;
            if(validacion(numero)){
               num=atof(numero);
               yu.setCantidad(num);
               }else{
                   cout<<"Ingrese solo numeros"<<endl;
                   system("pause");
                   return main();
               }
               cout<<"La cantidad de "<<num<<" yenes en pesos es: "<<yu.CalcularYuanPeso()<<endl;
               break;
        }
        case 9:{
        break;}
    }

}

char opcion[100];
int op=0;
int main()
{
  do{
    system("cls");
    menu();
    cout<<"\n1) Continuar\n2)Salir"<<endl;
    cin>>opcion;
    if(validacion(opcion)){
        op=atoi(opcion);
    }else{
        cout<<"Ingrese un numero valido"<<endl;
        system("pause");
    }
  }while(op!=2);
  return 0;
}
