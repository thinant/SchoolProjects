#include <stdio.h>

unsigned int demSoHoanThien(unsigned int);
bool laSoHoanThien(unsigned int);

int main()
{
	unsigned int n = 0, soSoHT = 0;

	printf("Nhap so n: ");		scanf_s("%u", &n);

	soSoHT = demSoHoanThien(n);

	printf("So so hoan thien nho hon %u: %u so.", n, soSoHT);

	return 0;
}

unsigned int demSoHoanThien(unsigned int n)
{
	unsigned int soSoHT = 0;

	for (int i = 1; i < n; i++)
		if (laSoHoanThien(i)) soSoHT++;

	return soSoHT;
}

bool laSoHoanThien(unsigned int n)
{
	bool laSoHT = false;
	unsigned int tongUoc = 0;

	for (unsigned int i = 1; i <= n / 2; i++)
		if (n % i == 0)	tongUoc += i;

	if (tongUoc == n) laSoHT = true;

	return laSoHT;
}