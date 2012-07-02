#include <stdio.h>

void main()
{
	long long int a,b;
	int i;
	a = 0; //sum of the squares
	b = 0; //square of the sums

	for (i = 1; i <= 100; ++i)
	{
		a += i * i;
		b += i;
	}
	b *= b;

	printf("solution: %d\n",b - a);
}