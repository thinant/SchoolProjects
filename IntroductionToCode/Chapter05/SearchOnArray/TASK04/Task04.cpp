#include <stdio.h>

#define TOI_DA 100

void inViTriCacSoNguyenTo(int mangNguyen[], unsigned int soPhanTu);
bool kiemTraSoNguyenTo(int n);
void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);

int main()
{
	int mangNguyen[TOI_DA];
	unsigned int soPhanTu = 0, viTriPhanTuLonNhat = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	inViTriCacSoNguyenTo(mangNguyen, soPhanTu);

	return 0;
}

void inViTriCacSoNguyenTo(int mangNguyen[], unsigned int soPhanTu)
{
	unsigned int soCacSoNguyenTo = 0;

	printf("Cac so nguyen to trong mang: ");
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (kiemTraSoNguyenTo(mangNguyen[i]))
		{
			printf("\nSo %d o vi tri %u", mangNguyen[i], i);
			soCacSoNguyenTo++;
		}

	if (soCacSoNguyenTo == 0)
		printf("Khong co so nao.");
}

bool kiemTraSoNguyenTo(int n)
{
	if (n < 2) return false;

	for (unsigned int i = 2; i <= n / 2; i++)
		if (n % i == 0) return false;

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