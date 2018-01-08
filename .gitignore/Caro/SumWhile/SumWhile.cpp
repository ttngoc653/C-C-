#include<stdio.h>

int main() {
	int sum = 0,i=0;
	do
	{
		printf("ENTER NUMBER: ");
		scanf("%d", &i);
		sum += i;
		printf("SUM = %d\n", sum);
	} while (i!=0);
	return 1;
}