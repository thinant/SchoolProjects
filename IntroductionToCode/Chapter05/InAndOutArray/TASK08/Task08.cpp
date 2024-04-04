#include <stdio.h>

#define TOIDA 100

void nhapSoNguyenDuong(unsigned int&);
void nhapMang(int[], unsigned int&);
void xuatSoNguyenToTrongMang(int[], unsigned int);
bool kiemTraSoNguyenTo(int);

int main()
{
	unsigned int soPhanTu = 0;
	int mangNguyen[TOIDA];

	nhapMang(mangNguyen, soPhanTu);

	xuatSoNguyenToTrongMang(mangNguyen, soPhanTu);

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

void nhapMang(int mangNguyen[], unsigned int& soPhanTu)
{
	nhapSoNguyenDuong(soPhanTu);

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		printf("Nhap phan tu thu %u: ", i);	scanf_s("%d", &mangNguyen[i]);
	}
}

void xuatSoNguyenToTrongMang(int mangNguyen[], unsigned int soPhanTu)
{
	printf("\nCac so nguyen to trong mang: ");
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (kiemTraSoNguyenTo(mangNguyen[i]))
			printf("%d ", mangNguyen[i]);
}

bool kiemTraSoNguyenTo(int n)
{
	bool laSoNguyenTo = true;

	if (n <= 1) laSoNguyenTo = false;

	for (unsigned int i = 2; i <= n/2; i++)
		if (n % i == 0)
		{
			laSoNguyenTo = false;
			break;
		}

	return laSoNguyenTo;
}