#include <stdio.h>

// Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal
// digits (including an optional 0x or 0X) into its equivalent integer value.
// The allowable digits are 0 through 9, a through f, and A through F.
//
int power(int base, unsigned int power)
{
    int result = 1;
    int i;

    for (i=0; i < power; i++) {
        result *= base;
    }

    return result;
}

int htoi(char* str)
{
    int max_len = 10;
    int n_chars=0;
    char c;
    char r_str[max_len];
    int i = 0;
    int result = 0;

    while (str[i] != '\0') {
        c = str[i];
        if ('0' <= c && c <= '9') {
            r_str[n_chars] = c - '0';
        } else if ('a' <= c && c <= 'f') {
            r_str[n_chars] = (c - 'a') + 10;
        } else if ('A' <= c && c <= 'F') {
            r_str[n_chars] = (c - 'A') + 10;
        } else if (i == 0 && c == '0') { // prefix
            i++;
            continue;
        } else if (i == 1 && (c == 'X' || c == 'x')) { // prefix
            i++;
            continue;
        } else {
            return -1; // error
        }

        n_chars++;
        i++;
    }

    // no chars
    if (n_chars == 0) {
        return -1;
    }

    for (i = n_chars - 1; i >= 0; i--) {
        c = r_str[i];

        int pos = (n_chars - i) - 1;
        int add = c * power(16, pos);

        result += add;
    }
    return result;
}

int main()
{
    char str[] = "0x21af";
    int d = htoi(str);

    printf("%s\n", str);
    printf("%d\n", d);

    return 0;
}
