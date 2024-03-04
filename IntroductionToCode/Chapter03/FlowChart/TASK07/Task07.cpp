#include <stdio.h>

int main()
{
	int n = 0;
	long long int s = 1;

	printf("Nhap n: ");		scanf_s("%d", &n);

	for (int i = 0; i <= n; i++)
	{
		s *= (2 * i + 1);
	}

	printf("P(%d) = %lld", n, s);

	return 0;
}