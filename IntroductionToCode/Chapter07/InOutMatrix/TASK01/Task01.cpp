#include <stdio.h>
#include <string.h>

#define TOI_DA 100
typedef unsigned int MANG2D_NGUYEN_DUONG[TOI_DA][TOI_DA];

void nhapMaTranNguyenDuong(MANG2D_NGUYEN_DUONG maTran, unsigned int& soDong, unsigned int& soCot);
void xuatMaTranNguyenDuong(MANG2D_NGUYEN_DUONG maTran, unsigned int soDong, unsigned int soCot);
bool kiemTraGiaTriLaSoNguyenDuong(char giaTri[]);
unsigned int chuyenChuoiThanhSo(char giaTri[]);

int main()
{
	MANG2D_NGUYEN_DUONG maTran{ 0 };
	unsigned int soDong = 0, soCot = 0;

	nhapMaTranNguyenDuong(maTran, soDong, soCot);

	printf("Ma tran da nhap la:\n");
	xuatMaTranNguyenDuong(maTran, soDong, soCot);

	return 0;
}

void nhapMaTranNguyenDuong(MANG2D_NGUYEN_DUONG maTran, unsigned int& soDong, unsigned int& soCot)
{
	char giaTri[10 + 1] = "";

	printf("Nhap so dong cua ma tran: ");
	scanf_s("%s", &giaTri, 10);
	while (!kiemTraGiaTriLaSoNguyenDuong(giaTri))
	{
		printf("Gia tri khong hop le. Vui long nhap so nguyen duong: ");
		scanf_s("%s", &giaTri, 10);
	}
	soDong = chuyenChuoiThanhSo(giaTri);

	printf("Nhap so cot cua ma tran: ");
	scanf_s("%s", &giaTri, 10);
	while (!kiemTraGiaTriLaSoNguyenDuong(giaTri))
	{
		printf("Gia tri khong hop le. Vui long nhap so nguyen duong: ");
		scanf_s("%s", &giaTri, 10);
	}
	soCot = chuyenChuoiThanhSo(giaTri);

	printf("Nhap noi dung ma tran:\n");

	for (unsigned int i = 0; i < soDong; i++)
		for (unsigned int j = 0; j < soCot; j++)
		{
			printf("Phan tu [%d][%d]: ", i, j);
			scanf_s("%s", &giaTri, 10);
			while (!kiemTraGiaTriLaSoNguyenDuong(giaTri))
			{
				printf("Gia tri khong hop le. Vui long nhap so nguyen duong: ");
				scanf_s("%s", &giaTri, 10);
			}
			maTran[i][j] = chuyenChuoiThanhSo(giaTri);
		}
}

void xuatMaTranNguyenDuong(MANG2D_NGUYEN_DUONG maTran, unsigned int soDong, unsigned int soCot)
{
	for (unsigned int i = 0; i < soDong; i++)
	{
		for (unsigned int j = 0; j < soCot; j++)
			printf("\t%u", maTran[i][j]);

		printf("\n");
	}

}

bool kiemTraGiaTriLaSoNguyenDuong(char giaTri[])
{
	for (unsigned int i = 0; i < strlen(giaTri); i++)
		if (giaTri[i] < '0' || giaTri[i] > '9')
			return false;

	return true;
}

unsigned int chuyenChuoiThanhSo(char giaTri[])
{
	unsigned int so = 0;

	for (unsigned int i = 0; i < strlen(giaTri); i++)
	{
		so *= 10;
		so += (giaTri[i] - '0');
	}

	return so;
}