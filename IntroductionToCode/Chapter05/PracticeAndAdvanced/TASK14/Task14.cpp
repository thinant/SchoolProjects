#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);
void themPhanTuVaoViTriTangDan(int mangNguyen[], unsigned int& soPhanTu, int x);
int timSoLeNhonhatLonHonMoiSoChan(int mangNguyen[], unsigned int soPhanTu);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	int mangNguyen[TOI_DA], soLeNhoNhatLonHonMoiSoChan = 0;
	unsigned int soPhanTu = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);

	printf("\nMang cua ban: ");
	xuatMangNguyen(mangNguyen, soPhanTu);

	soLeNhoNhatLonHonMoiSoChan = timSoLeNhonhatLonHonMoiSoChan(mangNguyen, soPhanTu);

	if (soLeNhoNhatLonHonMoiSoChan == 0)
		printf("\nKhong co so le nao lon hon moi so chan trong mang.");
	else
		printf("\n%d la so le nho nhat lon hon moi so chan trong mang.", soLeNhoNhatLonHonMoiSoChan);

	return 0;
}

void themPhanTuVaoViTriTangDan(int mangNguyen[], unsigned int& soPhanTu, int x)
{
	soPhanTu++;

	for (int i = soPhanTu - 1; i >= 0; i--)
	{
		if (mangNguyen[i - 1] <= x)
		{
			mangNguyen[i] = x;
			break;
		}

		mangNguyen[i] = mangNguyen[i - 1];
	}
}

int timSoLeNhonhatLonHonMoiSoChan(int mangNguyen[], unsigned int soPhanTu)
{
	bool coSoChan = 0;
	unsigned int soSoLe = 0, chiSoLe = 0;
	int soChanLonNhat = 0, soLeTangDan[TOI_DA]{};

	for (unsigned int i = 0; i < soPhanTu; i++)
		if ((mangNguyen[i] % 2 == 0) && (!coSoChan || soChanLonNhat < mangNguyen[i]))
		{
			soChanLonNhat = mangNguyen[i];
			while (soSoLe != 0 && soLeTangDan[chiSoLe] < soChanLonNhat)
			{
				chiSoLe++;
				soSoLe--;
			}
		}
		else if (soSoLe == 0 || soLeTangDan[chiSoLe] < mangNguyen[i])
			themPhanTuVaoViTriTangDan(soLeTangDan + chiSoLe, soSoLe, mangNguyen[i]);

	if (soSoLe == 0) return 0;

	return soLeTangDan[chiSoLe];
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