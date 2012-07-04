#include <stdio.h>

void main()
{
	int i, sum;
	for(i = 1,sum = 0;i < 1000;i++)
		sum += countLetters(i);
	sum += 11; //one thousand
	printf("solution: %d\n",sum);
}

int countLetters(int num)
{
	int tmp;
	int count = 0;
	int counts[20] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8};
	//3-one 3-two 5-three 4-four 4-five 3-six 5-seven 5-eight 4-nine 3-ten 6-eleven 6-twelve 8-thirteen 8-fourteen 7-fifteen 7-sixteen 9-seventeen 8-eighteen 8-nineteen
	int decine[8] = {6, 6, 5, 5, 5, 7, 6, 6};
	//6-twenty 6-thirty 5-forty 5-fifty 5-sixty 7-seventy 6-eighty 6-ninety

	if((num >= 100) && (num <= 999))
	{
		tmp = (num - (num % 10)) / 10;
		tmp = (tmp - (tmp % 10)) / 10;
		count += counts[tmp] + 7; //<number> hundred
		num -= tmp * 100;
		if (num > 0)
			count += 3; //and
	}

	
	if ((num >= 20) && (num <= 99))
	{
		tmp = (num - (num % 10)) / 10;
		count += decine[tmp - 2]; //eighty
		num -= tmp * 10;
	}

	if((num >= 1) && (num <= 19))
		count += counts[num];

	return count;
}