#include <stdio.h>

#define TOI_DA 100

unsigned int timViTriPhanTuLonNhat(float mangThuc[], unsigned int soPhanTu);
void xoaPhanTuLonNhat(float mangThuc[], unsigned int& soPhanTu, unsigned int viTri);
void nhapSoPhanTu(unsigned int& n);
void nhapmangThuc(float mangThuc[], unsigned int& soPhanTu);
void xuatMangThuc(float mangThuc[], unsigned int soPhanTu);

int main()
{
	float mangThuc[TOI_DA];
	unsigned int soPhanTu = 0, viTriPhanTuLonNhat = 0;
	nhapmangThuc(mangThuc, soPhanTu);

	printf("Mang ban dau:\n");
	xuatMangThuc(mangThuc, soPhanTu);

	viTriPhanTuLonNhat = timViTriPhanTuLonNhat(mangThuc, soPhanTu);

	xoaPhanTuLonNhat(mangThuc, soPhanTu, viTriPhanTuLonNhat);

	printf("\n\nMang sau khi xoa phan tu lon nhat:\n");
	xuatMangThuc(mangThuc, soPhanTu);

	return 0;
}

void xoaPhanTuLonNhat(float mangThuc[], unsigned int& soPhanTu, unsigned int viTri)
{
	for (unsigned int i = viTri; i < soPhanTu; i++)
		mangThuc[i] = mangThuc[i + 1];

	soPhanTu--;
}

unsigned int timViTriPhanTuLonNhat(float mangThuc[], unsigned int soPhanTu)
{
	unsigned int viTriPhanTuLonNhat = 0;
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (mangThuc[i] > mangThuc[viTriPhanTuLonNhat])
			viTriPhanTuLonNhat = i;

	return viTriPhanTuLonNhat;
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