#include <stdio.h>
#include <string.h>

#define TOI_DA 100
typedef int MANG2D_NGUYEN[TOI_DA][TOI_DA];

void nhapMaTranNguyen(MANG2D_NGUYEN maTran, unsigned int& soDong);
void xuatMaTranNguyen(MANG2D_NGUYEN maTran, unsigned int soDong);
bool kiemTraGiaTriLaSoNguyenDuong(char giaTri[]);
bool kiemTraGiaTriLaSoNguyen(char giaTri[]);
unsigned int chuyenChuoiThanhSoNguyenDuong(char giaTri[]);
int chuyenChuoiThanhSoNguyen(char giaTri[]);
unsigned int demPhanTuNguyenToDuongCheoChinhVaPhu(MANG2D_NGUYEN maTran, unsigned int soDong);
bool kiemTraSoNguyenTo(int so);

int main()
{
	MANG2D_NGUYEN maTran{ 0 };
	unsigned int soDong = 0, soPhanTuNguyenToDuongCheoChinhVaPhu;

	nhapMaTranNguyen(maTran, soDong);

	printf("Ma tran da nhap la:\n");
	xuatMaTranNguyen(maTran, soDong);

	soPhanTuNguyenToDuongCheoChinhVaPhu = demPhanTuNguyenToDuongCheoChinhVaPhu(maTran, soDong);

	printf("Co %u phan tu nguyen to nam tren duong cheo chinh va phu.", soPhanTuNguyenToDuongCheoChinhVaPhu);

	return 0;
}

void nhapMaTranNguyen(MANG2D_NGUYEN maTran, unsigned int& soDong)
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
			while (!kiemTraGiaTriLaSoNguyen(giaTri))
			{
				printf("Gia tri khong hop le. Vui long nhap so nguyen: ");
				scanf_s("%s", &giaTri, 20);
			}
			maTran[i][j] = chuyenChuoiThanhSoNguyen(giaTri);
		}
}

void xuatMaTranNguyen(MANG2D_NGUYEN maTran, unsigned int soDong)
{
	for (unsigned int i = 0; i < soDong; i++)
	{
		for (unsigned int j = 0; j < soDong; j++)
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
	unsigned int i = 0;
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

unsigned int demPhanTuNguyenToDuongCheoChinhVaPhu(MANG2D_NGUYEN maTran, unsigned int soDong)
{
	unsigned int soPhanTuNguyenTo = 0;
	for (unsigned int i = 0; i < soDong; i++)
	{
		if (kiemTraSoNguyenTo(maTran[i][i]))
			soPhanTuNguyenTo++;
		if (kiemTraSoNguyenTo(maTran[i][soDong - 1 - i]) && (i != soDong - i - 1))
			soPhanTuNguyenTo++;
	}

	return soPhanTuNguyenTo;
}

bool kiemTraSoNguyenTo(int so)
{
	if (so < 2) return false;

	for (unsigned int i = 2; i <= so / 2; i++)
		if (so % i == 0) return false;

	return true;
}