#include <stdio.h>
#include <math.h>
#define TOI_DA 100

unsigned int timViTriPhanTuGanXNhat(float mangThuc[], unsigned int soPhanTu, float x);
void xoaPhanTuGanXNhat(float mangThuc[], unsigned int& soPhanTu, unsigned int viTri);
void nhapSoPhanTu(unsigned int& n);
void nhapmangThuc(float mangThuc[], unsigned int& soPhanTu);
void xuatMangThuc(float mangThuc[], unsigned int soPhanTu);

int main()
{
	float mangThuc[TOI_DA], x = 0;
	unsigned int soPhanTu = 0, viTriPhanTuGanXNhat = 0;
	nhapmangThuc(mangThuc, soPhanTu);

	printf("Nhap so x: ");
	scanf_s("%f", &x);

	printf("Mang ban dau:\n");
	xuatMangThuc(mangThuc, soPhanTu);

	viTriPhanTuGanXNhat = timViTriPhanTuGanXNhat(mangThuc, soPhanTu, x);

	xoaPhanTuGanXNhat(mangThuc, soPhanTu, viTriPhanTuGanXNhat);

	printf("\n\nMang sau khi xoa phan tu gan x nhat:\n");
	xuatMangThuc(mangThuc, soPhanTu);

	return 0;
}

void xoaPhanTuGanXNhat(float mangThuc[], unsigned int& soPhanTu, unsigned int viTri)
{
	for (unsigned int i = viTri; i < soPhanTu; i++)
		mangThuc[i] = mangThuc[i + 1];

	soPhanTu--;
}

unsigned int timViTriPhanTuGanXNhat(float mangThuc[], unsigned int soPhanTu, float x)
{
	unsigned int viTriPhanTuGanXNhat = 0;
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (fabs(mangThuc[i] - x) < fabs(mangThuc[viTriPhanTuGanXNhat] - x))
			viTriPhanTuGanXNhat = i;

	return viTriPhanTuGanXNhat;
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

void nhapmangThuc(float mangThuc[], unsigned int& soPhanTu)
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