#include <stdio.h>
#include <string.h>

#define TOI_DA 100
typedef double MANG2D_THUC[TOI_DA][TOI_DA];

void taoMaTranThuc(MANG2D_THUC maTran, unsigned int& soDong, unsigned int& soCot);
void xuatMaTranThuc(MANG2D_THUC maTran, unsigned int soDong, unsigned int soCot);
bool kiemTraGiaTriLaSoNguyenDuong(char giaTri[]);
bool kiemTraGiaTriLaSoThuc(char giaTri[]);
unsigned int chuyenChuoiThanhSoNguyenDuong(char giaTri[]);
double chuyenChuoiThanhSoThuc(char giaTri[]);
bool laSoNguyenTo(int giaTri);

int main()
{
	MANG2D_THUC maTran = { 0 };
	unsigned int soDong = 0, soCot = 0, soCucTri = 0;

	printf("Ma tran:\n");
	taoMaTranThuc(maTran, soDong, soCot);

	xuatMaTranThuc(maTran, soDong, soCot);

	return 0;
}

void taoMaTranThuc(MANG2D_THUC maTran, unsigned int& soDong, unsigned int& soCot)
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
	soCot = soDong;

	unsigned int giaTriMaTran = 1;

	for (unsigned int i = 0; i < soDong - 1; i++)
		for (unsigned int j = 0; j <= i; j++)
		{
			maTran[i - j][j] = giaTriMaTran * giaTriMaTran;
			giaTriMaTran++;
		}

	giaTriMaTran = 2;

	for (int j = 0; j < soCot; j++)
		for (int i = soDong - 1; i >= j; i--) {
			while (!laSoNguyenTo(giaTriMaTran))
				giaTriMaTran++;

			maTran[i][soDong - 1 - i + j] = giaTriMaTran;
			giaTriMaTran++;
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

	if (chuyenChuoiThanhSoNguyenDuong(giaTri) >= 10)
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

bool laSoNguyenTo(int giaTri) {
	if (giaTri < 2) {
		return false;
	}

	for (unsigned int i = 2; i <= giaTri / 2; i++) {
		if (giaTri % i == 0) return false;
	}

	return true;
}