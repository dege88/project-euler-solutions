#include <stdio.h>

void main()
{
	int i;
	long int count,number,max_number,max_count;

	max_count = 0;
	max_number = 0;

	for(i = 1;i < 1000000;i++)
	{
		count = 0;
		number = i;
		while(number > 1)
		{
			if((number % 2) == 0)
				number /= 2;
			else
				number = (number * 3) + 1;
			count++;
		}
		if(count > max_count)
		{
			max_count = count;
			max_number = i;
		}
	}
	printf("solution: %ld\n", max_number);
}