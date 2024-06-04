#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n);
void nhapMangThuc(float mangThuc[], unsigned int& soPhanTu);
void xoaPhanTuDeMangTangDan(float mangThuc[], unsigned int& soPhanTu);
void xuatMangThuc(float mangThuc[], unsigned int soPhanTu);

int main()
{
	float mangThuc[TOI_DA];
	unsigned int soPhanTu = 0;
	nhapMangThuc(mangThuc, soPhanTu);

	printf("\nMang cua ban: ");
	xuatMangThuc(mangThuc, soPhanTu);

	xoaPhanTuDeMangTangDan(mangThuc, soPhanTu);

	printf("\nMang cua ban sau khi dieu chinh: ");
	xuatMangThuc(mangThuc, soPhanTu);
	return 0;
}

void xoaPhanTuDeMangTangDan(float mangThuc[], unsigned int& soPhanTu)
{
	float mangPhu[TOI_DA]{};
	for (unsigned int i = 0; i < soPhanTu; i++)
		mangPhu[i] = mangThuc[i];

	unsigned int mangDoDai[TOI_DA]{};
	for (unsigned int i = 0; i < soPhanTu; i++)
		mangDoDai[i] = 1;

	int mangLuuDau[TOI_DA]{};
	for (unsigned int i = 0; i < soPhanTu; i++)
		mangLuuDau[i] = -1;

	unsigned int doDaiLonNhat = 1;
	int viTriCuoiCung = -1;

	for (unsigned int i = 1; i < soPhanTu; i++)
		for (unsigned int j = 0; j < i; j++)
			if (mangPhu[i] >= mangPhu[j] && mangDoDai[i] < mangDoDai[j] + 1)
			{
				mangDoDai[i] = mangDoDai[j] + 1;
				mangLuuDau[i] = j;
				
				if (doDaiLonNhat < mangDoDai[i])
				{
					doDaiLonNhat = mangDoDai[i];
					viTriCuoiCung = i;
				}
			}

	soPhanTu = doDaiLonNhat;

	for (int i = soPhanTu - 1; i >= 0; i--)
	{
		mangThuc[i] = mangPhu[viTriCuoiCung];
		viTriCuoiCung = mangLuuDau[viTriCuoiCung];
	}
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