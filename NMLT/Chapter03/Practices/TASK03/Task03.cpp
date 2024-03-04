#include <stdio.h>

int main()
{
	int dd = 0, mm = 0;
	bool isLegit = true;
	int maxDays = 0;

	printf("Nhap ngay: ");		scanf_s("%d", &dd);
	printf("Nhap thang: ");		scanf_s("%d", &mm);

	//check legit
	if (mm <= 0 || mm > 12) isLegit = false;
	if (isLegit)
	{

		//set maximum number of Days of a month
		if ((mm < 8 && mm % 2 != 0) || (mm >= 8 && mm % 2 == 0)) maxDays = 31;
		else if (mm == 2) maxDays = 28;
		else maxDays = 30;

		if (dd <= 0 || dd > maxDays) isLegit = false;
	}

	//print next date
	if (isLegit)
	{
		int totalDays = 0, weekDay = 0;

		for (int i = 1; i < mm; i++)
		{
			if ((i < 8 && i % 2 != 0) || (i >= 8 && i % 2 == 0)) maxDays = 31;
			else if (i == 2) maxDays = 28;
			else maxDays = 30;

			totalDays += maxDays;	//sum of previous months' days
		}

		totalDays += dd;			//add passed days of the current month
		totalDays += 2;				//since 1/1/2003 is Wednesday, 
									//the current day is 2 extra days 
									//away from the last Sunday of the previous year

		weekDay = totalDays % 7;	//since there are 7 days a week.

		printf("Ngay %d/%d/%d la ", dd, mm, 2003);

		switch (weekDay)
		{
		case 0:
			printf("Chu Nhat.");
			break;
		case 1:
			printf("thu Hai.");
			break;
		case 2:
			printf("thu Ba.");
			break;
		case 3:
			printf("thu Tu.");
			break;
		case 4:
			printf("thu Nam.");
			break;
		case 5:
			printf("thu Sau .");
			break;
		case 6:
			printf("thu Bay.");
			break;
		}

	}
	else printf("Ngay khong hop le.");

	return 0;
}