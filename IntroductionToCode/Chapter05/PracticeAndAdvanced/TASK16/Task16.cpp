#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);
int timSoXuatHienNhieuNhat(int mangNguyen[], unsigned int soPhanTu, unsigned int& tanSuat);
int kiemTraTonTai(int mangNguyen[], unsigned int soPhanTu, int x);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	int mangNguyen[TOI_DA], soXuatHienNhieuNhat = 0;
	unsigned int soPhanTu = 0, tanSuatXuatHien = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	printf("\nMang cua ban: ");
	xuatMangNguyen(mangNguyen, soPhanTu);

	soXuatHienNhieuNhat = timSoXuatHienNhieuNhat(mangNguyen, soPhanTu, tanSuatXuatHien);

	printf("\n%d la so xuat hien nhieu nhat voi tan suat xuat hien la %u lan.", soXuatHienNhieuNhat, tanSuatXuatHien);

	return 0;
}

int timSoXuatHienNhieuNhat(int mangNguyen[], unsigned int soPhanTu, unsigned int& tanSuat)
{
	int mangLuuDau[TOI_DA]{};
	unsigned int mangTanSuat[TOI_DA]{}, soPhanTuKhacNhau = 0, viTriTanSuatLonNhat = -1;

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		int viTri = kiemTraTonTai(mangLuuDau, soPhanTuKhacNhau, mangNguyen[i]);
		if (viTri != -1)
		{
			mangTanSuat[viTri]++;
			if (viTriTanSuatLonNhat == -1 || mangTanSuat[viTriTanSuatLonNhat] < mangTanSuat[viTri])
				viTriTanSuatLonNhat = viTri;
		}
		else
		{
			mangLuuDau[soPhanTuKhacNhau++] = mangNguyen[i];
			mangTanSuat[soPhanTuKhacNhau - 1]++;
		}
	}

	if (viTriTanSuatLonNhat == -1 || mangTanSuat[viTriTanSuatLonNhat] < mangTanSuat[soPhanTuKhacNhau - 1])
		viTriTanSuatLonNhat = soPhanTuKhacNhau - 1;

	tanSuat = mangTanSuat[viTriTanSuatLonNhat];
	return mangLuuDau[viTriTanSuatLonNhat];
}

int kiemTraTonTai(int mangNguyen[], unsigned int soPhanTu, int x)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (mangNguyen[i] == x) return i;

	return -1;
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