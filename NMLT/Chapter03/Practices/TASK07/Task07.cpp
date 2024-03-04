#include <stdio.h>

int main()
{
	int h = 0;
	printf("Nhap chieu dai: ");		scanf_s("%d", &h);

	//in nua tren
	for (int i = 1; i <= h - 1; i++)
	{
		//in canh so 1
		for (int j = 1; j <= i; j++)				printf("*");
		for (int j = 1; j <= h - 1 - i; j++)		printf(" ");

		//in phan giua 2 canh
		printf("*");

		//in canh so 2
		for (int j = 1; j <= h - i; j++)			printf("*");
		for (int j = 1; j <= i - 1; j++)			printf(" ");
		
		printf("\n");
	}

	//in doan giua
	for (int i = 1; i <= 2 * h - 1; i++)				printf("*");
	printf("\n");

	//in nua tren
	for (int i = 1; i <= h - 1; i++)
	{
		//in canh so 1
		for (int j = 1; j <= h - 1 - i; j++)		printf(" ");
		for (int j = 1; j <= i; j++)				printf("*");
		
		//in phan giua 2 canh
		printf("*");

		//in canh so 2
		for (int j = 1; j <= i - 1; j++)			printf(" ");
		for (int j = 1; j <= h - i; j++)			printf("*");
		
		printf("\n");
	}

	return 0;
}