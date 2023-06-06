//
// Created by Miguel on 09/02/2023.
//

#ifndef PROYECTO1_CONVERTER_H
#define PROYECTO1_CONVERTER_H

#include <map>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Converter {
private:
    map<int, char> hexadecimalValues;
    map<char, int> hexadecimalValuesInChar;


    int* charToInteger(const char* value) {
        int* returnVal = (int*) malloc(sizeof(int));
        string aux;
        if (hexadecimalValuesInChar.count(*value) != 0) {
            *returnVal = hexadecimalValuesInChar[*value];
        } else {
            aux += *value;
            *returnVal = stoi(aux);
        }
        return returnVal;
    }


public:

    string *decimalBaseToOtherBaseConverter(int *value, const int *base) {
        int *coefficient = (int *) malloc(sizeof(int));
        int *remainder = (int *) malloc(sizeof(int));
        auto *newBaseNumber = new string();
        bool negative = *value < 0;
        if (negative) {
            *value *= -1;
        }
        while (*value / *base > 0) {
            *coefficient = *value / *base;
            *remainder = *value % *base;
            *value = *coefficient;
            if (*remainder >= 10) {
                *newBaseNumber += hexadecimalValues[*remainder];
            } else {
                *newBaseNumber += to_string(*remainder);
            }
        }

        if (*value >= 10) {
            *newBaseNumber += hexadecimalValues[*value];
        } else {
            *newBaseNumber += to_string(*value);
        }
        if (negative) {
            *newBaseNumber += '-';
        }
        reverse(newBaseNumber->begin(), newBaseNumber->end());
        return newBaseNumber;
    }

    int *otherBaseToDecimalBaseConverter(string *value, const int *originBase) {
        int *decimalBaseNumber = (int *) malloc(sizeof(int));
        int power = 0;
        char curr;
        *decimalBaseNumber = 0;

        for (int i = (int) value->size() - 1; i >= 0; i--) {
            if (value->at(i) != '-') {
                curr = value->at(i);
                *decimalBaseNumber += *charToInteger(&curr) * (int) (pow(*originBase, power));
            } else {
                *decimalBaseNumber *= -1;
            }
            power++;
        }

        return decimalBaseNumber;
    }

    Converter() {
        hexadecimalValues[10] = 'a';
        hexadecimalValues[11] = 'b';
        hexadecimalValues[12] = 'c';
        hexadecimalValues[13] = 'd';
        hexadecimalValues[14] = 'e';
        hexadecimalValues[15] = 'f';

        hexadecimalValuesInChar['a'] = 10;
        hexadecimalValuesInChar['b'] = 11;
        hexadecimalValuesInChar['c'] = 12;
        hexadecimalValuesInChar['d'] = 13;
        hexadecimalValuesInChar['e'] = 14;
        hexadecimalValuesInChar['f'] = 15;
    }

};


#endif //PROYECTO1_CONVERTER_H
