#include <stdio.h>

double tinhDienTich(double);
double tinhChuVi(double);

int main()
{
	double banKinh = 0;
	double chuVi = 0, dienTich = 0;

	printf("Nhap ban kinh: ");		scanf_s("%lf", &banKinh);

	dienTich = tinhDienTich(banKinh);
	chuVi = tinhChuVi(banKinh);

	printf("Dien tich hinh tron la: %lf\n", dienTich);
	printf("Chu vi hinh tron la: %lf", chuVi);

	return 0;
}

double tinhDienTich(double banKinh)
{
	double dienTich = 0;
	dienTich = banKinh * banKinh * 3.14;

	return dienTich;
}

double tinhChuVi(double banKinh)
{
	double chuVi = 0;
	chuVi = 2 * banKinh * 3.14;

	return chuVi;
}