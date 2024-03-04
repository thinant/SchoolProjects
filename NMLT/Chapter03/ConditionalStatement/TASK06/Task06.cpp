#include <stdio.h>

int main()
{
	float a = 0, b = 0, c = 0;
	float maxTemp = 0, minTemp = 0;

	printf("Nhap a: ");		scanf_s("%f", &a);
	printf("Nhap b: ");		scanf_s("%f", &b);
	printf("Nhap c: ");		scanf_s("%f", &c);

	maxTemp = minTemp = a;

	if (b > maxTemp)
	{
		maxTemp = b;
	}
	if (b < minTemp)
	{
		minTemp = b;
	}

	if (c > maxTemp)
	{
		maxTemp = c;
	}
	if (c < minTemp)
	{
		minTemp = c;
	}

	printf("Ba so theo thu tu tang dan: %f, %f, %f.", minTemp, (a + b + c) - (maxTemp + minTemp), maxTemp);

	return 0;
}