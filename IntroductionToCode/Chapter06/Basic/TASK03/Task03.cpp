#include <stdio.h>
#include <string.h>

#define TOI_DA 100

int nhapVaTinhDoDaiChuoi(char* chuoi);

int main()
{
	char chuoi[TOI_DA + 1];
	unsigned int doDaiChuoi = 0;

	doDaiChuoi = nhapVaTinhDoDaiChuoi(chuoi);

	printf("Chuoi vua nhap co doi dai: %u.", doDaiChuoi);

	return 0;
}

int nhapVaTinhDoDaiChuoi(char* chuoi)
{
	printf("Nhap chuoi: ");
	gets_s(chuoi, TOI_DA);

	return strlen(chuoi);
}