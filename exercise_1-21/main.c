#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	if(argc != 2) {
		printf("syntax: run file\n");
		exit(0);
	}

	FILE* f= fopen(argv[1], "r");
	char c;
	while((c = getchar(f)) != EOF) {


	}

	fclose(f);

	exit(0);
}
