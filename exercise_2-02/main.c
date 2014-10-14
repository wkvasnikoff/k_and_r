#include <stdio.h>

//  Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.
/*
 *  for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 *  s[i] = c;
 *
 */
#define MAXLINE 5

int main()
{
    int lim = MAXLINE;
    int i;
    char c;
    char s[lim];

    for (i=0; i < lim - 1; i++) {
        if ((c = getchar()) == '\n') {
            break;
        } else if (c == EOF) {
            break;
        } else {
            s[i] = c;
        }
    }
    s[i] = '\0';

    printf("%s\n", s);

    return 0;
}
