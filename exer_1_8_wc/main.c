#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c;
	int words, lines, chars;
	words = lines = chars = 0;

	char in_word = 0;
	while((c = getchar()) != EOF) {
		chars++;
		if(c == '\n' || c == '\t' || c == ' ') {
			if(in_word) {
				words++;
				in_word = 0;
			}
			if(c == '\n') {
				lines++;
			}
		} else {
			in_word = 1;
		}
	}
	if(in_word) {
		words++;
	}

	printf("\nchars: %d, words: %d, lines: %d\n", chars, words, lines);
	exit(0);
}
