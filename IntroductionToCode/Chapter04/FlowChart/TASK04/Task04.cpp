#include <stdio.h>

bool laSoChan(int);
int giaTriCuoiCung(bool, int);

int main()
{
	int n = 0;
	
	printf("Nhap n: ");		scanf_s("%d", &n);

	bool soChan = laSoChan(n);
	int giaTri = giaTriCuoiCung(soChan, n);

	printf("Gia tri xuat ra: %d", giaTri);

	return 0;
}

bool laSoChan(int n)
{
	bool soChan = false;
	if (n % 2 == 0) soChan = true;

	return soChan;
} 

int giaTriCuoiCung(bool soChan, int n)
{
	int giaTri = n;
	if (soChan) giaTri *= 2;

	return giaTri;
}
