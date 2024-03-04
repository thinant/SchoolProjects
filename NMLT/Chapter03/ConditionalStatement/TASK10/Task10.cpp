#include <stdio.h>

int main()
{
	int hh = 0, mm = 0, ss = 0;
	bool isTrue = true;

	printf("Nhap gio: ");		scanf_s("%d", &hh);
	printf("Nhap phut: ");		scanf_s("%d", &mm);
	printf("Nhap giay: ");		scanf_s("%d", &ss);

	if (0 > hh || 0 > mm || 0 > ss) isTrue = false;

	if (hh > 23 || mm > 59 || ss > 59) isTrue = false;

	if (isTrue) printf("Thoi gian hop le.");
	else printf("Thoi gian khong hop le.");

	return 0;
}