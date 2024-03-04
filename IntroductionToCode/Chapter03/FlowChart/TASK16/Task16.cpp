#include <stdio.h>

int main()
{
	int n = 0;
	printf("Nhap n: ");		scanf_s("%d", &n);

	printf("|%d| = ", n);

	if (n < 0) n = -n;

	printf("%d", n);

	return 0;
}