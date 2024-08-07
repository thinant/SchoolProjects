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
void timCotCoTongNhoNhatTrenMaTran(MANG2D_NGUYEN maTran, unsigned int soDong, unsigned int soCot, int& viTriCotCoTongNhoNhat, int& tongLonNhat);

int main()
{
	MANG2D_NGUYEN maTran{ 0 };
	unsigned int soDong = 0, soCot = 0;
	int viTriCotCoTongNhoNhat = 0, tongLonNhat = 0;

	nhapMaTranNguyen(maTran, soDong, soCot);

	printf("Ma tran da nhap la:\n");
	xuatMaTranNguyen(maTran, soDong, soCot);

	timCotCoTongNhoNhatTrenMaTran(maTran, soDong, soCot, viTriCotCoTongNhoNhat, tongLonNhat);

	printf("\nTong cot %d = %d la nho nhat.", viTriCotCoTongNhoNhat, tongLonNhat);

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

void timCotCoTongNhoNhatTrenMaTran(MANG2D_NGUYEN maTran, unsigned int soDong, unsigned int soCot, int& viTriCotCoTongNhoNhat, int& tongNhoNhat)
{
	viTriCotCoTongNhoNhat = -1, tongNhoNhat = 0;
	int tongCot[TOI_DA]{ 0 };

	for (int i = 0; i < soCot; i++)
	{
		for (int j = 0; j < soDong; j++)
			tongCot[i] += maTran[j][i];
		if (viTriCotCoTongNhoNhat == -1 || tongCot[i] < tongCot[viTriCotCoTongNhoNhat])
			viTriCotCoTongNhoNhat = i;
	}

	tongNhoNhat = tongCot[viTriCotCoTongNhoNhat];
}