#include <stdio.h>

#define TOI_DA 100

unsigned int timViTriPhanTuLonNhat(float mangThuc[], unsigned int soPhanTu);
unsigned int timViTriPhanTuNhoNhat(float mangThuc[], unsigned int soPhanTu);
void doiChoPhanTuLonNhatVaNhoNhat(float mangThuc[], unsigned int soPhanTu);
void nhapSoPhanTu(unsigned int& n);
void xuatMangThuc(float mangThuc[], unsigned int soPhanTu);
void nhapMangThuc(float mangThuc[], unsigned int& soPhanTu);

int main()
{
	float mangThuc[TOI_DA];
	unsigned int soPhanTu = 0, viTriPhanTuLonNhat = 0;
	nhapMangThuc(mangThuc, soPhanTu);

	printf("Mang truoc khi doi cho: ");
	xuatMangThuc(mangThuc, soPhanTu);

	doiChoPhanTuLonNhatVaNhoNhat(mangThuc, soPhanTu);

	printf("\nMang sau khi doi cho: ");
	xuatMangThuc(mangThuc, soPhanTu);

	return 0;
}

unsigned int timViTriPhanTuLonNhat(float mangThuc[], unsigned int soPhanTu)
{
	unsigned int viTriPhanTuLonNhat = 0;
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (mangThuc[i] > mangThuc[viTriPhanTuLonNhat])
			viTriPhanTuLonNhat = i;

	return viTriPhanTuLonNhat;
}

unsigned int timViTriPhanTuNhoNhat(float mangThuc[], unsigned int soPhanTu)
{
	unsigned int viTriPhanTuNhoNhat = 0;
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (mangThuc[i] < mangThuc[viTriPhanTuNhoNhat])
			viTriPhanTuNhoNhat = i;

	return viTriPhanTuNhoNhat;
}

void doiChoPhanTuLonNhatVaNhoNhat(float mangThuc[], unsigned int soPhanTu)
{
	unsigned int viTriLonNhat = timViTriPhanTuLonNhat(mangThuc, soPhanTu);
	unsigned int viTriNhoNhat = timViTriPhanTuNhoNhat(mangThuc, soPhanTu);
	
	float bienTrungGian = mangThuc[viTriLonNhat];
	mangThuc[viTriLonNhat] = mangThuc[viTriNhoNhat];
	mangThuc[viTriNhoNhat] = bienTrungGian;
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
	{
		printf("%.3f ", mangThuc[i]);
	}
}