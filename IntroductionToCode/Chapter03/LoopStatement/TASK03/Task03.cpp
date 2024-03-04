#include <stdio.h>

int main()
{
	int i = 10, s = 0;
	while (i > 0)
	{
		if (i % 2 == 0)
			s += i;
		else
			if (i > 5)
				s += 2 * i;
		i--;
	}
	printf("s = %d", s);

	return 0;
}