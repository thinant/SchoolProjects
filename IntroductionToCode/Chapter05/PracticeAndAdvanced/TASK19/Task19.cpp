#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);
void timDayConTangDanDaiNhat(int mangNguyen[], unsigned int soPhanTu, unsigned int& viTriBatDau, unsigned int& doDaiDay);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	int mangNguyen[TOI_DA];
	unsigned int soPhanTu = 0, viTriBatDau = 0, doDaiDay = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	printf("\nMang cua ban: ");
	xuatMangNguyen(mangNguyen, soPhanTu);

	timDayConTangDanDaiNhat(mangNguyen, soPhanTu, viTriBatDau, doDaiDay);

	printf("\nDay con tang dan dai nhat la day sau:\n");
	xuatMangNguyen(mangNguyen + viTriBatDau, doDaiDay);

	return 0;
}

void timDayConTangDanDaiNhat(int mangNguyen[], unsigned int soPhanTu, unsigned int& viTriBatDau, unsigned int& doDaiDay)
{
	unsigned int viTriDayMoi = 0, doDaiDayMoi = 1;
	viTriBatDau = 0, doDaiDay = 1;

	for (unsigned int i = 1; i < soPhanTu; i++)
		if (mangNguyen[i] >= mangNguyen[i - 1])
			doDaiDayMoi++;
		else 
		{
			if (doDaiDayMoi > doDaiDay)
			{
				doDaiDay = doDaiDayMoi;
				viTriBatDau = viTriDayMoi;
			}
			
			doDaiDayMoi = 1;
			viTriDayMoi = i;
		}

	if (doDaiDayMoi > doDaiDay)
	{
		doDaiDay = doDaiDayMoi;
		doDaiDayMoi = 1;
		viTriBatDau = viTriDayMoi;
		viTriDayMoi = soPhanTu - doDaiDay;
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
	}
}

void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		printf("%d ", mangNguyen[i]);
}