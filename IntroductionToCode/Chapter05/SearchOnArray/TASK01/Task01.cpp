#include <stdio.h>

#define TOI_DA 100

int timXCuoiCung(float mangThuc[], unsigned int soPhanTu, float x);
void nhapSoPhanTu(unsigned int& n);
void nhapMangThuc(float mangThuc[], unsigned int& soPhanTu);

int main()
{
	float mangThuc[TOI_DA], x = 0;
	unsigned int soPhanTu = 0;
	nhapMangThuc(mangThuc, soPhanTu);

	printf("Nhap so can tim: ");	scanf_s("%f", &x);

	int viTriX = timXCuoiCung(mangThuc, soPhanTu, x);

	if (viTriX == -1)
		printf("Khong ton tai gia tri %.3f trong mang", x);
	else
		printf("Vi tri cuoi cung cua %.3f la vi tri thu %d", x, viTriX);

	return 0;
}

int timXCuoiCung(float mangThuc[], unsigned int soPhanTu, float x)
{
	for(int i = soPhanTu - 1; i >= 0; i--)
		if (x == mangThuc[i])
			return i;
	
	return -1;
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