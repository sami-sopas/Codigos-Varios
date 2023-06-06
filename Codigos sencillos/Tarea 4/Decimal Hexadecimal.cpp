#include <iostream>

using namespace std;

void Hexadecimal(int*);
void digitos(int);

int main(){
    int* num;
    int a;

    cout<<"Ingresa un numero: ";
    cin>>a;

    num = &a;
    Hexadecimal(num);

    return 0;
}

void Hexadecimal(int* num){
    int cociente(0), residuo(0);
    while(*num / 16 > 0){
        cociente = *num / 16;
        residuo = *num % 16;
        *num = cociente;
        digitos(residuo);
    }
    digitos(cociente);
}

void digitos(int numero){
    switch(numero){
        case 0: cout<<"0"<<endl;  break;
        case 1: cout<<"1"<<endl;  break;
        case 2: cout<<"2"<<endl;  break;
        case 3: cout<<"3"<<endl;  break;
        case 4: cout<<"4"<<endl;  break;
        case 5: cout<<"5"<<endl;  break;
        case 6: cout<<"6"<<endl;  break;
        case 7: cout<<"7"<<endl;  break;
        case 8: cout<<"8"<<endl;  break;
        case 9: cout<<"9"<<endl;  break;
        case 10: cout<<"A"<<endl;  break;
        case 11: cout<<"B"<<endl;  break;
        case 12: cout<<"C"<<endl;  break;
        case 13: cout<<"D"<<endl;  break;
        case 14: cout<<"E"<<endl;  break;
        case 15: cout<<"F"<<endl;  break;
    }
}
