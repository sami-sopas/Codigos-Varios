//
// Created by Migue on 09/02/2023.
//

#ifndef PROYECTO1_VERIFIER_H
#define PROYECTO1_VERIFIER_H

#include <string>
#include <set>
#include <map>

using namespace std;

class Verifier {
private:
    set<char> hexValues;
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

    static bool isOverflow(int a, int b){
        int* result = (int*) malloc(sizeof(int));
        *result = a + b;
        if(a > 0 and b > 0 and *result < 0)
            return true;
        if(a < 0 and b < 0 and *result > 0)
            return true;
        return false;
    }

    static bool isUnderflow(const int* a,const int* b) {
        return (*b < 0) && (*a > std::numeric_limits<int>::max() + *b);
    }

    bool* withinLimits(string*& number, const int* originBase) {
        bool* ans = (bool*) malloc(sizeof (bool));
        *ans = true;
        int sum = 0;
        int power = 0;

        if (number->at(0) == '-') {
            for (int i = (int) number->size() - 1; i >= 1; i--) {
                char curr = number->at(i);
                int next = *charToInteger(&curr) * (int) (pow(*originBase, power));
                if (isUnderflow(&sum, &next)) {
                    *ans = false;
                    break;
                }
                sum -= next;
                power++;
            }
        } else {
            for (int i = (int) number->size() - 1; i >= 0; i--) {
                char curr = number->at(i);
                int next = *charToInteger(&curr) * (int) (pow(*originBase, power));
                if (isOverflow(sum, next)) {
                    *ans = false;
                    break;
                }
                sum += next;
                power++;
            }
        }
        return ans;
    }


public:
    Verifier() {
        for (char c = '0'; c <= '9'; c++) {
            hexValues.insert(c);
        }

        for (char c = 'a'; c <= 'f'; c++) {
            hexValues.insert(c);
        }
        hexadecimalValuesInChar['a'] = 10;
        hexadecimalValuesInChar['b'] = 11;
        hexadecimalValuesInChar['c'] = 12;
        hexadecimalValuesInChar['d'] = 13;
        hexadecimalValuesInChar['e'] = 14;
        hexadecimalValuesInChar['f'] = 15;
    }

     bool *binaryVerifier(string *binaryValue) {
        bool *good = (bool *) malloc(sizeof(bool));
        *good = true;
        int base = 2;
        bool negative = !(binaryValue->empty()) and binaryValue->at(0) == '-';
        if (negative) {
            for (int i = 1; i < binaryValue->size(); i++) {
                if (binaryValue->at(i) != '0' and binaryValue->at(i) != '1') {
                    *good = false;
                }
            }
            if (binaryValue->size() == 1) *good = false;

        } else {
            for (char i: *binaryValue) {
                if (i != '0' and i != '1') {
                    *good = false;
                }
            }
        }
        if (binaryValue->empty()) {
            *good = false;
        } else if(*good){
            *good = *withinLimits(binaryValue, &base);
        }

        return good;
    }

     bool *octalVerifier(string *octalValue) {
        bool *good = (bool *) malloc(sizeof(bool));
        *good = true;
        int base = 8;
        bool negative = !(octalValue->empty()) and octalValue->at(0) == '-';
        if (negative) {
            for (int i = 1; i < octalValue->size(); i++) {
                if (octalValue->at(i) < '0' or octalValue->at(i) > '7') {
                    *good = false;
                }
            }
            if (octalValue->size() == 1) *good = false;
        } else {
            for (char i: *octalValue) {
                if (i < '0' or i > '7') {
                    *good = false;
                }
            }
        }
        if (octalValue->empty()) {
            *good = false;
        } else if (*good) {
            *good = *withinLimits(octalValue, &base);
        }
        return good;
    }

    bool *hexadecimalVerifier(string *hexValue) {
        bool *good = (bool *) malloc(sizeof(bool));
        *good = true;
        int base = 16;
        bool negative = !(hexValue->empty()) and hexValue->at(0) == '-';
        if (negative) {
            for (int i = 1; i < hexValue->size(); i++) {
                if (hexValues.count(hexValue->at(i)) == 0) {
                    *good = false;
                }
            }

            if (hexValue->size() == 1) *good = false;

        } else {
            for (char i: *hexValue) {
                if (hexValues.count(i) == 0) {
                    *good = false;
                }
            }
        }
        if (hexValue->empty()){
            *good = false;
        } else if (*good) {
            *good = *withinLimits(hexValue, &base);
        }
        return good;
    }

     static bool *isANumber(string *number, const int *pointsAllowed) {
        bool *good = (bool *) malloc(sizeof(bool));
        bool negative = !(number->empty()) and number->at(0) == '-';
        int points = 0;
        *good = true;
        if (negative) {
            if (number->size() == 1) *good = false;
            for (int i = 1; i < number->size(); i++) {
                if (number->at(i) == '.') {
                    points++;
                    continue;
                }
                if ((number->at(i) < '0' or number->at(i) > '9')) {
                    *good = false;
                }
            }
        } else {
            for (char i: *number) {
                if (i == '.') {
                    points++;
                    continue;
                }
                if ((i < '0' or i > '9')) {
                    *good = false;
                }
            }
        }

        if (points > *pointsAllowed) *good = false;
        if (number->empty()) *good = false;
        return good;
    }



};

#endif //PROYECTO1_VERIFIER_H
