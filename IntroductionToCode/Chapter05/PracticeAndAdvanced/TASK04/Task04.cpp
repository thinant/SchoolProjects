#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n, unsigned int gioiHanTrai, unsigned int gioiHanPhai);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu, unsigned int gioiHanTrai, unsigned int gioiHanPhai);
bool kiemTraPhanTuTonTai(int x, int mangNguyen[], unsigned int soPhanTu);
bool kiemTraDayCon(int mangNguyenA[], unsigned int soPhanTuA, int mangNguyenB[], unsigned int soPhanTuB);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	int mangNguyenA[TOI_DA], mangNguyenB[TOI_DA];
	unsigned int soPhanTuA = 0, soPhanTuB = 0;

	printf("Nhap mang A:\n");
	nhapMangNguyen(mangNguyenA, soPhanTuA, 1, TOI_DA-1);

	printf("Nhap mang B:\n");
	nhapMangNguyen(mangNguyenB, soPhanTuB, soPhanTuA, TOI_DA);

	if (kiemTraDayCon(mangNguyenA, soPhanTuA, mangNguyenB, soPhanTuB))
		printf("A la day con cua B.");
	else
		printf("A khong la day con cua B.");

	return 0;
}

bool kiemTraPhanTuTonTai(int x, int mangNguyen[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (mangNguyen[i] == x)
			return true;

	return false;
}


void nhapSoPhanTu(unsigned int& soPhanTu, unsigned int gioiHanTrai, unsigned int gioiHanPhai)
{
	printf("Nhap so phan tu: ");	scanf_s("%u", &soPhanTu);

	while (soPhanTu == gioiHanTrai || soPhanTu > gioiHanPhai)
	{
		printf("So phan tu khong hop le. Vui long nhap lai: ");
		scanf_s("%u", &soPhanTu);
	}
}

void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu, unsigned int gioiHanTrai, unsigned int gioiHanPhai)
{
	nhapSoPhanTu(soPhanTu, gioiHanTrai, gioiHanPhai);

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		printf("Nhap phan tu thu %u: ", i);
		scanf_s("%d", &mangNguyen[i]);
	}
}

bool kiemTraDayCon(int mangNguyenA[], unsigned int soPhanTuA, int mangNguyenB[], unsigned int soPhanTuB)
{
	for (unsigned int i = 0; i < soPhanTuA; i++)
		if (!kiemTraPhanTuTonTai(mangNguyenA[i], mangNguyenB, soPhanTuB))
			return false;

	return true;
}

void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		printf("%d ", mangNguyen[i]);
}