#include <stdio.h>

bool laUoc(unsigned int, unsigned int);
bool laSoChan(unsigned int);
unsigned int demSoUocChan(unsigned int);

int main()
{
	unsigned int n = 0;
	printf("Nhap n: ");		scanf_s("%u", &n);

	unsigned int soUocChan = demSoUocChan(n);

	printf("So uoc chan cua %d la %d.", n, soUocChan);

	return 0;
}

bool laUoc(unsigned int n, unsigned int u)
{
	bool uoc = false;
	if (n % u == 0) uoc = true;

	return uoc;
}

bool laSoChan(unsigned int n)
{
	bool soChan = laUoc(n, 2);

	return soChan;
}

unsigned int demSoUocChan(unsigned int n)
{
	unsigned int soUocChan = 0;

	for (unsigned int i = 1; i <= n; i++)
		if (laUoc(n, i) && laSoChan(i)) soUocChan++;

	return soUocChan;
}
