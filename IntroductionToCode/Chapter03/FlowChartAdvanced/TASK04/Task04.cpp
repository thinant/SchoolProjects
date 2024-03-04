#include <stdio.h>

int main()
{
	int n = 0;
	int s = 0;
	long long int t = 1;
	double S = 0;

	printf("Nhap n: ");		scanf_s("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		s += i;
		t *= i;

		S += ((double)s) / t;
	}

	printf("S(%d) = %lf", n, S);

	return 0;
}