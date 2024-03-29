#include <stdio.h>

#define TOIDA 100

void nhapSoNguyenDuong(unsigned int&);
void khoiTaoMang(int[], unsigned int&, int);
void xuatMang(int[], unsigned int);

int main()
{
	unsigned int soPhanTu = 0;
	int giaTriKhoiTao = 0, mangNguyen[TOIDA];

	printf("Khoi tao mang so nguyen...\n\n");
	khoiTaoMang(mangNguyen, soPhanTu, giaTriKhoiTao);

	printf("\nHoan thanh!\n");
	xuatMang(mangNguyen, soPhanTu);

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

void khoiTaoMang(int mangNguyen[], unsigned int& soPhanTu, int giaTriKhoiTao)
{
	nhapSoNguyenDuong(soPhanTu);

	for (unsigned int i = 0; i < soPhanTu; i++)
		mangNguyen[i] = giaTriKhoiTao;
}

void xuatMang(int mangNguyen[], unsigned int soPhanTu)
{
	printf("\nNoi dung mang: ");
	for (unsigned int i = 0; i < soPhanTu; i++)
		printf("%d\t", mangNguyen[i]);
}