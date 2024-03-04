#include <stdio.h>

unsigned long long int tinhTong(unsigned int);

int main()
{
	unsigned int n = 0;

	printf("Nhap so n: ");		scanf_s("%u", &n);

	unsigned long long int tich = tinhTong(n);

	printf("S(%d) = %llu", n, tich);

	return 0;
}

unsigned long long int tinhTong(unsigned int n)
{
	unsigned long long int tong = 0;
	for (unsigned int i = 0; i <= n; i++) tong += (2 * i + 1);

	return tong;
}