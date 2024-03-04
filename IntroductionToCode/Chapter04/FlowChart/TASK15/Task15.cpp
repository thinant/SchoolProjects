#include <stdio.h>

unsigned long long int tinhTongLon(unsigned int);
unsigned long long int tinhTongNho(unsigned int);

int main()
{
	unsigned int n = 0;

	printf("Nhap so n: ");		scanf_s("%u", &n);

	unsigned long long int tong = tinhTongLon(n);

	printf("S(%u) = %llu", n, tong);

	return 0;
}

unsigned long long int tinhTongLon(unsigned int n)
{
	unsigned long long int tong = 0;
	for (unsigned int i = 1; i <= n; i++) tong += tinhTongNho(i);

	return tong;
}

unsigned long long int tinhTongNho(unsigned int n)
{
	unsigned long long int tong = 0;
	for (unsigned int i = 1; i <= n; i++) tong += i;

	return tong;
}