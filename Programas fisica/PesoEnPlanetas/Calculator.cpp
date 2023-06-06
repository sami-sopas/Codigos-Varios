#include"Calculator.h"

Calculator::Calculator() { }


const float Calculator::weightMercury(const float& mass)
{
    return mass * Gmercury;
}

const float Calculator::weightVenus(const float& mass)
{
    return mass * Gvenus;
}

const float Calculator::weightEarth(const float& mass)
{
    return mass * Gearth;
}

const float Calculator::weightMars(const float& mass)
{
    return mass * Gmars;
}

const float Calculator::weightJupiter(const float& mass)
{
    return mass * Gjupiter;
}

const float Calculator::weightSaturn(const float& mass)
{
    return mass * Gsaturn;
}

const float Calculator::weightUranus(const float& mass)
{
    return mass * Guranus;
}

const float Calculator::weightNeptune(const float& mass)
{
    return mass * Gneptune;
}

