#include <stdio.h>

#define TOI_DA 100

unsigned int timViTriPhanTuLonNhat(int mangNguyen[], unsigned int soPhanTu);
void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);

int main()
{
	int mangNguyen[TOI_DA];
	unsigned int soPhanTu = 0, viTriPhanTuLonNhat = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	viTriPhanTuLonNhat = timViTriPhanTuLonNhat(mangNguyen, soPhanTu);

	printf("Phan tu nho nhat la %d, nam o vi tri thu %u.", mangNguyen[viTriPhanTuLonNhat], viTriPhanTuLonNhat);

	return 0;
}

unsigned int timViTriPhanTuLonNhat(int mangNguyen[], unsigned int soPhanTu)
{
	unsigned int viTriPhanTuLonNhat = 0;
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (mangNguyen[i] > mangNguyen[viTriPhanTuLonNhat])
			viTriPhanTuLonNhat = i;

	return viTriPhanTuLonNhat;
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