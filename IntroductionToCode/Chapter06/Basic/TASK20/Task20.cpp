#include <stdio.h>
#include <string.h>

#define TOI_DA 100

void xoaKiTuKhoiChuoi(char chuoi[], char kiTu);

int main()
{
	char chuoi[TOI_DA + 1] = "\0", kiTu = '\0';

	printf("Nhap chuoi: ");
	gets_s(chuoi, TOI_DA);

	printf("Nhap ki tu: ");
	scanf_s("%c", &kiTu);

	xoaKiTuKhoiChuoi(chuoi, kiTu);

	printf("Chuoi sau khi loai tat ca ki tu %c: %s", kiTu, chuoi);

	return 0;
}

void xoaKiTuKhoiChuoi(char chuoi[], char kiTu)
{
	unsigned int soKiTuXoa = 0, doDaiChuoi = strlen(chuoi);

	for (unsigned int i = 0; i + soKiTuXoa <= doDaiChuoi; i++)
	{
		while (chuoi[i + soKiTuXoa] == kiTu)
			soKiTuXoa++;

		chuoi[i] = chuoi[i + soKiTuXoa];
	}
}