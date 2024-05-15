#include <stdio.h>

#define TOI_DA 100

int chenSauPhanTuLonNhatMangThuc(float mangThuc[], unsigned int& soPhanTu, float x);
unsigned int timViTriPhanTuLonNhat(float mangThuc[], unsigned int soPhanTu);
void nhapSoPhanTu(unsigned int& n);
void nhapMangThuc(float mangThuc[], unsigned int& soPhanTu);
void xuatMangThuc(float mangThuc[], unsigned int soPhanTu);

int main()
{
	float mangThuc[TOI_DA], x = 0;
	unsigned int soPhanTu = 0;
	int maLoi = 0;
	nhapMangThuc(mangThuc, soPhanTu);
	printf("Nhap x: ");
	scanf_s("%f", &x);

	printf("Mang ban dau:\n");
	xuatMangThuc(mangThuc, soPhanTu);

	maLoi = chenSauPhanTuLonNhatMangThuc(mangThuc, soPhanTu, x);

	if (maLoi == -1)
		printf("\n\nMang da dat kich thuoc toi da, khong the mo rong.");
	else
	{
		printf("\n\nMang sau khi chen %.3f:\n", x);
		xuatMangThuc(mangThuc, soPhanTu);
	}

	return 0;
}

int chenSauPhanTuLonNhatMangThuc(float mangThuc[], unsigned int& soPhanTu, float x)
{
	if (soPhanTu == TOI_DA)
		return -1; //ma loi -1: kich thuoc mang toi da

	unsigned int viTri = timViTriPhanTuLonNhat(mangThuc, soPhanTu) + 1;

	for (unsigned int i = soPhanTu; i > viTri; i--)
		mangThuc[i] = mangThuc[i - 1];

	mangThuc[viTri] = x;
	soPhanTu++;

	return 0; //ma loi: khong co loi
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