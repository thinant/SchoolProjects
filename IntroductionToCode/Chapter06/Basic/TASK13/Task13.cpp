#include <stdio.h>
#include <string.h>

#define TOI_DA 100

unsigned int demTanSuatKyTuTrongChuoi(char chuoi[], char kyTu);

int main()
{
	char chuoi[TOI_DA + 1], kyTu = '\0';

	printf("Nhap chuoi: ");
	gets_s(chuoi, TOI_DA);
	printf("Nhap kyTu: ");
	do
		scanf_s("%c", &kyTu);
	while (kyTu == '\0' || kyTu == '\n');

	unsigned int tanSuatKyTu = demTanSuatKyTuTrongChuoi(chuoi, kyTu);

	printf("So lan ky tu xuat hien trong chuoi la %d lan.", tanSuatKyTu);

	return 0;
}

unsigned int demTanSuatKyTuTrongChuoi(char chuoi[], char kyTu)
{
	unsigned int tanSuatKyTu = 0, doDaiChuoi = strlen(chuoi);

	for (unsigned int i = 0; i < doDaiChuoi; i++)
		if (chuoi[i] == kyTu)
			tanSuatKyTu++;

	return tanSuatKyTu;
}