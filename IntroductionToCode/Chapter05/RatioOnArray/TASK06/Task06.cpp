#include <stdio.h>

#define TOI_DA 100

unsigned int demPhanTuHoanThien(int mangNguyen[], unsigned int soPhanTu);
bool kiemTraSoHoanThien(int n);
void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);

int main()
{
	int mangNguyen[TOI_DA], x = 0;
	unsigned int soPhanTu = 0, soPhanTuHoanThien = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	soPhanTuHoanThien = demPhanTuHoanThien(mangNguyen, soPhanTu);

	printf("So phan tu nguyen to trong mang la: %u phan tu\n.", soPhanTuHoanThien);

	return 0;
}

unsigned int demPhanTuHoanThien(int mangNguyen[], unsigned int soPhanTu)
{
	unsigned int soPhanTuHoanThien = 0;

	for (unsigned int i = 0; i < soPhanTu; i++)
		if (kiemTraSoHoanThien(mangNguyen[i]))
			soPhanTuHoanThien++;

	return soPhanTuHoanThien;
}

bool kiemTraSoHoanThien(int n)
{
	if (n <= 0)
		return false;

	unsigned int tongUoc = 0;

	for (unsigned int i = 1; i <= n / 2; i++)
		if (n % i == 0)
			tongUoc += i;

	return tongUoc == n;
}

void nhapSoPhanTu(unsigned int& soPhanTu)
{
	printf("Nhap so phan tu: ");	scanf_s("%u", &soPhanTu);

	while (soPhanTu == 0 || soPhanTu > TOI_DA)
	{
		printf("So phan tu khong hop le. Vui long nhap lai: ");
		scanf_s("%u", &soPhanTu);
	}
}

void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu)
{
	nhapSoPhanTu(soPhanTu);

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		printf("Nhap phan tu thu %u: ", i);
		scanf_s("%d", &mangNguyen[i]);
	}
}