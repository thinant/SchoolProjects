#include <stdio.h>

#define TOI_DA 100

int tinhTongLeNguyen(int mangNguyen[], unsigned int soPhanTu);
void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);

int main()
{
	int mangNguyen[TOI_DA], tongLe = 0;
	unsigned int soPhanTu = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	tongLe = tinhTongLeNguyen(mangNguyen, soPhanTu);

	printf("Tong cac phan tu le trong mang la: %d", tongLe);

	return 0;
}

int tinhTongLeNguyen(int mangNguyen[], unsigned int soPhanTu)
{
	int tongLeNguyen = 0;
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (mangNguyen[i] % 2 != 0)
			tongLeNguyen += mangNguyen[i];

	return tongLeNguyen;
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