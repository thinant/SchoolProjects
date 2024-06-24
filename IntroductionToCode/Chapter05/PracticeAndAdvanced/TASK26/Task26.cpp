#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);
bool kiemTraMangCoDoiXung(int mangNguyen[], unsigned int soPhanTu);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	int mangNguyen[TOI_DA];
	unsigned int soPhanTu = 0;

	printf("Nhap mang:\n");
	nhapMangNguyen(mangNguyen, soPhanTu);

	bool coDoiXung = kiemTraMangCoDoiXung(mangNguyen, soPhanTu);

	if (coDoiXung)
		printf("\nMang doi xung.");
	else
		printf("\nMang khong doi xung.");

	return 0;
}

bool kiemTraMangCoDoiXung(int mangNguyen[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu / 2; i++)
		if (mangNguyen[i] != mangNguyen[soPhanTu - 1 - i])
			return false;

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