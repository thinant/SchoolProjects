#include <stdio.h>

int main()
{
	int h = 0, m = 0, s = 0;
	bool isLegit = true;

	printf("Nhap gio: ");		scanf_s("%d", &h);
	printf("Nhap phut: ");		scanf_s("%d", &m);
	printf("Nhap giay: ");		scanf_s("%d", &s);

	if (h >= 24 || h < 0 ||
		m >= 60 || m < 0 ||
		s >= 60 || s < 0) isLegit = false;

	if (isLegit)
	{
		int nHr = h, nMin = m, nSec = s;

		if (nSec == 0)
		{
			if (nMin == 0)
			{
				if (nHr == 0) nHr = 23;
				else nHr--;
				nMin = 59;
			}
			else nMin--;
			nSec = 59;
		}
		else nSec--;

		printf("1 giay truoc la ");
		if (nHr < 10) printf("0");		printf("%d : ", nHr);
		if (nMin < 10) printf("0");		printf("%d : ", nMin);
		if (nSec < 10) printf("0");		printf("%d", nSec);
	}
	else printf("Gio khong hop le.");

	return 0;

}