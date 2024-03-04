#include <stdio.h>

int main()
{
	int n = 0;
	long long int s = 1, S = 0;

	printf("Nhap n: ");		scanf_s("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		s *= i;
		S += s;
	}

	printf("S(%d) = %lld", n, S);

	return 0;
}