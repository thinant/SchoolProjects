#include <stdio.h>

void nhapSoNguyen(unsigned int&, char);
bool kiemTraSoDoiXung(unsigned int);
bool kiemTraDoiXungDauCuoi(unsigned int, unsigned int);
void catDauCuoi(unsigned int&, unsigned int);

int main()
{
	unsigned int n = 0;
	nhapSoNguyen(n, 'n');

	if (kiemTraSoDoiXung(n)) printf("%u la so doi xung.", n);
	else printf("%u khong la so doi xung.", n);

	return 0;
}

void nhapSoNguyen(unsigned int& n, char c)
{
	printf("Nhap so nguyen duong %c: ", c);		scanf_s("%u", &n);
}

bool kiemTraSoDoiXung(unsigned int n)
{
	bool laSoDoiXung = true;

	for (unsigned int soLan = 1; soLan <= 2; soLan++)
		if (!kiemTraDoiXungDauCuoi(n, soLan))
		{
			laSoDoiXung = false;
			break;
		}
		else catDauCuoi(n, soLan);

	return laSoDoiXung;
}

bool kiemTraDoiXungDauCuoi(unsigned int n, unsigned int soLan)
{
	bool coDoiXungDauCuoi = false;
	unsigned int cuoi = n % 10;
	unsigned int heSo = 10000;
	unsigned int dau = n;

	for (unsigned int i = 1; i < soLan; i++)
		heSo /= 100;

	dau /= heSo;

	coDoiXungDauCuoi = (dau == cuoi);

	return coDoiXungDauCuoi;
}

void catDauCuoi(unsigned int& n, unsigned int soLan)
{
	unsigned int heSo = 1000;
	for (unsigned int i = 1; i <= soLan; i++)
	{
		n /= 10;
		n %= heSo;
		heSo /= 100;
	}
}