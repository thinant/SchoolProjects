#include <stdio.h>

void nhapSoNguyen(int&, int&);
int timSoLonNhat(int&, int&);
bool ktDieuKien(int, int);

int main()
{
	int a = 0, b = 0;

	nhapSoNguyen(a, b);

	printf("Hai so a b thoa dieu kien la: %d va %d.", a, b);

	return 0;
}

void nhapSoNguyen(int& a, int& b)
{
	printf("Nhap so nguyen duong a: ");		scanf_s("%d", &a);
	printf("Nhap so nguyen duong b: ");		scanf_s("%d", &b);

	while (!ktDieuKien(a, b))
	{
		printf("Hai so khong thoa dieu kien. Vui long nhap lai.\n");
		printf("Nhap so nguyen duong a: ");		scanf_s("%d", &a);
		printf("Nhap so nguyen duong b: ");		scanf_s("%d", &b);
	}
}

int timSoLonNhat(int& a, int& b)
{
	int soLonNhat = a;
	if (b > a) soLonNhat = b;

	return soLonNhat;
}

bool ktDieuKien(int a, int b)
{
	int soLonNhat = timSoLonNhat(a, b);
	bool thoaDieuKien = false;

	thoaDieuKien = (soLonNhat > 0 && soLonNhat % 7 == 0);

	return thoaDieuKien;
}