#include <stdio.h>

void main()
{
	//int coins[] = {1, 2, 5, 10, 20, 50, 100, 200}; //8 coins
	int a,b,c,d,e,f,g,h;
	int count;
	count = 0;
	for(a = 0;a <= 200;a++)
		for(b = 0;b <= 100;b++)
			for(c = 0;c <= 40;c++)
				for(d = 0;d <= 20;d++)
					for(e = 0;e <=10;e++)
						for(f = 0;f <= 4;f++)
							for(g = 0;g <= 2;g++)
								for(h = 0;h <= 1; h++)
									if((a + (b * 2) + (c * 5) + (d * 10) + (e * 20) + (f * 50) + (g * 100) + (h * 200)) == 200)
										count ++;
	printf("solution: %d\n",count);
}