#include <stdio.h>
#include <string.h>

int main()
{
	char s[20] = "Truong DHKHTN TPHCM", * p, *next_p;
	p = strtok_s(s, " ", &next_p);
	while (p != NULL)
	{
		printf("%s\n", p);
		p = strtok_s(NULL, " ", &next_p);
	}
	return 0;
}