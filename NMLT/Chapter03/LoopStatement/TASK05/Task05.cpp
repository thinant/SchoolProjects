#include <stdio.h>

int main()
{
	int a = 11, b = 16, i = a;
	while (i < b)
	{
		if (i % 2 == 0)
		{
			printf("\t %d", i);
			break;
		}
		i++;
	}

	return 0;
}