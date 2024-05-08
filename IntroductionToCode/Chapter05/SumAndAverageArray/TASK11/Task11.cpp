#include <stdio.h>

#define TOI_DA 100

double tinhTrungBinhSoHoanThien(int mangNguyen[], unsigned int soPhanTu);
bool kiemTraSoHoanThien(int n);
void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);

int main()
{
	int mangNguyen[TOI_DA];
	double trungBinhSoHoanThien = 0;
	unsigned int soPhanTu = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	trungBinhSoHoanThien = tinhTrungBinhSoHoanThien(mangNguyen, soPhanTu);

	printf("TrungBinh cac phan tu la so hoan thien trong mang la: %lf", trungBinhSoHoanThien);

	return 0;
}

double tinhTrungBinhSoHoanThien(int mangNguyen[], unsigned int soPhanTu)
{
	double trungBinhSoHoanThien = 0;
	int soSoHoanThien = 0;

	for (unsigned int i = 0; i < soPhanTu; i++)
		if (kiemTraSoHoanThien(mangNguyen[i]))
		{
			trungBinhSoHoanThien += mangNguyen[i];
			soSoHoanThien++;
		}
		
	trungBinhSoHoanThien /= soSoHoanThien;

	return trungBinhSoHoanThien;
}

bool kiemTraSoHoanThien(int n)
{
	unsigned int tong = 0;

	for (unsigned int i = 1; i <= n / 2; i++)
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