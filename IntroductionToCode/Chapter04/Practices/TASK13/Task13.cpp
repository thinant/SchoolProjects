#include <stdio.h>

void nhapSoNguyen(int&, char);
void hoanVi(int&, int&);

int main()
{
	int a = 0, b = 0;

	nhapSoNguyen(a, 'a');
	nhapSoNguyen(b, 'b');

	hoanVi(a, b);

	printf("So a sau khi hoan vi: %d\n", a);
	printf("So b sau khi hoan vi: %d", b);

	return 0;
}

void nhapSoNguyen(int& a, char c)
{
	printf("Nhap so %c: ", c);
	scanf_s("%d", &a);
}

void hoanVi(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}