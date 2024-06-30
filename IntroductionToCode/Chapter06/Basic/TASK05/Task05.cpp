#include <stdio.h>
#include <string.h>

#define TOI_DA 100

void xoaKhoangTrangThua(char* chuoi);

int main()
{
	char chuoi[TOI_DA + 1];
	int soKhoangTrang = 0;

	printf("Nhap chuoi: ");
	gets_s(chuoi, TOI_DA);
	printf("\nDo dai chuoi chua dinh dang: %d", strlen(chuoi));

	xoaKhoangTrangThua(chuoi);

	printf("\nChuoi sau khi dinh dang lai: %s", chuoi);
	printf("\nDo dai chuoi da dinh dang: %d\n", strlen(chuoi));


	return 0;
}

void xoaKhoangTrangThua(char* chuoi)
{
	unsigned int soKhoangTrang = 0, i = 0;
	bool daCoKhoangTrang = false;

	while (chuoi[i + soKhoangTrang] != '\0' && chuoi[i + soKhoangTrang] != '\n')
		if (chuoi[i + soKhoangTrang] != ' ' || ((!daCoKhoangTrang) && i != 0))
		{
			chuoi[i] = chuoi[i + soKhoangTrang];
			if (chuoi[i] == ' ') daCoKhoangTrang = true;
			else daCoKhoangTrang = false;
			i++;
		}
		else
			soKhoangTrang++;
		
	unsigned int khoangTrangCuoi = 0;
	if (chuoi[i - 1] == ' ') khoangTrangCuoi++;
	chuoi[i - khoangTrangCuoi] = chuoi[i + soKhoangTrang];
}