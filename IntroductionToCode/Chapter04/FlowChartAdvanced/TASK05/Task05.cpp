#include <stdio.h>
#include <math.h>

void nhapHeSo(char, double&);
unsigned int timBacPT(double, double);
double giaiPTBac1(double, double);
double tinhDelta(double, double, double);
void giaiPTBac2(double, double, double, double&, double&, unsigned int&);
void giaiPT(double, double, double, double&, double&, unsigned int&);
void inKetQua(double, double, unsigned int);

int main()
{
	double a = 0, b = 0, c = 0;
	double x1 = 0, x2 = 0;
	unsigned int soNghiem = 0;

	nhapHeSo('a', a);
	nhapHeSo('b', b);
	nhapHeSo('c', c);

	printf("\nPhuong trinh: %lf*x^2 + %lf*x + %lf = 0\n", a, b, c);

	giaiPT(a, b, c, x1, x2, soNghiem);

	inKetQua(x1, x2, soNghiem);

	return 0;
}

void nhapHeSo(char c, double& a)
{
	printf("Nhap he so %c: ", c);	scanf_s("%lf", &a);
}

unsigned int timBacPT(double a, double b)
{
	unsigned int bac = 0;

	if (a == 0 && b != 0) bac = 1;
	else if (a != 0) bac = 2;

	return bac;
}

double giaiPTBac1(double a, double b)
{
	double nghiem = 0;
	nghiem = - b / a;

	return nghiem;
}

double tinhDelta(double a, double b, double c)
{
	double delta = 0;
	delta = b* b - 4 * a * c;

	return delta;
}

void giaiPTBac2(double a, double b, double c, double& x1, double& x2, unsigned int& soNghiem)
{
	double delta = 0;
	delta = tinhDelta(a, b, c);

	if (delta < 0) soNghiem = 0;
	else if (delta == 0)
	{
		soNghiem = 1;
		x1 = - b / (2 * a);
		x2 = x1;
	}
	else
	{
		soNghiem = 2;
		x1 = (-b + sqrt(delta)) / (2 * a);
		x2 = (-b - sqrt(delta)) / (2 * a);
	}
}

void giaiPT(double a, double b, double c, double& x1, double& x2, unsigned int& soNghiem)
{
	unsigned int bac = 0;
	bac = timBacPT(a, b);

	if (bac == 0)
	{
		if (c == 0) soNghiem = 3;
		else soNghiem = 0;
	}
	else if (bac == 1)
	{
		soNghiem = 1;
		x1 = giaiPTBac1(b, c);
		x2 = x1;
	}
	else giaiPTBac2(a, b, c, x1, x2, soNghiem);
}

void inKetQua(double x1, double x2, unsigned int soNghiem)
{
	if (soNghiem == 0) printf("Phuong trinh vo nghiem.");
	else if (soNghiem == 1) printf("x = %lf", x1);
	else if (soNghiem == 2)
	{
		printf("x1 = %lf\n", x1);
		printf("x2 = %lf", x2);
	}
	else printf("Phuong trinh vo so nghiem");
}