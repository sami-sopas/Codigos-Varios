//decimal a hexadecimal otro ejemplo
#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

int *ptr=NULL;
int decimal, n;
void conversion(int);

int main(int argc, char** argv){
	
    system("cls");
	cout << "Ingresa un numero: ";
	cin>> decimal;
	ptr=&decimal;
	conversion(*ptr);
	return 0;
}

void conversion(int n){

		string NumeroHexadecimal="";
		char hexa[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
        while(decimal>0)
        {
            n = decimal % 16;
            NumeroHexadecimal = hexa[n] + NumeroHexadecimal;
            decimal = decimal/16;
        }
        cout<<"\nEl numero en hexadecimal es: "<<NumeroHexadecimal<<endl; 
	}

	


