#include <stdio.h>

int main()
{
	double x = 0, y = 0;

	printf("Nhap x: ");		scanf_s("%lf", &x);
	printf("Nhap y: ");		scanf_s("%lf", &y);

	printf("Tong = %lf\n", x + y);
	printf("Hieu = %lf\n", x - y);
	printf("Tich = %lf\n", x * y);
	if (y != 0) printf("Thuong = %lf", x / y);

	return 0;
}