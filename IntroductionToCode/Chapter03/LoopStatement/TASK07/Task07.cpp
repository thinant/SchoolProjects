#include <stdio.h>

int main()
{
	int i = 1, s = 0;
	while (1)
	{
		s = s + i++;
		if (i % 2)
			i = i + 2;
		else
			i = i + 1;
		if (i > 20) break;
	}
	printf("%d", s);

	return 0;
}