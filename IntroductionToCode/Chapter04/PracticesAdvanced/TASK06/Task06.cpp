#include <stdio.h>
#include <ctime>
#include<conio.h>


void layGioHienTai(unsigned int&, unsigned int&, unsigned int&);
void tangMotGiay(unsigned int&, unsigned int&, unsigned int&);
void giamMotGiay(unsigned int&, unsigned int&, unsigned int&);
void dieuChinhGio(unsigned int&, unsigned int&, unsigned int&);

int main()
{
	unsigned int gio = 0, phut = 0, giay = 0;
	layGioHienTai(gio, phut, giay);

	printf("Gio phut giay hien tai: %u:%u:%u.\n", gio, phut, giay);


	dieuChinhGio(gio, phut, giay);

	return 0;
}

void layGioHienTai(unsigned int& gio, unsigned int& phut, unsigned int& giay)
{
	struct tm gioPhutGiay;
	time_t thoiGian = time(0);
	localtime_s(&gioPhutGiay, &thoiGian);

	gio = gioPhutGiay.tm_hour;
	phut = gioPhutGiay.tm_min;
	giay = gioPhutGiay.tm_sec;
}

void tangMotGiay(unsigned int& gio, unsigned int& phut, unsigned int& giay)
{
	if (giay == 59)
	{
		giay = 0;
		if (phut == 59)
		{
			phut = 0;
			if (gio == 23) gio = 0;
			else gio++;
		}
		else phut++;
	}
	else giay++;
}

void giamMotGiay(unsigned int& gio, unsigned int& phut, unsigned int& giay)
{
	if (giay == 0)
	{
		giay = 59;
		if (phut == 0)
		{
			phut = 59;
			if (gio == 0) gio = 23;
			else gio--;
		}
		else phut--;
	}
	else giay--;
}

void dieuChinhGio(unsigned int& gio, unsigned int& phut, unsigned int& giay)
{
	char asciiPhimNhan = 0;

	printf("Nhan mui ten len hoac xuong de tang hoac giam 1 ngay. Nhan phim khac bat ky de thoat: ");
	asciiPhimNhan = _getch();

	while (asciiPhimNhan == -32)
		asciiPhimNhan = _getch();


	if (asciiPhimNhan == 72)
	{
		printf("Up\n");
		tangMotGiay(gio, phut, giay);
		printf("Ngay thang nam ngay mai: %u:%u:%u\n", gio, phut, giay);
	}
	else if (asciiPhimNhan == 80)
	{
		printf("Down\n");
		giamMotGiay(gio, phut, giay);
		printf("Ngay thang nam ngay mai: %u:%u:%u\n", gio, phut, giay);
	}

	else printf("Thoat chuong trinh.\n");
}