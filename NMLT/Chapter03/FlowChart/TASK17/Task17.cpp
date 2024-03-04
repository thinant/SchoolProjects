#include <stdio.h>

int main()
{
	int n = 0;
	int max = 0;

	printf("Nhap n: ");		scanf_s("%d", &n);

	while (n > 0)
	{
		if (n % 10 > max)	max = n % 10;
		n /= 10;
	}

	printf("Chu so lon nhat = %d", max);

	return 0;
}