#include <stdio.h>
#include <stdlib.h>

int main()
{
	float lower, upper, step, f, c;
	lower = 0;
	upper = 300;
	step = 20;

	f = lower;
	printf("%3s %6s\n", "F", "C");
	while(f < upper) {
		c = (5.0/9.0) * (f - 32);

		printf("%3.0f %6.1f\n", f, c);
	
		f += step;
	}

	exit(0);
}
