#include "student.h"

using namespace std;

void Student::setName(Name& alum) {
    string aux = alum.getFirstName();
    propio.setFirstName(aux);

    string aux2 = alum.getLastName();
    propio.setLastName(aux2);
}

void Student::setCode(const int& cd) {
    code = cd;
}

void Student::setCarrer(const string& cr) {
    carrer = cr;
}

void Student::setEmail(const string& em) {
    email = em;
}

void Student::setStats(const char& s) {
    stats = s;
}

void Student::setProm(const float& pm) {
    prom = pm;
}

Name Student::getName() {
    return propio;
}

int Student::getCode() {
    return code;
}

string Student::getCarrer() {
    return carrer;
}

string Student::getEmail() {
    return email;
}

char Student::getStats() {
    return stats;
}

float Student::getProm() {
    return prom;
}
