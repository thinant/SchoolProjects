#include <stdio.h>

int main()
{
	int n = 0;
	int cnt = 0;

	printf("Nhap n: ");		scanf_s("%d", &n);

	if (n % 2 == 0)
	{
		cnt++;
		for (int i = 1; i <= n / 4; i++)
		{
			if (n % (2 * i) == 0) cnt++;
		}
	}

	printf("So uoc so chan cua %d la: %d", n, cnt);

	return 0;
}