#include <stdio.h>
#include <stdlib.h>

float f_to_c(int f)
{
	float c;
	return (5.0f/8)*(f-32);
}

int main()
{
	int f = 0;
	float c;

	for(f=0; f < 70; f += 2) {
		c = f_to_c(f);
		printf("F: %d, C: %.1f\n", f, c);
	}

	exit(0);
}
