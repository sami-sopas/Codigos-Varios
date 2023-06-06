#include <iostream>
#include <string>
#include "student.h"

using namespace std;

int main()
{
    Student marco;
    Name aux;
    string nameAux;

    cout << "Ingrese el nombre: ";
    getline(cin, nameAux);

    aux.setFirstName(nameAux);


    cout << "Ingrese los apellidos: ";
    getline(cin, nameAux);

    aux.setLastName(nameAux);

    marco.setName(aux);

    Name aux3 = marco.getName();

    cout << "El nombre es: " << aux3.getFirstName() << endl;

    marco.setCarrer("INNI");

    cout << "La carrera es: " << marco.getCarrer() << endl;

    return 0;
}
