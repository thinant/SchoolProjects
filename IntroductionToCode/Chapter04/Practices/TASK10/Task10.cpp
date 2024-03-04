#include <stdio.h>
#include <math.h>

bool kiemTraTamGiac(double a, double b, double c);
double tinhNuaChuVi(double a, double b, double c);
double tinhDienTich(double a, double b, double c);
double tinhChieuCao(double s, double a);

int main()
{
	double a = 0, b = 0, c = 0;
	double S = 0, ha = 0, hb = 0, hc = 0;

	printf("Nhap canh a: ");	scanf_s("%lf", &a);
	printf("Nhap canh b: ");	scanf_s("%lf", &b);
	printf("Nhap canh c: ");	scanf_s("%lf", &c);

	bool laTamGiac = kiemTraTamGiac(a, b, c);

	if (laTamGiac)
	{
		S = tinhDienTich(a, b, c);
		ha = tinhChieuCao(S, a);
		hb = tinhChieuCao(S, b);
		hc = tinhChieuCao(S, c);

		printf("Dien tich tam giac la: %lf\n", S);
		printf("Chieu cao ung voi canh a la: %lf\n", ha);
		printf("Chieu cao ung voi canh b la: %lf\n", hb);
		printf("Chieu cao ung voi canh c la: %lf", hc);
	}
	else printf("Ba canh khong tao thanh tam giac.");

	return 0;
}

bool kiemTraTamGiac(double a, double b, double c)
{
	bool laTamGiac = false;
	if (a + b > c && a + c > b && b + c > a) laTamGiac = true;

	return laTamGiac;
}

double tinhNuaChuVi(double a, double b, double c)
{
	double p = 0;
	p = (a + b + c) / 2;

	return p;
}

double tinhDienTich(double a, double b, double c)
{
	double p = 0, s = 0;
	p = tinhNuaChuVi(a, b, c);
	s = sqrt(p * (p - a) * (p - b) * (p - c));

	return s;
}

double tinhChieuCao(double s, double a)
{
	double h = 0;
	h = 2 * s / a;

	return h;
}