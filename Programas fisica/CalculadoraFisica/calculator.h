#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED
#include<iostream>
#include<math.h>

#define Pi 3.14159265
#define g 9.81

class Calculator{

    private:
        /** Atributes **/

        /** Variables for parametric equations (Parabolic Shot) **/
        int time;
        float grades,initialVelocity;
        float acelerationX,velocityX,distanceX; //on the x-xis (MRU)
        float aceletarionY,velocityY,distanceY; //on the y-xsis (MUA)

        /** Variables for free fall **/
        float finalVelocity,distance,finalTime;

        /** Variables for MUA **/
        long double aceleration,mass,initialDistance,finalDistance,velocity,initialTime,gforces;

    public:
        /** Methods **/
        Calculator();

        void parabolicShot();
        void freeFall();
        void calcTime();



};

#endif // CALCULATOR_H_INCLUDED
