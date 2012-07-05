#include <stdio.h>

void main()
{
	int days, date_day, date_month, date_year, count;

	days = 0;
	date_day = 1;
	date_month = 1;
	date_year = 1900;
	count = 0;

	while(date_year <= 2000)
	{
		if((date_day == 1) && (date_year >= 1901) && ((days % 7) == 6))
			count++;

		days++;
		date_day++;

		if((date_day > 31) && ((date_month == 1) || (date_month == 3) || (date_month == 5) || (date_month == 7) || (date_month == 8) || (date_month == 10) || (date_month == 12)))
		{
			date_day = 1;
			date_month += 1;
		}
		else if((date_day > 30) && ((date_month == 4) || (date_month == 6) || (date_month == 9) || (date_month == 11)))
		{
			date_day = 1;
			date_month += 1;
		}
		else if((date_day > 29) && (date_month == 2) && ((date_year % 4) == 0) && (((date_year % 100) != 0) || ((date_year % 400) == 0)))
		{
			date_day = 1;
			date_month += 1;
		}
		else if((date_day > 28) && (date_month == 2) && (!(((date_year % 4) == 0) && (((date_year % 100) != 0) || ((date_year % 400) == 0)))))
		{
			date_day = 1;
			date_month += 1;
		}

		if(date_month > 12)
		{
			date_month = 1;
			date_year++;
		}
	}

	printf("result: %d\n", count);
}