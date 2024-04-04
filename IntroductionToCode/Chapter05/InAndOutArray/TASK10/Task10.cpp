#include <stdio.h>

#define TOIDA 100

void nhapSoNguyenDuong(unsigned int&);
void nhapMang(int[], unsigned int&);
void xuatSoChinhPhuongOViTriLeTrongMang(int[], unsigned int);
bool kiemTraSoChinhPhuong(int);

int main()
{
	unsigned int soPhanTu = 0;
	int mangNguyen[TOIDA];

	nhapMang(mangNguyen, soPhanTu);

	xuatSoChinhPhuongOViTriLeTrongMang(mangNguyen, soPhanTu);

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

void xuatSoChinhPhuongOViTriLeTrongMang(int mangNguyen[], unsigned int soPhanTu)
{
	printf("\nCac so chinh phuong o vi tri le trong mang: ");
	for (unsigned int i = 1; i < soPhanTu; i += 2)
		if (kiemTraSoChinhPhuong(mangNguyen[i]))
			printf("%d ", mangNguyen[i]);
}

bool kiemTraSoChinhPhuong(int n)
{
	bool laSoChinhPhuong = false;

	for (unsigned int i = 0; i <= n / 2; i++)
		if (i*i == n)
		{
			laSoChinhPhuong = true;
			break;
		}

	return laSoChinhPhuong;
}