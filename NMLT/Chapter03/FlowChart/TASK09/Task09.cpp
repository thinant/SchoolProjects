#include <stdio.h>

int main()
{
	int n = 0;
	int s = 0, sign = -1;

	printf("Nhap n: ");		scanf_s("%d", &n);
	
	for (int i = 1; i <= n; i++)
	{
		sign *= -1;
		s += (sign * i);
	}

	printf("S(%d) = %d", n, s);

	return 0;
}