/*
 * Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case,
 *                with a conditional expression instead of if-else.
 */
#include <stdio.h>

char lower(char c)
{
    return 65 <= c && c <= 90 ? c + 32 : c;
}

int main()
{
    char c = 'A';
    printf ("%c\n", c);
    c = lower(c);
    printf ("%c\n", c);
}
