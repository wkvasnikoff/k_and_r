/**
 * Exercise 4-2. Extend atof to handle scientific notation of the form
 */
#include <ctype.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double atof(char s[]);

int main()
{
    double n = atof("-60.3e-1");

    printf("%f\n", n);
}

// atof: convert string s to double
double atof(char s[])
{
    double val, power;
    int i, sign;

    // skip white space
    for (i = 0; isspace(s[i]); i++) {
        ;
    }

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }

    if (s[i] == '.') {
        i++;
    }

    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    val =  sign * val / power;
    power = 0;

    // handle scientific notation
    if (s[i] == 'e') {
        i++; // skip the e

        bool neg = false;
        if (s[i] == '-') {
            neg = true;
            i++;
        }

        int exp;
        for (exp = 0; isdigit(s[i]); i++) {
            exp = exp * 10 + (s[i] - '0');
        }

        if (neg) {
            for(int j=0; j < exp; j++) {
                val /= 10;
            }
        } else {
            for(int j=0; j < exp; j++) {
                val *= 10;
            }
        }
    }

    return val;
}
