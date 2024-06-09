#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);
void lietKeCacDayConTangDan(int mangNguyen[], unsigned int soPhanTu);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	int mangNguyen[TOI_DA];
	unsigned int soPhanTu = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	printf("\nMang cua ban: ");
	xuatMangNguyen(mangNguyen, soPhanTu);

	lietKeCacDayConTangDan(mangNguyen, soPhanTu);

	return 0;
}

void lietKeCacDayConTangDan(int mangNguyen[], unsigned int soPhanTu)
{
	unsigned int mangViTriDayConTangDan[TOI_DA]{}, soDayCon = 0, soDayConTangDan = 0;
	
	for (unsigned int i = 1; i < soPhanTu; i++)
		if (i == 0 || mangNguyen[i] < mangNguyen[i - 1])
			 mangViTriDayConTangDan[soDayCon++] = i;

	printf("\nCac day con tang dan trong mang:\n");
	for (unsigned int i = 0; i < soDayCon; i++)
		if (i == soDayCon - 1 && mangViTriDayConTangDan[i] != soPhanTu - 1)
		{
			xuatMangNguyen(mangNguyen + mangViTriDayConTangDan[i], soPhanTu - mangViTriDayConTangDan[i]);
			printf("\n");
			soDayConTangDan++;
		}
		else if (mangViTriDayConTangDan[i + 1] - mangViTriDayConTangDan[i] != 1)
		{
			xuatMangNguyen(mangNguyen + mangViTriDayConTangDan[i], mangViTriDayConTangDan[i + 1] - mangViTriDayConTangDan[i]);
			printf("\n");
			soDayConTangDan++;
		}

	if (soDayConTangDan == 0) printf("\nMang khong co day con tang dan nao.");
	else printf("So day con tang dan la %u day.", soDayConTangDan);
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