#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void expand(char *s1, char *s2);

/*
 Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in the
 string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits,
 and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing -
 is taken literally.
*/

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("run <string to expand>\n");
        return EXIT_FAILURE;
    }

    if (strlen(argv[1]) >= 32) {
        printf("String in too long\n");
        return EXIT_FAILURE;
    }

    char s1[64];
    char s2[64];

    strcpy(s1, argv[1]);

    expand(s1, s2);

    printf("%s\n", s1);
    printf("%s\n", s2);

    return EXIT_SUCCESS;
}

void expand(char *s1, char *s2)
{
    char c;

    while(*s1 != '\0') {
        c = *s1;

        bool is_valid = (isalnum(c) || c == '.' || c == '-');

        if (!is_valid) {
            printf("Invalid char '%c'\n", c);
            return;
        }

        if (*s1 == '-' || *s1 == '.') {
            *s2 = *s1;
            s1++;
            s2++;
        } else if (*(s1 + 1) == '-') {
            // error case
            if (*s1 > *(s1 + 2)) {
                printf("Invalid range %c-%c", *s1, *(s1 + 2));
                return;
            }

            // handle range '-'
            c = *s1;
            while (c < *(s1 + 2)) {
                *s2 = c;
                c++;
                s2++;
            }

            s1 += 2;
        } else if (*(s1 + 1) == '.') {
            // error case
            if (*(s1 + 2) != '.' || *(s1 + 3) != '.') {
                printf("invalid ... range\n");
                return;
            }

            // handle range '...'
            c = *s1;
            while (c <= *(s1 + 4)) {
                *s2 = c;
                c++;
                s2++;
            }

            s1 += 5;
        } else {
            *s2 = *s1;
            s1++;
            s2++;
        }
    }
}

