#include <stdio.h>

int main()
{
	int n = 0;
	long long int s = 0;

	printf("Nhap n: ");		scanf_s("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		s += (i * i);
	}

	printf("S(%d) = %lld", n, s);

	return 0;
}