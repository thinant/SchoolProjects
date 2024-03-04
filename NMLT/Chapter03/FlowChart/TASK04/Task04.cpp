#include <stdio.h>

int main()
{
	int n = 0;

	printf("Nhap n: ");		scanf_s("%d", &n);

	if (n % 2 == 0) n *= 2;

	printf("n = %d.", n);

	return 0;
}