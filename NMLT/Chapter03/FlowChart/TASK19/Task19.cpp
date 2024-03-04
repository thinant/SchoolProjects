#include <stdio.h>

int main()
{
	int n = 0, k = 0;
	int s = 1;
	
	printf("Nhap n: ");		scanf_s("%d", &n);
	printf("Nhap k: ");		scanf_s("%d", &k);

	for (int i = 2; i <= k; i++)
	{
		s *= 10;
	}

	printf("Chu so dau tien cua %d: %d", n, n / s);

	return 0;
}