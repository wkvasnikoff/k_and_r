#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 80

void print_line(char* buffer, int start, int end)
{
	int i;
	for(i = start; i != end; i = (i+1) % MAXLINE) {
		putchar(buffer[i]);
	}
}

int main(int argc, char* argv[])
{
	if(argc != 2) {
		printf("./run file\n");
		exit(0);
	}

	char c, buffer[MAXLINE + 1];
	buffer[MAXLINE] = '\0';
	int start = 0, end=0, length=0, position=-1, i;
	FILE* f = fopen(argv[1], "r");
	while((c = fgetc(f)) != EOF) {
		position = (position + 1) % MAXLINE;
		length++;

		buffer[position] = c;

		if(c == ' ') {
			end = position;	
		}
	
		if(length == MAXLINE) {
			// no space to break on
			if(end == start) {
				end = position;
			}
			print_line(buffer, start, end);
			putchar('\n');
			length = 0;
			start = (end + 1) % MAXLINE;
			end = start;
		}
	}
	print_line(buffer, start, position);
	putchar('\n');

	fclose(f);	

	exit(0);
}
