#include <stdio.h>

void nhapSoNguyen(unsigned int&, char);
unsigned int tachChuSoBeNhat(unsigned int&);
unsigned int sapXepChuSo(unsigned int);

int main()
{
	unsigned int n = 0, soDaSapXep = 0;
	nhapSoNguyen(n, 'n');

	soDaSapXep = sapXepChuSo(n);

	printf("So %u sau khi duoc sap xep lai: %u.", n, soDaSapXep);

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

unsigned int tachChuSoBeNhat(unsigned int& n)
{
	unsigned int chuSoBeNhat = n % 10;
	unsigned int chuSoConLai = 0;
	n /= 10;

	while (n != 0)
	{
		if (chuSoBeNhat > n % 10)
		{
			chuSoConLai = chuSoConLai * 10 + chuSoBeNhat;
			chuSoBeNhat = n % 10;
		}
		else chuSoConLai = chuSoConLai * 10 + n % 10;

		n /= 10;
	}

	n = chuSoConLai;
	
	return chuSoBeNhat;
}

unsigned int sapXepChuSo(unsigned int n)
{
	unsigned int soDaSapXep = 0, chuSoBeNhat = 0;
	while (n != 0)
	{
		chuSoBeNhat = tachChuSoBeNhat(n);
		soDaSapXep = soDaSapXep * 10 + chuSoBeNhat;
	}

	return soDaSapXep;
}