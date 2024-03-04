#include <stdio.h>

int main()
{
	int a = 0, b = 0, c = 0;
	int type = 0;

	printf("Nhap a: ");		scanf_s("%d", &a);
	printf("Nhap b: ");		scanf_s("%d", &b);
	printf("Nhap c: ");		scanf_s("%d", &c);

	if (a + b > c && a + c > b && b + c > a)
	{
		if (a == b)
		{
			if (b == c) type = 1;
			else type = 2;
		}
		else if (a == c || b == c) type = 2;
		else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) type = 3;
		else type = 4;
	}

	switch (type)
	{
	case 1:
		printf("Ba diem tao thanh tam giac deu.");
		break;
	case 2:
		printf("Ba diem tao thanh tam giac can.");
		break;
	case 3:
		printf("Ba diem tao thanh tam giac vuong.");
		break;
	case 4: 
		printf("Ba diem tao thanh tam giac thuong.");
		break;
	default:
		printf("Ba diem khong tao thanh tam giac.");
	}

	return 0;
}
