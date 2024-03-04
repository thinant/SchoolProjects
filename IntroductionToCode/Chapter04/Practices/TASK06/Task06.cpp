#include <stdio.h>

bool laSoHopLe(unsigned int n, unsigned int l, unsigned int r);
unsigned int demSoChuSo(unsigned int n);
void inChuSo(unsigned int n, unsigned int hang, bool& khongCoHangChuc);
void inHang(unsigned int n, unsigned int hang);
void inSo(unsigned int n);

int main()
{
	unsigned int n = 0, gioiHanTrai = 0, gioiHanPhai = 999;
	printf("Nhap n: ");		scanf_s("%u", &n);

	while (!laSoHopLe(n, gioiHanTrai, gioiHanPhai))
	{
		printf("So khong hop le. Vui long nhap lai: ");		scanf_s("%u", &n);
	}

	printf("Cach doc %u: ", n);		inSo(n);

	return 0;
}

bool laSoHopLe(unsigned int n, unsigned int l, unsigned int r)
{
	bool soHopLe = true;
	if (n < l || n > r) soHopLe = false;

	return soHopLe;
}

unsigned int demSoChuSo(unsigned int n)
{
	unsigned int soChuSo = 0;
	while (n != 0)
	{
		soChuSo++;
		n /= 10;
	}

	return soChuSo;
}

void inChuSo(unsigned int n, unsigned int hang, bool& coHangChuc)
{
	switch (n)
	{
	case 0:
		if (hang == 2)
		{
			printf("le ");
			coHangChuc = false;
		}
		else printf("khong ");
		break;
	case 1:
		if (hang != 2) printf("mot ");
		break;
	case 2:
		printf("hai ");
		break;
	case 3:
		printf("ba ");
		break;
	case 4:
		printf("bon ");
		break;
	case 5:
		if (hang == 1 && coHangChuc) printf("lam ");
		else printf("nam ");
		break;
	case 6:
		printf("sau ");
		break;
	case 7:
		printf("bay ");
		break;
	case 8:
		printf("tam ");
		break;
	case 9:
		printf("chin ");
		break;
	}
}

void inHang(unsigned int n, unsigned int hang)
{
	switch (hang)
	{
	case 2: 
		if (n != 0) printf("muoi ");
		break;
	case 3:
		printf("tram ");
		break;
	}
}

void inSo(unsigned int n)
{
	unsigned int soChuSo = 0, hang = 0;
	bool coHangChuc = true;
	hang = soChuSo = demSoChuSo(n);
	
	if (soChuSo == 1) coHangChuc = false;

	if (n == 0) inChuSo(n, hang, coHangChuc);

	while (n != 0)
	{
		unsigned int h = 1;
		for (int i = 1; i < hang; i++)
		{
			h *= 10;
		}
		int chuSo = n / h;

		inChuSo(chuSo, hang, coHangChuc);
		inHang(chuSo, hang);

		n %= h;
		hang--;
	}
}