/*
 * Exercise 2-6. Write a function setbits(x,p,n,y) that
 * returns x with the n bits that begin at position
 * p set to the rightmost n bits of y, leaving the other bits unchanged.
 */

#include <stdio.h>

int setbits(int x, int p, int n, int y)
{
    int i;
    unsigned int mask=0;

    // create mask to copy n bits from y
    for (i=0; i < n; i++) {
        mask <<= 1;
        mask |= 1;
    }

    // copy n rightmost bits from y
    y &= mask;

    // move bit to correct position
    y <<= p;
    mask <<= p;

    // clear out area with zeros
    x &= ~mask;

    // copy y's bits in to position
    x |= y;

    return x;
}

int main()
{
    int x;
    x = setbits(0, 2, 2, 15);

    printf("%i\n", x);

    return 0;
}
