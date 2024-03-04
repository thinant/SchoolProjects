#include <stdio.h>

int main()
{
	int dd = 0, mm = 0, yyyy = 0;
	int maxDate = 0, date = 0;
	bool isLegit = true, isLeap = false;

	printf("Nhap ngay: ");		scanf_s("%d", &dd);
	printf("Nhap thang: ");		scanf_s("%d", &mm);
	printf("Nhap nam: ");		scanf_s("%d", &yyyy);

	if (yyyy % 400 == 0 || (yyyy % 100 != 0 && yyyy % 4 == 0)) isLeap = true;

	if (mm > 12) isLegit = false;

	for (int i = 1; i <= mm && isLegit; i++)
	{
		if ((i < 8 && i % 2 != 0) || (i >= 8 && i % 2 == 0)) maxDate = 31;
		else if (i == 2)
		{
			if (isLeap) maxDate = 29;
			else maxDate = 28;
		}
		else maxDate = 30;

		if (mm > i) date += maxDate;
		else if (dd > maxDate) isLegit = false;
		else date += dd;
	}

	if (isLegit) printf("Ngay thu %d.", date);
	else printf("Ngay thang nam khong hop le.");

	return 0;
}