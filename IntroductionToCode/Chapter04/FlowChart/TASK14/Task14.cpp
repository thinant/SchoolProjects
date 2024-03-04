#include <stdio.h>

double tinhLuyThua(double, unsigned int);

int main()
{
	double x = 0;
	unsigned int y = 0;

	printf("Nhap x: ");		scanf_s("%lf", &x);
	printf("Nhap y: ");		scanf_s("%u", &y);

	double luyThua = tinhLuyThua(x, y);

	printf("P(%lf, %u) = %lf ^ %u = %lf", x, y, x, y, luyThua);

	return 0;
}

double tinhLuyThua(double x, unsigned int y)
{
	double luyThua = 1;
	for (unsigned int i = 1; i <= y; i++)
		luyThua *= x;

	return luyThua;
}
