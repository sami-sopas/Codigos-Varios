//Samuel Osvaldo Ramirez Cuenca Actividad 5
#include <iostream>
#include <cstdlib>

using namespace std;

int *ptr1=NULL;
void decimal_binario(int*);
int n1=0;

int main(int argc, char** argv) {
system("cls");
cout<<"ingrese numero 1"<<endl;
cin>>n1;
ptr1=&n1;
decimal_binario(ptr1);
return 0;
}

void decimal_binario(int*){
int binario[10];
int i = 0; 
    while (n1>0) {
 
        binario[i] = n1%2;
        n1 = n1/2;
        i++;
    }
    
for (int j=i-1;j>=0;j--) //Funcion para imprimir al revez
        cout<<binario[j];
}


