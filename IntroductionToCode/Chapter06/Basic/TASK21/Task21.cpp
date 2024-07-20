#include <stdio.h>
#include <string.h>

#define TOI_DA 100

unsigned int xoaKiTuKhoiChuoi(char chuoi[], char kiTu);
char timKiTuXuatHienNhieuNhat(char chuoi[]);

int main()
{
	char chuoi[TOI_DA + 1] = "\0", kiTu = '\0';

	printf("Nhap chuoi: ");
	gets_s(chuoi, TOI_DA);

	kiTu = timKiTuXuatHienNhieuNhat(chuoi);

	printf("Ki tu xuat hien nhieu nhat trong chuoi la: %c", kiTu);

	return 0;
}

unsigned int xoaKiTuKhoiChuoi(char chuoi[], char kiTu)
{
	unsigned int soKiTuXoa = 0, doDaiChuoi = strlen(chuoi);

	for (unsigned int i = 0; i + soKiTuXoa <= doDaiChuoi; i++)
	{
		while (chuoi[i + soKiTuXoa] == kiTu)
			soKiTuXoa++;

		chuoi[i] = chuoi[i + soKiTuXoa];
	}

	return soKiTuXoa;
}

char timKiTuXuatHienNhieuNhat(char chuoi[])
{
	unsigned int tanSuatLonNhat = 0;
	char kiTuXuatHienNhieuNhat = '\0';
	char chuoiPhu[TOI_DA + 1] = "\0";

	strcpy_s(chuoiPhu, TOI_DA + 1, chuoi);

	while (strlen(chuoiPhu) != 0)
	{
		char kiTu = chuoiPhu[0];
		unsigned int tanSuat = xoaKiTuKhoiChuoi(chuoiPhu, kiTu);

		if (tanSuat > tanSuatLonNhat)
		{
			tanSuatLonNhat = tanSuat;
			kiTuXuatHienNhieuNhat = kiTu;
		}
	}

	return kiTuXuatHienNhieuNhat;
}