#include <stdio.h>
#include <string.h>

#define TOI_DA 100

void chenTuVaoViTri(char chuoi[], char tu[], unsigned int viTri);

int main()
{
	char chuoi[TOI_DA + 1] = "\0", tu[TOI_DA + 1] = "\0";
	unsigned int viTri = 0;

	printf("Nhap chuoi: ");
	gets_s(chuoi);

	printf("Nhap tu: ");
	do
		gets_s(tu);
	while (tu[0] == '\0' || tu[0] == '\n');

	printf("Nhap vi tri muon chen: ");
	scanf_s("%u", &viTri);

	chenTuVaoViTri(chuoi, tu, viTri);

	printf("Chuoi sau khi chen: %s", chuoi);

	return 0;
}

void chenTuVaoViTri(char chuoi[], char tu[], unsigned int viTri)
{
	unsigned int doDaiChuoi = strlen(chuoi), doDaiTu = strlen(tu);

	for (int i = doDaiChuoi; i >= (int)viTri; i--)
		chuoi[i + doDaiTu] = chuoi[i];

	for (unsigned int i = 0; i < doDaiTu; i++)
		chuoi[i + viTri] = tu[i];
}