#include <stdio.h>

int tachChuSo(unsigned int, unsigned int);
unsigned int tachChuSoDauTien(unsigned int);

int main()
{
	unsigned int n = 0;
	printf("Nhap n: ");		scanf_s("%u", &n);

	unsigned int chuSoDauTien = tachChuSoDauTien(n);

	printf("Chu so lon nhat cua %u la: %u", n, chuSoDauTien);

	return 0;
}

int tachChuSo(unsigned int n, unsigned int hang)
{
	int chuSo = n / hang;
	if (chuSo == 0) return chuSo = -1;
	else chuSo %= 10;

	return chuSo;
}
unsigned int tachChuSoDauTien(unsigned int n)
{
	unsigned int chuSoDauTien = 0;
	unsigned int chuSo = 0;
	unsigned int hang = 1;

	while (chuSo != -1)
	{
		chuSoDauTien = chuSo;
		chuSo = tachChuSo(n, hang);
		hang *= 10;
	}
	
	return chuSoDauTien;
}