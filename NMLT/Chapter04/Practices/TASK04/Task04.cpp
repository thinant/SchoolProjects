#include <stdio.h>

void inSoChinhPhuong(unsigned int);
bool laSoChinhPhuong(unsigned int);

int main()
{
	unsigned int n = 0;

	printf("Nhap so n: ");		scanf_s("%u", &n);

	printf("%u so chinh phuong dau tien: ", n);		inSoChinhPhuong(n);

	return 0;
}

void inSoChinhPhuong(unsigned int n)
{
	unsigned int soSoCP = 0, i = 0;

	while (soSoCP < n)
	{
		if (laSoChinhPhuong(i))
		{
			printf("%u ", i);
			soSoCP++;
		}

		i++;
	}
}

bool laSoChinhPhuong(unsigned int n)
{
	bool laSoCP = false;
	
	for(unsigned int i = 0; i <= n; i++)
		if (n == i * i)
		{
			laSoCP = true;
			break;
		}

	return laSoCP;
}