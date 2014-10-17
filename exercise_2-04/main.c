#include <stdio.h>

/*
 * Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes each character in s1 that
 * matches any character in the string s2.
 */
/*
/* squeeze: delete all c from s
void squeeze(char s[], int c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
        s[j] = '\0';
}
*/

void squeeze(char s1[], char s2[])
{
    int i, j, pos;
    pos = 0;

    for (i=0; s1[i] != '\0'; i++) {
        for (j=0; s2[j] != '\0'; j++) {
            if (s2[j] == s1[i]) {
                j = -1;
                break;
            }
        }
        // not in squeeze list
        if (j >= 0) {
            s1[pos] = s1[i];
            pos++;
        }
    }
    s1[pos] = '\0';
}

int main()
{
    char s1[] = "squeeze";
    char s2[] = "qe";

    printf("initial: %s\n", s1);
    printf("to remove: %s\n", s2);
    squeeze(s1, s2);
    printf("result: %s\n", s1);

    return 0;
}
