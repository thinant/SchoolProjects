#include <stdio.h>

#define TOI_DA 100

int chenTruocSoNguyenToDauTien(int mangNguyen[], unsigned int& soPhanTu, float x);
int timViTriSoNguyenToDauTien(int mangNguyen[], unsigned int soPhanTu);
bool kiemTraSoNguyenTo(int n);
void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	int mangNguyen[TOI_DA], x = 0;
	unsigned int soPhanTu = 0;
	int maLoi = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);
	printf("Nhap x: ");
	scanf_s("%d", &x);

	printf("Mang ban dau:\n");
	xuatMangNguyen(mangNguyen, soPhanTu);

	maLoi = chenTruocSoNguyenToDauTien(mangNguyen, soPhanTu, x);

	if (maLoi == -1)
		printf("\n\nMang da dat kich thuoc toi da, khong the mo rong.");
	else if (maLoi == -2)
		printf("\n\nMang khong co so nguyen to.");
	else
	{
		printf("\n\nMang sau khi chen %d:\n", x);
		xuatMangNguyen(mangNguyen, soPhanTu);
	}

	return 0;
}

int chenTruocSoNguyenToDauTien(int mangNguyen[], unsigned int& soPhanTu, float x)
{
	if (soPhanTu == TOI_DA)
		return -1; //ma loi -1: kich thuoc mang toi da

	unsigned int viTri = timViTriSoNguyenToDauTien(mangNguyen, soPhanTu);

	if (viTri == -1)
		return -2; //ma loi -2: khong tim thay vi tri chen

	for (unsigned int i = soPhanTu; i > viTri; i--)
		mangNguyen[i] = mangNguyen[i - 1];

	mangNguyen[viTri] = x;
	soPhanTu++;

	return 0; //ma loi 0: khong co loi
}

int timViTriSoNguyenToDauTien(int mangNguyen[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (kiemTraSoNguyenTo(mangNguyen[i]))
			return i;

	return -1;
}

bool kiemTraSoNguyenTo(int n)
{
	if (n < 2)
		return false;

	for (unsigned int i = 2; i <= n / 2; i++)
		if (n % i == 0)
			return false;

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