#include <stdio.h>

int main()
{
	int a = 0, b = 0;

	printf("Nhap a: ");		scanf_s("%d", &a);
	printf("Nhap b: ");		scanf_s("%d", &b);

	printf("USCLN cua %d va %d = ", a, b);

	while (a != 0 && b != 0)
	{
		if (b > a) b %= a;
		else a %= b;
	}

	printf("%d", a + b);

	return 0;
}