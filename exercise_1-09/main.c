/*
 * 	Convert multi blanks to single blank
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c, prev_blank = 0;

	while((c = getchar()) != EOF) {
		if(c == ' ') {
			if(!prev_blank) {
				prev_blank = 1;
				putchar(c);
			}
		} else {
			putchar(c);
			prev_blank = 0;
		}
	}
}
