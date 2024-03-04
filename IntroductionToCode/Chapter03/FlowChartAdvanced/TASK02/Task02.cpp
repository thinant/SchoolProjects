#include <stdio.h>

int main()
{
	int n = 0;
	double S = 0;

	printf("Nhap n: ");		scanf_s("%d", &n);

	for (int i = 0; i <= n; i++)
	{
		S += ((double)i) / (i + 1);
	}

	printf("S(%d) = %lf", n, S);

	return 0;

}