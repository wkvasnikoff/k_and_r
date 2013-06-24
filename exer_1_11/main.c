#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* stradd(char *str1, char *str2)
{
	int len;
	char* str;

	len = strlen(str1);
	len += strlen(str2);
	str = malloc(sizeof(char) * len);

	strcpy(str, str1);
	strcat(str, str2);

	return str;
}


int main()
{
	char c, in_word=0;

	while((c = getchar()) != EOF) {
		if(c == '\t' || c == ' ') {
			if(in_word) {
				putchar('\n');
				in_word = 0;
			}
		} else {
			putchar(c);
			in_word = 1;
		}
	}

	exit(0);
}
