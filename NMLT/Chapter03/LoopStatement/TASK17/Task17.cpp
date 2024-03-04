#include <stdio.h>

int main()
{
	int n = 0;
	int count = 0;

	printf("Nhap so: ");	scanf_s("%d", &n);

	for (int i = 1; i <= n / 2; i++)
		if (n % i == 0) count++;
	count++;

	printf("So uoc so cua %d la: %d.", n, count);

	return 0;
}