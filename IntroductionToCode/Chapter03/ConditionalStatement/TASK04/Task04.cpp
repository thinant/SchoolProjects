#include <stdio.h>

int main()
{
	int a = 0, b = 0;
	printf("Nhap a: ");	scanf_s("%d", &a);
	printf("Nhap b: ");	scanf_s("%d", &b);
	if (a > b) printf("Gia tri lon nhat: %d.", a);
	else	   printf("Gia tri lon nhat: %d.", b); 

	return 0;
}