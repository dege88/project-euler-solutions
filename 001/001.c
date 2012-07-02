#include <stdio.h>

void main()
{
	int i,sum;
	for(i = 1,sum = 0;i < 1000;i++)
		if(((i % 3) == 0) || ((i % 5) == 0))
			sum += i;
	printf("solution: %d\n",sum);
}