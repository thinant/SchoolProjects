#include <stdio.h>
#include <string.h>

#define TOI_DA 100

int timKyTuTrongChuoi(char chuoi[], char kyTu);

int main()
{
	char chuoi[TOI_DA + 1], kyTu = '\0';

	printf("Nhap chuoi: ");
	gets_s(chuoi, TOI_DA);
	printf("Nhap kyTu: ");
	do
		scanf_s("%c", &kyTu);
	while (kyTu == '\0' || kyTu == '\n');

	int viTriKyTu = timKyTuTrongChuoi(chuoi, kyTu);

	if (viTriKyTu >= 0)
		printf("Ky tu o vi tri %d.", viTriKyTu);
	else
		printf("Ky tu khong xuat hien trong chuoi.");

	return 0;
}

int timKyTuTrongChuoi(char chuoi[], char kyTu)
{
	char* kyTuCoTrongChuoi = strchr(chuoi, kyTu);

	if (kyTuCoTrongChuoi - chuoi > 0) 
		return kyTuCoTrongChuoi - chuoi;

	return -1;
}