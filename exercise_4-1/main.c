/**
 * Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost occurrence of t in s,
 * or -1 if there is none.
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int strindex(char s[], char t[]);

int main()
{
    char str[] = "How do you you do?";
    int n = strindex(str, "you");

    printf("%d\n", n);

    return EXIT_SUCCESS;
}

int strindex(char s[], char t[])
{
    int t_len = strlen(t);
    int end = strlen(s) - t_len;

    int right_most = -1;

    for (int i=0; i < end; i++) {
        bool found = true;
        for (int j = 0; j < t_len; j++) {
            if (s[i+j] != t[j]) {
                found = false;
                break;
            }
        }

        if (found) {
            right_most = i;
        }
    }

    return right_most;
}
