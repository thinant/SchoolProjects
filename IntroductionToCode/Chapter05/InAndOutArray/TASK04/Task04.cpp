#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOIDA 100

void nhapSoNguyenDuong(unsigned int&);
int sinhSoNguyenNgauNhienLonHon(int);
void sinhMangNguyenNgauNhienTangDan(int[], unsigned int&);
void xuatMang(int[], unsigned int);

int main()
{
	unsigned int soPhanTu = 0;
	int mangNguyenNgauNhienTangDan[TOIDA];

	printf("Sinh mang so nguyen ngau nhien tang dan...\n\n");
	sinhMangNguyenNgauNhienTangDan(mangNguyenNgauNhienTangDan, soPhanTu);

	printf("\nHoan thanh!\n");
	xuatMang(mangNguyenNgauNhienTangDan, soPhanTu);

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

int  sinhSoNguyenNgauNhienLonHon(int n)
{
	int soNguyenNgauNhienLonHon = n - 1;

	while (soNguyenNgauNhienLonHon < n) soNguyenNgauNhienLonHon = rand();


	return soNguyenNgauNhienLonHon;
}

void sinhMangNguyenNgauNhienTangDan(int mangNguyenNgauNhienTangDan[], unsigned int& soPhanTu)
{
	srand(time(0));
	int soNguyenNgauNhienLonHon = 0;
	nhapSoNguyenDuong(soPhanTu);

	mangNguyenNgauNhienTangDan[0] = rand();

	for (unsigned int i = 1; i < soPhanTu; i++)
	{
		soNguyenNgauNhienLonHon = sinhSoNguyenNgauNhienLonHon(mangNguyenNgauNhienTangDan[i-1]);
		mangNguyenNgauNhienTangDan[i] = soNguyenNgauNhienLonHon;
	}
}

void xuatMang(int mangNguyen[], unsigned int soPhanTu)
{
	printf("\nNoi dung mang: ");
	for (unsigned int i = 0; i < soPhanTu; i++)
		printf("%d\t", mangNguyen[i]);
}