#include <stdio.h>
#include <ctime>
#include<conio.h>


void layNgayHienTai(unsigned int&, unsigned int&, unsigned int&);
void tangMotNgay(unsigned int&, unsigned int&, unsigned int&);
void giamMotNgay(unsigned int&, unsigned int&, unsigned int&);
void dieuChinhNgay(unsigned int&, unsigned int&, unsigned int&);
unsigned int layNgayCuoiThang(unsigned int, unsigned int);

int main()
{
	unsigned int ngay = 0, thang = 0, nam = 0;
	layNgayHienTai(ngay, thang, nam);

	printf("Ngay thang nam hom nay: %u/%u/%u.\n", ngay, thang, nam);
	

	dieuChinhNgay(ngay, thang, nam);

	return 0;
}

void layNgayHienTai(unsigned int& ngay, unsigned int& thang, unsigned int& nam)
{
	struct tm ngayThangNam;
	time_t thoiGian = time(0);
	localtime_s(&ngayThangNam, &thoiGian);

	ngay = ngayThangNam.tm_mday;
	thang = 1 + ngayThangNam.tm_mon;
	nam = 1900 + ngayThangNam.tm_year;
}

void tangMotNgay(unsigned int& ngay, unsigned int& thang, unsigned int& nam)
{
	unsigned int ngayCuoiThang = layNgayCuoiThang(thang, nam);

	if (ngay == ngayCuoiThang)
	{
		ngay = 1;
		if (thang == 12)
		{
			thang = 1;
			nam++;
		}
		else thang++;
	}
	else ngay++;
}

void giamMotNgay(unsigned int& ngay, unsigned int& thang, unsigned int& nam)
{
	

	if (ngay == 1)
	{
		ngay = layNgayCuoiThang(thang, nam);
		if (thang == 1)
		{
			thang = 12;
			nam--;
		}
		else thang--;
	}
	else ngay--;
}

void dieuChinhNgay(unsigned int& ngay, unsigned int& thang, unsigned int& nam)
{
	char asciiPhimNhan = 0;
	
	printf("Nhan mui ten len hoac xuong de tang hoac giam 1 ngay. Nhan phim khac bat ky de thoat: ");
	asciiPhimNhan = _getch();

	while (asciiPhimNhan == -32)
		asciiPhimNhan = _getch();
		
	
	if (asciiPhimNhan == 72)
	{
		printf("Up\n");
		tangMotNgay(ngay, thang, nam);
		printf("Ngay thang nam ngay mai: %u/%u/%u\n", ngay, thang, nam);
	}
	else if (asciiPhimNhan == 80)
	{
		printf("Down\n");
		giamMotNgay(ngay, thang, nam);
		printf("Ngay thang nam ngay mai: %u/%u/%u\n", ngay, thang, nam);
	}

	else printf("Thoat chuong trinh.\n");
}
unsigned int layNgayCuoiThang(unsigned int thang, unsigned int nam)
{
	unsigned int ngayCuoiThang = 30;
	if ((thang < 8 && thang % 2 == 1) || (thang >= 8 && thang % 2 == 0)) ngayCuoiThang = 31;
	else if (thang == 2)
		if (nam % 400 == 0 || (nam % 100 != 0 && nam % 4 == 0)) ngayCuoiThang = 29;
		else ngayCuoiThang = 28;

	return ngayCuoiThang;
}