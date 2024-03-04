#include <stdio.h>

int main()
{
	int n = 0;
	int f1 = 1, f2 = 1;

	printf("Nhap n: ");		scanf_s("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		if (i == 1) printf("%d ", f1);
		else if (i == 2) printf("%d ", f2);
		else
		{
			int fn = f1 + f2;
			printf("%d ", fn);
			f1 = f2;
			f2 = fn;
		}
	}

	return 0;
}