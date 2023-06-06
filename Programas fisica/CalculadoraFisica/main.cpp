#include <iostream>
#include "calculator.h"

using namespace std;

void displayMenu();

int main()
{
    displayMenu();

    return 0;
}

void displayMenu()
{
    Calculator calculator; //Instance
    int opc;

    do{
        system("cls");

        cout << "CALCULADORA \n"
             << "1) Tiro Parabolico \n"
             << "2) Caida Libre \n"
             << "3) Calcular tiempo \n";
            cin >> opc;

            switch(opc)
            {
                case 1: //Tiro Parabolico
                    calculator.parabolicShot();
                break;

                case 2: //Caida libre
                    calculator.freeFall();
                break;

                case 3:
                    calculator.calcTime();
                break;


            }

    }while(opc!=5);
}
