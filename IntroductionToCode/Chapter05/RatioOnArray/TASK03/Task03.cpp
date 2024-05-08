#include <stdio.h>

#define TOI_DA 100

unsigned int demPhanTuX(float mangThuc[], unsigned int soPhanTu, float x);
void nhapSoPhanTu(unsigned int& n);
void nhapMangThuc(float mangThuc[], unsigned int& soPhanTu);

int main()
{
	float mangThuc[TOI_DA], x = 0;
	unsigned int soPhanTu = 0, soPhanTuX = 0;
	nhapMangThuc(mangThuc, soPhanTu);

	printf("Nhap so can tim: ");	scanf_s("%f", &x);

	soPhanTuX = demPhanTuX(mangThuc, soPhanTu, x);

	printf("So lan xuat hien cua phan tu %.3f la %u lan.", x, soPhanTuX);

	return 0;
}

unsigned int demPhanTuX(float mangThuc[], unsigned int soPhanTu, float x)
{
	unsigned int soPhanTuX = 0;
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (x == mangThuc[i])
			soPhanTuX++;

	return soPhanTuX;
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

void nhapMangThuc(float mangThuc[], unsigned int& soPhanTu)
{
	nhapSoPhanTu(soPhanTu);

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		printf("Nhap phan tu thu %u: ", i);
		scanf_s("%f", &mangThuc[i]);
	}
}