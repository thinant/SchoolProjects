#include <stdio.h>

int main()
{
	float a = 0, b = 0, c = 0;
	printf("Nhap a: ");	scanf_s("%f", &a);
	printf("Nhap b: ");	scanf_s("%f", &b);
	printf("Nhap c: ");	scanf_s("%f", &c);

	float max = a;

	if (b > max) max = b;
	if (c > max) max = c;

	printf("Gia tri lon nhat: %f", max);

	return 0;
}