/*Desarrollé un programa que encuentre el número mayor en un
arreglo de punteros*/

#include <iostream>

using namespace std;

int mayor (int *num);
int vector[]={78,5,7,9,20,15};

int main() {
int *pv;
pv = vector;
int m = mayor(pv);
cout<<"El numero mayor es:" << m;
return 0;
}

int mayor(int *num) {
int may = *num;
for(int i=1; i<6; i++) {
if(*num > may)
may=*num;
}
return may;
}
