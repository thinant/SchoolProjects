#include <stdio.h>

void inSoNguyenToNhoHon(unsigned int);
bool laSoNguyenTo(unsigned int);

int main()
{
	unsigned int n = 0;

	printf("Nhap so nguyen n: ");	scanf_s("%u", &n);

	printf("Cac so nguyen to nho hon %u: ", n);		 inSoNguyenToNhoHon(n);

	return 0;
}

void inSoNguyenToNhoHon(unsigned int n)
{
	unsigned int soSNT = 0;

	for (unsigned int i = 2; i < n; i++)
		if (laSoNguyenTo(i))
		{
			printf("%u ", i);
			soSNT++;
		}

	if (soSNT == 0) printf("khong co so nguyen to nao nho hon %u", n);
}

bool laSoNguyenTo(unsigned int n)
{
	bool laSNT = true;

	if (n < 2) laSNT = false;
	for (int i = 2; i < n; i++)
		if (n % i == 0)
		{
			laSNT = false;
			break;
		}

	return laSNT;
}