#include <stdio.h>

int main()
{
	int a = 18, i = 1;
	do {
		if (a % i == 0)
			printf("\t %d", i);
			i++;
	} while (i <= a);

	return 0;
}