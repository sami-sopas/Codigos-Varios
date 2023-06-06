#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include "name.h"

class Student{
/// Atributos
private:
    Name propio;
    int code;
    string carrer;
    string email;
    char stats;
    float prom;
/// Metodos
public:
    void setName(Name&);
    void setCode(const int&);
    void setCarrer(const string&);
    void setEmail(const string&);
    void setStats(const char&);
    void setProm(const float&);

    Name getName();
    int getCode();
    string getCarrer();
    string getEmail();
    char getStats();
    float getProm();
};

#endif // STUDENT_H_INCLUDED
