#include <stdio.h>

int main()
{
	int n = 0;
	int remaining = 0, sorted = 0;

	printf("Nhap n: ");		scanf_s("%d", &n);

	while (n != 0)
	{
		if (remaining == 0)
		{
			sorted = sorted * 10 + n % 10;
			n /= 10;
		}

		if (n == 0) break;

		if(sorted % 10 > n % 10)
		{
			remaining = remaining * 10 + sorted % 10;
			sorted = sorted / 10 * 10 + n % 10;
		}
		else
		{
			remaining = remaining * 10 + n % 10;
		}

		if (n / 10 == 0)
		{
			n = remaining;
			remaining = 0;
		}
		else
		{
			n /= 10;
		}
	}

	printf("So da sap xep: %d.", sorted);

	return 0;
}