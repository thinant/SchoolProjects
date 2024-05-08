#include <stdio.h>

#define TOI_DA 100

unsigned int demPhanTuAm(float mangThuc[], unsigned int soPhanTu);
unsigned int demPhanTuDuong(float mangThuc[], unsigned int soPhanTu);
void nhapSoPhanTu(unsigned int& n);
void nhapMangThuc(float mangThuc[], unsigned int& soPhanTu);

int main()
{
	float mangThuc[TOI_DA], x = 0;
	unsigned int soPhanTu = 0, soPhanTuAm = 0, soPhanTuDuong = 0;
	nhapMangThuc(mangThuc, soPhanTu);

	soPhanTuAm = demPhanTuAm(mangThuc, soPhanTu);
	soPhanTuDuong = demPhanTuDuong(mangThuc, soPhanTu);

	printf("So phan tu am trong mang la: %u phan tu\n.", soPhanTuAm);
	printf("So phan tu duong trong mang la: %u phan tu\n.", soPhanTuDuong);

	return 0;
}

unsigned int demPhanTuAm(float mangThuc[], unsigned int soPhanTu)
{
	unsigned int soPhanTuAm = 0;

	for (unsigned int i = 0; i < soPhanTu; i++)
		if (mangThuc[i] < 0)
			soPhanTuAm++;

	return soPhanTuAm;
}
unsigned int demPhanTuDuong(float mangThuc[], unsigned int soPhanTu)
{
	{
		unsigned int soPhanTuDuong = 0;

		for (unsigned int i = 0; i < soPhanTu; i++)
			if (mangThuc[i] > 0)
				soPhanTuDuong++;

		return soPhanTuDuong;
	}
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