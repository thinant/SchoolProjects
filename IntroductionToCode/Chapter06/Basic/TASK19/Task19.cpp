#include <stdio.h>
#include <string.h>

#define TOI_DA 100

void tachSoKhoiChuoi(char chuoi[], unsigned int mangSo[], unsigned int& soPhanTu);
unsigned int chuyenChuoiThanhSo(char chuoi[]);
bool kiemTraKiTuLaSo(char kiTu);
void xuatChuoiSoNguyen(unsigned int mangNguyen[], unsigned int soPhanTu);

int main()
{
	char chuoi[TOI_DA + 1] = "\0";
	unsigned int mangSo[TOI_DA];
	unsigned int soPhanTu = 0;

	printf("Nhap chuoi: ");
	gets_s(chuoi, TOI_DA);

	tachSoKhoiChuoi(chuoi, mangSo, soPhanTu);

	printf("Chuoi sau khi tach: %s\n", chuoi);
	printf("Cac so tach duoc tu chuoi: ");
	xuatChuoiSoNguyen(mangSo, soPhanTu);

	return 0;
}
void tachSoKhoiChuoi(char chuoi[], unsigned int mangSo[], unsigned int& soPhanTu)
{
	char so[TOI_DA + 1] = "\0";
	unsigned int doDai = strlen(chuoi);
	soPhanTu = 0;

	for (unsigned int i = 0, soChuSoBiLoai = 0; i + soChuSoBiLoai <= doDai; i++)
	{
		while (kiemTraKiTuLaSo(chuoi[i + soChuSoBiLoai]))
		{
			unsigned int doDaiSo = strlen(so);
			so[doDaiSo++] = chuoi[i + soChuSoBiLoai];
			so[doDaiSo] = '\0';
			soChuSoBiLoai++;
		}

		if (strlen(so) != 0)
		{
			mangSo[soPhanTu++] = chuyenChuoiThanhSo(so);
			so[0] = '\0';
		}

		chuoi[i] = chuoi[i + soChuSoBiLoai];
	}
}

unsigned int chuyenChuoiThanhSo(char chuoi[])
{
	unsigned int so = 0, doDai = strlen(chuoi);

	for (unsigned int i = 0; i < doDai; i++)
	{
		so *= 10;
		so = so + (chuoi[i] - '0');
	}

	return so;
}

bool kiemTraKiTuLaSo(char kiTu)
{
	return kiTu >= '0' && kiTu <= '9';
}

void xuatChuoiSoNguyen(unsigned int mangNguyen[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		printf("%u ", mangNguyen[i]);
}
