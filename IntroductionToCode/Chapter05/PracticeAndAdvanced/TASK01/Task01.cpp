#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n);
void nhapMangThuc(float mangThuc[], unsigned int& soPhanTu);
bool kiemTraPhanTuTonTai(float x, float mangThuc[], unsigned int soPhanTu);
void xuatMangThuc(float mangThuc[], unsigned int soPhanTu);

int main()
{
	float mangThuc[TOI_DA];
	unsigned int soPhanTu = 0;
	nhapMangThuc(mangThuc, soPhanTu);

	printf("Mang cua ban: ");
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

		while (kiemTraPhanTuTonTai(mangThuc[i], mangThuc, i))
		{
			printf("Phan tu ban vua nhap da ton tai. Vui long nhap lai: ");
			scanf_s("%f", &mangThuc[i]);
		}
	}
}

void xuatMangThuc(float mangThuc[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		printf("%.3f ", mangThuc[i]);
}