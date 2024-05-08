#include <stdio.h>

#define TOI_DA 100

int tinhTongBoiCua3Va5(int mangNguyen[], unsigned int soPhanTu);
void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);

int main()
{
	int mangNguyen[TOI_DA], tongBoiCua3Va5 = 0;
	unsigned int soPhanTu = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	tongBoiCua3Va5 = tinhTongBoiCua3Va5(mangNguyen, soPhanTu);

	printf("Tong cac phan tu la boi cua 3 va 5 trong mang la: %d", tongBoiCua3Va5);

	return 0;
}

int tinhTongBoiCua3Va5(int mangNguyen[], unsigned int soPhanTu)
{
	int tongBoiCua3Va5 = 0;
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (mangNguyen[i] % 15 == 0)
			tongBoiCua3Va5 += mangNguyen[i];

	return tongBoiCua3Va5;
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