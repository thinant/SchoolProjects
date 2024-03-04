#include <stdio.h>

bool laSoNguyenTo(unsigned int);

int main()
{
	unsigned int x = 0;
	printf("Nhap so x: ");		scanf_s("%u", &x);

	if (laSoNguyenTo(x)) printf("%d la so nguyen to", x);
	else printf("%d khong la so nguyen to", x);

	return 0;
}

bool laSoNguyenTo(unsigned int x)
{
	bool soNguyenTo = true;

	if (x <= 2) soNguyenTo = false;
	else
		for (unsigned int i = 2; i <= x/2; i++)
		{
			if (x % i == 0)
			{
				soNguyenTo = false;
				break;
			}
		}

	return soNguyenTo;
}