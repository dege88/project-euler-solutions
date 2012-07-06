#include <stdio.h>

int getNAndDestroy(int *numbers, int num);

void main()
{
	int numbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i, j, k, divider;
	printf("solution: ");
	for (i = 0,k = 0,divider = 3628800;i < 10;i++)
	{
		divider /= 10 - i;
		for(j = 0;(j < (10 - i)) && ((k + (divider * j)) < 1000000);j++);
		k += divider * (j - 1);
		printf("%d", getNAndDestroy(numbers, j));

	}
	printf("\n");
}

int getNAndDestroy(int *numbers, int num)
{
	int i, count;
	for(i = 0,count = 0;(i < 10) && (count < num);i++)
		if(numbers[i] != -1)
			count++;
	numbers[i - 1] = -1;
	return i - 1;
}