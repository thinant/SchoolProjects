#include <stdio.h>

int main()
{
	int dd = 0, mm = 0, yyyy = 0;
	int maxDays = 30;
	bool isTrue = true;
	bool isLeap = false;

	printf("Nhap ngay: ");		scanf_s("%d", &dd);
	printf("Nhap thang: ");		scanf_s("%d", &mm);
	printf("Nhap nam: ");		scanf_s("%d", &yyyy);

	if (0 > yyyy) isTrue = false;

	if (0 > mm || 12 < mm) isTrue = false;

	if ((mm < 8 && mm % 2 == 1) || (mm >= 8 && mm % 2 == 0)) maxDays ++;
	else if (mm == 2) maxDays = 28;

	if (yyyy % 400 == 0 || (yyyy % 100 != 0 && yyyy % 4 == 0))
	{
		isLeap = true;
		if (mm == 2)
		{
			maxDays++;
		}
	}

	

	if (dd > maxDays || 0 > dd) isTrue = false;

	if (isTrue)
	{
		if (isLeap) printf("Nam nay la nam nhuan.");
		else printf("Nam nay la nam khong nhuan.");
	}
	else printf("Ngay thang nam khong hop le.");

	return 0;
}