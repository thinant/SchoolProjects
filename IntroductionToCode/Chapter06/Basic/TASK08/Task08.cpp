#include <stdio.h>
#include <string.h>

#define TOI_DA 100

void inHoaChuoi(char chuoi[]);

int main()
{
	char chuoi[TOI_DA + 1];

	printf("Nhap chuoi: ");
	gets_s(chuoi, TOI_DA);

	inHoaChuoi(chuoi);


	printf("Chuoi sau khi dinh dang chu hoa: %s", chuoi);

	return 0;
}

void inHoaChuoi(char chuoi[])
{
	unsigned int doDaiChuoi = strlen(chuoi);
	int buocNhay = 'A' - 'a';

	for (unsigned int i = 0; i < doDaiChuoi; i++)
		if (chuoi[i] >= 'a' && chuoi[i] <= 'z')
			chuoi[i] += buocNhay;
}