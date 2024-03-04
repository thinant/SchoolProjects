#include <stdio.h>

int main()
{
	int n = 0;
	int s = 0;
	double S = 0;

	printf("Nhap n: ");		scanf_s("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		s += i;
		S += ((double)1 / s);
	}

	printf("S(%d) = %lf", n, S);

	return 0;
}