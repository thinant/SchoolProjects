#include <stdio.h>

bool laSoHoanThien(unsigned int);
unsigned int tinhTongCacUoc(unsigned int);

int main()
{
	unsigned int x = 0;
	printf("Nhap so x: ");		scanf_s("%u", &x);

	if (laSoHoanThien(x)) printf("%d la so hoan thien", x);
	else printf("%d khong la so hoan thien", x);

	return 0;
}

bool laSoHoanThien(unsigned int x)
{
	bool soHoanThien = (x == tinhTongCacUoc(x));

	return soHoanThien;
}

unsigned int tinhTongCacUoc(unsigned int x)
{
	unsigned int tong = 0;
	for (unsigned int i = 1; i <= x / 2; i++)
		if (x % i == 0) tong += i;

	return tong;
}