#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Count the frequency of the characters in the input
 */

int main()
{
	int c,i,j;
	int n_chars = 'z' - 'a' + 1;
	int chars[n_chars];
	int lower = 'a' - 'A';

	memset(chars, 0, sizeof(chars));

	while((c = getchar()) != EOF) {
		if( 'A' <= c && c <= 'Z') {
			c = c - lower;
		}

		if('a' <= c && c <= 'z') {
			chars[c - 'a']++;
		}
	}

	puts("");
	for(i=0; i < n_chars; i++) {
		
		printf("%c ", i + 'a');
		for(j=0; j < chars[i]; j++) {
			putchar('*');
		}
		puts("");
	}

	exit(0);
}
