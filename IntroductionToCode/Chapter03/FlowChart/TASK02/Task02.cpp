#include <stdio.h>

int main()
{
	int n = 0;
	printf("Nhap n: ");		scanf_s("%d", &n);

	if (n % 2 == 0) printf("%d la so chan.", n);
	else printf("%d la so le.", n);

	return 0;
}