#include <stdio.h>
#include <string.h>

#define TOI_DA 100

void tachHoLotLen(char hoTen[], char hoLot[], char ten[]);

int main()
{
	char hoTen[TOI_DA + 1] = "\0", hoLot[TOI_DA + 1] = "\0", ten[TOI_DA + 1] = "\0";

	printf("Nhap ho ten: ");
	gets_s(hoTen, TOI_DA);

	tachHoLotLen(hoTen, hoLot, ten);

	printf("\nHo ten: %s", hoTen);
	printf("\nHo va lot: %s", hoLot);
	printf("\nTen: %s", ten);

	return 0;
}

void tachHoLotLen(char hoTen[], char hoLot[], char ten[])
{
	int i = strlen(hoTen) - 1;
	hoLot[0] = '\0', ten[0] = '\0';
	bool coKyTu = false;

	while (i >= 0)
	{
		if (hoTen[i] != ' ')
			coKyTu = true;
		else if (coKyTu)
		{
			strcpy_s(ten, TOI_DA, hoTen + i + 1);
			if (i > 0)
				strncpy_s(hoLot, TOI_DA, hoTen, i);

			break;
		}
		i--;
	}
}