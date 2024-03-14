#include <stdio.h>

void nhapSoNguyen(unsigned int&, char);
unsigned int tinhTongUoc(unsigned int);

int main()
{
	unsigned int n = 0, tongUoc = 0;
	nhapSoNguyen(n, 'n');

	tongUoc = tinhTongUoc(n);

	printf("Tong cac uoc cua %u la: %u\n", n, tongUoc);

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

unsigned int tinhTongUoc(unsigned int n)
{
	unsigned int tongUoc = 0;

	for (unsigned int i = 1; i <= n / 2; i++)
		if (n % i == 0)tongUoc += i;
	tongUoc += n;
	
	return tongUoc;
}