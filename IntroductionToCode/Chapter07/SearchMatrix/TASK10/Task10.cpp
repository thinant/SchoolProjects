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
void timCacPhanTuCucDaiTrenMaTran(MANG2D_NGUYEN maTran, unsigned int soDong, unsigned int soCot,
	MANG2D_NGUYEN maTranDanhDauCucDai, unsigned int& soPhanTuCucDai);

int main()
{
	MANG2D_NGUYEN maTran{ 0 }, maTranDanhDauCucDai{ 0 };
	unsigned int soDong = 0, soCot = 0, soPhanTuCucDai = 0;

	nhapMaTranNguyen(maTran, soDong, soCot);;

	printf("\nMa tran da nhap la:\n");
	xuatMaTranNguyen(maTran, soDong, soCot);

	timCacPhanTuCucDaiTrenMaTran(maTran, soDong, soCot,
		maTranDanhDauCucDai, soPhanTuCucDai);

	if (soPhanTuCucDai <= 0)
		printf("\nMa tran khong co phan tu cuc dai.");
	else
	{
		printf("\nMa tran co %d phan tu cuc dai:\n", soPhanTuCucDai);
		
		for (unsigned int i = 0; i < soDong; i++)
			for (unsigned int j = 0; j < soCot; j++)
				if (maTranDanhDauCucDai[i][j] == 1)
					printf("%d o vi tri [%u][%u]\n", maTran[i][j], i, j);
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

void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		printf("%d ", mangNguyen[i]);
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

void timCacPhanTuCucDaiTrenMaTran(MANG2D_NGUYEN maTran, unsigned int soDong, unsigned int soCot,
	MANG2D_NGUYEN maTranDanhDauCucDai, unsigned int& soPhanTuCucDai)
{
	soPhanTuCucDai = 0;

	for (unsigned int i = 0; i < soDong; i++)
		for (int j = 0; j < soCot; j++)
		{
			if ((i == 0 || maTran[i][j] > maTran[i - 1][j]) &&
				(i == soDong - 1 || maTran[i][j] > maTran[i + 1][j]) &&
				(j == 0 || maTran[i][j] > maTran[i][j - 1]) &&
				(j == soCot - 1 || maTran[i][j] > maTran[i][j + 1]) &&
				(i == 0 || j == 0 || maTran[i][j] > maTran[i - 1][j - 1]) &&
				(i == soDong - 1 || j == soCot - 1 || maTran[i][j] > maTran[i + 1][j + 1]))
			{
				maTranDanhDauCucDai[i][j] = 1;
				soPhanTuCucDai++;
			}
			else maTranDanhDauCucDai[i][j] = 0;
		}
}
