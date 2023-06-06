#ifndef NAME_H_INCLUDED
#define NAME_H_INCLUDED

#include <string>

using namespace std;

class Name{
///Atributos
private:
    string firstName;
    string lastName;
/// Metodos
public:
    void setFirstName(const string&);
    void setLastName(const string&);

    string getFirstName();
    string getLastName();
};

#endif // NAME_H_INCLUDED
