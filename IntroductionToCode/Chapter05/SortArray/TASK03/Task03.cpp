#include <stdio.h>

#define TOI_DA 100

void hoanViSoNguyen(int& a, int& b);
void sapXepTangPhanTuLe(int mangNguyen[], unsigned int soPhanTu);
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

	sapXepTangPhanTuLe(mangNguyen, soPhanTu);

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

void sapXepTangPhanTuLe(int mangNguyen[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu - 1; i++)
		if (mangNguyen[i] % 2 == 1)
			for (unsigned j = i + 1; j < soPhanTu; j++)
				if (mangNguyen[j] % 2 == 1)
					if (mangNguyen[i] > mangNguyen[j])
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