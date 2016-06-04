/*
 * Exercise 2-9. In a two’s complement number system, x &= (x−1) deletes the rightmost 1-bit in x.
 * Explain why. Use this observation to write a faster version of bitcount.
 */

#include <stdio.h>
void printb(int x)
{
    int n_bits = sizeof(x) * 8;
    int bit = 1 << (n_bits - 1);

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
 * Bitcount only needs to loop when there are 1's to count
 */
int bitcount(int x)
{
    int n = 0;
    while (x) {
        x &= (x-1);
        n++;
    }
    return n;
}

int main()
{
    int x = 8;
    printb(x);
    int n = bitcount(x);
    printf("%d\n", n);
}
