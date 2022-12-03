/*
 * Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third argument is
 * a minimum field width; the converted number must be padded with blanks on the left if necessary to
 * make it wide enough.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int n, char s[], int w);

int main()
{
    char s[32];

    itoa(-36, s, 7);
    printf("%s\n", s);

    itoa(1000, s, 7);
    printf("%s\n", s);
    itoa(3331000, s, 7);
    printf("%s\n", s);

    return EXIT_SUCCESS;
}

void reverse(char s[])
{
    int j = strlen(s) - 1;

    for(int i=0; i < j; i++, j--) {
        char c = s[j];

        s[j] = s[i];
        s[i] = c;
    }
}

void itoa(int n, char s[], int w)
{
    int sign = n;
    unsigned int n2;

    if (n < 0) {
        n2 = -n;
    } else {
        n2 = n;
    }

    int i = 0;
    while(n2) {
        char d = '0' + (n2 % 10);
        s[i] = d;
        i++;
        n2 -= (n2 % 10);
        n2 /= 10;
    }

    if (sign < 0) {
        s[i] = '-';
        i++;
    }

    for (; i < w; i++) {
        s[i] = ' ';
    }

    s[i] = '\0';

    reverse(s);
}
