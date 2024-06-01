#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(unsigned int mangNguyen[], unsigned int& soPhanTu);
unsigned int timBac(unsigned int n);
bool kiemTraSoAmstrong(unsigned int n);
unsigned int tinhTongPhanTuAmstrong(unsigned int mangNguyen[], unsigned int soPhanTu);
void xuatMangNguyen(unsigned int mangNguyen[], unsigned int soPhanTu);

int main()
{
	unsigned int mangNguyen[TOI_DA];
	unsigned int soPhanTu = 0, tong = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	tong = tinhTongPhanTuAmstrong(mangNguyen, soPhanTu);

	printf("Tong cac phan tu la so Amstrong trong mang: %d", tong);
	return 0;
}

unsigned int timBac(unsigned int n)
{
	unsigned int bac = 1, hang = 1;
	for (; n / hang >= 10; bac++)
		hang *= 10;
	return bac;
}

bool kiemTraSoAmstrong(unsigned int n)
{
	unsigned int bac = timBac(n), tong = 0, banSao = n;

	while (n != 0)
	{
		unsigned int chuSo = 1;

		for (unsigned int i = 1; i <= bac; i++)
			chuSo *= (n % 10);

		tong += chuSo;
		n /= 10;
	}

	return tong == banSao;
}

unsigned int tinhTongPhanTuAmstrong(unsigned int mangNguyen[], unsigned int soPhanTu)
{
	unsigned int tong = 0;

	for (unsigned int i = 0; i < soPhanTu; i++)
		if (kiemTraSoAmstrong(mangNguyen[i]))
			tong += mangNguyen[i];

	return tong;
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

void nhapMangNguyen(unsigned int mangNguyen[], unsigned int& soPhanTu)
{
	nhapSoPhanTu(soPhanTu);

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		printf("Nhap phan tu thu %u: ", i);
		scanf_s("%d", &mangNguyen[i]);
	}
}

void xuatMangNguyen(unsigned int mangNguyen[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		printf("%u ", mangNguyen[i]);
}