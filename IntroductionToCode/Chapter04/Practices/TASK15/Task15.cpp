#include <stdio.h>

void nhapSoNguyen(unsigned int&, char);
void demChanLe(unsigned int, unsigned int&, unsigned int&);

int main()
{
	unsigned int n = 0, chan = 0, le = 0;
	nhapSoNguyen(n, 'n');

	demChanLe(n, chan, le);

	printf("So chu so chan trong so %u la: %u\n", n, chan);
	printf("So chu so le trong so %u la: %u\n", n, le);

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