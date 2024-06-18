#include <stdio.h>

#define TOI_DA 106 //so phan tu neu tam giac 14 hang
#define HANG_TOI_DA 14

void nhapSoHang(unsigned int& n);
void veTamGiacPascal(unsigned int tamGiacPascal[], unsigned int soHang, unsigned int& soPhanTu);
void xuatTamGiacPascal(unsigned int tamGiacPascal[], unsigned int soPhanTu);

int main()
{
	unsigned int tamGiacPascal[TOI_DA], soPhanTu = 0, soHang = 0;

	nhapSoHang(soHang);
	
	veTamGiacPascal(tamGiacPascal, soHang, soPhanTu);

	xuatTamGiacPascal(tamGiacPascal, soPhanTu);

	return 0;
}

void veTamGiacPascal(unsigned int tamGiacPascal[], unsigned int soHang, unsigned int& soPhanTu)
{
	tamGiacPascal[0] = 1;
	unsigned int hangTren = 0, giaTri = 1;
	soPhanTu = 1;

	for (unsigned int i = 2; i <= soHang; i++)
	{
		for (unsigned int j = 1; j <= i + 1; j++)
		{
			if (j == 1 || j == i + 1)
				giaTri = 1;
			else if (i == 2 && j == 2)
				giaTri = 2;
			else
			{
				giaTri = tamGiacPascal[hangTren] + tamGiacPascal[hangTren + 1];
				hangTren++;
			}

			tamGiacPascal[soPhanTu++] = giaTri;
		}

		hangTren++;
	}

}


void nhapSoHang(unsigned int& n)
{
	printf("Nhap so hang cua tam giac pascal: ");	scanf_s("%u", &n);

	while (n <= 0 || n > HANG_TOI_DA)
	{
		printf("So phan tu khong hop le. Vui long nhap lai: ");
		scanf_s("%u", &n);
	}
}

void xuatTamGiacPascal(unsigned int tamGiacPascal[], unsigned int soPhanTu)
{
	unsigned int demSo1 = 0;
	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		printf("%u ", tamGiacPascal[i]);
		if (tamGiacPascal[i] == 1)
			demSo1++;
		if (demSo1 == 2 || (demSo1 == 1 && i == 0))
		{
			demSo1 = 0;
			printf("\n");
		}
	}
}