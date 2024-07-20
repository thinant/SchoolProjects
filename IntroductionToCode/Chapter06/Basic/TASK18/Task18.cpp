#include <stdio.h>
#include <string.h>

#define TOI_DA 100

bool kiemTraChuoiDoiXung(char chuoi[]);

int main()
{
	char chuoi[TOI_DA + 1] = "\0";

	printf("Nhap chuoi: ");
	gets_s(chuoi, TOI_DA);

	if (kiemTraChuoiDoiXung(chuoi))
		printf("\nChuoi doi xung.");
	else
		printf("\nChuoi khong doi xung.");

	return 0;
}

bool kiemTraChuoiDoiXung(char chuoi[])
{
	unsigned int doDai = strlen(chuoi);

	for (unsigned int i = 0; i < doDai / 2; i++)
		if (chuoi[i] != chuoi[doDai - 1 - i])
			return false;

	return true;
}