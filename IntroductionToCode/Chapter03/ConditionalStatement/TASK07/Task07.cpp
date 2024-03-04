#include <stdio.h>

int main()
{
	int n = 0;
	int vitri = 0, chuso = 0, i = 0;

	printf("Nhap so: ");	scanf_s("%d", &n);
	while (n != 0)
	{
		i++;
		if (n % 10 > chuso)
		{
			chuso = n % 10;
			vitri = i;
		}

		n /= 10;
	}

	if (i > 3)
	{
		printf("So da nhap khong hop le.");
	}
	else
	{
		switch (vitri)
		{
		case 1:
			printf("Chu so lon nhat nam o hang don vi la chu so %d.", chuso);
			break;
		case 2:
			printf("Chu so lon nhat nam o hang chuc la chu so %d.", chuso);
			break;
		case 3:
			printf("Chu so lon nhat nam o hang tram la chu so %d.", chuso);
			break;
		default:
			printf("So da nhap khong hop le.");
		}
	}

	return 0;
}