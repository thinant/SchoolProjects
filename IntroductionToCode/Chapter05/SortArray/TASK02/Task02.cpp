#include <stdio.h>

#define TOI_DA 100

void hoanViSoNguyen(int& a, int& b);
void sapXepTangPhanTuNguyenTo(int mangNguyen[], unsigned int soPhanTu);
bool kiemTraSoNguyenTo(int a);
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

	sapXepTangPhanTuNguyenTo(mangNguyen, soPhanTu);

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

void sapXepTangPhanTuNguyenTo(int mangNguyen[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu - 1; i++)
		if (kiemTraSoNguyenTo(mangNguyen[i]))
			for (unsigned j = i + 1; j < soPhanTu; j++)
				if (kiemTraSoNguyenTo(mangNguyen[j]))
					if (mangNguyen[i] > mangNguyen[j])
						hoanViSoNguyen(mangNguyen[i], mangNguyen[j]);
				
}

bool kiemTraSoNguyenTo(int a)
{
	if (a < 2) return false;

	for (unsigned int i = 2; i <= a / 2; i++)
		if (a % i == 0) return false;

	return true;
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