#include <stdio.h>

double tinhTongThuc(unsigned int);
unsigned long long int tinhTongNguyen(unsigned int);
double tinhPhanSo(unsigned int);

int main()
{
	unsigned int n = 0;

	printf("Nhap so n: ");		scanf_s("%u", &n);

	double tong = tinhTongThuc(n);

	printf("S(%u) = %lf", n, tong);

	return 0;
}

double tinhTongThuc(unsigned int n)
{
	double tong = 0;
	for (unsigned int i = 1; i <= n; i++) tong += tinhPhanSo(i);

	return tong;
}

unsigned long long int tinhTongNguyen(unsigned int n)
{
	unsigned long long int tong = 0;
	for (unsigned int i = 1; i <= n; i++) tong += i;

	return tong;
}

double tinhPhanSo(unsigned int n)
{
	double phanSo = 1;
	unsigned long long int mau = tinhTongNguyen(n);
	phanSo /= mau;

	return phanSo;
}