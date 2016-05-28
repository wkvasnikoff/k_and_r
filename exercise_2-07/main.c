/*
 * Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits
 * that begin at position p inverted (i.e., 1 changed into 0 and vice versa),
 * leaving the others unchanged.
 */

#include <stdio.h>
void printb(unsigned char x)
{
    unsigned char bit = 1;
    while (x) {
        if (x & one) {
            printf("1");
        } else {
            printf("0");
        }

        x <<= 1;
    }
    printf("\n");
}

int invert(unsigned char x, int p, int n)
{


    return x;
}

int main()
{
    unsigned char x = 2;

    printf("%u\n", x);

    printb(x);
}
