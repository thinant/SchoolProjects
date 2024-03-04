#include <stdio.h>
#include <conio.h>

int main()
{
	int a = 9, b = 6;
	a++;
	a = a + b--;
	a = a + (--b);
	if (a % 2 == 0) printf("Gia tri cua a la chan");
	printf("Tong cua a va b la: %d", a + b);
	
	return 0;
}