#include <stdio.h>

int main()
{
	int n = 0;
	printf("Nhap n: "); scanf_s("%d", &n);

	if (n > 5) n += 2;
	else n = 0;

	printf("n = %d", n);

	return 0;
}