#include <stdio.h>

int main()
{
	int x = 0;
	bool isPrime = true;

	printf("Nhap x: ");	scanf_s("%d", &x);

	if (x < 2) isPrime = false;
	for (int i = 2; i <= x / 2; i++)
	{
		if (x % i == 0)
		{
			isPrime = false;
			break;
		}
	}

	if (isPrime) printf("%d la so nguyen to.", x);
	else printf("%d khong la so nguyen to.", x);

	return 0;

}