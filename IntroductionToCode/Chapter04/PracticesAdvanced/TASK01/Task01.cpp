#include <stdio.h>

void nhapSoNguyen(unsigned int&, char, unsigned int);
unsigned int timViTri(unsigned int x, unsigned int n);

int main()
{
	unsigned int n = 0, x = 0, gioiHanN = 100000, gioiHanX = 10, viTri = 0;
	nhapSoNguyen(n, 'n', gioiHanN);
	nhapSoNguyen(x, 'x', gioiHanX);

	viTri = timViTri(x, n);

	printf("Vi tri cua %u trong %u: %u", x, n, viTri);

	return 0;	
}



void nhapSoNguyen(unsigned int& n, char c, unsigned int gioiHan)
{
	printf("Nhap so nguyen duong %c: ", c);		scanf_s("%u", &n);

	while (n >= gioiHan)
	{
		printf("So khong hop le. Vui long nhap lai: ");		scanf_s("%u", &n);
	}
}

unsigned int timViTri(unsigned int x, unsigned int n)
{
	int viTri = -1;
	unsigned int soChuSo = 0;

	while (n != 0)
	{
		if (n % 10 == x) viTri = soChuSo;
		n /= 10;
		soChuSo++;
	}

	if (viTri < 0) viTri = soChuSo;
	
	viTri = soChuSo - viTri;

	return viTri;
}