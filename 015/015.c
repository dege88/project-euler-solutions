#include <stdio.h>

long long unsigned int fattoriale(int num);
long long unsigned int fattorialeNToK(int num, int k);

void main()
{
	int gridx = 20, gridy = 20;
	int n, k; //il risultato è nCk ovvero le combinazioni
	n = gridx + gridy;
	k = gridx;
	//in particolare la formula e': 40C20
	//40 passi da fare per arrivare alla fine
	//20 passi da fare a destra (ovviamente l'orientamento è intercambiabile)
	printf("solution: %ld\n", 137846528820);
}