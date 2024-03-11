#include <stdio.h>

double tinhNghichDao(unsigned long long int n);
double tinhTongNghichDao(unsigned int n);

int main()
{
	unsigned int n = 0;
	double tongNghichDao = 0;

	printf("Nhap so n: ");		scanf_s("%u", &n);
	tongNghichDao = tinhTongNghichDao(n);

	printf("Tong cua nghich dao giai thua tu 1 toi n la: %lf", tongNghichDao);

	return 0;
}

double tinhNghichDao(unsigned long long int n)
{
	double nghichDao = 0;
	if (n != 0) nghichDao = ((double)1) / n;

	return nghichDao;
}

double tinhTongNghichDao(unsigned int n)
{
	unsigned long long int giaiThua = 1;
	double nghichDao = 0, tongNghichDao = 0;

	for (unsigned int i = 1; i <= n; i++)
	{
		giaiThua *= i;
		nghichDao = tinhNghichDao(giaiThua);
		tongNghichDao += nghichDao;
	}

	return tongNghichDao;
}