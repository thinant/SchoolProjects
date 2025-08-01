#include <stdio.h>

typedef struct {
	double phanThuc;
	double phanAo;
} Complex;

void nhapSoPhuc(Complex& c);
void xuatSoPhuc(Complex c);

Complex tongSoPhuc(Complex c1, Complex c2);
Complex hieuSoPhuc(Complex c1, Complex c2);
Complex tichSoPhuc(Complex c1, Complex c2);

int main() {
	Complex c1, c2, tong, hieu, tich;
	printf("\nNhap so phuc 1:\n");
	nhapSoPhuc(c1);
	printf("\nSo phuc 1 da nhap la: ");
	xuatSoPhuc(c1);

	printf("\nNhap so phuc 2:\n");
	nhapSoPhuc(c2);
	printf("\nSo phuc 2 da nhap la: ");
	xuatSoPhuc(c2);

	tong = tongSoPhuc(c1, c2);
	printf("\nTong hai so phuc la: ");
	xuatSoPhuc(tong);

	hieu = hieuSoPhuc(c1, c2);
	printf("\nHieu hai so phuc la: ");
	xuatSoPhuc(hieu);

	tich = tichSoPhuc(c1, c2);
	printf("\nTich hai so phuc la: ");
	xuatSoPhuc(tich);

	return 0;
}

void nhapSoPhuc(Complex& c) {
	printf("\nNhap phan thuc: ");
	scanf_s("%lf", &c.phanThuc);

	printf("\nNhap phan ao: ");
	scanf_s("%lf", &c.phanAo);
}

void xuatSoPhuc(Complex c) {
	if (c.phanAo > 0)
		printf("%lf + %lfi\n", c.phanThuc, c.phanAo);
	else if (c.phanAo < 0)
		printf("%lf - %lfi\n", c.phanThuc, -c.phanAo);
	else
		printf("%lf\n", c.phanThuc);
}

Complex tongSoPhuc(Complex c1, Complex c2) {
	Complex tong;

	tong.phanThuc = c1.phanThuc + c2.phanThuc;
	tong.phanAo = c1.phanAo + c2.phanAo;

	return tong;
}

Complex hieuSoPhuc(Complex c1, Complex c2) {
	Complex hieu;

	hieu.phanThuc = c1.phanThuc - c2.phanThuc;
	hieu.phanAo = c1.phanAo - c2.phanAo;

	return hieu;
}

Complex tichSoPhuc(Complex c1, Complex c2) {
	Complex tich;

	tich.phanThuc = c1.phanThuc * c2.phanThuc - c1.phanAo * c2.phanAo;
	tich.phanAo = c1.phanThuc * c2.phanAo + c1.phanAo * c2.phanThuc;

	return tich;
}