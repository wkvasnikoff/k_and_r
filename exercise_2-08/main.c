/*
 * Exercise 2-8. Write a function rightrot(x,n) that returns the value of the
 *   integer x rotated to the right by n positions.
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

int rightrot(int x, int n)
{
    int num_bits = sizeof(x) * 8;
    int bit = 0;
    int left_bit_mask = 1 << (num_bits - 1);

    for (int i = 0; i < n; i++) {
        bit = x & 1;
        x >>= 1;
        if (bit) {
            x |= left_bit_mask;
        } else {
            x &= ~left_bit_mask;
        }
    }

    return x;
}

int main()
{
    int x = -8;
    printb(x);
    x = rightrot(x, 4);
    printb(x);
}
