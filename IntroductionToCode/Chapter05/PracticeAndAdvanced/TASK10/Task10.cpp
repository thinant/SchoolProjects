#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);
int xoaPhanTuX(int x, int mangNguyen[], unsigned int& soPhanTu);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	int mangNguyen[TOI_DA], x = 0, bienBaoLoi = 0;
	unsigned int soPhanTu = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	printf("Mang ban dau: ");
	xuatMangNguyen(mangNguyen, soPhanTu);

	printf("\nNhap so X can xoa: ");
	scanf_s("%d", &x);

	bienBaoLoi = xoaPhanTuX(x, mangNguyen, soPhanTu);

	if (bienBaoLoi == 0)
	{
		printf("Mang sau khi xoa phan tu %d: ", x);
		xuatMangNguyen(mangNguyen, soPhanTu);
	}
	else
		printf("Khong ton tai phan tu %d trong mang.", x);
	

	return 0;
}

int xoaPhanTuX(int x, int mangNguyen[], unsigned int& soPhanTu)
{
	int soPhanTuX = 0;
	for (unsigned int i = 0; i < soPhanTu - soPhanTuX; i++)
	{
		while (mangNguyen[i + soPhanTuX] == x)
			soPhanTuX++;

		mangNguyen[i] = mangNguyen[i + soPhanTuX];
	}

	soPhanTu -= soPhanTuX;

	if (soPhanTuX == 0) return -1;

	return 0;
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