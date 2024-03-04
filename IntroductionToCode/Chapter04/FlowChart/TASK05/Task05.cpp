#include <stdio.h>

bool lonHon5(int);
int giaTriCuoiCung(bool, int);

int main()
{
	int n = 0;

	printf("Nhap n: ");		scanf_s("%d", &n);

	bool soLon = lonHon5(n);
	int giaTri = giaTriCuoiCung(soLon, n);

	printf("Gia tri xuat ra: %d", giaTri);

	return 0;
}

bool lonHon5(int n)
{
	bool soLon = false;
	if (n > 5) soLon = true;

	return soLon;
}

int giaTriCuoiCung(bool lonHon5, int n)
{
	int giaTri = n;
	if (lonHon5) giaTri += 2;

	return giaTri;
}
