#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n);
void nhapMangThuc(float mangThuc[], unsigned int& soPhanTu);
void tinhTongTungDayConGiam(float mangTong[], unsigned int& soLuongTong, float mangThuc[], unsigned int soPhanTu);
void xuatMangThuc(float mangThuc[], unsigned int soPhanTu);

int main()
{
	float mangThuc[TOI_DA], mangTong[TOI_DA];
	unsigned int soPhanTu = 0, soLuongTong = 0;
	nhapMangThuc(mangThuc, soPhanTu);

	tinhTongTungDayConGiam(mangTong, soLuongTong, mangThuc, soPhanTu);

	printf("Tong cac day con: ");
	xuatMangThuc(mangTong, soLuongTong);
	return 0;
}

void tinhTongTungDayConGiam(float mangTong[], unsigned int& soLuongTong, float mangThuc[], unsigned int soPhanTu)
{
	float tong = 0;
	soLuongTong = 0;

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		tong += mangThuc[i];

		if (i + 1 != soPhanTu && mangThuc[i] < mangThuc[i + 1])
		{
			mangTong[soLuongTong++] = tong;
			tong = 0;
		}
	}

	mangTong[soLuongTong++] = tong;
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