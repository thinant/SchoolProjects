#include <stdio.h>
#include <string.h>

#define TOI_DA 100

void dinhDangHoa(char chuoi[]);

int main()
{
	char chuoi[TOI_DA + 1];
	
	printf("Nhap chuoi: ");
	gets_s(chuoi);

	dinhDangHoa(chuoi);

	printf("Chuoi sau khi dinh dang lai: %s", chuoi);

	return 0;
}

void dinhDangHoa(char chuoi[])
{
	unsigned int doDaiChuoi = strlen(chuoi);

	for (unsigned int i = 0; i < doDaiChuoi; i++)
		if (i == 0 || chuoi[i - 1] == ' ')
		{
			if (chuoi[i] >= 'a' && chuoi[i] <= 'z')
				chuoi[i] += ('A' - 'a');
		}
		else if (chuoi[i] >= 'A' && chuoi[i] <= 'Z')
				chuoi[i] += ('a' - 'A');
}