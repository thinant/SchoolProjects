#include <stdio.h>
#include <string.h>

#define TOI_DA 100
typedef int MANG2D_NGUYEN[TOI_DA][TOI_DA];

void nhapMaTranNguyen(MANG2D_NGUYEN maTran, unsigned int& soDong, unsigned int& soCot);
void xuatMaTranNguyen(MANG2D_NGUYEN maTran, unsigned int soDong, unsigned int soCot);
bool kiemTraGiaTriLaSoNguyenDuong(char giaTri[]);
bool kiemTraGiaTriLaSoNguyen(char giaTri[]);
unsigned int chuyenChuoiThanhSoNguyenDuong(char giaTri[]);
int chuyenChuoiThanhSoNguyen(char giaTri[]);
void timSoDuongChanNhoNhatTrenMaTran(MANG2D_NGUYEN maTran, unsigned int soDong, unsigned int soCot, unsigned int& viTriDongDuongChanNhoNhat, unsigned int& viTriCotDuongChanNhoNhat);

int main()
{
	MANG2D_NGUYEN maTran{ 0 };
	unsigned int soDong = 0, soCot = 0, viTriDongDuongChanNhoNhat = 0, viTriCotDuongChanNhoNhat = 0;

	nhapMaTranNguyen(maTran, soDong, soCot);

	printf("Ma tran da nhap la:\n");
	xuatMaTranNguyen(maTran, soDong, soCot);

	timSoDuongChanNhoNhatTrenMaTran(maTran, soDong, soCot, viTriDongDuongChanNhoNhat, viTriCotDuongChanNhoNhat);

	if (viTriDongDuongChanNhoNhat == -1)
		printf("Mang khong co phan tu duong chan nao.\n");
	else
	{
		printf("Phan tu duong chan nho nhat trong ma tran la: %d, o vi tri [%u][%u]",
			maTran[viTriDongDuongChanNhoNhat][viTriCotDuongChanNhoNhat], viTriDongDuongChanNhoNhat, viTriCotDuongChanNhoNhat);
	}

	return 0;
}

void nhapMaTranNguyen(MANG2D_NGUYEN maTran, unsigned int& soDong, unsigned int& soCot)
{
	char giaTri[20 + 1] = "";

	printf("Nhap so dong cua ma tran: ");
	scanf_s("%s", &giaTri, 20);
	while (!kiemTraGiaTriLaSoNguyenDuong(giaTri))
	{
		printf("Gia tri khong hop le. Vui long nhap so nguyen duong: ");
		scanf_s("%s", &giaTri, 20);
	}
	soDong = chuyenChuoiThanhSoNguyen(giaTri);

	printf("Nhap so cot cua ma tran: ");
	scanf_s("%s", &giaTri, 20);
	while (!kiemTraGiaTriLaSoNguyenDuong(giaTri))
	{
		printf("Gia tri khong hop le. Vui long nhap so nguyen duong: ");
		scanf_s("%s", &giaTri, 20);
	}
	soCot = chuyenChuoiThanhSoNguyen(giaTri);

	printf("Nhap noi dung ma tran:\n");

	for (unsigned int i = 0; i < soDong; i++)
		for (unsigned int j = 0; j < soCot; j++)
		{
			printf("Phan tu [%d][%d]: ", i, j);
			scanf_s("%s", &giaTri, 20);
			while (!kiemTraGiaTriLaSoNguyen(giaTri))
			{
				printf("Gia tri khong hop le. Vui long nhap so thuc: ");
				scanf_s("%s", &giaTri, 20);
			}
			maTran[i][j] = chuyenChuoiThanhSoNguyen(giaTri);
		}
}

void xuatMaTranNguyen(MANG2D_NGUYEN maTran, unsigned int soDong, unsigned int soCot)
{
	for (unsigned int i = 0; i < soDong; i++)
	{
		for (unsigned int j = 0; j < soCot; j++)
			printf("\t%d", maTran[i][j]);

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

bool kiemTraGiaTriLaSoNguyen(char giaTri[])
{
	for (unsigned int i = 0; i < strlen(giaTri); i++)
		if (giaTri[i] == '-')
		{
			if (i != 0)
				return false;
		}
		else if (giaTri[i] < '0' || giaTri[i] > '9')
			return false;

	return true;
}

unsigned int chuyenChuoiThanhSoNguyenDuong(char giaTri[])
{
	unsigned int so = 0;

	for (unsigned int i = 0; i < strlen(giaTri); i++)
	{
		so *= 10;
		so += (giaTri[i] - '0');
	}

	return so;
}

int chuyenChuoiThanhSoNguyen(char giaTri[])
{
	int so = 0;
	unsigned int hangThapPhan = 10, i = 0;
	bool laSoAm = false;

	for (i = 0; i < strlen(giaTri) && giaTri[i] != '.'; i++)
	{
		if (giaTri[i] == '-')
		{
			laSoAm = true;
			continue;
		}
		so *= 10;
		so += (giaTri[i] - '0');
	}

	if (laSoAm) so *= -1;

	return so;
}

void timSoDuongChanNhoNhatTrenMaTran(MANG2D_NGUYEN maTran, unsigned int soDong, unsigned int soCot,
	unsigned int& viTriDongDuongChanNhoNhat, unsigned int& viTriCotDuongChanNhoNhat)
{
	viTriDongDuongChanNhoNhat = -1, viTriCotDuongChanNhoNhat = -1;
	int giaTriDuongChanNhoNhat = -1;

	for (int i = soDong - 1; i >= 0; i--)
		for (int j = soCot - 1; j >= 0; j--)
			if ((maTran[i][j] > 0 && maTran[i][j] % 2 == 0)
				&& (giaTriDuongChanNhoNhat == -1 || maTran[i][j] < giaTriDuongChanNhoNhat))
			{
				giaTriDuongChanNhoNhat = maTran[i][j];
				viTriDongDuongChanNhoNhat = i;
				viTriCotDuongChanNhoNhat = j;
			}
}