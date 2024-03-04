#include <stdio.h>

void xuatLoaiTamGiac(bool, unsigned int);
bool laTamGiac(double, double, double);
bool laTamGiacVuong(double, double, double);
unsigned int soCanhBangNhau(double, double, double);

int main()
{
	double a = 0, b = 0, c = 0;
	printf("Nhap canh a: ");	scanf_s("%lf", &a);
	printf("Nhap canh b: ");	scanf_s("%lf", &b);
	printf("Nhap canh c: ");	scanf_s("%lf", &c);

	if (laTamGiac(a, b, c))
	{
		bool tamGiacVuong = laTamGiacVuong(a, b, c);
		unsigned int canhBangNhau = soCanhBangNhau(a, b, c);

		xuatLoaiTamGiac(tamGiacVuong, canhBangNhau);
	}
	else printf("Ba canh khong tao thanh tam giac.");

	return 0;
}


void xuatLoaiTamGiac(bool tamGiacVuong, unsigned int canhBangNhau)
{
	if (tamGiacVuong)
	{
		if (canhBangNhau == 2) printf("Tam giac vuong can.");
		else printf("Tam giac vuong.");
	}
	else
	{
		if (canhBangNhau == 3) printf("Tam giac deu.");
		else if (canhBangNhau == 2) printf("Tam giac can.");
		else printf("Tam giac thuong.");
	}
}

bool laTamGiac(double a, double b, double c)
{
	bool tamGiac = false;

	if (a + b > c && a + c > b && b + c > a) tamGiac = true;

	return tamGiac;
}


bool laTamGiacVuong(double a, double b, double c)
{
	bool tamGiacVuong = false;

	if (a * a == b * b + c * c || 
		b * b == a * a + c * c || 
		c * c == a * a + b * b)	tamGiacVuong = true;

	return tamGiacVuong;
}

unsigned int soCanhBangNhau(double a, double b, double c)
{
	int soCanh = 0;

	if (a == b && b == c)	soCanh = 3;
	else if (a == b || b == c || c == a) soCanh = 2;
	
	return soCanh;
}