#include <stdio.h>

unsigned long long int tinhGiaiThua(unsigned int);
unsigned long long int tinhTongNguyen(unsigned int);
double tinhTongThuc(unsigned int);
double taoPhanSo(unsigned int n);

int main()
{
	unsigned int n = 0;
	printf("Nhap n: ");		scanf_s("%u", &n);

	double tong = tinhTongThuc(n);

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

unsigned long long int tinhTongNguyen(unsigned int n)
{
	unsigned long long int tong = 0;
	for (unsigned int i = 1; i <= n; i++)
		tong += i;

	return tong;
}

double tinhTongThuc(unsigned int n)
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
	unsigned long long int tongNguyen = tinhTongNguyen(n);
	double phanSo = 1 * tongNguyen;

	unsigned long long int giaiThua = tinhGiaiThua(n);
	phanSo /= giaiThua;

	return phanSo;
}