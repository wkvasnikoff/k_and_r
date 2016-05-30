/*
 * Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits
 * that begin at position p inverted (i.e., 1 changed into 0 and vice versa),
 * leaving the others unchanged.
 */

#include <stdio.h>
void printb(unsigned char x)
{
    unsigned char bit = 0x80;
    int n_bits = 8;

    for (int i = 0; i < n_bits; i++) {
        if (x & bit) {
            printf("1");
        } else {
            printf("0");
        }

        x <<= 1;
    }
    printf("\n");
}

/*
 * Inverting p with length n on x counting from least significant side
 */
int invert(unsigned char x, int p, int n)
{
    unsigned char mask = 0;
    for (int i = p; i < p + n; i++) {
        mask |= 1 << i;
    }

    return mask ^ x;
}

int main()
{
    unsigned char x = 2;

    x = invert(x, 1, 2);
    printb(x);
}
