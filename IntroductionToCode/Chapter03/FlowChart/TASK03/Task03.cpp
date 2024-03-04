#include <stdio.h>

int main()
{
	double a = 0, b = 0, c = 0;
	bool isSpecial = false;

	printf("Nhap canh a: ");	scanf_s("%lf", &a);
	printf("Nhap canh b ");		scanf_s("%lf", &b);
	printf("Nhap canh c: ");	scanf_s("%lf", &c);

	printf("Tam giac ");
	if ((a * a == b * b + c * c) || (b * b == a * a + c * c) || (c * c == a * a + b * b))
	{
		printf("vuong ");
		isSpecial = true;
	}

	if (a == b || a == c || b == c)
	{
		if (a + b + c == a * 3) printf("deu ");
		else printf("can ");

		isSpecial = true;
	}

	if (!isSpecial) printf("thuong ");

	return 0;
}