#include <stdio.h>

bool laSoChan(int);

int main()
{
	int n = 0;
	printf("Nhap n: ");		scanf_s("%d", &n);
	if (laSoChan(n)) printf("%d la so chan", n);
	else printf("%d la so le", n);

	return 0;
}

bool laSoChan(int n)
{
	bool soChan = false;
	soChan = (n % 2 == 0);

	return soChan;
}