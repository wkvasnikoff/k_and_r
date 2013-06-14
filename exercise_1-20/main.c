#include <stdio.h>
#include <stdlib.h>

#define TABSIZE 8

int main()
{
	int c = 0, n = 0, pos=0, i;
	while((c = getchar()) != EOF) {
		// add correct number of spaces
		if(c == '\t') {
			pos = (TABSIZE - (n % TABSIZE));
			for(i=0; i < pos; i++) {
				putchar('*');
				n++;
			}
			continue;
		} else {
			n++;
		}

		if(c == '\n') {
			putchar(c);
			n = 0;
		} else {	
			putchar(c);
		} }

	exit(0);
}
