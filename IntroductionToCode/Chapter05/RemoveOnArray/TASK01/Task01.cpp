#include <stdio.h>

#define TOI_DA 100

void xoaTaiViTriLe(float mangThuc[], unsigned int& soPhanTu);
void nhapSoPhanTu(unsigned int& n);
void nhapMangThuc(float mangThuc[], unsigned int& soPhanTu);
void xuatMangThuc(float mangThuc[], unsigned int soPhanTu);

int main()
{
	float mangThuc[TOI_DA];
	unsigned int soPhanTu = 0;
	nhapMangThuc(mangThuc, soPhanTu);

	printf("Mang ban dau:\n");
	xuatMangThuc(mangThuc, soPhanTu);

	xoaTaiViTriLe(mangThuc, soPhanTu);

	printf("\n\nMang sau khi xoa nhung phan tu o vi tri le:\n");
	xuatMangThuc(mangThuc, soPhanTu);

	return 0;
}

void xoaTaiViTriLe(float mangThuc[], unsigned int& soPhanTu)
{
	unsigned int soPhanTuMoi = 0;

	for (unsigned int i = 0; i < soPhanTu; i+=2)
	{
		mangThuc[soPhanTuMoi] = mangThuc[i];
		soPhanTuMoi++;
	}

	soPhanTu = soPhanTuMoi;
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