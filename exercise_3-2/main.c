#include <stdio.h>
#include <stdlib.h>

/*
Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into visible
escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the
other direction as well, converting escape sequences into the real characters.
*/

void escape(char *in, char *out);
void unescape(char *out, char *in);

int main(int argc, char *argv[])
{
    char input[] = "How are you?\n\tFine.\n";
    char output[32];
    char output2[32];

    printf(input);

    escape(output, input);
    printf("%s\n", output);

    unescape(output2, output);
    printf("%s\n", output2);

    return EXIT_SUCCESS;
}

void escape(char *out, char *in)
{
    while(*in) {

        switch (*in) {
            case '\n':
                *out = '\\';
                out++;
                *out = 'n';
                break;
            case '\t':
                *out = '\\';
                out++;
                *out = 't';
                break;
            default:
                *out = *in;
                break;
        }

        out++;
        in++;
    }
    *out = '\0';
}

void unescape(char *out, char *in)
{
    while(*in) {
        if (*in == '\\' && *(in+1) == 'n') {
            *out = '\n';
            in++;
        } else if (*in == '\\' && *(in+1) == 't') {
            *out = '\t';
            in++;
        } else {
            *out = *in;
        }

        out++;
        in++;
    }
}
