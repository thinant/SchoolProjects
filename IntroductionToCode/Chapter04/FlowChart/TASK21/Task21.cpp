#include <stdio.h>

unsigned int timBoiChungNhoNhat(unsigned int, unsigned int);
unsigned int timUocChungLonNhat(unsigned int, unsigned int);
void timPhanDu(unsigned int&, unsigned int&);

int main()
{
	unsigned int a = 0, b = 0;

	printf("Nhap a:	");		scanf_s("%u", &a);
	printf("Nhap b:	");		scanf_s("%u", &b);

	unsigned int boiChungNhoNhat = timBoiChungNhoNhat(a, b);

	printf("Boi chung nho nhat cua %d va %d la %d", a, b, boiChungNhoNhat);

	return 0;
}

unsigned int timBoiChungNhoNhat(unsigned int a, unsigned int b)
{
	unsigned int uocChungNhoNhat = timUocChungLonNhat(a, b);
	unsigned int boiChungNhoNhat = 0;
	if (uocChungNhoNhat != 0) boiChungNhoNhat = a* b / uocChungNhoNhat;

	return boiChungNhoNhat;
}


unsigned int timUocChungLonNhat(unsigned int a, unsigned int b)
{
	unsigned int uscln = 0;
	while (a != 0 && b != 0)
	{
		timPhanDu(a, b);
	}

	if (a == 0) uscln = b;
	else uscln = a;

	return uscln;
}

void timPhanDu(unsigned int& a, unsigned int& b)
{
	if (a > b) a = a % b;
	else b = b % a;
}