#include <stdio.h>
#include <string.h>

#define TOI_DA 100

void doiTuDauCuoi(char chuoi[]);

int main()
{
	char chuoi[TOI_DA + 1];

	printf("Nhap chuoi: ");
	gets_s(chuoi, TOI_DA);

	doiTuDauCuoi(chuoi);

	printf("Chuoi sau khi doi cho tu dau va tu cuoi: %s", chuoi);

	return 0;
}

void doiTuDauCuoi(char chuoi[])
{
	char chuoiGiua[TOI_DA + 1] = "\0";
	char chuoiDau[TOI_DA + 1] = "\0";
	unsigned int i = 0; 
	bool coKyTu = false;

	while (i < strlen(chuoi))
	{
		if (chuoi[i] != ' ')
			coKyTu = true;
		else if (coKyTu)
		{
			strcpy_s(chuoiGiua, TOI_DA, chuoi + i + 1);
			chuoi[i] = '\0';
		}
		i++;
	}

	coKyTu = false;
	i = 0;
	while (i < strlen(chuoiGiua))
	{
		if (chuoiGiua[i] != ' ')
			coKyTu = true;
		else if (coKyTu)
		{
			strcpy_s(chuoiDau, TOI_DA, chuoiGiua + i + 1);
			chuoiGiua[i] = '\0';
		}
		i++;
	}
	if (strlen(chuoiDau)*strlen(chuoiGiua) > 0)
		strcat_s(chuoiDau, TOI_DA, " ");
	strcat_s(chuoiDau, TOI_DA, chuoiGiua);

	if (strlen(chuoiDau) * strlen(chuoi) > 0)
		strcat_s(chuoiDau, TOI_DA, " ");
	strcat_s(chuoiDau, TOI_DA, chuoi);

	strcpy_s(chuoi, TOI_DA, chuoiDau);
}