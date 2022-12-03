#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/*
Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b character
representation in the string s. In particular, itob(n,s,16) formats s as a hexadecimal integer in s.
*/
void itob(int n, char *s, int b);


int main()
{
    int n = 8;
    char str[32];

    itob(n, str, 2);
    printf("%s\n", str);
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

void itob(int n, char *s, int b)
{
    int r = 0;

    char lookup[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int i = 0;
    while (n) {
        r = n % b;
        s[i] = lookup[r];
        n = n - r;
        n /= b;
        i++;
    }
    s[i] = '\0';

    reverse(s);
}

