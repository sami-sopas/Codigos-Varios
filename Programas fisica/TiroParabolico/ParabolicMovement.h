#ifndef PARABOLICMOVEMENT_H_INCLUDED
#define PARABOLICMOVEMENT_H_INCLUDED
#include"math.h"
#include<iostream>

class ParabolicMovement
{
    private:
        const float G = 9.81;
        const float Pi = 3.14;

        float acelerationX,velocityX,distanceX; //on the x-xis (MRU)
        float aceletarionY,velocityY,distanceY; //on the y-xsis (MUA)

    public:
        ParabolicMovement(); //ctrot

               //recibe velocidad inicial y angulo
        float flightTime(const float&,const float&); //Retorna el tiempo de vuelo

              //recibe velocida inicial y angulo
        float reach(const float&,const float&); //Retorna el alcanze maximo alcanzado

             //recibe velocidad inicial y angulo
        float maxHeight(const float&,const float&); //Retorna la altura maxima alcanzada

            //recibe segundos, velocidad inicial y angulo
        void table(const int&,const float&,const float&); //Imprime los datos pasando x segundos


};


#endif // PARABOLICMOVEMENT_H_INCLUDED
