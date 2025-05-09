#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);
void themPhanTuVaoViTriTangDan(int mangNguyen[], unsigned int& soPhanTu, int x);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	int mangNguyen[TOI_DA], x = 0;
	unsigned int soPhanTu = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	printf("\nMang cua ban: ");
	xuatMangNguyen(mangNguyen, soPhanTu);

	printf("\nNhap so can chen: ");
	scanf_s("%d", &x);

	themPhanTuVaoViTriTangDan(mangNguyen, soPhanTu, x);

	printf("\nMang cua ban sau khi chen x ma van giu nguyen tinh tang dan: ");
	xuatMangNguyen(mangNguyen, soPhanTu);
	return 0;
}

void themPhanTuVaoViTriTangDan(int mangNguyen[], unsigned int& soPhanTu, int x)
{
	soPhanTu++;

	for (int i = soPhanTu - 1; i >= 0; i--)
	{
		if (mangNguyen[i - 1] <= x)
		{
			mangNguyen[i] = x;
			break;
		}

		mangNguyen[i] = mangNguyen[i - 1];
	}
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

		while (i != 0 && mangNguyen[i - 1] > mangNguyen[i])
		{
			printf("Gia tri khong hop le. Vui long nhap lai: ");
			scanf_s("%d", &mangNguyen[i]);
		}
	}
}

void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		printf("%d ", mangNguyen[i]);
}