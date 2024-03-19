#include <stdio.h>

void nhapSoNguyen(unsigned int&, char, unsigned int);
bool kiemtraTangDan(unsigned int, unsigned int);
bool kiemtraThuTu(unsigned int);

int main()
{
	unsigned int n = 0, gioiHan = 100000;
	nhapSoNguyen(n, 'n', gioiHan);

	bool coThuTu = kiemtraThuTu(n);

	if (coThuTu) printf("%u la so co thu tu.", n);
	else printf("%u la so khong co thu tu.", n);

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

bool kiemtraTangDan(unsigned int n1, unsigned int n2)
{
	bool tangDan = n1 > n2;
	return tangDan;
}

bool kiemtraThuTu(unsigned int n)
{
	unsigned int n1 = 0, n2 = 0;
	bool coThuTu = true, thuTuMacDinh = true, coTangDan = true;

	n1 = n % 10;
	n /= 10;
	n2 = n % 10;

	thuTuMacDinh = kiemtraTangDan(n1, n2);

	n /= 10;

	while (n != 0)
	{
		n1 = n2;
		n2 = n % 10;
		coTangDan = kiemtraTangDan(n1, n2);

		if (coTangDan != thuTuMacDinh)
		{
			coThuTu = false;
			break;
		}

		n /= 10;
	}

	return coThuTu;
}