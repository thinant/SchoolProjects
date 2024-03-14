#include <stdio.h>

void nhapSoNguyen(unsigned int&, char);
unsigned int timUocLeLonNhat(unsigned int);

int main()
{
	unsigned int n = 0, uocLeLonNhat = 0;
	nhapSoNguyen(n, 'n');

	uocLeLonNhat = timUocLeLonNhat(n);

	if (uocLeLonNhat != 0) printf("Uoc so le lon nhat cua %u la: %u\n", n, uocLeLonNhat);
	else printf("So %u khong co uoc so le nao.", n);

	return 0;
}

void nhapSoNguyen(unsigned int& n, char c)
{
	printf("Nhap so nguyen duong %c: ", c);		scanf_s("%u", &n);

	while (n >= 100000)
	{
		printf("So khong hop le. Vui long nhap lai: ");		scanf_s("%u", &n);
	}
}

unsigned int timUocLeLonNhat(unsigned int n)
{
	unsigned int uocLeLonNhat = n / 2;
	for (uocLeLonNhat; uocLeLonNhat >= 1; uocLeLonNhat--)
		if (uocLeLonNhat % 2 == 1 && n % uocLeLonNhat == 0) break;

	return uocLeLonNhat;
}