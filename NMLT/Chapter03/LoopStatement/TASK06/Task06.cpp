#include <stdio.h>

int main()
{
	int a = 10, s = 0, i = 0;
	while (i < a)
	{
		i++;
		if (i % 2 == 0)
			continue;
		else
			s = s + i;
	}
	printf("s=%d", s);

	return 0;
}