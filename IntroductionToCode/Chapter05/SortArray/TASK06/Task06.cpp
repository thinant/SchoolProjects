#include <stdio.h>

#define TOI_DA 100

void hoanViSoNguyen(int& a, int& b);
void sapXepAmDuong(int mangNguyen[], unsigned int soPhanTu);
void sapXepMangNguyen(int mangNguyen[], unsigned int soPhanTu, bool laMangChan);
void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	int mangNguyen[TOI_DA];
	unsigned int soPhanTu = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	printf("Mang truoc khi sap xep: ");
	xuatMangNguyen(mangNguyen, soPhanTu);

	sapXepAmDuong(mangNguyen, soPhanTu);

	printf("\nMang sau khi sap xep: ");
	xuatMangNguyen(mangNguyen, soPhanTu);

	return 0;
}

void hoanViSoNguyen(int& a, int& b)
{
	int trungGian = a;
	a = b;
	b = trungGian;
}

void sapXepAmDuong(int mangNguyen[], unsigned int soPhanTu)
{
	sapXepMangNguyen(mangNguyen, soPhanTu, true);
	sapXepMangNguyen(mangNguyen, soPhanTu, false);
}

void sapXepMangNguyen(int mangNguyen[], unsigned int soPhanTu, bool laSapXepAm)
{
	for (unsigned int i = 0; i < soPhanTu - 1; i++)
		if ((laSapXepAm && mangNguyen[i] < 0) || (!laSapXepAm && mangNguyen[i] > 0))
			for (unsigned int j = i + 1; j < soPhanTu; j++)
				if (mangNguyen[i]*mangNguyen[j] > 0 && mangNguyen[i] < mangNguyen[j])
					hoanViSoNguyen(mangNguyen[i], mangNguyen[j]);
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