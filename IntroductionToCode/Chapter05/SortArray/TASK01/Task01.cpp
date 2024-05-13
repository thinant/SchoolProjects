#include <stdio.h>

#define TOI_DA 100

void hoanViSoThuc(float& a, float& b);
void sapXepGiamMangThuc(float mangThuc[], unsigned int soPhanTu);
void nhapSoPhanTu(unsigned int& n);
void nhapMangThuc(float mangThuc[], unsigned int& soPhanTu);
void xuatMangThuc(float mangThuc[], unsigned int soPhanTu);

int main()
{
	float mangThuc[TOI_DA];
	unsigned int soPhanTu = 0;
	nhapMangThuc(mangThuc, soPhanTu);

	printf("Mang truoc khi sap xep: ");
	xuatMangThuc(mangThuc, soPhanTu);

	sapXepGiamMangThuc(mangThuc, soPhanTu);

	printf("\nMang sau khi sap xep: ");
	xuatMangThuc(mangThuc, soPhanTu);

	return 0;
}

void hoanViSoThuc(float& a, float& b)
{
	float trungGian = a;
	a = b;
	b = trungGian;
}

void sapXepGiamMangThuc(float mangThuc[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu - 1; i++)
		for (unsigned j = i + 1; j < soPhanTu; j++)
			if (mangThuc[i] < mangThuc[j])
				hoanViSoThuc(mangThuc[i], mangThuc[j]);
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
		printf("%.3f ", mangThuc[i]);
}