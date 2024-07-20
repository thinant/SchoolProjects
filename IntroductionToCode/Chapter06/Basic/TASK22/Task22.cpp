#include <stdio.h>
#include <string.h>

#define TOI_DA 100

void xoaTuKhoiChuoi(char chuoi[], char tu[]);

int main()
{
	char chuoi[TOI_DA + 1] = "\0", tu[TOI_DA + 1] = "\0";

	printf("Nhap chuoi: ");
	gets_s(chuoi, TOI_DA);

	printf("Nhap tu: ");
	do
		gets_s(tu, TOI_DA);
	while (tu[0] == '\0' || tu[0] == '\n');

	xoaTuKhoiChuoi(chuoi, tu);

	printf("Chuoi sau khi loai tat ca tu %s: %s", tu, chuoi);

	return 0;
}

void xoaTuKhoiChuoi(char chuoi[], char tu[])
{
	

	while (true)
	{
		unsigned int doDaiTu = strlen(tu), doDaiChuoi = strlen(chuoi);
		char* viTri = strstr(chuoi, tu);

		if (viTri - chuoi < 0 || viTri - chuoi > doDaiChuoi)
			break;
		else
			for (unsigned int i = viTri - chuoi; i + doDaiTu <= doDaiChuoi; i++)
				chuoi[i] = chuoi[i + doDaiTu];
	}
}