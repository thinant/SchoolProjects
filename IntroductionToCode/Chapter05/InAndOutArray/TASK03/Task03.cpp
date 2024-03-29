#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOIDA 100

void nhapSoNguyenDuong(unsigned int&);
int sinhSoNguyenAmNgauNhien();
void sinhMangNguyenAmNgauNhien(int[], unsigned int&);
void xuatMang(int[], unsigned int);

int main()
{
	unsigned int soPhanTu = 0;
	int mangNguyenAmNgauNhien[TOIDA];

	printf("Sinh mang so nguyen am ngau nhien...\n\n");
	sinhMangNguyenAmNgauNhien(mangNguyenAmNgauNhien, soPhanTu);

	printf("\nHoan thanh!\n");
	xuatMang(mangNguyenAmNgauNhien, soPhanTu);

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

int sinhSoNguyenAmNgauNhien()
{
	int soNguyenAmNgauNhien = 0;

	while (soNguyenAmNgauNhien == 0) soNguyenAmNgauNhien = rand();

	if (soNguyenAmNgauNhien > 0) soNguyenAmNgauNhien *= -1;

	return soNguyenAmNgauNhien;
}

void sinhMangNguyenAmNgauNhien(int mangNguyenAmNgauNhien[], unsigned int& soPhanTu)
{
	srand(time(0));
	int soNguyenAmNgauNhien = 0;
	nhapSoNguyenDuong(soPhanTu);

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		soNguyenAmNgauNhien = sinhSoNguyenAmNgauNhien();
		mangNguyenAmNgauNhien[i] = soNguyenAmNgauNhien;
	}
}

void xuatMang(int mangNguyen[], unsigned int soPhanTu)
{
	printf("\nNoi dung mang: ");
	for (unsigned int i = 0; i < soPhanTu; i++)
		printf("%d\t", mangNguyen[i]);
}