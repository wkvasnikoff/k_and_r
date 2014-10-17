/*
Exercise 2-5. Write the function any(s1,s2), which returns the first
location in a string s1 where any character from the string s2 occurs,
or -1 if s1 contains no characters from s2. (The standard library
function strpbrk does the same job but returns a pointer to the location.)
*/

#include <stdio.h>

int any(char s1[], char s2[])
{
    int i, j;

    for (i=0; s1[i] != '\0'; i++) {
        for (j=0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    char s1[] = "The fish like to jump.";
    char s2[] = "jzyx";

    int pos = any(s1, s2);

    printf("%s\n", s1);
    printf("%s\n", s2);
    printf("pos: %i\n", pos);

    return 0;
}


