#include <stdio.h>

bool laSoChinhPhuong(unsigned int);

int main()
{
	unsigned int x = 0;
	printf("Nhap so x: ");		scanf_s("%u", &x);

	if (laSoChinhPhuong(x)) printf("%d la so chinh phuong", x);
	else printf("%d khong la so chinh phuong", x);

	return 0;
}

bool laSoChinhPhuong(unsigned int x)
{
	bool soChinhPhuong = false;

	for (unsigned int i = 1; i <= x / 2; i++)
	{
		if (x == i * i)
		{
			soChinhPhuong = true;
			break;
		}
	}

	return soChinhPhuong;
}