#include <stdio.h>

#define TOI_DA 100

void nhapSoNguyenDuong(unsigned int& n, unsigned int gioiHan);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);
int timPhanTuLonThuK(int mangNguyen[], unsigned int soPhanTu, unsigned int k);
unsigned int timViTriNhoNhat(int mangNguyen[], unsigned int soPhanTu);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	int mangNguyen[TOI_DA];
	unsigned int soPhanTu = 0, k = 0, phanTuLonThuK = 0;

	nhapMangNguyen(mangNguyen, soPhanTu);
	nhapSoNguyenDuong(k, soPhanTu);

	phanTuLonThuK = timPhanTuLonThuK(mangNguyen, soPhanTu, k);

	printf("Phan tu lon thu %u la %d.", k, phanTuLonThuK);

	return 0;
}

void nhapSoNguyenDuong(unsigned int& soPhanTu, unsigned int gioiHan)
{
	printf("Nhap so: ");	scanf_s("%u", &soPhanTu);

	while (soPhanTu <= 0 || soPhanTu > gioiHan)
	{
		printf("So phan tu khong hop le. Vui long nhap lai: ");
		scanf_s("%u", &soPhanTu);
	}
}

void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu)
{
	nhapSoNguyenDuong(soPhanTu, TOI_DA);

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		printf("Nhap phan tu thu %u: ", i);
		scanf_s("%d", &mangNguyen[i]);
	}
}

int timPhanTuLonThuK(int mangNguyen[], unsigned int soPhanTu, unsigned int k)
{
	unsigned int viTriPhanTuLonThuK = 0, kichCo = 0;
	int kPhanTuLonNhat[TOI_DA]{};

	for (unsigned int i = 0; i < soPhanTu; i++)
		if (kichCo < k)
			kPhanTuLonNhat[kichCo++] = mangNguyen[i];
		else
		{
			viTriPhanTuLonThuK = timViTriNhoNhat(kPhanTuLonNhat, kichCo);
			if (mangNguyen[i] > kPhanTuLonNhat[viTriPhanTuLonThuK])
				kPhanTuLonNhat[viTriPhanTuLonThuK] = mangNguyen[i];
		}

	viTriPhanTuLonThuK = timViTriNhoNhat(kPhanTuLonNhat, kichCo);
	return kPhanTuLonNhat[viTriPhanTuLonThuK];
}

unsigned int timViTriNhoNhat(int mangNguyen[], unsigned int soPhanTu)
{
	unsigned int viTriNhoNhat = 0;

	for (unsigned int i = 1; i < soPhanTu; i++)
		if (mangNguyen[i] < mangNguyen[viTriNhoNhat])
			viTriNhoNhat = i;

	return viTriNhoNhat;
}


void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		printf("%d ", mangNguyen[i]);
}