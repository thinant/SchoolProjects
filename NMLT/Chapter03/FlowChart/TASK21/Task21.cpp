#include <stdio.h>

int main()
{
	int a = 0, b = 0;
	int x = 1;

	printf("Nhap a: ");		scanf_s("%d", &a);
	printf("Nhap b: ");		scanf_s("%d", &b);

	printf("BSCNN cua %d va %d = ", a, b);
	x = a * b;

	while (a != 0 && b != 0)
	{
		if (b > a) b %= a;
		else a %= b;
	}

	printf("%d", x / (a + b));

	return 0;
}