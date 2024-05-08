#include <stdio.h>

#define TOI_DA 100

unsigned int demPhanTuChan(int mangNguyen[], unsigned int soPhanTu);
void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);

int main()
{
	int mangNguyen[TOI_DA], x = 0;
	unsigned int soPhanTu = 0, soPhanTuChan = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	soPhanTuChan = demPhanTuChan(mangNguyen, soPhanTu);

	printf("So phan tu chan trong mang la: %u phan tu\n.", soPhanTuChan);
	printf("So phan tu le trong mang la: %u phan tu\n.", soPhanTu - soPhanTuChan);

	return 0;
}

unsigned int demPhanTuChan(int mangNguyen[], unsigned int soPhanTu)
{
	unsigned int soPhanTuChan = 0;

	for (unsigned int i = 0; i < soPhanTu; i++)
		if (mangNguyen[i] % 2 == 0)
			soPhanTuChan++;

	return soPhanTuChan;
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