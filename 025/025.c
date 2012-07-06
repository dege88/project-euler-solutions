#include <stdio.h>

void addAndCopy(int *term1, int *term2);

void main()
{
	int term1[1000], term2[1000];
	int i;
	for(i = 0;i < 999;i++)
	{
		term1[i] = 0;
		term2[i] = 0;
	}
	term1[999] = 1;
	term2[999] = 1;

	for(i = 3;!digitsCount(term2);i++)
		addAndCopy(term1, term2);

	printf("solution: %d\n",i - 1);
}

void addAndCopy(int *term1, int *term2)
{
	int i, tmp[1000];
	for(i = 0;i < 1000;i++)
		tmp[i] = term2[i];

	for(i = 999;i >= 0;i--)
	{
		term2[i] += term1[i];
		term1[i] = tmp[i];
		if(term2[i] >= 10)
		{
			term2[i] -= 10;
			term2[i - 1] += 1;
		}
	}

}

int digitsCount(int *term)
{
	return term[0] != 0; //i need a check only of the last digit!
}