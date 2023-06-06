#include <iostream>
#include"figuras.h"
#include"triangulo.h"
#include"cuadrado.h"
#include"rectangulo.h"
#include"poligono.h"

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
    char myChar[100];
    int opc=0;
    double num=0;;
    Triangulo t;
    Cuadrado c;
    Rectangulo r;
    Poligono p;

    cout<<"MENU "<<endl;
    cout<<"1. Triangulo"<<endl;
    cout<<"2. Cuadrado"<<endl;
    cout<<"3. Rectangulo"<<endl;
    cout<<"4. Poligono"<<endl;
    cout<<"5. Salir"<<endl;
    cin>>myChar;
        if(validacion(myChar)){
        opc=atoi(myChar);
        }
    switch(opc){
        case 1:{
            cout<<"Ingrese la base del triangulo: "<<endl;
            cin>>myChar;
                    if(validacion(myChar))
                        {
                        num=atof(myChar);
                        t.setBase(num);
                        }else{
                        cout<<"Ingrese un caracter valido"<<endl;
                        system("pause");
                        return main();
                        }

                        cout<<"Ingrese la altura del triangulo: "<<endl;
                        cin>>myChar;
                    if(validacion(myChar))
                        {
                        num=atof(myChar);
                        t.setAltura(num);
                        t.CalcularArea();
                        cout<<"El area del triangulo es: "<<t.getArea()<<endl;}
                        else{cout<<"Ingrese un caracter valido"<<endl;
                        system("pause");
                        return main();
                        }
                        break;
                    }
        case 2:{
            cout<<"Ingrese la medida de un lado del cuadrado: "<<endl;
            cin>>myChar;
            if(validacion(myChar))
            {
                num=atof(myChar);
                c.setLado(num);
                c.CalcularArea();
            cout<<"El area del cuadrado es: "<<c.getArea()<<endl;}
            else{cout<<"Ingrese un caracter valido"<<endl;
            system("pause");
            return main();
            }
            break;
            }
        case 3:{
            cout<<"Ingrese la base del rectangulo: "<<endl;
            cin>>myChar;
            if(validacion(myChar)){
                num=atof(myChar);
                r.setBase(num);
            }else{
                cout<<"Ingrese un caracter valido"<<endl;
                system("pause");
                return main();
            }
            cout<<"Ingrese la altura del rectangulo: "<<endl;
            cin>>myChar;
            if(validacion(myChar)){
                num=atof(myChar);
                r.setAltura(num);
                r.CalcularArea();
            }else{
                cout<<"Ingrese un caracter valido"<<endl;
                system("pause");
                return main();
            }
            cout<<"El area del rectangulo es: "<<r.getArea()<<endl;
            break;
        }
        case 4:{
            cout<<"Ingrese el numero de lados del poligono: "<<endl;
            cin>>myChar;
            if(validacion(myChar)){
               num=atof(myChar);
               }else{
                   cout<<"Ingrese un numero valido"<<endl;
                    system("pause");
                   return main();
               }
            if(num<4){
                cout<<"No puede ingresar un poligono menor a 5 lados"<<endl;
            }else{
            p.setLados(num);
            cout<<"Ingrese la medida de un lado del poligono: "<<endl;
            cin>>num;
            }
            p.setMedidaLados(num);
            p.CalcularPerimetro();
            p.CalcularApotema();
            p.CalcularArea();
            cout<<"El apotema del poligono es: "<<p.getApotema()<<endl;
            cout<<"El area del poligono es: "<<p.getArea()<<endl;
            break;
            }
            case 5:{
                cout<<"Saliendo del programa..."<<endl;
            break;
            }
    }
}

char myChar2[100];
int op=0;
int main(){
    do{
        system("cls");
        menu();
        cout<<"\n1) Continuar\n2) Salir\n";
        cin>>myChar2;
        if(validacion(myChar2))
        {
        op=atoi(myChar2);
        }
        else{
        cout<<"Ingrese un caracter valido"<<endl;
        system("pause");
        return main();
        }
    }while(op!= 2);
return 0;
}


