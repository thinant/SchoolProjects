#include <stdio.h>

#define TOI_DA 100

int timViTriChanCuoiCung(int mangNguyen[], unsigned int soPhanTu);
void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);

int main()
{
	int mangNguyen[TOI_DA];
	unsigned int soPhanTu = 0;
	int viTriChanCuoiCung = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	viTriChanCuoiCung = timViTriChanCuoiCung(mangNguyen, soPhanTu);

	if (viTriChanCuoiCung == -1)
		printf("Khong co phan tu chan nao trong mang.");
	else
		printf("Phan tu chan cuoi cung la %d, nam o vi tri thu %u.", mangNguyen[viTriChanCuoiCung], viTriChanCuoiCung);

	return 0;
}

int timViTriChanCuoiCung(int mangNguyen[], unsigned int soPhanTu)
{
	for (int i = soPhanTu - 1; i >= 0; i--)
		if (mangNguyen[i] % 2 == 0)
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

void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu)
{
	nhapSoPhanTu(soPhanTu);

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		printf("Nhap phan tu thu %u: ", i);
		scanf_s("%d", &mangNguyen[i]);
	}
}