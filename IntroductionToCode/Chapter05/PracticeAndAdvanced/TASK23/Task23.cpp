#include <stdio.h>

#define TOI_DA 100
#define CHU_SO_HEX 16

void nhapSoPhanTu(unsigned int& n);
void nhapMangHex(char mangHex[], unsigned int& soPhanTu);
void tachMangConHex(char mangHex[], unsigned int soPhanTu, unsigned int mangLuuDiemDau[], unsigned int mangLuuDiemCuoi[], unsigned int& soMangCon);
void xuatMangHex(char mangHex[], unsigned int soPhanTu);
void khoiTaoMang(unsigned int mang[], unsigned int soPhanTu, unsigned int giaTri);

int main()
{
	char mangHex[TOI_DA]{};
	unsigned int soPhanTu = 0, mangLuuDiemDau[TOI_DA]{}, mangLuuDiemCuoi[TOI_DA]{}, soMangCon = 0;
	nhapMangHex(mangHex, soPhanTu);

	printf("\nMang cua ban: ");
	xuatMangHex(mangHex, soPhanTu);

	tachMangConHex(mangHex, soPhanTu, mangLuuDiemDau, mangLuuDiemCuoi, soMangCon);

	printf("\nCac mang con tach ra tu mang hex:");
	for (unsigned int i = 0; i < soMangCon; i++)
	{
		printf("\n");
		xuatMangHex(mangHex + mangLuuDiemDau[i], mangLuuDiemCuoi[i] - mangLuuDiemDau[i] + 1);
	}

	return 0;
}

void tachMangConHex(char mangHex[], unsigned int soPhanTu, unsigned int mangLuuDiemDau[], unsigned int mangLuuDiemCuoi[], unsigned int& soMangCon)
{
	mangLuuDiemDau[0] = 0, mangLuuDiemCuoi[0] = 0, soMangCon = 0;

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		mangLuuDiemDau[soMangCon] = i;
		for (unsigned int j = i + 1; j < soPhanTu; j++)
			if (mangHex[j] == mangHex[i])
			{
				mangLuuDiemCuoi[soMangCon++] = j;
				break;
			}		
	}
			
}

void khoiTaoMang(unsigned int mang[], unsigned int soPhanTu, unsigned int giaTri)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		mang[i] = giaTri;
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

void nhapMangHex(char mangHex[], unsigned int& soPhanTu)
{
	nhapSoPhanTu(soPhanTu);

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		printf("Nhap phan tu thu %u: ", i);
		scanf_s("%c", &mangHex[i]);

		while ((mangHex[i] < '0' || mangHex[i] > '9') && (mangHex[i] < 'A' || mangHex[i] > 'F'))
		{
			if (mangHex[i] == '\n' || mangHex[i] == '\0' || mangHex[i] == ' ')
				scanf_s("%c", &mangHex[i]);
			else
			{
				printf("Phan tu khong nam trong bo ma Hex. Vui long nhap lai: ");
				scanf_s("%c", &mangHex[i]);
			}
		}
	}
}

void xuatMangHex(char mangHex[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		printf("%c ", mangHex[i]);
}