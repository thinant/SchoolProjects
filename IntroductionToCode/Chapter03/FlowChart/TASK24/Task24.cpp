#include <stdio.h>

int main()
{
	int x = 0;;
	int sum = 0;

	printf("Nhap x: ");		scanf_s("%d", &x);

	for (int i = 1; i <= x / 2; i++)
	{
		if (x % i == 0) sum += i;
	}

	if (sum == x) printf("%d la so hoan thien.", x);
	else printf("%d khong la so hoan thien.", x);
}