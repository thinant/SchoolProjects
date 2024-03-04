#include <stdio.h>

int main()
{
	printf("BANG CUU CHUONG TU 2 DEN 9:\n\n");
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 2; j <= 9; j++)
			printf("%d x %d = %d\t", j, i, j * i);
		printf("\n");
	}

	return 0;
}