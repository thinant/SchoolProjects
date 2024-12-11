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
void taoMaTranSoLonNhat(MANG2D_THUC maTran, unsigned int soDong, MANG2D_THUC maTranSoLonNhat);

int main()
{
	MANG2D_THUC maTran, maTranSoLonNhat;
	unsigned int soDong = 0;

	printf("Ma tran:\n");
	nhapMaTranThuc(maTran, soDong);

	printf("\nMa tran da nhap la:\n");
	xuatMaTranThuc(maTran, soDong);

	taoMaTranSoLonNhat(maTran, soDong, maTranSoLonNhat);

	printf("Ma tran so lon nhat tao thanh tu ma tran tren la:\n");
	xuatMaTranThuc(maTranSoLonNhat, soDong);


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

void taoMaTranSoLonNhat(MANG2D_THUC maTran, unsigned int soDong, MANG2D_THUC maTranSoLonNhat)
{
	for (int i = 0; i < soDong; i++)
		for (int j = 0; j < soDong; j++)
		{
			double soLonNhat = maTran[i][j];
			if (i > j)
				for (unsigned int i_ = j; i_ <= i; i_++)
					for (unsigned int j_ = j; j_ <= i_; j_++)
					{
						if (soLonNhat < maTran[i_][j_])
						{
							soLonNhat = maTran[i_][j_];
						}
					}
			else if (i < j)
				for (unsigned int i_ = i; i_ <= j; i_++)
					for (unsigned int j_ = i_; j_ <= j; j_++)
					{
						if (soLonNhat < maTran[i_][j_])
						{
							soLonNhat = maTran[i_][j_];
						}
					}

			maTranSoLonNhat[i][j] = soLonNhat;	
		}
}
