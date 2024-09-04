#include <stdio.h>
#include <string.h>

#define TOI_DA 100
typedef double MANG2D_THUC[TOI_DA][TOI_DA];

void nhapMaTranThuc(MANG2D_THUC maTran, unsigned int& soDong, unsigned int& soCot);
void xuatMaTranThuc(MANG2D_THUC maTran, unsigned int soDong, unsigned int soCot);
bool kiemTraGiaTriLaSoNguyenDuong(char giaTri[]);
bool kiemTraGiaTriLaSoThuc(char giaTri[]);
unsigned int chuyenChuoiThanhSoNguyenDuong(char giaTri[]);
double chuyenChuoiThanhSoThuc(char giaTri[]);
bool tongHaiMaTran(MANG2D_THUC maTran_a, unsigned int soDong_a, unsigned int soCot_a, MANG2D_THUC maTran_b, unsigned int soDong_b, unsigned int soCot_b, MANG2D_THUC maTranTong);
bool tichHaiMaTran(MANG2D_THUC maTran_a, unsigned int soDong_a, unsigned int soCot_a, MANG2D_THUC maTran_b, unsigned int soDong_b, unsigned int soCot_b, MANG2D_THUC maTranTich);


int main()
{
	MANG2D_THUC maTran_a{ 0 }, maTran_b{ 0 }, maTranTong{ 0 }, maTranTich{ 0 };
	unsigned int soDong_a = 0, soCot_a = 0, soDong_b = 0, soCot_b = 0;

	printf("Ma tran a:\n");
	nhapMaTranThuc(maTran_a, soDong_a, soCot_a);
	printf("Ma tran b:\n");
	nhapMaTranThuc(maTran_b, soDong_b, soCot_b);

	printf("\nMa tran a da nhap la:\n");
	xuatMaTranThuc(maTran_a, soDong_a, soCot_a);

	printf("\nMa tran b da nhap la:\n");
	xuatMaTranThuc(maTran_b, soDong_b, soCot_b);

	if (!tongHaiMaTran(maTran_a, soDong_a, soCot_a, maTran_b, soDong_b, soCot_b, maTranTong))
		printf("\nKhong the tinh tong hai ma tran!\n");
	else
	{
		printf("\nTong hai ma tran la:\n");
		xuatMaTranThuc(maTranTong, soDong_a, soCot_a);
	}

	if (!tichHaiMaTran(maTran_a, soDong_a, soCot_a, maTran_b, soDong_b, soCot_b, maTranTich))
		printf("\nKhong the tinh tich hai ma tran!\n");
	else
	{
		printf("\nTich hai ma tran la:\n");
		xuatMaTranThuc(maTranTich, soDong_a, soCot_b);
	}

	return 0;
}

void nhapMaTranThuc(MANG2D_THUC maTran, unsigned int& soDong, unsigned int& soCot)
{
	char giaTri[20 + 1] = "";

	printf("Nhap so dong cua ma tran: ");
	scanf_s("%s", &giaTri, 20);
	while (!kiemTraGiaTriLaSoNguyenDuong(giaTri))
	{
		printf("Gia tri khong hop le. Vui long nhap so nguyen duong: ");
		scanf_s("%s", &giaTri, 20);
	}
	soDong = chuyenChuoiThanhSoNguyenDuong(giaTri);

	printf("Nhap so cot cua ma tran: ");
	scanf_s("%s", &giaTri, 20);
	while (!kiemTraGiaTriLaSoNguyenDuong(giaTri))
	{
		printf("Gia tri khong hop le. Vui long nhap so nguyen duong: ");
		scanf_s("%s", &giaTri, 20);
	}
	soCot = chuyenChuoiThanhSoNguyenDuong(giaTri);

	printf("Nhap noi dung ma tran:\n");

	for (unsigned int i = 0; i < soDong; i++)
		for (unsigned int j = 0; j < soCot; j++)
		{
			printf("Phan tu [%d][%d]: ", i, j);
			scanf_s("%s", &giaTri, 20);
			while (!kiemTraGiaTriLaSoThuc(giaTri))
			{
				printf("Gia tri khong hop le. Vui long nhap so thuc: ");
				scanf_s("%s", &giaTri, 20);
			}
			maTran[i][j] = chuyenChuoiThanhSoThuc(giaTri);
		}
}

void xuatMaTranThuc(MANG2D_THUC maTran, unsigned int soDong, unsigned int soCot)
{
	for (unsigned int i = 0; i < soDong; i++)
	{
		for (unsigned int j = 0; j < soCot; j++)
			printf("\t%lf", maTran[i][j]);

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

bool kiemTraGiaTriLaSoThuc(char giaTri[])
{
	bool laPhanThapPhan = false;
	for (unsigned int i = 0; i < strlen(giaTri); i++)
		if (giaTri[i] == '-')
		{
			if (i != 0)
				return false;
		}
		else if (giaTri[i] == '.')
			if (i == 0 || laPhanThapPhan)
				return false;
			else
				laPhanThapPhan = true;
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

double chuyenChuoiThanhSoThuc(char giaTri[])
{
	double so = 0, soThapPhan = 0;
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

	for (i; i < strlen(giaTri); i++)
	{
		if (giaTri[i] == '.')
			continue;
		soThapPhan = (double)(giaTri[i] - '0') / hangThapPhan;
		so += soThapPhan;
		hangThapPhan *= 10;
	}

	if (laSoAm) so *= -1;

	return so;
}

bool tongHaiMaTran(MANG2D_THUC maTran_a, unsigned int soDong_a, unsigned int soCot_a, MANG2D_THUC maTran_b, unsigned int soDong_b, unsigned int soCot_b, MANG2D_THUC maTranTong)
{
	if (soDong_a != soDong_b || soCot_a != soCot_b) return false;

	for (unsigned int i = 0; i < soDong_a; i++)
		for (unsigned j = 0; j < soCot_a; j++)
			maTranTong[i][j] = maTran_a[i][j] + maTran_b[i][j];

	return true;
}
bool tichHaiMaTran(MANG2D_THUC maTran_a, unsigned int soDong_a, unsigned int soCot_a, MANG2D_THUC maTran_b, unsigned int soDong_b, unsigned int soCot_b, MANG2D_THUC maTranTich)
{
	if (soCot_a != soDong_b) return false;

	for (unsigned int i = 0; i < soDong_a; i++)
		for (unsigned j = 0; j < soCot_b; j++)
			for (unsigned k = 0; k < soCot_a; k++)
				maTranTich[i][j] += maTran_a[i][k] * maTran_b[k][j];

	return true;
}