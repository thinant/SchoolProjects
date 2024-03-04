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
		//set next date
		int nDay = dd, nMonth = mm, nYear = yyyy;

		if (nDay == maxDays)
		{
			nDay = 1;
			if (nMonth == 12) nMonth = 1;
			else nMonth++;
		}
		else nDay++;

		if (nDay == nMonth && nMonth == 1) nYear++;

		printf("Ngay sau do: %d/%d/%d.", nDay, nMonth, nYear);
	}
	else printf("Ngay khong hop le.");

	return 0;
}