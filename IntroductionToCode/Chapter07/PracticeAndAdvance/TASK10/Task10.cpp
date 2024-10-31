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
void taoMaTranGiaTriLonNhat(MANG2D_THUC maTran, unsigned int soDong, unsigned int soCot, MANG2D_THUC maTranGiaTriLonNhat);
double tinhGiaTriLonNhatMaTranVuong(MANG2D_THUC maTran, int soDong, int soCot, int tam_i, int tam_j);

int main()
{
	MANG2D_THUC maTran, maTranGiaTriLonNhat;
	unsigned int soDong = 0, soCot = 0;

	printf("Ma tran:\n");
	nhapMaTranThuc(maTran, soDong, soCot);

	printf("\nMa tran da nhap la:\n");
	xuatMaTranThuc(maTran, soDong, soCot);

	taoMaTranGiaTriLonNhat(maTran, soDong, soCot, maTranGiaTriLonNhat);

	printf("Ma tran gia tri lon nhat tao thanh tu ma tran tren la:\n");
	xuatMaTranThuc(maTranGiaTriLonNhat, soDong, soCot);


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

void taoMaTranGiaTriLonNhat(MANG2D_THUC maTran, unsigned int soDong, unsigned int soCot, MANG2D_THUC maTranGiaTriLonNhat)
{
	for (unsigned int i = 0; i < soDong; i++)
		for (unsigned int j = 0; j < soCot; j++)
			maTranGiaTriLonNhat[i][j] = tinhGiaTriLonNhatMaTranVuong(maTran, soDong, soCot, i, j);
}

double tinhGiaTriLonNhatMaTranVuong(MANG2D_THUC maTran, int soDong, int soCot, int tam_i, int tam_j)
{
	double giaTriLonNhat = 0;
	unsigned int soPhanTuMaTran = 0;
	for (int i = tam_i - 1; i < soDong && i <= tam_i + 1; i++)
	{
		if (i < 0) continue;
		for (int j = tam_j - 1; j < soCot && j <= tam_j + 1; j++)
		{
			if (j < 0) continue;
			if (soPhanTuMaTran == 0 || giaTriLonNhat < maTran[i][j])
				giaTriLonNhat = maTran[i][j];
			soPhanTuMaTran++;
		}
	}

	return giaTriLonNhat;
}