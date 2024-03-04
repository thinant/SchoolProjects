#include <stdio.h>

double taoPhanSo(unsigned int);
double tinhTong(unsigned int);

int main()
{
	unsigned int n = 0;
	printf("Nhap n: ");		scanf_s("%u", &n);

	double tong = tinhTong(n);

	printf("S(%u) = %lf", n, tong);

	return 0;
}

double taoPhanSo(unsigned int n)
{
	double phanSo = 1*n;

	phanSo /= (n + 1);

	return phanSo;
}

double tinhTong(unsigned int n)
{
	double tong = 0;

	for (unsigned int i = 1; i <= n; i++)
	{
		double phanSo = taoPhanSo(i);
		tong += phanSo;
	}

	return tong;
}