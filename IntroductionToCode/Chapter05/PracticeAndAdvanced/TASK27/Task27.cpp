#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SO_PHAN_TU 10000
#define GIOI_HAN 32000

void phatSinhMang(unsigned int mang[], unsigned int mangTanSo[], unsigned int soPhanTu, unsigned int soPhanTuKhacNhau);
void xuatTanSo(unsigned int mangTanSo[], unsigned int soPhanTu);

int main()
{
	unsigned int mang[SO_PHAN_TU]{}, mangTanSo[GIOI_HAN + 1]{};
	
	phatSinhMang(mang, mangTanSo, SO_PHAN_TU, GIOI_HAN);

	xuatTanSo(mangTanSo, GIOI_HAN + 1);

	return 0;
}

void phatSinhMang(unsigned int mang[], unsigned int mangTanSo[], unsigned int soPhanTu, unsigned int soPhanTuKhacNhau)
{
	time_t seed;
	srand((unsigned int)time(&seed));

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		mang[i] = rand() % (soPhanTuKhacNhau + 1);
		mangTanSo[mang[i]]++;
	}
}

void xuatTanSo(unsigned int mangTanSo[], unsigned int soPhanTu)
{
	unsigned int soXuatHienNhieuNhat = 0;

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		if (mangTanSo[i] == 0)
			continue;

		printf("\n%d xuat hien %d lan", i, mangTanSo[i]);
		
		if (mangTanSo[i] > mangTanSo[soXuatHienNhieuNhat])
			soXuatHienNhieuNhat = i;
	}

	printf("\n%d la so xuat hien nhieu nhat.", soXuatHienNhieuNhat);
}