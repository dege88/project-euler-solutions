#include <stdio.h>

void main()
{
	int i,sum;
	for(i = 2,sum = 0;i < 999999;i++)
		if(checkNumber(i))
			sum += i;
	printf("solution: %d\n",sum);
}

int checkNumber(int number)
{
	int sum, temp, numberCopy;
	sum = 0;
	numberCopy = number;
	while(numberCopy > 0)
	{
		temp = numberCopy % 10;
		numberCopy = (numberCopy - temp) / 10;
		sum += (temp * temp * temp * temp * temp);
	}
	return (sum == number);
}