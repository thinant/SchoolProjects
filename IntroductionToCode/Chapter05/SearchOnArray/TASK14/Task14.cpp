#include <stdio.h>

#define TOI_DA 100

void xuatSoTu1DenX(float mangThuc[], unsigned int soPhanTu, float x);
void nhapSoPhanTu(unsigned int& n);
void nhapMangThuc(float mangThuc[], unsigned int& soPhanTu);

int main()
{
	float mangThuc[TOI_DA], x = 0;
	unsigned int soPhanTu = 0;
	nhapMangThuc(mangThuc, soPhanTu);

	printf("Nhap so can tim: ");	scanf_s("%f", &x);

	xuatSoTu1DenX(mangThuc, soPhanTu, x);

	return 0;
}

void xuatSoTu1DenX(float mangThuc[], unsigned int soPhanTu, float x)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		if ((mangThuc[i] >= 1 && mangThuc[i] <= x) || (mangThuc[i] >= x && mangThuc[i] <= 1))
			printf("%.3f ", mangThuc[i]);
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