#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);
void tinhTongTungDayConTang(int mangTong[], unsigned int& soLuongTong, int mangNguyen[], unsigned int soPhanTu);
double tinhTrungBinhCacTongDayConTang(int mangNguyen[], unsigned int soPhanTu);
double tinhTrungBinhDay(int mangNguyen[], unsigned int soPhanTu);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	int mangNguyen[TOI_DA];
	unsigned int soPhanTu = 0;
	double trungBinhTongDayTang = 0;

	nhapMangNguyen(mangNguyen, soPhanTu);
	trungBinhTongDayTang = tinhTrungBinhCacTongDayConTang(mangNguyen, soPhanTu);

	printf("Trung binh cac tong day con tang trong mang: %lf", trungBinhTongDayTang);

	return 0;
}

void tinhTongTungDayConTang(int mangTong[], unsigned int& soLuongTong, int mangNguyen[], unsigned int soPhanTu)
{
	int tong = 0;
	soLuongTong = 0;

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		tong += mangNguyen[i];

		if (i + 1 != soPhanTu && mangNguyen[i] > mangNguyen[i + 1])
		{
			mangTong[soLuongTong++] = tong;
			tong = 0;
		}
	}

	mangTong[soLuongTong++] = tong;
}

double tinhTrungBinhCacTongDayConTang(int mangNguyen[], unsigned int soPhanTu)
{
	int mangTong[TOI_DA];
	unsigned int soLuongTong = 0;
	double trungBinhTongDay = 0;

	tinhTongTungDayConTang(mangTong, soLuongTong, mangNguyen, soPhanTu);

	trungBinhTongDay = tinhTrungBinhDay(mangTong, soLuongTong);

	return trungBinhTongDay;
}

double tinhTrungBinhDay(int mangNguyen[], unsigned int soPhanTu)
{

	double tong = 0;

	for (unsigned int i = 0; i < soPhanTu; i++)
		tong += mangNguyen[i];

	return tong / soPhanTu;
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