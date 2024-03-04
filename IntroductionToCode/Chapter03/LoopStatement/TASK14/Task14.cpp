#include <stdio.h>

int main()
{
	int n = 0;
	int k = 2, count = 1;
	bool isPrime = true;
	
	printf("Nhap n: ");		scanf_s("%d", &n);

	printf("%d so nguyen to dau tien: ", n);

	while (count <= n)
	{
		for (int i = 2; i <= k / 2; i++)
			if (k % i == 0)
			{
				isPrime = false;
				break;
			}

		if (isPrime)
		{
			printf("%d ", k);
			count++;
		}

		k++;
		isPrime = true;
	}

	return 0;
}