#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);
int tinhTongPhanTuXungQuanh(int mangNguyen[], unsigned int soPhanTu);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	int mangNguyen[TOI_DA];
	unsigned int soPhanTu = 0;
	int tongPhanTuXungQuanh = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	tongPhanTuXungQuanh = tinhTongPhanTuXungQuanh(mangNguyen, soPhanTu);

	printf("Tong cac phan tu xung quanh trong mang: %d", tongPhanTuXungQuanh);
	return 0;
}

int tinhTongPhanTuXungQuanh(int mangNguyen[], unsigned int soPhanTu)
{
	int tong = 0;

	for (unsigned int i = 1; i < soPhanTu - 1; i++)
		if (mangNguyen[i - 1] + mangNguyen[i + 1] == mangNguyen[i])
			tong += mangNguyen[i];

	return tong;
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

void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		printf("%d ", mangNguyen[i]);
}