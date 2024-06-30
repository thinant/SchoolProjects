#include <stdio.h>
#include <string.h>

#define TOI_DA 100

void inHoaKyTuDauMoiTu(char chuoi[]);

int main()
{
	char chuoi[TOI_DA + 1];

	printf("Nhap chuoi: ");
	gets_s(chuoi, TOI_DA);

	inHoaKyTuDauMoiTu(chuoi);


	printf("Chuoi sau khi dinh dang in hoa ky tu dau tien cua moi tu: %s", chuoi);

	return 0;
}

void inHoaKyTuDauMoiTu(char chuoi[])
{
	unsigned int doDaiChuoi = strlen(chuoi);
	int buocNhay = 'A' - 'a';

	for (unsigned int i = 0; i < doDaiChuoi; i++)
		if (i == 0 || chuoi[i - 1] == ' ')
			if (chuoi[i] >= 'a' && chuoi[i] <= 'z')
				chuoi[i] += buocNhay;
}