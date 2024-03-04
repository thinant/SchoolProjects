#include <stdio.h>
#include <math.h>
int main()
{
	float a = 0, b = 0, c = 0;
	double x1 = 0, x2 = 0, D = 0;
	int soNghiem = 0;

	printf("Nhap a:	");		scanf_s("%f", &a);
	printf("Nhap b:	");		scanf_s("%f", &b);
	printf("Nhap c:	");		scanf_s("%f", &c);

	if (a == 0)
		if (b == 0)
			if (c == 0) soNghiem = 3;
			else soNghiem = 0;
		else
		{
			x1 = x2 = -c / b;
			soNghiem = 1;
		}
	else
	{
		D = b * b - 4 * a * c;

		if (D < 0) soNghiem = 0;
		else if (D == 0)
		{
			x1 = x2 = -b / (2 * a);
			soNghiem = 1;
		}
		else
		{
			x1 = (-b + sqrt(D)) / (2 * a);
			x2 = (-b - sqrt(D)) / (2 * a);
			soNghiem = 2;
		}
	}

	if (soNghiem == 0) printf("Phuong trinh vo nghiem.");
	else if (soNghiem == 1) printf("x = %lf", x1);
	else if (soNghiem == 2) printf("x1 = %lf\nx2 = %lf", x1, x2);
	else printf("Phuong trinh vo so nghiem.");

	return 0;
}