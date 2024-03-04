#include <stdio.h>

unsigned int tinhGiaTriTuyetDoi(int);

int main()
{
	int n = 0;
	printf("Nhap n: ");		scanf_s("%d", &n);

	unsigned int giaTri = tinhGiaTriTuyetDoi(n);

	printf("|%d| = %u", n, giaTri);

	return 0;
}

unsigned int tinhGiaTriTuyetDoi(int n)
{
	unsigned int giaTri = 0;
	if (n < 0) giaTri -= n;
	else giaTri = n;

	return giaTri;
}