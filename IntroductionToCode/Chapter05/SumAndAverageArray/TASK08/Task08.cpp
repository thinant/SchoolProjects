#include <stdio.h>

#define TOI_DA 100

int tinhTongCucTieu(int mangNguyen[], unsigned int soPhanTu);
void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);

int main()
{
	int mangNguyen[TOI_DA], tongCucTieu = 0;
	unsigned int soPhanTu = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	tongCucTieu = tinhTongCucTieu(mangNguyen, soPhanTu);

	printf("Tong cac phan tu cuc tieu trong mang la: %d", tongCucTieu);

	return 0;
}

int tinhTongCucTieu(int mangNguyen[], unsigned int soPhanTu)
{
	int tongCucTieu = 0;
	for (unsigned int i = 0; i < soPhanTu; i++)
		if ((i == 0 && mangNguyen[i] < mangNguyen[i + 1]) ||
			(i == soPhanTu - 1 && mangNguyen[i] < mangNguyen[i - 1]) ||
			(i > 0 && i < soPhanTu - 1 && mangNguyen[i] < mangNguyen[i - 1] && mangNguyen[i] < mangNguyen[i + 1]))
			tongCucTieu += mangNguyen[i];

	return tongCucTieu;
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