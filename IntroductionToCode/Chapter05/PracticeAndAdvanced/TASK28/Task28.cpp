#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n);
void nhapMangThuc(float mangThuc[], unsigned int& soPhanTu);
void xoayMangKLan(float mangThuc[], unsigned int soPhanTu, unsigned int k);
void xuatMangThuc(float mangThuc[], unsigned int soPhanTu);

int main()
{
	float mangThuc[TOI_DA];
	unsigned int soPhanTu = 0, k = 0;

	printf("Nhap mang:\n");
	nhapMangThuc(mangThuc, soPhanTu);

	printf("Nhap so lan muon xoay phai: ");
	scanf_s("%u", &k);

	printf("\nMang truoc khi xoay:\n");
	xuatMangThuc(mangThuc, soPhanTu);

	xoayMangKLan(mangThuc, soPhanTu, k);

	printf("\nMang sau khi xoay:\n");
	xuatMangThuc(mangThuc, soPhanTu);

	return 0;
}

void xoayMangKLan(float mangThuc[], unsigned int soPhanTu, unsigned int k)
{
	float mangMoRong[TOI_DA]{};

	for (unsigned int i = soPhanTu - k; i < soPhanTu; i++)
		mangMoRong[i - (soPhanTu - k)] = mangThuc[i];

	for (unsigned int i = soPhanTu - 1; i >= k; i--)
		mangThuc[i] = mangThuc[i - k];

	for (unsigned int i = 0; i < k; i++)
		mangThuc[i] = mangMoRong[i];
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