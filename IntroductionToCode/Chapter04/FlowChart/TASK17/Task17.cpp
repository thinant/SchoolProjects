#include <stdio.h>

int tachChuSo(unsigned int, unsigned int);
unsigned int timChuSoLonNhat(unsigned int);

int main()
{
	unsigned int n = 0;
	printf("Nhap n: ");		scanf_s("%u", &n);

	unsigned int chuSoLonNhat = timChuSoLonNhat(n);

	printf("Chu so lon nhat cua %u la: %u", n, chuSoLonNhat);

	return 0;
}

int tachChuSo(unsigned int n, unsigned int hang)
{
	int chuSo = n / hang;
	if (chuSo == 0) return chuSo = -1;
	else chuSo %= 10;

	return chuSo;
}
unsigned int timChuSoLonNhat(unsigned int n)
{
	unsigned int chuSoLonNhat = 0;
	unsigned int chuSo = 0;
	unsigned int hang = 1;

	while (chuSo != -1)
	{
		if (chuSo > chuSoLonNhat) chuSoLonNhat = chuSo;
		chuSo = tachChuSo(n, hang);
		hang *= 10;
	}
	
	return chuSoLonNhat;
}