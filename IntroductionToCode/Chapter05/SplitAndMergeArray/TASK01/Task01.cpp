#include <stdio.h>

#define TOI_DA 100

void tachMangChanLe(int mangNguyen[], unsigned int soPhanTu, int mang_a[], 
					unsigned int& soPhanTu_a, int mang_b[], unsigned int& soPhanTu_b);
void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	int mangNguyen[TOI_DA], mang_a[TOI_DA], mang_b[TOI_DA];
	unsigned int soPhanTu = 0, soPhanTu_a = 0, soPhanTu_b = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	printf("Mang ban dau:\n");
	xuatMangNguyen(mangNguyen, soPhanTu);

	tachMangChanLe(mangNguyen, soPhanTu, mang_a, soPhanTu_a, mang_b, soPhanTu_b);

	printf("\n\nMang le:\n");
	xuatMangNguyen(mang_a, soPhanTu_a);
	printf("\n\nMang chan:\n");
	xuatMangNguyen(mang_b, soPhanTu_b);

	return 0;
}

void tachMangChanLe(int mangNguyen[], unsigned int soPhanTu, int mang_a[],
	unsigned int& soPhanTu_a, int mang_b[], unsigned int& soPhanTu_b)
{
	soPhanTu_a = 0;
	soPhanTu_b = 0;

	for (unsigned int i = 0; i < soPhanTu; i++)
		if (mangNguyen[i] % 2 != 0)
			mang_a[soPhanTu_a++] = mangNguyen[i];
		else
			mang_b[soPhanTu_b++] = mangNguyen[i];
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