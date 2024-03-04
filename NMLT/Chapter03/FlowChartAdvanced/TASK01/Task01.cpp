#include <stdio.h>

int main()
{
	long long int S = 0;
	int n = 0;

	printf("Nhap n: ");		scanf_s("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		long long int t = 1;

		for (int j = 1; j <= i; j++)
			t *= i;
		 S += t;
	}

	printf("S(%d) = %lld", n, S);

	return 0;
}