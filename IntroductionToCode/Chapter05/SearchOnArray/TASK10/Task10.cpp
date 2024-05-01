#include <stdio.h>

#define TOI_DA 100

void InPhanTuChiaHetCho3Va5(int mangNguyen[], unsigned int soPhanTu);
void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);

int main()
{
	int mangNguyen[TOI_DA];
	unsigned int soPhanTu = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	InPhanTuChiaHetCho3Va5(mangNguyen, soPhanTu);

	return 0;
}


void InPhanTuChiaHetCho3Va5(int mangNguyen[], unsigned int soPhanTu)
{
	unsigned int soPhanTuThoa = 0;

	printf("Cac phan tu la boi cua 3 va 5 la: ");
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (mangNguyen[i] % 15 == 0)
		{
			printf("%d ", mangNguyen[i]);
			soPhanTuThoa++;
		}

	if (soPhanTuThoa == 0)
		printf("Khong co phan tu nao.");
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