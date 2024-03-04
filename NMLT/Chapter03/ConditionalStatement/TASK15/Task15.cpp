#include <stdio.h>
#include <math.h>

int main()
{
	int n = 0;
	int can2 = 0;

	printf("Nhap n: ");		scanf_s("%d", &n);

	can2 = (int)sqrt(n);

	if (can2 * can2 == n) printf("%d la so chinh phuong.", n);
	else printf("%d khong la so chinh phuong.", n);

	return 0;
}