#include <stdio.h>

int main()
{
	printf("Cac so hoan thien nho hon 5000: ");
	for (int i = 3; i <= 5000; i++)
	{
		int sum = 0;

		for (int j = 1; j <= i / 2; j++)
		{
			if (i % j == 0) sum += j;
		}

		if (sum == i) printf("%d ", i);
	}

	return 0;
}