#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);
void themPhanTuVaoViTriTangDan(int mangNguyen[], unsigned int& soPhanTu, int x);
void themPhanTuVaoViTriGiamDan(int mangNguyen[], unsigned int& soPhanTu, int x);
void tachMangChanTangLeGiam(int mangNguyen[], unsigned int soPhanTu,
							int mangChan[], unsigned int& soPhanTuChan,
							int mangLe[], unsigned int& soPhanTuLe);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	int mangNguyen[TOI_DA], mangChan[TOI_DA], mangLe[TOI_DA];
	unsigned int soPhanTu = 0, soPhanTuChan = 0, soPhanTuLe = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	tachMangChanTangLeGiam(mangNguyen, soPhanTu, mangChan, soPhanTuChan, mangLe, soPhanTuLe);

	printf("\nMang chan: ");
	xuatMangNguyen(mangChan, soPhanTuChan);
	printf("\nMang le: ");
	xuatMangNguyen(mangLe, soPhanTuLe);

	return 0;
}

void themPhanTuVaoViTriTangDan(int mangNguyen[], unsigned int& soPhanTu, int x)
{
	soPhanTu++;

	for (int i = soPhanTu - 1; i >= 0; i--)
	{
		if (i == 0 || mangNguyen[i - 1] <= x)
		{
			mangNguyen[i] = x;
			break;
		}

		mangNguyen[i] = mangNguyen[i - 1];
	}
}

void themPhanTuVaoViTriGiamDan(int mangNguyen[], unsigned int& soPhanTu, int x)
{
	soPhanTu++;

	for (int i = soPhanTu - 1; i >= 0; i--)
	{
		if (i == 0 || mangNguyen[i - 1] >= x)
		{
			mangNguyen[i] = x;
			break;
		}

		mangNguyen[i] = mangNguyen[i - 1];
	}
}

void tachMangChanTangLeGiam(int mangNguyen[], unsigned int soPhanTu,
	int mangChan[], unsigned int& soPhanTuChan,
	int mangLe[], unsigned int& soPhanTuLe)
{
	soPhanTuChan = 0, soPhanTuLe = 0;
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (mangNguyen[i] % 2 == 0)
			themPhanTuVaoViTriTangDan(mangChan, soPhanTuChan, mangNguyen[i]);
		else
			themPhanTuVaoViTriGiamDan(mangLe, soPhanTuLe, mangNguyen[i]);
}


void nhapSoPhanTu(unsigned int& soPhanTu)
{
	printf("Nhap so phan tu: ");	scanf_s("%u", &soPhanTu);

	while (soPhanTu <= 0 || soPhanTu > TOI_DA)
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

void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		printf("%d ", mangNguyen[i]);
}