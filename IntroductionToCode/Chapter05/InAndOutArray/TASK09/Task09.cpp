#include <stdio.h>

#define TOIDA 100

void nhapSoNguyenDuong(unsigned int&);
void nhapMang(int[], unsigned int&);
void xuatSoNguyenToTrongMangNhoHon(int, int[], unsigned int);
bool kiemTraSoNguyenTo(int);

int main()
{
	unsigned int soPhanTu = 0;
	int mangNguyen[TOIDA], gioiHan = 0;

	nhapMang(mangNguyen, soPhanTu);

	printf("Nhap so gioi han n: ");		scanf_s("%d", &gioiHan);

	xuatSoNguyenToTrongMangNhoHon(gioiHan, mangNguyen, soPhanTu);

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

void xuatSoNguyenToTrongMangNhoHon(int gioiHan, int mangNguyen[], unsigned int soPhanTu)
{
	unsigned int soCacSoNguyenTo = 0;
	printf("\nCac so nguyen to trong mang nho hon %d: ", gioiHan);
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (kiemTraSoNguyenTo(mangNguyen[i]) && mangNguyen[i] < gioiHan)
		{
			printf("%d ", mangNguyen[i]);
			soCacSoNguyenTo++;
		}

	if (soCacSoNguyenTo == 0) printf("khong co so nguyen to nao nho hon %d trong mang. ", gioiHan);
}

bool kiemTraSoNguyenTo(int n)
{
	bool laSoNguyenTo = true;

	if (n <= 1) laSoNguyenTo = false;

	for (unsigned int i = 2; i <= n / 2; i++)
		if (n % i == 0)
		{
			laSoNguyenTo = false;
			break;
		}

	return laSoNguyenTo;
}