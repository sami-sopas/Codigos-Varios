#include <iostream>

using namespace std;

int mayor(int*);
int vector[] = {78, 5, 7, 9, 20, 15};

int main(){
    int* ptr;
    ptr = &vector[0];
    int numMayor = mayor(ptr);

    cout<<"El numero mayor es: "<<numMayor<<endl;

    return 0;
}

int mayor(int* p){
    int aux = *p;

    for(int i(1); i < 6; i++)
        if(p[i] > aux)
            aux = p[i];

    return aux;
}
