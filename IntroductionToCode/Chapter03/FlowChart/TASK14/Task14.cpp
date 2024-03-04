#include <stdio.h>

int main()
{
	int y = 0;
	float x = 0;
	double S = 1;

	printf("Nhap x: ");		scanf_s("%f", &x);
	printf("Nhap y: ");		scanf_s("%d", &y);

	for (int i = 1; i <= y; i++)
	{
		S *= x;
	}

	printf("P(%f, %d) = %lf", x, y, S);

	return 0;
}