#include <stdio.h>

#define TOI_DA 100

int tinhTongSoHoanThien(int mangNguyen[], unsigned int soPhanTu);
bool kiemTraSoHoanThien(int n);
void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);

int main()
{
	int mangNguyen[TOI_DA], tongSoHoanThien = 0;
	unsigned int soPhanTu = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	tongSoHoanThien = tinhTongSoHoanThien(mangNguyen, soPhanTu);

	printf("Tong cac phan tu la so hoan thien trong mang la: %d", tongSoHoanThien);

	return 0;
}

int tinhTongSoHoanThien(int mangNguyen[], unsigned int soPhanTu)
{
	int tongSoHoanThien = 0;
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (kiemTraSoHoanThien(mangNguyen[i]))
			tongSoHoanThien += mangNguyen[i];

	return tongSoHoanThien;
}

bool kiemTraSoHoanThien(int n)
{
	unsigned int tong = 0;

	for (unsigned int i = 1; i <= n/2; i++)
	{
		if (n % i == 0)
			tong += i;
	}

	return tong == n;
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