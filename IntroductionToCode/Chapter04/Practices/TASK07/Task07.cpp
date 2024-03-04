//chinh tu 17:30 den 17:00 vi gio la so nguyen

#include <stdio.h>

bool laSoHopLe(unsigned int, unsigned int, unsigned int);
void nhapSoHopLe(unsigned int&, unsigned int, unsigned int);
unsigned long long int tinhTienThue(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

int main()
{
	unsigned int gioBatDau = 0, gioKetThuc = 0, gioiHanTrai = 6, gioiHanPhai = 21, gioMoc = 17, giaTruoc = 2500, giaSau = 3000;
	unsigned long long int tienThue = 0;

	printf("Nhap gio bat dau thue: ");	scanf_s("%u", &gioBatDau);
	nhapSoHopLe(gioBatDau, gioiHanTrai, gioiHanPhai - 1);
	
	printf("Nhap gio ket thuc thue: ");	scanf_s("%u", &gioKetThuc);
	nhapSoHopLe(gioKetThuc, gioBatDau + 1, gioiHanPhai);

	tienThue = tinhTienThue(gioBatDau, gioKetThuc, gioMoc, giaTruoc, giaSau);

	printf("Tien thue may la: %llud", tienThue);

	return 0;
}

bool laSoHopLe(unsigned int n, unsigned int l, unsigned int r)
{
	bool soHopLe = true;

	if (n < l || n > r) soHopLe = false;

	return soHopLe;
}

void nhapSoHopLe(unsigned int& n, unsigned int l, unsigned int r)
{
	while (!laSoHopLe(n, l, r))
	{
		printf("So khong hop le. Vui long nhap lai: ");		scanf_s("%u", &n);
	}
}

unsigned long long int tinhTienThue(unsigned int gioBatDau, unsigned int gioKetThuc, unsigned int gioMoc, unsigned int giaTruoc, unsigned int giaSau)
{
	unsigned long long int tienThue = 0;

	if (gioKetThuc <= gioMoc) tienThue = giaTruoc * (gioKetThuc - gioBatDau);
	else if (gioBatDau >= gioMoc) tienThue = giaSau * (gioKetThuc - gioBatDau);
	else tienThue = giaTruoc * (gioMoc - gioBatDau) + giaSau * (gioKetThuc - gioMoc);

	return tienThue;
}