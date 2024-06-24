#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);
void daoMang(int mangNguyen[], unsigned int soPhanTu);
void hoanVi(int& a, int& b);
bool kiemTraMangCoThuTu(int mangNguyen[], unsigned int soPhanTu);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	int mangNguyen[TOI_DA];
	unsigned int soPhanTu = 0;

	printf("Nhap mang:\n");
	nhapMangNguyen(mangNguyen, soPhanTu);
	
	daoMang(mangNguyen, soPhanTu);

	printf("\nMang sau khi dao: ");
	xuatMangNguyen(mangNguyen, soPhanTu);

	bool coThuTu = kiemTraMangCoThuTu(mangNguyen, soPhanTu);

	if (coThuTu)
		printf("\nMang co thu tu.");
	else 
		printf("\nMang khong co thu tu.");

	return 0;
}

void daoMang(int mangNguyen[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu / 2; i++)
		hoanVi(mangNguyen[i], mangNguyen[soPhanTu - 1 - i]);
}

void hoanVi(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

bool kiemTraMangCoThuTu(int mangNguyen[], unsigned int soPhanTu)
{
	bool coTang = false, coGiam = false;

	for (unsigned int i = 0; i < soPhanTu - 1; i++)
	{
		if (coTang && coGiam)
			return false;
		if (mangNguyen[i] < mangNguyen[i + 1])
			coTang = true;
		else if (mangNguyen[i] > mangNguyen[i + 1])
			coGiam = true;
	}

	return true;
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