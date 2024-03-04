#include <stdio.h>
#include <math.h>
int main()
{
	float a = 0, b = 0, c = 0;
	double x1 = 0, x2 = 0,  x3 = 0, x4 = 0, D = 0;
	int soNghiem = 0;

	printf("Nhap a:	");		scanf_s("%f", &a);
	printf("Nhap b:	");		scanf_s("%f", &b);
	printf("Nhap c:	");		scanf_s("%f", &c);

	if (a == 0)
		if (b == 0)
			if (c == 0) soNghiem = 5;
			else soNghiem = 0;
		else
		{
			if (c < 0 || c == 0)
			{
				x1 = x2 = sqrt(-c / b);
				x3 = x4 = -sqrt(-c / b);

				soNghiem = 2;
				if (x1 == x3) soNghiem = 1;
			}
			else soNghiem = 0;
		}
	else
	{
		D = b * b - 4 * a * c;

		if ((D < 0) || (-b / a < 0 && c / a > 0)) soNghiem = 0;
		else if (D == 0)
		{
			x1 = x2 = sqrt(- b / (2 * a));
			x3 = x4 = -sqrt(-b / (2 * a));
			soNghiem = 2;

			if (x1 == x3) soNghiem = 1;
		}
		else 
		{
			if (c / a < 0)
			{
				x1 = x2 = sqrt((-b + sqrt(D)) / (2 * a));
				x3 = x4 = -sqrt((-b + sqrt(D)) / (2 * a));
				soNghiem = 2;
			}

			else
			{
				x1 = sqrt((-b + sqrt(D)) / (2 * a));
				x2 = -sqrt((-b + sqrt(D)) / (2 * a));
				x3 = sqrt((-b - sqrt(D)) / (2 * a));
				x4 = -sqrt((-b - sqrt(D)) / (2 * a));
				soNghiem = 4;

				if (x1 == x2) soNghiem--;
				if (x3 == x4) soNghiem--;
			}
		}
	}

	if (soNghiem == 0) printf("Phuong trinh vo nghiem.");
	else if (soNghiem == 1) printf("x = %d", 0);
	else if (soNghiem == 2) printf("x1 = %lf\nx2 = %lf", x1, x3);
	else if (soNghiem == 3)
	{
		printf("x1 = %lf\nx2 = %lf\n", x1, x3);
		if (x1 == x2) printf("x3 = %lf", x4);
		else printf("x3 = %lf", x2);
	}
	else if (soNghiem == 4) printf("x1 = %lf\nx2 = %lf\nx3 = %lf\nx4 = %lf", x1, x2, x3, x4);
	else printf("Phuong trinh vo so nghiem.");

	return 0;
}