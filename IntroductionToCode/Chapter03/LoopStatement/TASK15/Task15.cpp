#include <stdio.h>

int main()
{
	int a = 0, b = 0;
	int a1 = 0, b1 = 0;
	int ucl = 0, bcn = 0;

	printf("Nhap a: ");		scanf_s("%d", &a);
	printf("Nhap b: ");		scanf_s("%d", &b);

	a1 = a;		b1 = b;

	while (a1 != 0 && b1 != 0)
	{
		if (a1 > b1) a1 = a1 % b1;
		else b1 = b1 % a1;
	}

	if (a1 == 0) ucl = b1;
	else ucl = a1;
	bcn = a * b / ucl;

	printf("Uoc chung lon nhat cua %d va %d la: %d.\n", a, b, ucl);
	printf("Boi chung nho nhat cua %d va %d la: %d.\n", a, b, bcn);

	return 0;
}