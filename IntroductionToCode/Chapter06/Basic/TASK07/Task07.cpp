#include <stdio.h>
#include <string.h>

#define TOI_DA 100

void inThuongChuoi(char chuoi[]);

int main()
{
	char chuoi[TOI_DA + 1];

	printf("Nhap chuoi: ");
	gets_s(chuoi, TOI_DA);

	inThuongChuoi(chuoi);


	printf("Chuoi sau khi dinh dang chu thuong: %s", chuoi);

	return 0;
}

void inThuongChuoi(char chuoi[])
{
	unsigned int doDaiChuoi = strlen(chuoi);
	int buocNhay = 'a' - 'A';

	for (unsigned int i = 0; i < doDaiChuoi; i++)
		if (chuoi[i] >= 'A' && chuoi[i] <= 'Z')
			chuoi[i] += buocNhay;
}