#include <stdio.h>

unsigned int timUocChungLonNhat(unsigned int, unsigned int);
void timPhanDu(unsigned int&, unsigned int&);

int main()
{
	unsigned int a = 0, b = 0;

	printf("Nhap a:	");		scanf_s("%u", &a);
	printf("Nhap b:	");		scanf_s("%u", &b);

	unsigned int uocChungLonNhat = timUocChungLonNhat(a, b);

	printf("Uoc chung lon nhat cua %d va %d la %d", a, b, uocChungLonNhat);

	return 0;
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