#include <iostream>
#include <cstdlib>
#include <limits>
#include "Converter.h"
#include "Calculator.h"
#include "Verifier.h"

#ifdef WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define SUM 1
#define SUB 2
#define MULTIPLY 3
#define DIVIDE 4
#define PERCENTAGE 5
#define POWER_OF_2 6
#define FACTORIAL 7
#define POWER 8
#define SQUARE_ROOT 9
#define COSINE 10
#define SINE 11
#define TANGENT 12
#define DEC_BIN 13
#define BIN_DEC 14
#define DEC_OCT 15
#define OCT_DEC 16
#define DEC_HEX 17
#define HEX_DEC 18
#define BIN_OCT 19
#define OCT_BIN 20
#define BIN_HEX 21
#define HEX_BIN 22
#define EXIT 23

using namespace std;
using ld = long double;

int menu(Verifier*& verifier);

void clearBuffer();

void inputOfTwoRealNumbers(Verifier*& verifier, ld *&a, ld *&b);

void inputOfARealNumber(Verifier*& verifier, ld *&a);

void inputOfAnInteger(Verifier*& verifier, int *&val);

void inputOfALongInt(Verifier*& verifier, long long int *&val);

void inputOfABinaryNumber(Verifier*& verifier, string *&number);

void inputOfAOctalNumber(Verifier*& verifier, string *&number);

void inputOfAHexadecimalNumber(Verifier *&verifier, string *&number);

void sum(ld *a, ld *b);

void sub(ld *a, ld *b);

void mul(ld *a, ld *b);

void divide(ld *a, ld *b);

void percentage(long long int *value, int *wanted);

void power(ld *a);

void factorial(long long int *value);

void power(ld *a, int *p);

void squareRoot(ld *a);

void cosine(ld *a);

void sine(ld *a);

void tangent(ld *a);

void decimalToBinary(Converter *&converter, int *decimalValue);

void binaryToDecimal(Converter *&converter, string *binaryValue);

void decimalToOctal(Converter *&converter, int *decimalValue);

void octalToDecimal(Converter *&converter, string *octalValue);

void decimalToHexadecimal(Converter *&converter, int *decimalValue);

void hexadecimalToDecimal(Converter *&converter, string *hexadecimalValue);

void binaryToOctal(Converter *&converter, string *binaryValue);

void octalToBinary(Converter *&converter, string *octalValue);

void binaryToHexadecimal(Converter *&converter, string *binaryValue);

void hexadecimalToBinary(Converter *&converter, string *hexadecimalValue);

void pause();


int main() {
    ld *a;
    ld *b;
    int opt;
    long long int *longValue;
    int *decimalValue;
    string *valueInOtherBase;
    auto *converter = new Converter();
    auto *verifier = new Verifier();
    a = (ld *) malloc(sizeof(ld));
    b = (ld *) malloc(sizeof(ld));
    longValue = (long long int *) malloc(sizeof(long long int));
    decimalValue = (int *) malloc(sizeof(int));
    do {
        valueInOtherBase = new string();
        opt = menu(verifier);
        switch (opt) {
            case SUM:
                cout << "Tendra que ingresar 2 numeros reales para continuar" << endl;
                pause();
                inputOfTwoRealNumbers(verifier,a, b);
                sum(a, b);
                break;
            case SUB:
                cout << "Tendra que ingresar 2 numeros reales para continuar" << endl;
                pause();
                inputOfTwoRealNumbers(verifier,a, b);
                sub(a, b);
                break;
            case MULTIPLY:
                cout << "Tendra que ingresar 2 numeros reales para continuar" << endl;
                pause();
                inputOfTwoRealNumbers(verifier,a, b);
                mul(a, b);
                break;
            case DIVIDE:
                cout << "Tendra que ingresar 2 numeros reales para continuar" << endl;
                pause();
                inputOfTwoRealNumbers(verifier,a, b);
                divide(a, b);
                break;
            case PERCENTAGE:
                cout << "Tendra que ingresar 2 numeros enteros para continuar" << endl;
                cout << "El valor que se tiene que es el 100% y el porcentaje deseado" << endl;
                pause();
                inputOfALongInt(verifier,longValue);
                inputOfAnInteger(verifier,decimalValue);
                percentage(longValue, decimalValue);
                break;
            case POWER_OF_2:
                cout << "Tendra que ingresar un numero real para continuar" << endl;
                pause();
                inputOfARealNumber(verifier,a);
                power(a);
                break;
            case FACTORIAL:
                cout << "Tendra que ingresar un numero entero para continuar" << endl;
                pause();
                inputOfALongInt(verifier,longValue);
                factorial(longValue);
                break;
            case POWER:
                cout << "Tendra que ingresar un numero real y entero para continuar" << endl;
                pause();
                inputOfARealNumber(verifier,a);
                inputOfAnInteger(verifier,decimalValue);
                power(a, decimalValue);
                break;
            case SQUARE_ROOT:
                cout << "Tendra que ingresar un numero real para continuar" << endl;
                pause();
                inputOfARealNumber(verifier,a);
                squareRoot(a);
                break;
            case COSINE:
                cout << "Tendra que ingresar un numero real para continuar" << endl;
                pause();
                inputOfARealNumber(verifier,a);
                cosine(a);
                break;
            case SINE:
                cout << "Tendra que ingresar un numero real para continuar" << endl;
                pause();
                inputOfARealNumber(verifier,a);
                sine(a);
                break;
            case TANGENT:
                cout << "Tendra que ingresar un numero real para continuar" << endl;
                pause();
                inputOfARealNumber(verifier,a);
                tangent(a);
                break;
            case DEC_BIN:
                cout << "Tendra que ingresar un numero entero para continuar" << endl;
                pause();
                inputOfAnInteger(verifier,decimalValue);
                decimalToBinary(converter, decimalValue);
                break;
            case BIN_DEC:
                cout << "Tendra que ingresar un numero binario para continuar" << endl;
                pause();
                inputOfABinaryNumber(verifier,valueInOtherBase);
                binaryToDecimal(converter, valueInOtherBase);
                break;
            case DEC_OCT:
                cout << "Tendra que ingresar un numero decimal para continuar" << endl;
                pause();
                inputOfAnInteger(verifier, decimalValue);
                decimalToOctal(converter, decimalValue);
                break;
            case OCT_DEC:
                cout << "Tendra que ingresar un numero octal para continuar" << endl;
                pause();
                inputOfAOctalNumber(verifier,valueInOtherBase);
                octalToDecimal(converter, valueInOtherBase);
                break;
            case DEC_HEX:
                cout << "Tendra que ingresar un numero entero para continuar" << endl;
                pause();
                inputOfAnInteger(verifier,decimalValue);
                decimalToHexadecimal(converter, decimalValue);
                break;
            case HEX_DEC:
                cout << "Tendra que ingresar un numero hexadecimal para continuar" << endl;
                pause();
                inputOfAHexadecimalNumber(verifier, valueInOtherBase);
                hexadecimalToDecimal(converter, valueInOtherBase);
                break;
            case BIN_OCT:
                cout << "Tendra que ingresar un numero binario para continuar" << endl;
                pause();
                inputOfABinaryNumber(verifier, valueInOtherBase);
                binaryToOctal(converter, valueInOtherBase);
                break;
            case OCT_BIN:
                cout << "Tendra que ingresar un numero octal para continuar" << endl;
                pause();
                inputOfAOctalNumber(verifier,valueInOtherBase);
                octalToBinary(converter, valueInOtherBase);
                break;
            case BIN_HEX:
                cout << "Tendra que ingresar un numero binario para continuar" << endl;
                pause();
                inputOfABinaryNumber(verifier,valueInOtherBase);
                binaryToHexadecimal(converter, valueInOtherBase);
                break;
            case HEX_BIN:
                cout << "Tendra que ingresar un numero hexadecimal para continuar" << endl;
                pause();
                inputOfAHexadecimalNumber(verifier, valueInOtherBase);
                hexadecimalToBinary(converter, valueInOtherBase);
                break;
            case EXIT:
                system(CLEAR);
                break;
            default:
                cout << "Opcion invalida, intente de nuevo" << endl;
                break;
        }
        pause();
        system(CLEAR);
    } while (opt != EXIT);
    return 0;
}

int menu(Verifier*& verifier) {
    int allowedPoints = 0;
    int opt;
    bool answered = false;
    string answer;
    cout << "1.- Sumar" << endl;
    cout << "2.- Restar" << endl;
    cout << "3.- Multiplicar" << endl;
    cout << "4.- Dividir" << endl;
    cout << "5.- Porcentaje" << endl;
    cout << "6.- Elevar al cuadrado" << endl;
    cout << "7.- Factorial" << endl;
    cout << "8.- Elevar numero" << endl;
    cout << "9.- Raiz cuadrada" << endl;
    cout << "10.- Coseno" << endl;
    cout << "11.- Seno" << endl;
    cout << "12.- Tangente" << endl;
    cout << "13.- Decimal a binario" << endl;
    cout << "14.- Binario a decimal" << endl;
    cout << "15.- Decimal a octal" << endl;
    cout << "16.- Octal a decimal" << endl;
    cout << "17.- Decimal a hexadecimal" << endl;
    cout << "18.- Hexadecimal a decimal" << endl;
    cout << "19.- Binario a octal" << endl;
    cout << "20.- Octal a binario" << endl;
    cout << "21.- Binario a hexadecimal" << endl;
    cout << "22.- Hexadecimal a binario" << endl;
    cout << "23.- Salir" << endl;
    cout << "Que opcion deseas realizar: " << endl;
    while (not answered) {
        getline(cin, answer);
        if (*Verifier::isANumber(&answer, &allowedPoints)) {
            answered = true;
            opt = stoi(answer);
        } else {
            cout << "Entrada invalida, por favor ingrese un numero" << endl;
            cout << "Que opcion deseas realizar: " << endl;
        }
    }
    return opt;
}

void inputOfTwoRealNumbers(Verifier*& verifier,ld *&a, ld *&b) {
    string *number;
    int numbersAdded = 0;
    int pointsAllowed = 1;
    system(CLEAR);
    while (numbersAdded != 2) {
        number = new string();
        cout << "Ingrese un numero: " << endl;
        getline(cin, *number);
        if (*Verifier::isANumber(number, &pointsAllowed)) {
            try {
                if (numbersAdded == 0) {
                    *a = stold(*number);
                } else {
                    *b = stold(*number);
                }
                numbersAdded++;
            } catch(const out_of_range& exception) {
                cout << "El numero es demasiado grande" << endl;
            } catch (const invalid_argument& exception) {
                cout << "Ingrese un real valido" << endl;
            }
        } else {
            cout << "Por favor ingrese un numero" << endl;
        }
    }
}

void inputOfARealNumber(Verifier*& verifier,ld *&a) {
    string *number;
    int numbersAdded = 0;
    int pointsAllowed = 1;
    system(CLEAR);
    while (numbersAdded != 1) {
        number = new string();
        cout << "Ingrese un numero: " << endl;
        getline(cin, *number);
        if (*Verifier::isANumber(number, &pointsAllowed)) {
            try {
                *a = stold(*number);
                numbersAdded++;
            } catch(const out_of_range& exception) {
                cout << "El numero es demasiado grande" << endl;
            } catch(const invalid_argument& except) {
                cout << "Ingrese un real valido" << endl;
            }
        } else {
            cout << "Por favor ingrese un numero" << endl;
        }
    }
}

void inputOfAnInteger(Verifier*& verifier,int *&val) {
    string *number;
    int numbersAdded = 0;
    int pointsAllowed = 0;
    system(CLEAR);
    while (numbersAdded != 1) {
        number = new string();
        cout << "Ingrese un numero: " << endl;
        getline(cin, *number);
        if (*Verifier::isANumber(number, &pointsAllowed)) {
            try {
                *val = stoi(*number);
                numbersAdded++;
            } catch(const out_of_range& exception) {
                cout << "El numero es demasiado grande" << endl;
            }
        } else {
            cout << "Por favor ingrese un numero" << endl;
        }
    }
}

void inputOfALongInt(Verifier*& verifier,long long int *&val) {
    string *number;
    int numbersAdded = 0;
    int pointsAllowed = 0;
    system(CLEAR);
    while (numbersAdded != 1) {
        number = new string();
        cout << "Ingrese un numero: " << endl;
        getline(cin, *number);
        if (*Verifier::isANumber(number, &pointsAllowed)) {
            try {
                *val = stoll(*number);
                numbersAdded++;
            } catch(const out_of_range& exception) {
                cout << "El numero es demasiado grande" << endl;
            }
        } else {
            cout << "Por favor ingrese un numero" << endl;
        }
    }
}

void inputOfABinaryNumber(Verifier*& verifier,string *&number) {
    string *binaryNumber;
    bool accepted = false;
    while (not accepted) {
        binaryNumber = new string();
        cout << "Dame un numero en binario (base 2): " << endl;
        getline(cin, *binaryNumber);
        if (*verifier->binaryVerifier(binaryNumber)) {
            accepted = true;
            *number = *binaryNumber;
        } else {
            cout << "Ingrese un numero en binario." << endl;
            delete binaryNumber;
        }
    }
}

void inputOfAOctalNumber(Verifier*& verifier, string *&number) {
    string *octalNumber;
    bool accepted = false;
    while (not accepted) {
        octalNumber = new string();
        cout << "Dame un numero en octal (base 8): " << endl;
        getline(cin, *octalNumber);
        if (*verifier->octalVerifier(octalNumber)) {
            accepted = true;
            *number = *octalNumber;
        } else {
            cout << "Ingrese un numero en base 8." << endl;
            delete octalNumber;
        }
    }
}

void inputOfAHexadecimalNumber(Verifier *&verifier, string *&number) {
    string *hexadecimalValue;
    bool accepted = false;
    while (not accepted) {
        hexadecimalValue = new string();
        cout << "Dame un numero en hexadecimal (base 16): " << endl;
        getline(cin, *hexadecimalValue);
        if (*verifier->hexadecimalVerifier(hexadecimalValue)) {
            accepted = true;
            *number = *hexadecimalValue;
        } else {
            cout << "Ingrese un numero en base 16" << endl;
            delete hexadecimalValue;
        }
    }
}

void sum(ld *a, ld *b) {
    if (isinf(*Calculator::add(a, b))) {
        cout << "Operacion invalida" << endl;
    } else {
        cout << *Calculator::add(a, b) << endl;
    }
}

void sub(ld *a, ld *b) {
    if (isinf(*Calculator::subtract(a, b))) {
        cout << "Operacion invalida" << endl;
    } else {
        cout << *Calculator::subtract(a, b) << endl;
    }
}

void mul(ld *a, ld *b) {
    if (isinf(*Calculator::multiply(a, b))) {
        cout << "Operacion invalida" << endl;
    } else {
        cout << *Calculator::multiply(a, b) << endl;
    }
}

void divide(ld *a, ld *b) {
    if (*b == 0) {
        cout << "Division por 0 es imposible" << endl;
    } else {
        if (isinf(*Calculator::divide(a, b))) {
            cout << "Operacion invalida" << endl;
        } else {
            cout << *Calculator::divide(a, b) << endl;
        }
    }
}

void percentage(long long int *value, int *wanted) {
    if (* wanted < 0 or * wanted > 100) {
        cout << "Porcentaje deseado invalido" << endl;
    } else {
        cout << *Calculator::percentage(value, wanted) << endl;
    }
}

void power(ld *a) {
    if (isinf(*Calculator::squarePower(a))) {
        cout << "Operacion invalida" << endl;
    } else {
        cout << *Calculator::squarePower(a) << endl;
    }
}

void factorial(long long int *value) {
    if (*value < -20 or *value > 20) {
        cout << "Factorial no soportado" << endl;
    } else {
        cout << *Calculator::factorial(value) << endl;
    }
}

void power(ld *a, int *p) {
    ld res = *Calculator::power(a, p);
    if(isinf(res)) {
        cout << "Numero demasiado grande" << endl;
    } else {
        cout << res << endl;
    }
}

void squareRoot(ld *a) {
    if (*a < 0) {
        cout << "Numeros negativos requieren numeros complejos para tener raiz cuadrada" << endl;
    } else {
        cout << *Calculator::squareRoot(a) << endl;
    }
}

void cosine(ld *a) {
    cout << *Calculator::cosine(a) << endl;
}

void sine(ld *a) {
    cout << *Calculator::sine(a) << endl;
}

void tangent(ld *a) {
    bool good = true;
    ld aux = 90.0;
    int pos = 1;
    while (aux <= abs(*a)) {
        if (*a == aux and pos % 2 != 0) {
            good = false;
        }
        aux += 90.0;
        pos++;
    }
    if (good) {
        cout << *Calculator::tangent(a) << endl;
    } else {
        cout << "Numero invalido" << endl;
    }
}

void decimalToBinary(Converter *&converter, int *decimalValue) {
    int base = 2;
    cout << *converter->decimalBaseToOtherBaseConverter(decimalValue, &base) << endl;
}

void binaryToDecimal(Converter *&converter, string *binaryValue) {
    int base = 2;
    cout << *converter->otherBaseToDecimalBaseConverter(binaryValue, &base) << endl;
}

void decimalToOctal(Converter *&converter, int *decimalValue) {
    int base = 8;
    cout << *converter->decimalBaseToOtherBaseConverter(decimalValue, &base) << endl;
}

void octalToDecimal(Converter *&converter, string *octalValue) {
    int base = 8;
    cout << *converter->otherBaseToDecimalBaseConverter(octalValue, &base) << endl;
}

void decimalToHexadecimal(Converter *&converter, int *decimalValue) {
    int base = 16;
    cout << *converter->decimalBaseToOtherBaseConverter(decimalValue, &base) << endl;
}

void hexadecimalToDecimal(Converter *&converter, string *hexadecimalValue) {
    int base = 16;
    cout << *converter->otherBaseToDecimalBaseConverter(hexadecimalValue, &base) << endl;
}

void binaryToOctal(Converter *&converter, string *binaryValue) {
    int base = 2;
    int targetBase = 8;
    int *decimalNumber = converter->otherBaseToDecimalBaseConverter(binaryValue, &base);
    cout << *decimalNumber << endl;
    cout << *converter->decimalBaseToOtherBaseConverter(decimalNumber, &targetBase) << endl;
}

void octalToBinary(Converter *&converter, string *octalValue) {
    int base = 8;
    int targetBase = 2;
    int *decimalNumber = converter->otherBaseToDecimalBaseConverter(octalValue, &base);
    cout << *converter->decimalBaseToOtherBaseConverter(decimalNumber, &targetBase) << endl;
}

void binaryToHexadecimal(Converter *&converter, string *binaryValue) {
    int base = 2;
    int targetBase = 16;
    int *decimalNumber = converter->otherBaseToDecimalBaseConverter(binaryValue, &base);
    cout << *converter->decimalBaseToOtherBaseConverter(decimalNumber, &targetBase) << endl;
}

void hexadecimalToBinary(Converter *&converter, string *hexadecimalValue) {
    int base = 16;
    int targetBase = 2;
    int *decimalNumber = converter->otherBaseToDecimalBaseConverter(hexadecimalValue, &base);
    cout << *converter->decimalBaseToOtherBaseConverter(decimalNumber, &targetBase) << endl;
}


void pause() {
    cout << "Presione ENTER para continuar..." << endl;
    clearBuffer();
}

void clearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}