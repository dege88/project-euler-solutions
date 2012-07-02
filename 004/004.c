#include <stdio.h>

int ispalindromo(int num);

void main()
{
	int i,j,max = 0;
	for(i = 999;i >= 100;i--)
		for(j = 999;j >= 100;j--)
			if((ispalindromo(i * j)) && ((i * j) > max))
				max = i * j;
			printf("%d\n", max);
}

int ispalindromo(int num)
{
	int out = 0, bckp = num;
	while(num > 0)
	{
		out = (out * 10) + (num % 10);
		num = num / 10;
	}
	return out == bckp;
}