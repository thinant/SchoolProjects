#include <stdio.h>

int main()
{
	int dd = 0, mm = 0, yyyy = 0;
	int maxDays = 0;
	bool isTrue = true;

	printf("Nhap ngay: ");		scanf_s("%d", &dd);
	printf("Nhap thang: ");		scanf_s("%d", &mm);
	printf("Nhap nam: ");		scanf_s("%d", &yyyy);

	if (0 > yyyy) isTrue = false;

	if (0 > mm || 12 < mm) isTrue = false;

	if ((mm < 8 && mm % 2 == 1) || (mm >= 8 && mm % 2 == 0)) maxDays = 31;
	else if (mm == 2) maxDays = 28;
	else maxDays = 30;

	if (maxDays == 28)
	{
		if (yyyy % 400 == 0 || (yyyy % 100 != 0 && yyyy % 4 ==0)) maxDays = 29;
	}

	if (dd > maxDays) isTrue = false;

	if (isTrue) printf("Ngay thang nam hop le.");
	else printf("Ngay thang nam khong hop le.");

	return 0;
}