#include <stdio.h>

void nhapSoNguyen(unsigned int&, char);
void demChanLe(unsigned int, unsigned int&, unsigned int&);
void ketLuanChanLe(unsigned int n);

int main()
{
	unsigned int n = 0;
	nhapSoNguyen(n, 'n');

	ketLuanChanLe(n);

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

void demChanLe(unsigned int n, unsigned int& chan, unsigned int& le)
{
	while (n != 0)
	{
		if ((n % 10) % 2 == 0) chan++;
		else le++;
		n /= 10;
	}
}

void ketLuanChanLe(unsigned int n)
{
	unsigned int chan = 0, le = 0;
	demChanLe(n, chan, le);

	if (le == 0) printf("So %u toan chu so chan.", n);
	else if (chan == 0) printf("So %u toan chu so le.", n);
	else printf("So %u chua ca chu so chan va le.", n);
}