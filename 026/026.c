#include <stdio.h>

void smarddivision(int num, int *cifre);

void main()
{
	int i, start, restart, flag, k, max, maxNumber;
	int cifre[10001];
	max = 1;
	for(i = 7;i < 1000;i++)
		{
			smarddivision(i, cifre);
			if(cifre[10000] == 9999) //probabilmente ricorsivo, conto le cifre che ricorrono
			{
				for(start = 0, flag = 0;(start < 9997) && (flag == 0);start++)
					for(restart = 1;(flag == 0) && (restart <= i);restart++)
					{
						for(k = start;((k - start) < restart) && (cifre[k] == cifre[k + restart]) && (cifre[k + restart] == cifre[k + (restart * 2)]); k++);
						if((k - start) == restart) flag = 1;
					}
				if((flag == 1) && (restart - 1) > max)
					{
						max = restart - 1;
						maxNumber = i;
					}
			}
		}
	printf("solution: %d\n",maxNumber);
}

void smarddivision(int num, int *cifre)
{
	int index, temp, counter;
	index = 0;
	temp = 1;
	if(temp >= num)
		cifre[10000] = index - 1;
	else
	{
		temp *= 10;
		while((temp > 0) && (index < 10000)){
			while(temp < num)
			{
				temp *= 10;
				cifre[index++] = 0;
			}
			index--;
			counter = 0;
			while(temp >= num)
			{
				temp -= num;
				counter++;
			}
			cifre[index++] = counter;
		}
		cifre[10000] = index - 1;
	}
}