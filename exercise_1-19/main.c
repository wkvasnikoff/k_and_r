#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void reverse(char* str)
{
	int len = strlen(str);
	if(len > 0) {
		reverse(str+1);
	}

	putchar(*str);
}

int main(int argc, char* argv[])
{
	char* str = "fish";
	reverse(argv[1]);
	
	exit(0);
}
