#include <stdio.h>

#define TOIDA 100

void nhapSoNguyenDuong(unsigned int&);
void nhapMang(int[], unsigned int&);
void xuatPhanTuLeTrongMang(int[], unsigned int);

int main()
{
	unsigned int soPhanTu = 0;
	int mangNguyen[TOIDA];

	nhapMang(mangNguyen, soPhanTu);

	xuatPhanTuLeTrongMang(mangNguyen, soPhanTu);

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

void xuatPhanTuLeTrongMang(int mangNguyen[], unsigned int soPhanTu)
{
	printf("\nCac phan tu le trong mang: ");
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (mangNguyen[i] % 2 != 0)
			printf("%d ", mangNguyen[i]);
}