#include <stdio.h>
#include <string.h>

#define TOI_DA 100

void demTanSuatKyTuTrongChuoi(char chuoi[], char mangKiTu[], unsigned int mangTanSuat[]);
void lietKeTanSuatKyTu(char mangKiTu[], unsigned int mangTanSuat[]);

int main()
{
	char chuoi[TOI_DA + 1] = "\0", mangKiTu[TOI_DA + 1] = "\0";
	unsigned int mangTanSuat[TOI_DA + 1]{ 0 };

	printf("Nhap chuoi: ");
	gets_s(chuoi);

	demTanSuatKyTuTrongChuoi(chuoi, mangKiTu, mangTanSuat);

	lietKeTanSuatKyTu(mangKiTu, mangTanSuat);

	return 0;
}

void demTanSuatKyTuTrongChuoi(char chuoi[], char mangKiTu[], unsigned int mangTanSuat[])
{
	unsigned int doDaiChuoi = strlen(chuoi), soKiTu = 0;

	for (int i = 0; i < doDaiChuoi; i++)
	{
		int viTri = strchr(mangKiTu, chuoi[i]) - mangKiTu;
		if (viTri >= 0 && viTri < soKiTu)
			mangTanSuat[viTri]++;
		else
		{
			mangTanSuat[soKiTu] = 1;
			mangKiTu[soKiTu++] = chuoi[i];
			mangKiTu[soKiTu] = '\0';
		}
	}
}

void lietKeTanSuatKyTu(char mangKiTu[], unsigned int mangTanSuat[])
{
	unsigned int doDaiChuoi = strlen(mangKiTu);

	for (unsigned int i = 0; i < doDaiChuoi; i++)
		printf("Ki tu %c xuat hien %d lan.\n", mangKiTu[i], mangTanSuat[i]);
}