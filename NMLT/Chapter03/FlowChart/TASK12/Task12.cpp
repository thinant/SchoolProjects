#include <stdio.h>

int main()
{
	int n = 0;
	double s = 0;

	printf("Nhap n: ");		scanf_s("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		s += ((double)1) / i;
	}

	printf("S(%d) = %lf", n, s);

	return 0;
}