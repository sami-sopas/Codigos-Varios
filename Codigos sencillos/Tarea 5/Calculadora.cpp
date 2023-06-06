#include <iostream>
#include <string>
#include <math.h>

using namespace std;

void pedir2numeros(char);
string suma(int*, int*);
string resta(int*, int*);
string multiplicacion(int*, int*);
string division(int*, int*);
string potencia(int*, int*);

string factorial();

void pedirnumero(char);
void DecimalABinario(int*);
void DecimalAOctal(int*);
void DecimalAHexadecimal(int*);
void digitos(int);

double* BinarioADecimal();
int* OctalADecimal();
int* HexadecimalADecimal();

int main(){
    char op;

    do{
        cout<<endl<<"------------------------------"<<endl;
        cout<<"Selecciona una opcion."<<endl<<endl;
        cout<<"a. Suma."<<endl<<"b. Resta."<<endl<<"c. Multiplicacion."<<endl<<"d. Division."<<endl<<"e. Potencia."<<endl<<"f. Factorial."<<endl<<"g. Decimal -> Binario."<<endl<<"h. Binario -> Decimal."<<endl<<"i. Decimal -> Octal."<<endl<<"j. Octal -> Decimal."<<endl<<"k. Decimal -> Hexadecimal."<<endl<<"l. Hexadecimal -> Decimal."<<endl<<"m. SALIR.";
        cout<<endl<<"------------------------------"<<endl;
        cin>>op;

        switch(op){
            case 'a': case 'A': case 'b': case 'B': case 'c': case 'C': case 'd': case 'D': case 'e': case 'E': pedir2numeros(op); break;
            case 'f': case 'F': cout<<factorial()<<endl;   break;
            case 'g': case 'G': case 'i': case 'I': case 'k': case 'K': pedirnumero(op);    break;
            case 'h': case 'H': cout<<*BinarioADecimal()<<endl;  break;
            case 'j': case 'J': cout<<*OctalADecimal()<<endl;   break;
            case 'l': case 'L': cout<<*HexadecimalADecimal()<<endl; break;
            case 'm': case 'M': break;
            default: cout<<"Opcion incorrecta. Vuelve a intentarlo"<<endl;
        }
    }while(op != 'm');

    return 0;
}

void pedir2numeros(char op){
    int *num1, *num2;
    int aux1, aux2;

    cout<<endl<<"Teclea el primer numero: ";
    cin>>aux1;
    cout<<"Teclea el segundo numero: ";
    cin>>aux2;

    num1 = &aux1;
    num2 = &aux2;

    switch(op){
        case 'a': case 'A': cout<<suma(num1, num2)<<endl;   break;
        case 'b': case 'B': cout<<resta(num1, num2)<<endl;  break;
        case 'c': case 'C': cout<<multiplicacion(num1, num2)<<endl; break;
        case 'd': case 'D': cout<<division(num1, num2)<<endl;   break;
        case 'e': case 'E': cout<<potencia(num1, num2)<<endl;   break;
    }
}

string suma(int* num1, int* num2){
    return "La suma es igual a: " + to_string(*num1 + *num2);
}

string resta(int* num1, int* num2){
    return "La resta es igual a: " + to_string(*num1 - *num2);
}

string multiplicacion(int* num1, int* num2){
    return "El producto es igual a: " + to_string(*num1 * *num2);
}

string division(int* num1, int* num2){
    return "La division es igual a: " + to_string(*num1 / *num2);
}

string potencia(int* num1, int* num2){
    return "La potencia es igual a: " + to_string(pow(*num1, *num2));
}

string factorial(){
    int num;
    float acum(1);

    cout<<"Teclea numero: ";
    cin>>num;

    for(int i(1); i <= num; i++)
        acum *= i;

    return "Factorial de " + to_string(num) + " -> " + to_string(acum);
}

void pedirnumero(char op){
    int* num, aux;

    cout<<"Teclea numero: ";
    cin>>aux;

    num = &aux;

    switch(op){
        case 'g': case 'G': DecimalABinario(num);  break;
        case 'i': case 'I': DecimalAOctal(num);    break;
        case 'k': case 'K': DecimalAHexadecimal(num);  break;
    }

    cout<<"AVISO: Leer de abajo hacia arriba el resultado."<<endl;
}

///Conversiones desde DECIMAL

void DecimalABinario(int* num){
    int cociente(0), residuo(0);

    while(*num / 2 > 0){
        cociente = *num / 2;
        residuo = *num % 2;

        *num = cociente;

        cout<<residuo<<endl;;
    }
    cout<<cociente<<endl;
}

void DecimalAOctal(int* num){
    int cociente(0), residuo(0);

    while(*num / 8 > 0){
        cociente = *num / 8;
        residuo = *num % 8;

        *num = cociente;

        cout<<residuo<<endl;;
    }
    cout<<cociente<<endl;
}

void DecimalAHexadecimal(int* num){
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

///Conversiones a DECIMAL

double* BinarioADecimal(){
    int exp,digito;
    double numbin;
    double* resultado(new double);

    cout<<"Teclea numero BIN: ";
    cin>>numbin;

    exp = 0;
    *resultado = 0;
    while(((int)(numbin / 10)) != 0){
        digito = (int)numbin % 10;
        *resultado += digito * pow(2.0,exp);
        exp++;
        numbin = (int)(numbin / 10);
    }
   *resultado += numbin * pow(2.0,exp);

   return resultado;
}

int* OctalADecimal(){
    int* resultado(new int);
    int num, rem;

    cout<<"Teclea numero OCT: ";
    cin>>num;

    *resultado = 0;

    for(int i(0); num != 0; i++){
        rem = num % 10;
        num /= 10;
        *resultado += rem * pow(8, i);
    }

    return resultado;
}

int* HexadecimalADecimal(){
    int* resultado (new int);
    char num[10];

    cout<<"Teclea numero HEX (solo mayusculas): ";
    cin>>num;

    *resultado = 0;

    int base(1);
    for(int i(9); i >= 0; i--)
        if(num[i] >= '0' and num[i] <= '9'){
            *resultado += (num[i] - 48) * base;
            base *= 16;
        }else if(num[i] >= 'A' and num[i] <= 'F'){
            *resultado += (num[i] - 55) * base;
            base *= 16;
        }

    return resultado;
}
