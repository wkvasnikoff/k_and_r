#include <stdlib.h>
#include <stdio.h>

#define OUTSIDE 0
#define STRING 1
#define COMMENT 2
/*
 * Remove comments from source code
 */
int main(int argc, char* argv[])
{
	char c;
	char prev;
	int state = OUTSIDE;	

	if(argc != 2) {
		printf("./run file\n");
		exit(0);
	}

	FILE* file = fopen(argv[1], "r");

	while((c = fgetc(file)) != EOF) {
		if(state == OUTSIDE) {
			if(prev) {
				if(c == '*') {
					state = COMMENT;
					continue;
				} else {
					putchar(prev);
					prev = 0;
				}
			} else {
				if(c == '/') {
					prev = c;
					continue;
				} else if(c == '"') {
					state = STRING;
				}
			}
		} else if(state == STRING) {
			if(prev) {
				prev = 0;
			} else {
				if(c == '\\') {
					prev = c;
				} else if(c == '"') {
					state = OUTSIDE;
				}
			}
		} else if(state == COMMENT) {
			if(prev) {
				prev = 0;
				if(c == '/') {
					state = OUTSIDE;
				}
			} else {
				if(c == '*') {
					prev = c;
				}
			}
			continue;
		}

		putchar(c);
	}
	
	fclose(file);

	exit(0);
}
