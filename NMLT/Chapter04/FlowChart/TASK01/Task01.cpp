#include <stdio.h>

//prototypes
double Tong(double, double);
double Hieu(double, double);
double Tich(double, double);
double Thuong(double, double);

//main function
int main()
{
	double x = 0, y = 0;
	printf("Nhap vao x: ");		scanf_s("%lf", &x);
	printf("Nhap vao y: ");		scanf_s("%lf", &y);

	printf("%lf + %lf = %lf\n", x, y, Tong(x, y));
	printf("%lf - %lf = %lf\n", x, y, Hieu(x, y));
	printf("%lf * %lf = %lf\n", x, y, Tich(x, y));
	if (y != 0) printf("%lf + %lf = %lf\n", x, y, Tong(x, y));
	else printf("Khong the chia cho 0\n");

	return 0;
}

//functions
double Tong(double x, double y)
{
	double S = x + y;
	return S;
}

double Hieu(double x, double y)
{
	double M = x - y;
	return M;
}

double Tich(double x, double y)
{
	double T = x * y;
	return T;
}

double Thuong(double x, double y)
{
	double D = x / y;
	return D;
}