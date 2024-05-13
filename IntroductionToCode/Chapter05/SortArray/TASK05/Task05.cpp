#include <stdio.h>

#define TOI_DA 100

void hoanViSoNguyen(int& a, int& b);
void sapXepChanLe(int mangNguyen[], unsigned int soPhanTu);
void tachChanLe(int mangNguyen[], unsigned int soPhanTu, unsigned int& soPhanTuChan, unsigned int& soPhanTuLe);
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

	sapXepChanLe(mangNguyen, soPhanTu);

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

void sapXepChanLe(int mangNguyen[], unsigned int soPhanTu)
{
	unsigned int soPhanTuChan = 0, soPhanTuLe = 0;
	tachChanLe(mangNguyen, soPhanTu, soPhanTuChan, soPhanTuLe);

	sapXepMangNguyen(mangNguyen, soPhanTuChan, true);
	sapXepMangNguyen(mangNguyen + soPhanTuChan, soPhanTuLe, false);
}

void tachChanLe(int mangNguyen[], unsigned int soPhanTu, unsigned int& soPhanTuChan, unsigned int& soPhanTuLe)
{
	for (unsigned int i = 0; i < soPhanTu - 1; i++)
		if (mangNguyen[i] % 2 == 1)
		{
			for (unsigned int j = i + 1; j < soPhanTu; j++)
				if (mangNguyen[j] % 2 == 0)
				{
					soPhanTuChan++;
					hoanViSoNguyen(mangNguyen[i], mangNguyen[j]);
					break;
				}
		}
		else
			soPhanTuChan++;

	soPhanTuLe = soPhanTu - soPhanTuChan;
}

void sapXepMangNguyen(int mangNguyen[], unsigned int soPhanTu, bool laMangChan)
{
	for (unsigned int i = 0; i < soPhanTu - 1; i++)
		for (unsigned int j = i + 1; j < soPhanTu; j++)
			if ((laMangChan && mangNguyen[i] > mangNguyen[j]) ||
				(!laMangChan && mangNguyen[i] < mangNguyen[j]))
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