#include <stdio.h>
#include <string.h>

#define TOI_DA 100

unsigned int demSoKhoangTrang(char* chuoi);

int main()
{
	char chuoi[TOI_DA + 1];
	int soKhoangTrang = 0;

	printf("Nhap chuoi: ");
	gets_s(chuoi, TOI_DA);

	soKhoangTrang = demSoKhoangTrang(chuoi);

	printf("So khoang trang trong chuoi la: %u", soKhoangTrang);
	
	return 0;
}

unsigned int demSoKhoangTrang(char* chuoi)
{
	unsigned int soKhoangTrang = 0, doDaiChuoi = strlen(chuoi);

	for (unsigned int i = 0; i < doDaiChuoi; i++)
		if (chuoi[i] == ' ')
			soKhoangTrang++;

	return soKhoangTrang;
}