#include <stdio.h>
#include <string.h>

void main()
{
	char names[5163][50];
	char ordered_names[5163][50];
	int i, j;
	char tmp;
	int min;
	int sum, tmp_sum;
	FILE *fp;

	//load the names list
	fp = fopen("names.txt","r");
	fread(&tmp,sizeof(char),1,fp); //dump the first '\"'
	for(i = 0;i < 5163;i++)
	{
		j = 0;
		fread(&tmp,sizeof(char),1,fp);
		while(tmp != '\"')
		{
			names[i][j] = tmp;
			fread(&tmp,sizeof(char),1,fp);
			j++;
		}
		names[i][j] = '\0';
		fread(&tmp,sizeof(char),1,fp); //dump ','
		fread(&tmp,sizeof(char),1,fp); //dump '\"'
	}
	fclose(fp);

	//order the names list
	for(j = 0,min = 0;j < 5163;j++)
		if(strncmp(names[j],names[min],50) < 0)
			min = j;
	strcpy(ordered_names[0],names[min]);
	for(i = 1;i < 5163;i++)
	{
		for(j = 0,min = -1;j < 5163;j++)
			if(strncmp(names[j],ordered_names[i - 1],50) > 0)
				if(min == -1)
					min = j;
				else if(strncmp(names[j],names[min],50) < 0)
					min = j;
		strcpy(ordered_names[i],names[min]);
	}
	
	//finally calculate the solution
	for(i = 0,sum = 0;i < 5163;i++)
	{
		for(j = 0,tmp_sum = 0;ordered_names[i][j] != 0;j++)
			tmp_sum += ordered_names[i][j] - 'A' + 1;
		sum += tmp_sum * (i + 1);
	}

	printf("solution: %d\n",sum);
}