#include <stdio.h>

#define TOIDA 100
#define GIOI_HAN 20

void nhapSoNguyenDuong(unsigned int&);
void nhapMang(int[], unsigned int&);
void xuatPhanTuChanTrongMangNhoHonGioiHan(int[], unsigned int);

int main()
{
	unsigned int soPhanTu = 0;
	int mangNguyen[TOIDA];

	nhapMang(mangNguyen, soPhanTu);

	xuatPhanTuChanTrongMangNhoHonGioiHan(mangNguyen, soPhanTu);

	return 0;
}

void nhapSoNguyenDuong(unsigned int& n)
{
	printf("Nhap so phan tu cua mang, toi da %u phan tu: ", TOIDA);
	scanf_s("%u", &n);

	while (n > TOIDA)
	{
		printf("So phan tu khong hop le. Vui long nhap lai, toi da %u phan tu: ", TOIDA);
		scanf_s("%u", &n);
	}
}

void nhapMang(int mangNguyen[], unsigned int& soPhanTu)
{
	nhapSoNguyenDuong(soPhanTu);

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		printf("Nhap phan tu thu %u: ", i);	scanf_s("%d", &mangNguyen[i]);
	}
}

void xuatPhanTuChanTrongMangNhoHonGioiHan(int mangNguyen[], unsigned int soPhanTu)
{
	printf("\nCac phan tu chan trong mang nho hon %d: ", GIOI_HAN);
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (mangNguyen[i] %2 ==  0 && mangNguyen[i] < GIOI_HAN)
			printf("%d ", mangNguyen[i]);
}