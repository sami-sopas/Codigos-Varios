#include <iostream>
#include "ParabolicMovement.h"
using namespace std;

void displayMenu();

int main()
{
    displayMenu();
    return 0;
}

void displayMenu()
{
    short unsigned int opc(0);
    unsigned int time;
    ParabolicMovement pm;
    float grades, initialVelocity;

    do{
        system("cls");

        cout << "\t CALCULADORA DE TIRO PARABOLICO \n"
             << "-------------------------------------------------\n\n"
             << "Escribe la velocidad inicial: ";
         cin >> initialVelocity;

        cout << "\nEscribe los grados del angulo: ";
         cin >> grades;

        cout << "\nEscribe el tiempo transcurrido a calcular ";
         cin >> time;

        cout << "\tResultados...\n"
            << "--------------------------\n\n";

        cout << "Tiempo de vuelo: " << pm.flightTime(initialVelocity,grades) << endl;

        cout << endl;

        cout << "Alcanze: " << pm.reach(initialVelocity,grades) << endl;

        cout << endl;

        cout << "Altura maxima: " << pm.maxHeight(initialVelocity,grades) << endl;

        cout << endl;

        cout << "\nTabla de valores\n";

        pm.table(time,initialVelocity,grades);

        cout << "\n\n"
             << "[1] Ingresar nuevos valores\n"
             << "[2] Salir\n";
         cin >> opc;

        system("pause");
    }while(opc != 2);


}
