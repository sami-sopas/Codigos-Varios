#include <iostream>
#include <string>

using namespace std;

void Binario(int*);

int main(){
    int* num;
    int a;

    cout<<"Ingresa un numero: ";
    cin>>a;

    num = &a;
    Binario(num);

    return 0;
}

void Binario(int* num){
    int cociente(0), residuo(0);

    while(*num / 2 > 0){
        cociente = *num / 2;
        residuo = *num % 2;

        *num = cociente;

        cout<<residuo;
    }
    cout<<cociente;
}
