#include <stdio.h>

#define TOI_DA 100

void xuatSoThoaDieuKien(float mangThucA[], float mangThucB[], unsigned int soPhanTuA, unsigned int soPhanTuB);
bool kiemTraPhanTuOTrongMang(float x, float mang[], unsigned int soPhanTu);
void xuatMangThuc(float mangThuc[], unsigned int soPhanTu);
void nhapSoPhanTu(unsigned int& n);
void nhapMangThuc(float mangThuc[], unsigned int& soPhanTu);

int main()
{
	float mangThucA[TOI_DA], mangThucB[TOI_DA];
	unsigned int soPhanTuA = 0, soPhanTuB = 0;

	printf("Nhap mang thuc A:\n");
	nhapMangThuc(mangThucA, soPhanTuA);

	printf("Nhap mang thuc B:\n");
	nhapMangThuc(mangThucB, soPhanTuB);

	xuatSoThoaDieuKien(mangThucA, mangThucB, soPhanTuA, soPhanTuB);

	return 0;
}

void xuatSoThoaDieuKien(float mangThucA[], float mangThucB[], unsigned int soPhanTuA, unsigned int soPhanTuB)
{
	float mangChiThuocA[TOI_DA], mangThuocAVaB[TOI_DA];
	unsigned int m = 0, n = 0;

	for (unsigned int i = 0; i < soPhanTuA; i++)
		if (!kiemTraPhanTuOTrongMang(mangThucA[i], mangThucB, soPhanTuB))
		{
			mangChiThuocA[m] = mangThucA[i];
			m++;
		}
		else
		{
			mangThuocAVaB[n] = mangThucA[i];
			n++;
		}

	printf("\nCac phan tu chi thuoc A: ");
	xuatMangThuc(mangChiThuocA, m);

	printf("\nCac phan tu thuoc ca A va B: ");
	xuatMangThuc(mangThuocAVaB, n);
}

bool kiemTraPhanTuOTrongMang(float x, float mang[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (mang[i] == x)
			return true;

	return false;
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

void xuatMangThuc(float mangThuc[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		printf("%.3f ", mangThuc[i]);
	}
}