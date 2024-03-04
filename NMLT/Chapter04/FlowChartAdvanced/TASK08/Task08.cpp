#include <stdio.h>
#include <math.h>

double tinhS(unsigned int);

int main()
{
	unsigned int n = 0;
	printf("Nhap n: ");		scanf_s("%u", &n);

	double S = tinhS(n);

	printf("S(%u) = %lf", n, S);

	return 0;
}

double tinhS(unsigned int n)
{
	double S = 0;

	for (unsigned int i = n; i >= 1; i--)
	{
		S = sqrt(i + S);
	}

	return S;
}