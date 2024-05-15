#include <stdio.h>

#define TOI_DA 100

void ghepMangChanLe(int mangNguyen[], unsigned int& soPhanTu, int mang_a[],
	unsigned int soPhanTu_a, int mang_b[], unsigned int soPhanTu_b);
void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	int mang_c[TOI_DA], mang_a[TOI_DA], mang_b[TOI_DA];
	unsigned int soPhanTu = 0, soPhanTu_a = 0, soPhanTu_b = 0;

	printf("Nhap mang a:\n");
	nhapMangNguyen(mang_a, soPhanTu_a);
	printf("Nhap mang b:\n");
	nhapMangNguyen(mang_b, soPhanTu_b);

	ghepMangChanLe(mang_c, soPhanTu, mang_a, soPhanTu_a, mang_b, soPhanTu_b);

	printf("\n\nMang ghep:\n");
	xuatMangNguyen(mang_c, soPhanTu);

	return 0;
}

void ghepMangChanLe(int mang_c[], unsigned int& soPhanTu, int mang_a[],
	unsigned int soPhanTu_a, int mang_b[], unsigned int soPhanTu_b)
{
	soPhanTu = 0;

	for (unsigned int i = 0; i < soPhanTu_a; i++)
		if (mang_a[i] % 2 == 0)
			mang_c[soPhanTu++] = mang_a[i];
	for (unsigned int i = 0; i < soPhanTu_b; i++)
		if (mang_b[i] % 2 == 0)
			mang_c[soPhanTu++] = mang_b[i];
	for (unsigned int i = 0; i < soPhanTu_a; i++)
		if (mang_a[i] % 2 != 0)
			mang_c[soPhanTu++] = mang_a[i];
	for (unsigned int i = 0; i < soPhanTu_b; i++)
		if (mang_b[i] % 2 != 0)
			mang_c[soPhanTu++] = mang_b[i];
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