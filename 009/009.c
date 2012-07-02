#include <stdio.h>

void main()
{
	int a,b,flag = 0;
	for(a = 1;(a < 998) && (flag == 0);a++)
		for (b = 1;((a + b) < 999) && (flag == 0);b++)
			if (((a * a) + (b * b)) == ((1000 - a - b) * (1000 - a - b)))
				flag = 1;
	a--;
	b--;
	printf("result: %d\n", a * b * (1000 - a - b));
}