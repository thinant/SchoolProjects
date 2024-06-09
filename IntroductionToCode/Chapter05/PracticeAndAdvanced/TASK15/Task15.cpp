#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);
int timSoChanNhonhatLonHonMoiSoLe(int mangNguyen[], unsigned int soPhanTu);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	int mangNguyen[TOI_DA], soChanNhoNhatNhoHonMoiSoLe = 0;
	unsigned int soPhanTu = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	printf("\nMang cua ban: ");
	xuatMangNguyen(mangNguyen, soPhanTu);

	soChanNhoNhatNhoHonMoiSoLe = timSoChanNhonhatLonHonMoiSoLe(mangNguyen, soPhanTu);

	if (soChanNhoNhatNhoHonMoiSoLe == -1)
		printf("\nKhong co so chan nao nho hon moi so le trong mang.");
	else
		printf("\n%d la so chan nho nhat nho hon moi so le trong mang.", soChanNhoNhatNhoHonMoiSoLe);

	return 0;
}

int timSoChanNhonhatLonHonMoiSoLe(int mangNguyen[], unsigned int soPhanTu)
{
	bool coSoChan = 0;
	int soChanNhoNhat = -1, soLeNhoNhat = 0;

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		if ((mangNguyen[i] % 2 == 0) && (soChanNhoNhat == -1 || soChanNhoNhat > mangNguyen[i]))
			soChanNhoNhat = mangNguyen[i];
		else if ((mangNguyen[i] % 2 != 0) && (soLeNhoNhat == 0 || soLeNhoNhat > mangNguyen[i]))
			soLeNhoNhat = mangNguyen[i];
	}

	if (soChanNhoNhat  > soLeNhoNhat || soChanNhoNhat == -1) return -1;

	if (soChanNhoNhat < soLeNhoNhat || soLeNhoNhat == 0) return soChanNhoNhat;
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