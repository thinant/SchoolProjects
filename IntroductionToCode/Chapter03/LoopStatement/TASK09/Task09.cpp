#include <stdio.h>

int main()
{
	int m = 0, n = 0;

	printf("Nhap so hang: ");	scanf_s("%d", &m);
	printf("Nhap so dong: ");	scanf_s("%d", &n);

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			if (i == 1 || i == m || j == 1 || j == n)
				printf("* ");
			else printf("  ");

		printf("\n");
	}

	return 0;
}