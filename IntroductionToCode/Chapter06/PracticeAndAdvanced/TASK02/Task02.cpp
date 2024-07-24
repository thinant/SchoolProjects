#include <stdio.h>
#include <string.h>

#define TOI_DA 100

void daoTuTrongChuoi(char chuoi[]);

int main()
{
	char chuoi[TOI_DA + 1];

	printf("Nhap chuoi: ");
	gets_s(chuoi);

	daoTuTrongChuoi(chuoi);

	printf("Chuoi sau khi dinh dang lai: %s", chuoi);

	return 0;
}

void  daoTuTrongChuoi(char chuoi[])
{
	unsigned int doDaiChuoi = strlen(chuoi), doDaiTu = 0;

	char chuoiPhu[TOI_DA + 1] = "\0";

	for (int i = doDaiChuoi - 1; i >= 0; i--)
		if (chuoi[i] == ' ')
		{
			strncat_s(chuoiPhu, chuoi + i + 1, doDaiTu);
			strcat_s(chuoiPhu, " ");
			doDaiTu = 0;
		}
		else doDaiTu++;

	strncat_s(chuoiPhu, chuoi, doDaiTu);

	strcpy_s(chuoi, TOI_DA, chuoiPhu);
}