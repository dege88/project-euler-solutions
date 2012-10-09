#include <stdio.h>

void main()
{
	int dispari,sum;
	for(dispari = 3,sum = 1;dispari <= 1001;dispari += 2)
		sum += (dispari * dispari * 4) - ((dispari - 1) * 6);
	printf("solution: %d\n",sum);
}