#include "calculator.h"

using namespace std;

Calculator::Calculator() { }

void Calculator::parabolicShot()
{
    cout << "Dame la cantidad de segundos" << endl;
    cin >> time;
    cout << "Dame la velocidad inicial " << endl;
    cin >> initialVelocity;
    cout << "Dame los grados " << endl;
    cin >> grades;

    //Operations

    for(int i = 1; i <= time; i++){
    distanceX = initialVelocity * i * cos((grades*Pi/180));
    distanceY = (-0.5)*g * pow(i,2) + initialVelocity * i * sin((grades*Pi/180));
    velocityX = initialVelocity * cos((grades*Pi/180));
    velocityY = -g * i + initialVelocity * sin((grades*Pi/180));

    cout << endl;
    cout << "Distancia en X: " << distanceX << " m" << endl;
    cout << "Distancia en Y: " << distanceY << " m" << endl;
    cout << "Velocidad en X: " << velocityX << " m/s" << endl;
    cout << "Velocidad en Y: " << velocityY << " m/s" << endl;
    }



    cout << endl;
    system("pause");
}

void Calculator::freeFall()
{
    cout << "Ingrese la distancia" << endl;
    cin >> distance;

    //Operations
    finalTime = sqrt((2*distance)/g);
    finalVelocity = g * finalTime;

    cout << endl;
    cout << "Tiempo final: " << finalTime << " s" << endl;
    cout << "Velocidad final: " << finalVelocity << " m/s" << endl;

    system("pause");
}

void Calculator::calcTime()
{
    cout << "Escriba la distancia en metros" << endl;
    cin >> finalDistance;
    cout << "Escriba la velocidad final en m/s" << endl;
    cin >> finalVelocity;

    //Operations
    initialVelocity = 0;
    initialTime = 0;

    finalTime = (2*finalDistance) / finalVelocity;
    aceleration = (finalVelocity-initialVelocity) / (finalTime -initialTime);
    gforces = aceleration / g;

    cout << endl;
    cout << "Aceleracion: " << aceleration << " m/s2" << endl;
    cout << "Tiempo final: " << finalTime << " s" << endl;
    cout << "Fuerzas g: " << gforces << " g" << endl;

    cout << endl;
    system("pause");
}
