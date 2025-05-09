#include <stdio.h>

#define TOI_DA 100

int timViTriDuongNhoNhat(float mangThuc[], unsigned int soPhanTu);
void nhapSoPhanTu(unsigned int& n);
void nhapMangThuc(float mangThuc[], unsigned int& soPhanTu);

int main()
{
	float mangThuc[TOI_DA];
	unsigned int soPhanTu = 0;
	nhapMangThuc(mangThuc, soPhanTu);

	int viTriDuongNhoNhat = timViTriDuongNhoNhat(mangThuc, soPhanTu);

	if (viTriDuongNhoNhat == -1)
		printf("Khong ton tai gia tri am nao trong mang");
	else
		printf("Gia tri am lon nhat trong mang la %.3f, o vi tri thu %d", mangThuc[viTriDuongNhoNhat], viTriDuongNhoNhat);

	return 0;
}

int timViTriDuongNhoNhat(float mangThuc[], unsigned int soPhanTu)
{
	int viTriDuongNhoNhat = -1;

	for (unsigned int i = 0; i < soPhanTu; i++)
		if ((mangThuc[i] > 0)
			&& (viTriDuongNhoNhat == -1 || mangThuc[i] < mangThuc[viTriDuongNhoNhat]))
			viTriDuongNhoNhat = i;

	return viTriDuongNhoNhat;
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