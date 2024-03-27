#include <stdio.h>

void nhapSoNguyen(unsigned int&, char, unsigned int);
float tinhTrungBinhChan(unsigned int);

int main()
{
	unsigned int n = 0;
	float trungBinhChan = 0;

	nhapSoNguyen(n, 'n', 100000);

	trungBinhChan = tinhTrungBinhChan(n);

	printf("Trung binh cua cac chu so chan trong %u la: %f", n, trungBinhChan);

	return 0;
}

void nhapSoNguyen(unsigned int& n, char c, unsigned int gioiHan)
{
	printf("Nhap so nguyen duong %c: ", c);		scanf_s("%u", &n);

	while (n >= gioiHan)
	{
		printf("So khong hop le. Vui long nhap lai: ");		scanf_s("%u", &n);
	}
}

float tinhTrungBinhChan(unsigned int n)
{
	unsigned int chuSo = n % 10, tongChan = 0, soChuSoChan = 0;
	float trungBinhChan = 0;

	while (n != 0)
	{
		if (chuSo % 2 == 0)
		{
			tongChan += chuSo;
			soChuSoChan++;
		}

		n /= 10;
		chuSo = n % 10;
	}

	trungBinhChan = (float)tongChan / soChuSoChan;

	return trungBinhChan;
}