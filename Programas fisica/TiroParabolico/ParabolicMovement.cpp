#include "ParabolicMovement.h"

using namespace std;

ParabolicMovement::ParabolicMovement() { }

float ParabolicMovement::flightTime(const float& initialVelocity, const float& grades)
{
    float result;

    result = (2 * initialVelocity * sin((grades*Pi/180))) / G;

    return result;
}

float ParabolicMovement::reach(const float& initialVelocity, const float& grades)
{
    float result;

    result = (pow(initialVelocity,2) / G) * sin(((2 * grades) * Pi / 180));

    return result;
}

float ParabolicMovement::maxHeight(const float& initialVelocity, const float& grades)
{
    float result;

    result = (initialVelocity * initialVelocity) * (sin(grades*Pi/180) * sin(grades*Pi/180)) / (2 * G);

    return result;

}

void ParabolicMovement::table(const int& time, const float& initialVelocity, const float& grades)
{

    for(int i = 1; i <= time; i++){
    distanceX = initialVelocity * i * cos((grades*Pi/180));
    distanceY = (-0.5)*G * pow(i,2) + initialVelocity * i * sin((grades*Pi/180));
    velocityX = initialVelocity * cos((grades*Pi/180));
    velocityY = -G * i + initialVelocity * sin((grades*Pi/180));

    cout << endl;
    cout << "Distancia en X: " << distanceX << " m" << endl;
    cout << "Distancia en Y: " << distanceY << " m" << endl;
    cout << "Velocidad en X: " << velocityX << " m/s" << endl;
    cout << "Velocidad en Y: " << velocityY << " m/s" << endl;
    cout << endl;
    }
}




