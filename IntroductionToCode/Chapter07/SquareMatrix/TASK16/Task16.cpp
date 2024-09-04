#include <stdio.h>
#include <string.h>

#define TOI_DA 100
typedef double MANG2D_THUC[TOI_DA][TOI_DA];

void nhapMaTranThuc(MANG2D_THUC maTran, unsigned int& soDong);
void xuatMaTranThuc(MANG2D_THUC maTran, unsigned int soDong);
bool kiemTraGiaTriLaSoNguyenDuong(char giaTri[]);
bool kiemTraGiaTriLaSoThuc(char giaTri[]);
unsigned int chuyenChuoiThanhSoNguyenDuong(char giaTri[]);
double chuyenChuoiThanhSoThuc(char giaTri[]);
void sapXepCacDuongCheoChinh(MANG2D_THUC maTran, unsigned int soDong);
void sapXepDuongCheoLoai1(MANG2D_THUC maTran, unsigned int soDong, unsigned int viTriDong, unsigned int viTriCot);
void hoanVi(double& a, double& b);


int main()
{
	MANG2D_THUC maTran{ 0 };
	unsigned int soDong = 0, viTriDong = 0, viTriCot = 0;

	nhapMaTranThuc(maTran, soDong);

	printf("Ma tran da nhap la:\n");
	xuatMaTranThuc(maTran, soDong);

	sapXepCacDuongCheoChinh(maTran, soDong);

	printf("Ma tran sau khi sap xep theo tung duong cheo la:\n");
	xuatMaTranThuc(maTran, soDong);

	return 0;
}

void nhapMaTranThuc(MANG2D_THUC maTran, unsigned int& soDong)
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

	printf("Nhap noi dung ma tran:\n");

	for (unsigned int i = 0; i < soDong; i++)
		for (unsigned int j = 0; j < soDong; j++)
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

void xuatMaTranThuc(MANG2D_THUC maTran, unsigned int soDong)
{
	for (unsigned int i = 0; i < soDong; i++)
	{
		for (unsigned int j = 0; j < soDong; j++)
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

void sapXepCacDuongCheoChinh(MANG2D_THUC maTran, unsigned int soDong)
{
	for (unsigned int k = 0; k < soDong; k++)
	{
		sapXepDuongCheoLoai1(maTran, soDong, 0, k);
		sapXepDuongCheoLoai1(maTran, soDong, k, 0);
	}
}

void sapXepDuongCheoLoai1(MANG2D_THUC maTran, unsigned int soDong, unsigned int viTriDong, unsigned int viTriCot)
{
	for (unsigned int i = viTriDong, j = viTriCot; i < soDong - 1 && j < soDong - 1; i++, j++)
		for (unsigned int i1 = i + 1, j1 = j + 1; i1 < soDong && j1 < soDong; i1++, j1++)
			if (maTran[i][j] > maTran[i1][j1]) hoanVi(maTran[i][j], maTran[i1][j1]);
}

void hoanVi(double& a, double& b)
{
	double tmp = a;
	a = b;
	b = tmp;
}

