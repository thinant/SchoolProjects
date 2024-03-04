#include <stdio.h>

unsigned long long int tinhTong(unsigned int);
unsigned long long int tinhBinhPhuong(unsigned int);

int main()
{
	unsigned int n = 0;

	printf("Nhap so n: ");		scanf_s("%u", &n);

	unsigned long long int tong = tinhTong(n);

	printf("S(%u) = %llu", n, tong);

	return 0;
}

unsigned long long int tinhTong(unsigned int n)
{
	unsigned long long int tong = 0;
	for (unsigned int i = 1; i <= n; i++) tong += tinhBinhPhuong(i);

	return tong;
}

unsigned long long int tinhBinhPhuong(unsigned int n)
{
	unsigned long long int binhPhuong = n*n;
	
	return binhPhuong;
}