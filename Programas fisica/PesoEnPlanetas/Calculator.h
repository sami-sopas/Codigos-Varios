#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

class Calculator
{
    private:
        //Gravity forces
        const float Gmercury = 3.7;
        const float Gvenus = 8.87;
        const float Gearth = 9.8;
        const float Gmars = 3.71;
        const float Gjupiter = 24.79;
        const float Gsaturn = 10.44;
        const float Guranus = 8.87;
        const float Gneptune = 11.15;

    public:
        Calculator();

        //Return the weight, receives the mass
        const float weightMercury(const float&);
        const float weightVenus(const float&);
        const float weightEarth(const float&);
        const float weightMars(const float&);
        const float weightJupiter(const float&);
        const float weightSaturn(const float&);
        const float weightUranus(const float&);
        const float weightNeptune(const float&);
};
#endif // CALCULATOR_H_INCLUDED
