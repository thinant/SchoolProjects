#include <stdio.h>

double tinhTong(unsigned int);
double tinhPhanSo(unsigned int);

int main()
{
	unsigned int n = 0;

	printf("Nhap so n: ");		scanf_s("%u", &n);

	double tong = tinhTong(n);

	printf("S(%u) = %lf", n, tong);

	return 0;
}

double tinhTong(unsigned int n)
{
	double tong = 0;
	for (unsigned int i = 1; i <= n; i++) tong += tinhPhanSo(i);

	return tong;
}

double tinhPhanSo(unsigned int n)
{
	double phanSo = 1;
	phanSo /= n;

	return phanSo;
}