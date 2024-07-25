#include <stdio.h>
#include <string.h>

#define TOI_DA 100

unsigned int demKyTuGiongNhauTrongHaiChuoi(char chuoi_a[], char chuoi_b[]);

int main()
{
	char chuoi_a[TOI_DA + 1] = "\0", chuoi_b[TOI_DA + 1] = "\0";
	unsigned int soKyTuTrung = 0;

	printf("Nhap chuoi a: ");
	gets_s(chuoi_a);

	printf("Nhap chuoi b: ");
	do
		gets_s(chuoi_b);
	while (chuoi_b[0] == '\0' || chuoi_b[0] == '\n');

	soKyTuTrung = demKyTuGiongNhauTrongHaiChuoi(chuoi_a, chuoi_b);

	printf("So ky tu giong nhau trong hai chuoi la: %d", soKyTuTrung);

	return 0;
}

unsigned int demKyTuGiongNhauTrongHaiChuoi(char chuoi_a[], char chuoi_b[])
{
	unsigned int doDaiChuoi_a = strlen(chuoi_a), doDaiChuoi_b = strlen(chuoi_b), soKiTu = 0;
	char mangKiTuTrung[TOI_DA + 1] = "\0";

	for (int i = 0; i < doDaiChuoi_a; i++)
	{
		int viTriTrung = strchr(chuoi_b, chuoi_a[i]) - chuoi_b;
		if (viTriTrung >= 0 && viTriTrung < doDaiChuoi_b)
		{
			int viTri = strchr(mangKiTuTrung, chuoi_a[i]) - mangKiTuTrung;
			if (viTri < 0 || viTri >= strlen(mangKiTuTrung))
			{
				mangKiTuTrung[soKiTu++] = chuoi_a[i];
				mangKiTuTrung[soKiTu] = '\0';
			}
		}
	}

	return soKiTu;
}