#include <stdio.h>

int main()
{
	int h = 0;

	printf("Nhap chieu cao: ");	scanf_s("%d", &h);

	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= i; j++)
			if (i == 1 || i == h || j == 1 || j == i)
				printf("* ");
			else printf("  ");

		printf("\n");
	}

	return 0;
}