#include <stdio.h>

int sumOfDivisors(int num);

void main()
{
	int sums[9999];
	int i, count;
	for (i = 0; i < 9999; ++i)
		sums[i] = sumOfDivisors(i + 1);
	for(i = 0,count = 0;i < 9999;i++)
		if((sums[i] < 9999) && (sums[i] > (i + 1)) && (sums[sums[i] - 1] == (i + 1)))
			count += (i + 1) + sums[i];
	printf("solution: %d\n", count);
}

int sumOfDivisors(int num)
{
	int i, sum;
	for (i = 1,sum = 0;i <= (num / 2);i++)
		if((num % i) == 0)
			sum += i;
	return sum;
}