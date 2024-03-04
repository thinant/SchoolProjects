#include <stdio.h>

unsigned long long int tinhGiaiThua(unsigned int);
double tinhTong(unsigned int);
double taoPhanSo(unsigned int n);

int main()
{
	unsigned int n = 0;
	printf("Nhap n: ");		scanf_s("%u", &n);

	double tong = tinhTong(n);

	printf("S(%u) = %lf", n, tong);

	return 0;
}

unsigned long long int tinhGiaiThua(unsigned int n)
{
	unsigned long long int giaiThua = 1;

	for (unsigned int i = 1; i <= n; i++)
		giaiThua *= i;

	return giaiThua;
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

double taoPhanSo(unsigned int n)
{
	double phanSo = 1;
	unsigned long long int giaiThua = tinhGiaiThua(n);

	phanSo /= giaiThua;

	return phanSo;
}