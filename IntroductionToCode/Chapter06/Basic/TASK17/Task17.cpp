#include <stdio.h>
#include <string.h>

#define TOI_DA 100

char* tachChuoiVoiTuBatDau(char chuoi[], char tu[]);

int main()
{
	char chuoi[TOI_DA + 1] = "\0", tu[TOI_DA + 1] = "\0";

	printf("Nhap chuoi: ");
	gets_s(chuoi, TOI_DA);
	printf("Nhap tu bat dau cua chuoi muon tach: ");
	do
		gets_s(tu, TOI_DA);
	while (tu[0] == '\0' || tu[0] == '\n');
	
	char* chuoiTach = tachChuoiVoiTuBatDau(chuoi, tu);

	if (chuoiTach)
		printf("\nChuoi sau khi tach: %s", chuoiTach);
	else
		printf("\nChuoi khong ton tai tu da nhap.");

	return 0;
}

char* tachChuoiVoiTuBatDau(char chuoi[], char tu[])
{
	return strstr(chuoi, tu);
}