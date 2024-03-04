#include <stdio.h>

double tinhDienTich(double, double);
double tinhChuVi(double, double);

int main()
{
	double chieuDai = 0, chieuRong = 0;
	double chuVi = 0, dienTich = 0;

	printf("Nhap chieu dai: ");		scanf_s("%lf", &chieuDai);
	printf("Nhap chieu rong: ");	scanf_s("%lf", &chieuRong);

	dienTich = tinhDienTich(chieuDai, chieuRong);
	chuVi = tinhChuVi(chieuDai, chieuRong);
	
	printf("Dien tich hinh chu nhat la: %lf\n", dienTich);
	printf("Chu vi hinh chu nhat la: %lf", chuVi);

	return 0;
}

double tinhDienTich(double chieuDai, double chieuRong)
{
	double dienTich = 0;
	dienTich = chieuDai * chieuRong;

	return dienTich;
}

double tinhChuVi(double chieuDai, double chieuRong)
{
	double chuVi = 0;
	chuVi = 2 * (chieuDai + chieuRong);

	return chuVi;
}