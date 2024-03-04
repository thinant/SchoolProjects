#include <stdio.h>

bool laSoHopLe(unsigned int, unsigned int, unsigned int);
void nhapSoHopLe(unsigned int&, unsigned int, unsigned int);
unsigned long long int tinhTienLuong(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

int main()
{
	unsigned int gioVao = 0, gioRa = 0, gioiHanTrai = 6, gioiHanPhai = 18, gioMoc = 12, luongTruoc = 6000, luongSau = 7500;
	unsigned long long int tienLuong = 0;

	printf("Nhap gio vao ca: ");	scanf_s("%u", &gioVao);
	nhapSoHopLe(gioVao, gioiHanTrai, gioiHanPhai - 1);

	printf("Nhap gio ra ca: ");	scanf_s("%u", &gioRa);
	nhapSoHopLe(gioRa, gioVao + 1, gioiHanPhai);

	tienLuong = tinhTienLuong(gioVao, gioRa, gioMoc, luongTruoc, luongSau);

	printf("Tien luong nhan vien la: %llud", tienLuong);

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

unsigned long long int tinhTienLuong(unsigned int gioVao, unsigned int gioRa, unsigned int gioMoc, unsigned int luongTruoc, unsigned int luongSau)
{
	unsigned long long int tienLuong = 0;

	if (gioRa<= gioMoc) tienLuong = luongTruoc * (gioRa - gioVao);
	else if (gioVao >= gioMoc) tienLuong = luongSau * (gioRa - gioVao);
	else tienLuong = luongTruoc * (gioMoc - gioVao) + luongSau * (gioRa - gioMoc);

	return tienLuong;
}