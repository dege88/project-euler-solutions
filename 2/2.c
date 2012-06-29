#include <stdio.h>

void main()
{
	int term1,term2,temp,sum;
	for(term1 = 1,term2 = 2,sum = 0;term2 <= 4000000;temp = term1,term1 = term2,term2 += temp)
		if((term2 % 2) == 0)
			sum += term2;
	printf("solution: %d\n",sum);
}