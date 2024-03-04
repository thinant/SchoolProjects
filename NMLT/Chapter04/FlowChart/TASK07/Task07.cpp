#include <stdio.h>

unsigned long long int tinhTich(unsigned int);

int main()
{
	unsigned int n = 0;

	printf("Nhap so n: ");		scanf_s("%u", &n);

	unsigned long long int tich = tinhTich(n);

	printf("P(%u) = %llu", n, tich);

	return 0;
}

unsigned long long int tinhTich(unsigned int n)
{
	unsigned long long int tich = 1;
	for (unsigned int i = 1; i <= n; i++) tich *= (2 * i + 1);

	return tich;
}