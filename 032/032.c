#include <stdio.h>

int hasNoReplicatingNumbers(int number);
int digitCount(int number);
int arePandigital(int number1, int number2);
int power(int number,int power);
void add(int *to, int product);

void main()
{
	int a, b, sum;
	int products[51];
	products[50] = 0;
	for(a = 1;a < power(10, 7);a++)
		if(hasNoReplicatingNumbers(a))
			for(b = 1;b < power(10, 8 - digitCount(a));b++)
				if(arePandigital(a, b))
					add(products, a * b);
	for(products[50]--,sum = 0;products[50] >= 0;products[50]--)
		sum += products[products[50]];
	printf("solution: %d\n",sum);
}

int hasNoReplicatingNumbers(int number)
{
	int numberList[10];
	int i, flag;
	for(i = 0;i <= 9;i++) numberList[i] = 0;
	while(number > 0)
	{
		numberList[number % 10]++;
		number /= 10;
		
	}
	for(i = 1, flag = 1;(flag == 1) && (i <= 9);i++)
		if(numberList[i] > 1)
			flag = 0;
	return ((flag) && (numberList[0] == 0));
}

int digitCount(int number)
{
	int count;
	count = 0;
	while(number > 0)
	{
		number /= 10;
		count++;
	}
	return count;
}

int arePandigital(int number1, int number2)
{
	int product = number1 * number2;
	int numberList[10];
	int i, flag;
	if(((digitCount(number1) + digitCount(number2) + digitCount(product)) == 9) && (hasNoReplicatingNumbers(product)))
	{
		for(i = 0;i <= 9;i++) numberList[i] = 0;
		while(number1 > 0)
		{
			numberList[number1 % 10]++;
			number1 /= 10;
		}
		while(number2 > 0)
		{
			numberList[number2 % 10]++;
			number2 /= 10;
		}
		while(product > 0)
		{
			numberList[product % 10]++;
			product /= 10;
		}
		for(i = 1, flag = 1;(flag == 1) && (i <= 9);i++)
			if(numberList[i] != 1)
				flag = 0;
		return (flag == 1);
	}
	else
		return 0;
}

int power(int number,int power)
{
	int out;
	for(out = 1;power > 0;power--)
		out *= number;
	return out;
}

void add(int *to, int product)
{
	int i;
	if(to[50] < 50)
	{
		for(i = 0;(i < to[50]) && (product != to[i]);i++);
		if(i == to[50])
			to[to[50]++] = product;
	}
	else
		printf("warning: array out of range\n");
}