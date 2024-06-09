#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);
int timDayConTangDanTongLonNhat(int mangNguyen[], unsigned int soPhanTu, unsigned int& viTriBatDau, unsigned int& viTriKetThuc);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	int mangNguyen[TOI_DA], tongLonNhat = 0;
	unsigned int soPhanTu = 0, viTriBatDau = 0, viTriKetThuc = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	printf("\nMang cua ban: ");
	xuatMangNguyen(mangNguyen, soPhanTu);

	tongLonNhat = timDayConTangDanTongLonNhat(mangNguyen, soPhanTu, viTriBatDau, viTriKetThuc);

	printf("\nDay con tang dan co tong lon nhat la %d la day sau:\n", tongLonNhat);
	xuatMangNguyen(mangNguyen + viTriBatDau, viTriKetThuc - viTriBatDau);

	return 0;
}

int timDayConTangDanTongLonNhat(int mangNguyen[], unsigned int soPhanTu, unsigned int& viTriBatDau, unsigned int& viTriTongKetThuc)
{
	unsigned int mangViTriDayConTangDan[TOI_DA]{}, soDayCon = 0;
	unsigned int tong = 0, viTriTongLonNhat = -1;
	int tongLonNhat = 0;

	for (unsigned int i = 0; i < soPhanTu; i++)
		if (i != 0 && mangNguyen[i] >= mangNguyen[i - 1])
			tong += mangNguyen[i];
		else
		{
			if (i != 0 && (viTriTongLonNhat == -1 || tongLonNhat < tong))
			{
				viTriTongLonNhat = soDayCon - 1;
				tongLonNhat = tong;
			}

			tong = mangNguyen[i];
			mangViTriDayConTangDan[soDayCon++] = i;
		}

	if (viTriTongLonNhat == -1 || tongLonNhat < tong)
		viTriTongLonNhat = mangViTriDayConTangDan[soDayCon-1];

	viTriBatDau = mangViTriDayConTangDan[viTriTongLonNhat];

	if (viTriTongLonNhat != soDayCon - 1)
		viTriTongKetThuc = mangViTriDayConTangDan[viTriTongLonNhat + 1];
	else viTriTongKetThuc = soPhanTu;

	return tongLonNhat;
}

void nhapSoPhanTu(unsigned int& soPhanTu)
{
	printf("Nhap so phan tu: ");	scanf_s("%u", &soPhanTu);

	while (soPhanTu <= 0 || soPhanTu > TOI_DA)
	{
		printf("So phan tu khong hop le. Vui long nhap lai: ");
		scanf_s("%u", &soPhanTu);
	}
}

void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu)
{
	nhapSoPhanTu(soPhanTu);

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		printf("Nhap phan tu thu %u: ", i);
		scanf_s("%d", &mangNguyen[i]);
	}
}

void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		printf("%d ", mangNguyen[i]);
}