#include <stdio.h>

void nhapSoNguyen(unsigned int&, char);
bool kiemTraSoNguyenTo(unsigned int);
unsigned int demSoNguyenTo(unsigned int);

int main()
{
	unsigned int n = 0, snt = 0;
	nhapSoNguyen(n, 'n');

	snt = demSoNguyenTo(n);

	printf("So chu so nguyen to trong so %u la: %u\n", n, snt);

	return 0;
}

void nhapSoNguyen(unsigned int& n, char c)
{
	printf("Nhap so nguyen duong %c: ", c);		scanf_s("%u", &n);

	while (n >= 100000)
	{
		printf("So khong hop le. Vui long nhap lai: ");		scanf_s("%u", &n);
	}
}

bool kiemTraSoNguyenTo(unsigned int n)
{
	bool laSNT = true;

	if (n < 2) laSNT = false;

	for (unsigned int i = 2; i <= n / 2; i++)
		if (n % i == 0)
		{
			laSNT = false;
			break;
		}

	return laSNT;
}

unsigned int demSoNguyenTo(unsigned int n)
{
	unsigned int snt = 0;
	while (n != 0)
	{
		if (kiemTraSoNguyenTo(n % 10)) snt++;
		n /= 10;
	}

	return snt;
}