#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n, unsigned int gioiHanTrai, unsigned int gioiHanPhai);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu, unsigned int gioiHanTrai, unsigned int gioiHanPhai);
bool kiemTraPhanTuTonTai(int x, int mangNguyen[], unsigned int soPhanTu);
void hoanDoi(int& a, int& b);
void sapXepMangTangDan(int mangNguyen[], unsigned int soPhanTu);
void lietKeCacBo4CoTongBangNhau(int mangNguyen[], unsigned int soPhanTu);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	int mangNguyen[TOI_DA];
	unsigned int soPhanTu = 0;

	printf("Nhap mang :\n");
	nhapMangNguyen(mangNguyen, soPhanTu, 4, TOI_DA);

	printf("Cac bo 4 a + b = c + d trong mang la:\n");
	lietKeCacBo4CoTongBangNhau(mangNguyen, soPhanTu);

	return 0;
}

bool kiemTraPhanTuTonTai(int x, int mangNguyen[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		if (mangNguyen[i] == x)
			return true;

	return false;
}

void hoanDoi(int& a, int& b)
{
	int bienTrungGian = a;
	a = b;
	b = bienTrungGian;
}

void sapXepMangTangDan(int mangNguyen[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu - 1; i++)
		for (unsigned int j = i + 1; j < soPhanTu; j++)
			if (mangNguyen[i] > mangNguyen[j])
				hoanDoi(mangNguyen[i], mangNguyen[j]);
}

void lietKeCacBo4CoTongBangNhau(int mangNguyen[], unsigned int soPhanTu)
{
	sapXepMangTangDan(mangNguyen, soPhanTu);

	for (unsigned int i = 0; i < soPhanTu - 1; i++)
		for (unsigned j = soPhanTu - 1; j > i + 2; j--)
		{
			unsigned int mocTrai = i + 1, mocPhai = j - 1;
			int tong = mangNguyen[i] + mangNguyen[j];

			while (mocTrai < mocPhai)
			{
				int tongPhu = mangNguyen[mocTrai] + mangNguyen[mocPhai];

				if (tongPhu == tong)
				{
					printf("%d + %d = %d + %d\n", mangNguyen[i], mangNguyen[j],
						                        mangNguyen[mocTrai], mangNguyen[mocPhai]);
					mocTrai++;
					mocPhai--;
				}
				else if (tongPhu < tong)
					mocTrai++;
				else
					mocPhai--;
			}
		}
}


void nhapSoPhanTu(unsigned int& soPhanTu, unsigned int gioiHanTrai, unsigned int gioiHanPhai)
{
	printf("Nhap so phan tu: ");	scanf_s("%u", &soPhanTu);

	while (soPhanTu == gioiHanTrai || soPhanTu > gioiHanPhai)
	{
		printf("So phan tu khong hop le. Vui long nhap lai: ");
		scanf_s("%u", &soPhanTu);
	}
}

void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu, unsigned int gioiHanTrai, unsigned int gioiHanPhai)
{
	nhapSoPhanTu(soPhanTu, gioiHanTrai, gioiHanPhai);

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		printf("Nhap phan tu thu %u: ", i);
		scanf_s("%d", &mangNguyen[i]);

		while (kiemTraPhanTuTonTai(mangNguyen[i], mangNguyen, i))
		{
			printf("Phan tu da ton tai trong mang. Vui long nhap lai: ");
			scanf_s("%d", &mangNguyen[i]);
		}
	}
}

bool kiemTraDayCon(int mangNguyenA[], unsigned int soPhanTuA, int mangNguyenB[], unsigned int soPhanTuB)
{
	for (unsigned int i = 0; i < soPhanTuA; i++)
		if (!kiemTraPhanTuTonTai(mangNguyenA[i], mangNguyenB, soPhanTuB))
			return false;

	return true;
}

void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		printf("%d ", mangNguyen[i]);
}