#include <stdio.h>
#include <string.h>

#define TOI_DA 100

int timTenTrongHoTen(char hoTen[], char ten[]);

int main()
{
	char hoTen[TOI_DA + 1], ten[TOI_DA + 1];

	printf("Nhap ho ten: ");
	gets_s(hoTen, TOI_DA);
	printf("Nhap ten: ");
	do
		gets_s(ten, TOI_DA);
	while (ten[0] == '\0' || ten[0] == '\n');

	bool laTenDung = timTenTrongHoTen(hoTen, ten) >= 0;

	if (laTenDung)
		printf("Ten nhap dung.");
	else
		printf("Ten nhap sai");

	return 0;
}

int timTenTrongHoTen(char hoTen[], char ten[])
{
	char* tenCoTrongChuoi = strstr(hoTen, ten);

	if (tenCoTrongChuoi - hoTen >= 0)
		return tenCoTrongChuoi - hoTen;

	return -1;
}