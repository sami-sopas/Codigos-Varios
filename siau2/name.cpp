#include "name.h"

void Name::setFirstName(const string& dato) {
    firstName = dato;
}

void Name::setLastName(const string& dato) {
    lastName = dato;
}

string Name::getFirstName() {
    return firstName;
}

string Name::getLastName() {
    return lastName;
}
