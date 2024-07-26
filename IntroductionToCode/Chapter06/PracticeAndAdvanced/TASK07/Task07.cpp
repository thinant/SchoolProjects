#include <stdio.h>
#include <string.h>

#define TOI_DA 100

unsigned int demTuTrongChuoi(char chuoi[]);
bool kiemTraKyTuHetTu(char kyTu);

int main()
{
	char chuoi[TOI_DA + 1] = "\0";
	unsigned int soTu = 0;

	printf("Nhap chuoi: ");
	gets_s(chuoi);

	soTu = demTuTrongChuoi(chuoi);

	printf("So tu trong chuoi la: %d", soTu);

	return 0;
}

unsigned int demTuTrongChuoi(char chuoi[])
{
	unsigned int doDaiChuoi = strlen(chuoi), soTu = 0;

	for (int i = 0; i < doDaiChuoi; i++)
	{
		if (!kiemTraKyTuHetTu(chuoi[i]) && kiemTraKyTuHetTu(chuoi[i + 1]))
			soTu++;
	}

	return soTu;
}

bool kiemTraKyTuHetTu(char kyTu)
{
	char chuoiKyTuHetTu[TOI_DA + 1] = " .,;?!";
	int viTri = strchr(chuoiKyTuHetTu, kyTu) - chuoiKyTuHetTu;

	return (viTri >= 0 && viTri < strlen(chuoiKyTuHetTu));

}