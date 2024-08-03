#include <stdio.h>
#include <string.h>

#define TOI_DA 100
typedef unsigned int MANG2D_NGUYEN_DUONG[TOI_DA][TOI_DA];

void nhapMaTranNguyenDuong(MANG2D_NGUYEN_DUONG tamGiacPascal, unsigned int& chieuCao);
void xuatMaTranNguyenDuong(MANG2D_NGUYEN_DUONG tamGiacPascal, unsigned int chieuCao);
bool kiemTraGiaTriLaSoNguyenDuong(char giaTri[]);
unsigned int chuyenChuoiThanhSo(char giaTri[]);

int main()
{
	MANG2D_NGUYEN_DUONG tamGiacPascal{ 0 };
	unsigned int chieuCao;

	nhapMaTranNguyenDuong(tamGiacPascal, chieuCao);

	printf("Tam giac Pascal co chieu cao %d:\n", chieuCao);
	xuatMaTranNguyenDuong(tamGiacPascal, chieuCao);

	return 0;
}

void nhapMaTranNguyenDuong(MANG2D_NGUYEN_DUONG tamGiacPascal, unsigned int& chieuCao)
{
	char giaTri[10 + 1] = "";

	printf("Nhap chieu cao tam giac: ");
	scanf_s("%s", &giaTri, 10);
	while (!kiemTraGiaTriLaSoNguyenDuong(giaTri))
	{
		printf("Gia tri khong hop le. Vui long nhap so nguyen duong: ");
		scanf_s("%s", &giaTri, 10);
	}
	chieuCao = chuyenChuoiThanhSo(giaTri);

	for (unsigned int i = 0; i < chieuCao; i++)
		for (unsigned int j = 0; j <= i; j++)
		{
			if (j == 0 || j == i)
				tamGiacPascal[i][j] = 1;
			else
				tamGiacPascal[i][j] = tamGiacPascal[i - 1][j - 1] + tamGiacPascal[i - 1][j];
		}
}

void xuatMaTranNguyenDuong(MANG2D_NGUYEN_DUONG tamGiacPascal, unsigned int chieuCao)
{
	for (unsigned int i = 0; i < chieuCao; i++)
	{
		for (unsigned int j = 0; j <= i; j++)
			printf("\t%u", tamGiacPascal[i][j]);

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

unsigned int chuyenChuoiThanhSo(char giaTri[])
{
	unsigned int so = 0;

	for (unsigned int i = 0; i < strlen(giaTri); i++)
	{
		so *= 10;
		so += (giaTri[i] - '0');
	}

	return so;
}