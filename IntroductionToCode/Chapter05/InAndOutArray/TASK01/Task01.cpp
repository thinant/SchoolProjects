#include <stdio.h>

#define TOIDA 100

void nhapSoNguyenDuong(unsigned int&);
void nhapMang(float[], unsigned int&);
void xuatMang(float[], unsigned int);

int main()
{
	unsigned int soPhanTu = 0;
	float mangThuc[TOIDA];

	nhapMang(mangThuc, soPhanTu);

	xuatMang(mangThuc, soPhanTu);

	return 0;
}

void nhapSoNguyenDuong(unsigned int& n)
{
	printf("Nhap so phan tu cua mang, toi da %u phan tu: ", TOIDA);
	scanf_s("%u", &n);

	while (n > TOIDA)
	{
		printf("So phan tu khong hop le. Vui long nhap lai, toi da %u phan tu: ", TOIDA);
		scanf_s("%u", &n);
	}
}

void nhapMang(float mangThuc[], unsigned int& soPhanTu)
{
	nhapSoNguyenDuong(soPhanTu);

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		printf("Nhap phan tu thu %u: ", i);	scanf_s("%f", &mangThuc[i]);
	}
}

void xuatMang(float mangThuc[], unsigned int soPhanTu)
{
	printf("\nNoi dung mang: ");
	for (unsigned int i = 0; i < soPhanTu; i++)
		printf("%.2f\t", mangThuc[i]);
}