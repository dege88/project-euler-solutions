#include <stdio.h>

typedef int factorizedNumber[25];

void factorize(int number, factorizedNumber out);
void factorMultiply(factorizedNumber factorized, int factor);
void factorCopy(factorizedNumber factorFrom, factorizedNumber factorTo);
int isEqual(factorizedNumber factor1, factorizedNumber factor2);
int isDuped(factorizedNumber *numbers, int index, factorizedNumber factorized);

void main()
{
	factorizedNumber numbers[9801];
	int a, b;
	int index = 0;
	factorizedNumber base, temp;
	for(a = 2;a <= 100; a++)
	{
		factorize(a, base);
		for(b = 2;b <= 100;b++)
		{
			factorCopy(base, temp);
			factorMultiply(temp, b);
			if(!isDuped(numbers, index, temp))
				factorCopy(temp, numbers[index++]);
		}
	}
	printf("solution: %d\n",index);
}

void factorize(int number, factorizedNumber out)
{
	int primi[] = {
		2,
		3, 5, 7, 11,
		13, 17, 19, 23,
		29, 31, 37, 41,
		43, 47, 53, 59,
		61, 67, 71, 73,
		79, 83, 89, 97}; //25 numeri primi sotto il 100 (compreso)
	int i, count;
	for(i = 24;i >= 0;i--)
		{
			count = 0;
			while((number % primi[i]) == 0)
				{
					number /= primi[i];
					count++;
				}
			out[i] = count;
		}
}

void factorMultiply(factorizedNumber factorized, int factor)
{
	int i;
	for (i = 0;i < 25;i++)
		factorized[i] *= factor;
}

void factorCopy(factorizedNumber factorFrom, factorizedNumber factorTo)
{
	int i;
	for(i = 0;i < 25;i++)
		factorTo[i] = factorFrom[i];
}

int isEqual(factorizedNumber factor1, factorizedNumber factor2)
{
	int i, out;
	for(i = 0,out = 1;i < 25;i++)
		out = out && (factor1[i] == factor2[i]);
	return out;
}

int isDuped(factorizedNumber *numbers, int index, factorizedNumber factorized)
{
	if(index > 0)
	{
		index--;
		while((index >= 0) && (!(isEqual(factorized,numbers[index]))))
			index--;
		return (index >= 0);
	}
	else
		return 0;
}