#include <stdio.h>

int main()
{
	int dd = 0, mm = 0, yyyy = 0;
	bool isLeap = false, isLegit = true;
	int maxDays = 0;

	printf("Nhap ngay: ");		scanf_s("%d", &dd);
	printf("Nhap thang: ");		scanf_s("%d", &mm);
	printf("Nhap nam: ");		scanf_s("%d", &yyyy);

	//check legit
	if (yyyy <= 0)	isLegit = false;
	if (mm <= 0 || mm > 12) isLegit = false;
	if (isLegit)
	{
		//check leap
		if ((yyyy % 400 == 0) || (yyyy % 100 != 0 && yyyy % 4 == 0)) isLeap = true;

		//set maximum number of Days of a month
		if ((mm < 8 && mm % 2 != 0) || (mm >= 8 && mm % 2 == 0)) maxDays = 31;
		else if (mm == 2)
		{
			maxDays = 28;
			if (isLeap) maxDays++;
		}
		else maxDays = 30;

		if (dd <= 0 || dd > maxDays) isLegit = false;
	}

	//print next date
	if (isLegit)
	{
		//set previous date
		int pDay = dd, pMonth = mm, pYear = yyyy;

		if (pDay == 1)
		{
			if (pMonth == 1)
			{
				pYear--;
				pMonth = 12;
				pDay = 31;
			}
			else
			{
				pMonth--;
				if (maxDays < 31 || pMonth == 7) pDay = 31;
				else if (pMonth == 2)
				{
					pDay = 28;
					if (isLeap) pDay++;
				}
				else pDay = 30;
			}
		}
		else pDay--;

		printf("Ngay truoc do: %d/%d/%d.", pDay, pMonth, pYear);
	}
	else printf("Ngay khong hop le.");

	return 0;
}