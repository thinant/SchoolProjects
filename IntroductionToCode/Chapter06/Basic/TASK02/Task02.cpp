#include <stdio.h>
#include <string.h>

int main()
{
	char s1[30] = "Truong DHKHTN", s2[30] = "Tp. HCM", s3[30], s[30];
	strcpy_s(s, s1);
	strcpy_s(s3, "aeiou");
	strcat_s(s, s2);
	int n = strlen(s), k = 0;
	printf("Chuoi: %s", s);
	for (int i = 0; i < n; i++)
	{
		if (strchr(s3, s[i]))
			k++;
	}
	printf("\nKet qua: %d", k);
}