#include <stdio.h>

int isAbundant(int num);
int isSumOfAbundants(int num, int *abundants, int abundants_index);

void main()
{
	int abundants[28123];
	int abundants_index;
	int i, sum;
	for(i = 1,abundants_index = 0;i <= 28123;i++)
		if(isAbundant(i))
		{
			abundants[abundants_index] = i;
			abundants_index++;
		}

	for(i = 1,sum = 0;i <= 28123;i++)
		if(!isSumOfAbundants(i, abundants, abundants_index))
			sum += i;

	printf("solution: %d\n",sum);
}

int isAbundant(int num)
{
	int i, sum;
	for(i = 1,sum = 0;i <= (num / 2);i++)
		if((num % i) == 0)
			sum += i;
	return sum > num;
}

int isSumOfAbundants(int num, int *abundants, int abundants_index)
{
	int i, flag, j;
	for (i = 0,flag = 0;(i < abundants_index) && (abundants[i] < num) && (flag == 0);i++)
		for(j = 0;(j < abundants_index) && (flag == 0);j++)
			if((abundants[i] + abundants[j]) == num)
				flag = 1;
	return flag;
}