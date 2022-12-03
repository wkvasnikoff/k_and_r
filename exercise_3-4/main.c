#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/*
    Exercise 3-4. In a two's complement number representation, our version of itoa does not handle the
    largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why not. Modify it to print
    that value correctly, regardless of the machine on which it runs.
*/
void itoa(int n, char s[]);

int main()
{
    char str[32];
    int n = INT_MIN;

    printf("%d\n", n);
    itoa(n, str);

    printf("%s\n", str);

    return EXIT_SUCCESS;
}

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[])
{
    int i = 0;

    // use unsigned int so there is space to hald -INT_MIN
    unsigned int i2;

    if (n < 0) {
        i2 = (unsigned int)-n;
    } else {
        i2 = (unsigned int)n;
    }

    // make n positive
    i = 0;
    do {
        /* generate digits in reverse order */
        s[i++] = i2 % 10 + '0'; /* get next digit */
    } while ((i2 /= 10) > 0);

    // delete it
    if (n < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}
