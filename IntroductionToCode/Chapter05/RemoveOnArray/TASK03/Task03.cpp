#include <stdio.h>

#define TOI_DA 100

void xoaPhanTuNhoHonX(float mangThuc[], unsigned int& soPhanTu, float x);
void nhapSoPhanTu(unsigned int& n);
void nhapMangThuc(float mangThuc[], unsigned int& soPhanTu);
void xuatMangThuc(float mangThuc[], unsigned int soPhanTu);

int main()
{
	float mangThuc[TOI_DA], x = 0;
	unsigned int soPhanTu = 0;
	nhapMangThuc(mangThuc, soPhanTu);

	printf("Nhap so x: ");
	scanf_s("%f", &x);

	printf("Mang ban dau:\n");
	xuatMangThuc(mangThuc, soPhanTu);

	xoaPhanTuNhoHonX(mangThuc, soPhanTu, x);

	printf("\n\nMang sau khi xoa nhung phan tu nho hon %.3f:\n", x);
	xuatMangThuc(mangThuc, soPhanTu);

	return 0;
}

void xoaPhanTuNhoHonX(float mangThuc[], unsigned int& soPhanTu, float x)
{
	unsigned int soPhanTuMoi = 0, k = 0;

	for(; soPhanTuMoi + k < soPhanTu; soPhanTuMoi++)
	{
		for (; soPhanTuMoi + k < soPhanTu; k++)
			if (mangThuc[soPhanTuMoi + k] >= x) break;

		if (soPhanTuMoi + k >= soPhanTu) break;

		mangThuc[soPhanTuMoi] = mangThuc[soPhanTuMoi + k];
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