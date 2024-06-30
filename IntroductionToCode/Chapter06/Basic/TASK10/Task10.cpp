#include <stdio.h>
#include <string.h>

#define TOI_DA 100

void inHoaXenKe(char chuoi[]);

int main()
{
	char chuoi[TOI_DA + 1];

	printf("Nhap chuoi: ");
	gets_s(chuoi, TOI_DA);

	inHoaXenKe(chuoi);


	printf("Chuoi sau khi dinh dang in hoa xen ke: %s", chuoi);

	return 0;
}

void inHoaXenKe(char chuoi[])
{
	unsigned int doDaiChuoi = strlen(chuoi);
	int buocNhay = 'A' - 'a';
	bool laChuHoa = true;

	for (unsigned int i = 0; i < doDaiChuoi; i++)
	{
		if (laChuHoa && chuoi[i] >= 'a' && chuoi[i] <= 'z')
			chuoi[i] += buocNhay;
		else if (!laChuHoa && chuoi[i] >= 'A' && chuoi[i] <= 'Z')
			chuoi[i] -= buocNhay;

		if ((chuoi[i] >= 'a' && chuoi[i] <= 'z') || (chuoi[i] >= 'A' && chuoi[i] <= 'Z'))
			laChuHoa = !laChuHoa;
	}
}
