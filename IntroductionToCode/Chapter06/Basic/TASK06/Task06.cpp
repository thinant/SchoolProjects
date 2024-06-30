#include <stdio.h>
#include <string.h>

#define TOI_DA 100

void noiChuoi(char s1[], char s2[]);

int main()
{
	char s1[TOI_DA + 1], s2[TOI_DA + 1];

	printf("Nhap chuoi s1: ");
	gets_s(s1, TOI_DA);
	printf("Nhap chuoi s2: ");
	gets_s(s2, TOI_DA);

	noiChuoi(s1, s2);

	printf("Chuoi s1 sau khi noi voi s2: %s", s1);

	return 0;
}

void noiChuoi(char s1[], char s2[])
{
	strcat_s(s1, TOI_DA + 1, s2);
}