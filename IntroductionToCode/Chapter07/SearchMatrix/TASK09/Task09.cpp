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
void timCacPhanTuTrungNhauTrenHaiMaTran(MANG2D_NGUYEN maTran_a, MANG2D_NGUYEN maTran_b, unsigned int soDong_a, unsigned int soCot_a, 
	unsigned int soDong_b, unsigned int soCot_b, int cacPhanTuTrungNhau[], unsigned int& soPhanTuTrungNhau);
bool kiemTraPhanTuTonTaiTrongMaTran(int so, MANG2D_NGUYEN maTran, unsigned int soDong, unsigned int soCot);
bool kiemTraPhanTuTonTaiTrongMang(int so, int mangNguyen[], unsigned int soPhanTu);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	MANG2D_NGUYEN maTran_a{ 0 }, maTran_b{ 0 };
	unsigned int soDong_a = 0, soCot_a = 0, soDong_b = 0, soCot_b = 0, soPhanTuTrungNhau = 0;
	int cacPhanTuTrungNhau[TOI_DA]{ 0 };

	printf("Ma tran A:\n");
	nhapMaTranNguyen(maTran_a, soDong_a, soCot_a);
	printf("Ma tran B:\n");
	nhapMaTranNguyen(maTran_b, soDong_b, soCot_b);

	printf("\nMa tran A da nhap la:\n");
	xuatMaTranNguyen(maTran_a, soDong_a, soCot_a);
	printf("\nMa tran B da nhap la:\n");
	xuatMaTranNguyen(maTran_b, soDong_b, soCot_b);

	timCacPhanTuTrungNhauTrenHaiMaTran(maTran_a, maTran_b, soDong_a, soCot_a, soDong_b, soCot_b, 
		cacPhanTuTrungNhau, soPhanTuTrungNhau);

	if (soPhanTuTrungNhau <= 0)
		printf("\nHai ma tran khong co phan tu trung nhau.");
	else
	{
		printf("\nCac phan tu trung nhau la: ");
		xuatMangNguyen(cacPhanTuTrungNhau, soPhanTuTrungNhau);
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

void timCacPhanTuTrungNhauTrenHaiMaTran(MANG2D_NGUYEN maTran_a, MANG2D_NGUYEN maTran_b, unsigned int soDong_a, unsigned int soCot_a,
	unsigned int soDong_b, unsigned int soCot_b, int cacPhanTuTrungNhau[], unsigned int& soPhanTuTrungNhau)
{
	soPhanTuTrungNhau = 0;
	int dayDaDuyet[TOI_DA]{0};
	unsigned int soPhanTuDaDuyet = 0;

	for (unsigned int i = 0; i < soDong_a; i++)
		for (int j = 0; j < soCot_a; j++)
		{
			if (!kiemTraPhanTuTonTaiTrongMang(maTran_a[i][j], dayDaDuyet, soPhanTuDaDuyet)
				&& kiemTraPhanTuTonTaiTrongMaTran(maTran_a[i][j], maTran_b, soDong_b, soCot_b))
				cacPhanTuTrungNhau[soPhanTuTrungNhau++] = maTran_a[i][j];

			dayDaDuyet[soPhanTuDaDuyet++] = maTran_a[i][j];

		}
			
}

bool kiemTraPhanTuTonTaiTrongMaTran(int so, MANG2D_NGUYEN maTran, unsigned int soDong, unsigned int soCot)
{
	for (unsigned int i = 0; i < soDong; i++)
		for (unsigned int j = 0; j < soCot; j++)
			if (maTran[i][j] == so)
				return true;

	return false;
}

bool kiemTraPhanTuTonTaiTrongMang(int so, int mangNguyen[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (mangNguyen[i] == so) return true;

	return false;
}