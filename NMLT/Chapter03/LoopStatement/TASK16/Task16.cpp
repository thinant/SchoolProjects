#include <stdio.h>

int main()
{
	int n = 0;
	long int bin = 1;
	bool isNeg = false;

	printf("Nhap n: ");		scanf_s("%d", &n);

	if (n < 0)
	{
		isNeg = true;
		n = -n;
	}

	while (n != 0)
	{
		bin = bin * 10 + n % 2;
		n /= 2;
	}

	printf("Bieu dien nhi phan dang dau luong: ");
	if (isNeg)	printf("1");
	else printf("0");

	if (bin == 1) printf("0");
	while (bin != 1)
	{
		printf("%d", bin % 10);

		if (bin == 0) printf("0");

		bin /= 10;
	} 

	return 0;
}