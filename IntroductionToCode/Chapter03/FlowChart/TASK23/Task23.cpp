#include <stdio.h>

int main()
{
	int x = 0;
	bool laSoCP = false;

	printf("Nhap x: ");		scanf_s("%d", &x);

	for (int i = 1; i <= x / 2; i++)
	{
		if (x == i * i)
		{
			laSoCP = true;
			break;
		}
	}

	if (laSoCP) printf("%d la so chinh phuong.", x);
	else printf("%d khong la so chinh phuong.", x);

	return 0;
}