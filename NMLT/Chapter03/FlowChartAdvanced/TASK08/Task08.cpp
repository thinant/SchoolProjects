#include <stdio.h>
#include <math.h>

int main()
{
	int n = 0;
	double S = 0;

	printf("Nhap n: ");		scanf_s("%d", &n);

	for (int i = n; i >= 1; i--)
	{
		S = sqrt(i + S);
	}

	printf("S(%d) = %lf", n, S);
	return 0;
}