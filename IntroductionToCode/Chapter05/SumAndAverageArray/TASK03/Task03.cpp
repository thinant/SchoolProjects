#include <stdio.h>

#define TOI_DA 100

unsigned int tinhTongPhanTuNguyenTo(int mangNguyen[], unsigned int soPhanTu);
bool kiemTraSoNguyenTo(int n);
void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);

int main()
{
	int mangNguyen[TOI_DA], x = 0;
	unsigned int soPhanTu = 0, tongPhanTuNguyenTo = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	tongPhanTuNguyenTo = tinhTongPhanTuNguyenTo(mangNguyen, soPhanTu);

	printf("Tong cac phan tu nguyen to trong mang la %u\n", tongPhanTuNguyenTo);

	return 0;
}

unsigned int tinhTongPhanTuNguyenTo(int mangNguyen[], unsigned int soPhanTu)
{
	unsigned int tongPhanTuNguyenTo = 0;

	for (unsigned int i = 0; i < soPhanTu; i++)
		if (kiemTraSoNguyenTo(mangNguyen[i]))
			tongPhanTuNguyenTo += mangNguyen[i];

	return tongPhanTuNguyenTo;
}

bool kiemTraSoNguyenTo(int n)
{
	if (n < 2)
		return false;

	for (unsigned int i = 2; i <= n / 2; i++)
		if (n % i == 0)
			return false;

	return true;
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