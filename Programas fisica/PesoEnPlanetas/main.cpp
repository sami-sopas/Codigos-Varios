#include <iostream>
#include "Calculator.h"

using namespace std;

void displayMenu();

int main()
{
    displayMenu();
    return 0;
}

void displayMenu()
{
    unsigned int opc;
    float mass;
    Calculator calculator;

    do
    {
        system("cls");

        cout << "\t CONOCE TU PESO EN OTROS PLANETAS !!! \n"
             << "------------------------------------------------- \n\n"
             << "Escribe tu masa en Kg \n" << endl;
        cin >> mass;

        cout << "\t SELECCIONA UN PLANETA \n"
             << "-------------------------------------\n\n"
             << "[1] Mercurio \n"
             << "[2] Venus \n"
             << "[3] Tierra \n"
             << "[4] Marte \n"
             << "[5] Jupiter \n"
             << "[6] Saturno \n"
             << "[7] Urano \n"
             << "[8] Mercurio \n"
             << "[9] Salir \n" << endl;

        cin >> opc;

        switch(opc)
        {
            case 1:
                cout << "\nTu peso en Mercurio es de: " << calculator.weightMercury(mass) << " Newtons" << endl;
                break;

            case 2:
                cout << "\nTu peso en Venus es de: " << calculator.weightVenus(mass) << " Newtons" << endl;
                break;

            case 3:
                cout << "\nTu peso en La Tierra es de: " << calculator.weightEarth(mass) << " Newtons" << endl;
                break;

            case 4:
                cout << "\nTu peso en Marte es de: " << calculator.weightMars(mass) << " Newtons" << endl;
                break;

            case 5:
                cout << "\nTu peso en Jupiter es de: " << calculator.weightJupiter(mass) << " Newtons" << endl;
                break;

            case 6:
                cout << "\nTu peso en Saturno es de: " << calculator.weightSaturn(mass) << " Newtons" << endl;
                break;

            case 7:
                cout << "\nTu peso en Urano es de: " << calculator.weightUranus(mass) << " Newtons" << endl;
                break;

            case 8:
                cout << "\nTu peso en Mercurio es de: " << calculator.weightMercury(mass) << " Newtons" << endl;
                break;

            case 9:
                cout << "\nSaliendo del programa...." << endl;
                break;

            default:
                cout << "\nEsa opcion no existe ! " << endl;
                break;
        }


        cout << "\n";
        system("pause");
    }while(opc != 9);
}
