#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	char c, prev;
	enum state {NORMAL, STRING, COMMENT};
	int state = NORMAL;	

	const int test = 4;

	if(argc != 2) {
		printf("./run file\n");
		exit(0);
	}

	FILE* file = fopen(argv[1], "r");

	while((c = fgetc(file)) != EOF) {
		if(state == NORMAL) {
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
					state = NORMAL;
				}
			}
		} else if(state == COMMENT) {
			if(prev) {
				prev = 0;
				if(c == '/') {
					state = NORMAL;
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
