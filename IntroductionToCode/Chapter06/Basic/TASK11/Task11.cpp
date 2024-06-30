#include <stdio.h>
#include <string.h>

#define TOI_DA 100

void daoChuoi(char chuoi[]);
void hoanVi(char& a, char& b);

int main()
{
	char chuoi[TOI_DA + 1];

	printf("Nhap chuoi: ");
	gets_s(chuoi, TOI_DA);

	daoChuoi(chuoi);


	printf("Chuoi sau khi dao: %s", chuoi);

	return 0;
}

void daoChuoi(char chuoi[])
{
	unsigned int doDaiChuoi = strlen(chuoi);

	for (unsigned int i = 0; i < doDaiChuoi / 2; i++)
		hoanVi(chuoi[i], chuoi[doDaiChuoi - i - 1]);
}

void hoanVi(char& a, char& b)
{
	char tmp = a;
	a = b;
	b = tmp;
}
