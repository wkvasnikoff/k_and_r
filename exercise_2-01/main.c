#include <stdio.h>
#include <limits.h>
#include <float.h>
/*
 * Exercise 5-1. Write a program to determine the ranges of char, short, int, and long variables, both
 * signed and unsigned, by printing appropriate values from standard headers and by direct
 * computation. Harder if you compute them: determine the ranges of the various floating-point types.
 */
int main()
{
    printf("***** Using limits.h ******\n");
    printf("char: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("short %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("int: %d to %d\n", INT_MIN, INT_MAX);
    printf("long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("uchar: %d to %u\n", 0, UCHAR_MAX);
    printf("ushort: %d to %u\n", 0, USHRT_MAX);
    printf("uint: %d to %u\n", 0, UINT_MAX);
    printf("ulong: %d to %lu\n", 0, ULONG_MAX);

    printf("\n***** By Direct Computation *****\n");
    char ch = -1, ch2;
    short sh = -1, sh2;
    int i = -1, i2;
    long l = -1, l2;

    unsigned char uchar = 0;
    unsigned short ushort = 0;
    unsigned int uint = 0;
    unsigned long ulong = 0;

    // char
    while (ch2 = ch * 2) {
        ch = ch2;
    }
    ch2 = ch - 1;

    // short
    while (sh2 = sh * 2) {
        sh = sh2;
    }
    sh2 = sh - 1;

    // int
    while (i2 = i * 2) {
        i = i2;
    }
    i2 = i - 1;

    // long
    while (l2 = l * 2) {
        l = l2;
    }
    l2 = l - 1;

    printf("char: %d to %d\n", ch, ch2);
    printf("short: %d to %d\n", sh, sh2);
    printf("int: %d to %d\n", i, i2);
    printf("long: %ld to %ld\n", l, l2);
    printf("uchar: %u to %u\n", 0, --uchar);
    printf("ushort: %u to %u\n", 0, --ushort);
    printf("uint: %u to %u\n", 0, --uint);
    printf("ulong: %u to %lu\n", 0, --ulong);

    printf("\n***** Using float.h *****\n");
    printf("float: %e to %e\n", FLT_MIN, FLT_MAX);
    printf("double: %e to %e\n", DBL_MIN, DBL_MAX);

    return 0;
}
