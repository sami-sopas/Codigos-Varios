//
// Created by Miguel on 09/02/2023.
//

#ifndef PROYECTO1_CALCULATOR_H
#define PROYECTO1_CALCULATOR_H

#include <cmath>
#include <cstdlib>

using namespace std;

class Calculator {
private:
    using ld = long double;
    constexpr static const ld PI = 3.141592653589793238462643383279;

    static ld convertDegreeToRadians(const ld *degree) {
        return (*degree * (PI / 180.0));
    }

public:
    Calculator() = default;

    static inline ld *add(const ld *a, const ld *b) {
        ld *result = (ld *) malloc(sizeof(ld));
        *result = *a + *b;
        return result;
    }

    static inline ld *subtract(const ld *a, const ld *b) {
        ld *result = (ld *) malloc(sizeof(ld));
        *result = *a - *b;
        return result;
    }

    static inline ld *multiply(const ld *a, const ld *b) {
        ld *result = (ld *) malloc(sizeof(ld));
        *result = *a * *b;
        return result;
    }

    static inline ld *divide(const ld *a, const ld *b) {
        ld *result = (ld *) malloc(sizeof(ld));
        *result = *a / *b;
        return result;
    }

    static inline ld *percentage(const long long int *value, const int *desiredPercentage) {
        ld *answer = (ld *) malloc(sizeof(ld));
        *answer = *value * *desiredPercentage;
        *answer /= 100;
        return answer;
    }

    static inline ld *squarePower(const ld *a) {
        ld *answer = (ld *) malloc(sizeof(ld));
        *answer = *a * *a;
        return answer;
    }

    static long long int *factorial(long long int *n) {
        auto *answer = (long long int *) malloc(sizeof(long long int));
        bool negative = *n < 0;
        if (negative) *n = *n * -1;
        *answer = 1;
        for (long long int i = *n; i >= 1; i--) {
            *answer *= i;
        }
        if (negative) *answer = *answer * -1;
        return answer;
    }

    static ld *power(const ld *x, const int *y) {
        ld *answer = (ld *) malloc(sizeof(ld));
        *answer = *x;
        for (int i = 0; i < *y; i++) {
            *answer *= *x;
        }
        return answer;
    }

    static inline ld *squareRoot(const ld *x) {
        ld *answer = (ld *) malloc(sizeof(ld));
        *answer = sqrt(*x);
        return answer;
    }

    static inline ld *cosine(const ld *x) {
        ld *answer = (ld *) malloc(sizeof(ld));
        *answer = cos(convertDegreeToRadians(x));
        return answer;
    }

    static inline ld *sine(const ld *x) {
        ld *answer = (ld *) malloc(sizeof(ld));
        *answer = sin(convertDegreeToRadians(x));
        return answer;
    }

    static inline ld *tangent(const ld *x) {
        ld *answer = (ld *) malloc(sizeof(ld));
        *answer = tan(convertDegreeToRadians(x));
        return answer;
    }

};

#endif //PROYECTO1_CALCULATOR_H
