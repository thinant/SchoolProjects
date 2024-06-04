#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n);
void nhapMangThuc(float mangThuc[], unsigned int& soPhanTu);
bool kiemTraPhanTuTonTai(float x, float mangThuc[], unsigned int soPhanTu);
void xoaPhanTuTrung(float mangThuc[], unsigned int& soPhanTu);
void xuatMangThuc(float mangThuc[], unsigned int soPhanTu);

int main()
{
	float mangThuc[TOI_DA];
	unsigned int soPhanTu = 0;
	nhapMangThuc(mangThuc, soPhanTu);

	printf("\nMang cua ban: ");
	xuatMangThuc(mangThuc, soPhanTu);

	xoaPhanTuTrung(mangThuc, soPhanTu);

	printf("\nMang cua ban sau khi xoa trung: ");
	xuatMangThuc(mangThuc, soPhanTu);
	return 0;
}

bool kiemTraPhanTuTonTai(float x, float mangThuc[], unsigned int soPhanTu)
{
	for (int i = 0; i < soPhanTu; i++)
		if (mangThuc[i] == x)
			return true;

	return false;
}

void xoaPhanTuTrung(float mangThuc[], unsigned int& soPhanTu)
{
	unsigned int soPhanTuTrung = 0;

	for (unsigned int i = 0; i < soPhanTu - soPhanTuTrung; i++)
	{
		while (kiemTraPhanTuTonTai(mangThuc[i + soPhanTuTrung], mangThuc, i))
			soPhanTuTrung++;

		mangThuc[i] = mangThuc[i + soPhanTuTrung];
	}

	soPhanTu -= soPhanTuTrung;
}


void nhapSoPhanTu(unsigned int& soPhanTu)
{
	printf("Nhap so phan tu: ");	scanf_s("%u", &soPhanTu);

	while (soPhanTu <= 0 || soPhanTu > TOI_DA)
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

void xuatMangThuc(float mangThuc[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		printf("%.3f ", mangThuc[i]);
}