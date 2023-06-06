#include <iostream>

 using namespace std;

 int* Suma(int*, int*);
 int* Resta(int*, int*);
 int* Multiplicacion(int*, int*);
 int* Division(int*, int*);

 int main(){
    char op;
    int num1, num2;
    int* num1ptr(nullptr);
    int* num2ptr(nullptr);

    do{
        cout<<"-------------"<<endl;
        cout<<"MENU. Escoje."<<endl<<"a. Suma."<<endl<<"b. Resta."<<endl<<"c. Multiplicacion"<<endl<<"d. Division"<<endl<<"e. Salir."<<endl;
        cout<<"-------------"<<endl;
        fflush(stdin); cin>>op;

        if(op != 'e'){
            cout<<endl<<"Ingrese el primer numero: ";
            fflush(stdin); cin>>num1;
            num1ptr = &num1;

            cout<<endl<<"Ingrese el segundo numero: ";
            fflush(stdin); cin>>num2;
            num2ptr = &num2;
        }

        switch(op){
            case 'a': cout<<*Suma(num1ptr, num2ptr)<<endl;  break;
            case 'b': cout<<*Resta(num1ptr, num2ptr)<<endl;  break;
            case 'c': cout<<*Multiplicacion(num1ptr, num2ptr)<<endl;  break;
            case 'd': cout<<*Division(num1ptr, num2ptr)<<endl;  break;
            case 'e': break;
            default: cout<<endl<<"Opcion incorrecta. Vuelve a intentarlo..."<<endl;
        }


    }while(op != 'e');

    return 0;
 }

int* Suma(int* n1, int* n2){
    int* aux = new int;

    *aux = *n1 + *n2;

    return aux;
}

int* Resta(int* n1, int* n2){
    int* aux = new int;

    *aux = *n1 - *n2;

    return aux;
}

int* Multiplicacion(int* n1, int* n2){
    int* aux = new int;

    *aux = *n1 * *n2;

    return aux;
}

int* Division(int* n1, int* n2){
    int* aux = new int;

    *aux = *n1 / *n2;

    return aux;
}
