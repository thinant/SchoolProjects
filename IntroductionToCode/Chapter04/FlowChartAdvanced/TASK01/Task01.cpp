#include <stdio.h>

unsigned long long int tinhNLuyThuaN(unsigned int);
unsigned long long int tinhTong(unsigned int);

int main()
{
	unsigned int n = 0;
	printf("Nhap n: ");		scanf_s("%u", &n);

	unsigned long long int tong = tinhTong(n);

	printf("S(%u) = %llu", n, tong);

	return 0;
}

unsigned long long int tinhNLuyThuaN(unsigned int n)
{
	unsigned long long int nLuyThuaN = 1;
	
	for (unsigned int i = 1; i <= n; i++)
		nLuyThuaN *= n;

	return nLuyThuaN;
}

unsigned long long int tinhTong(unsigned int n)
{
	unsigned long long int tong = 0;

	for (unsigned int i = 1; i <= n; i++)
	{
		unsigned long long int nLuyThuaN = tinhNLuyThuaN(i);
		tong += nLuyThuaN;
	}

	return tong;
}