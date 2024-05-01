#include <stdio.h>

#define TOI_DA 100

int timViTriLeLonNhat(int mangNguyen[], unsigned int soPhanTu);
void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);

int main()
{
	int mangNguyen[TOI_DA];
	unsigned int soPhanTu = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	int viTriLeLonNhat = timViTriLeLonNhat(mangNguyen, soPhanTu);

	if (viTriLeLonNhat == -1)
		printf("Khong ton tai gia tri am nao trong mang");
	else
		printf("Gia tri le lon nhat trong mang la %d, o vi tri thu %d", mangNguyen[viTriLeLonNhat], viTriLeLonNhat);

	return 0;
}

int timViTriLeLonNhat(int mangNguyen[], unsigned int soPhanTu)
{
	int viTriLeLonNhat = -1;

	for (unsigned int i = 0; i < soPhanTu; i++)
		if ((mangNguyen[i] % 2 != 0)
			&& (viTriLeLonNhat == -1 || mangNguyen[i] > mangNguyen[viTriLeLonNhat]))
			viTriLeLonNhat = i;

	return viTriLeLonNhat;
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