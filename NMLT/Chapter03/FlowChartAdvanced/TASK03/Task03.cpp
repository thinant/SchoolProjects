#include <stdio.h>

int main()
{
	int n = 0;
	long long int t = 1;
	double S = 0;

	printf("Nhap n: ");		scanf_s("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		t *= i;
		S += ((double)1) / t;
	}

	printf("S(%d) = %lf", n, S);

	return 0;
}