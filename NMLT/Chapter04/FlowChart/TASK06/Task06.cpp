#include <stdio.h>

unsigned long long int tinhGiaiThua(unsigned int);

int main()
{
	unsigned int n = 0;
	
	printf("Nhap so n: ");		scanf_s("%u", &n);

	unsigned long long int giaiThua = tinhGiaiThua(n);

	printf("%u! = %llu", n, giaiThua);

	return 0;
}

unsigned long long int tinhGiaiThua(unsigned int n)
{
	unsigned long long int giaiThua = 1;
	for (unsigned int i = 1; i <= n; i++) giaiThua *= i;

	return giaiThua;
}