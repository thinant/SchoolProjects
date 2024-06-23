#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyenDuong(unsigned int mangNguyenDuong[], unsigned int& soPhanTu);
void tongHopMangGiamDan(unsigned int mangA[], unsigned int soPhanTuA, unsigned int mangB[], unsigned int soPhanTuB,
	unsigned int mangC[], unsigned int& soPhanTuC);
void tongHopMangTangDan(unsigned int mangA[], unsigned int soPhanTuA, unsigned int mangB[], unsigned int soPhanTuB,
	unsigned int mangD[], unsigned int& soPhanTuD);
void taoSoLonNhatVaBeNhat(unsigned int mangA[], unsigned int soPhanTuA, unsigned int mangB[], unsigned int soPhanTuB,
	unsigned int mangC[], unsigned int mangD[]);
void xuatMangNguyenDuong(unsigned int mangNguyenDuong[], unsigned int soPhanTu);

int main()
{
	unsigned int mangA[TOI_DA]{}, mangB[TOI_DA]{}, mangC[TOI_DA]{}, mangD[TOI_DA]{};
	unsigned int soPhanTuA = 0, soPhanTuB = 0;

	printf("Nhap mang A:\n");
	nhapMangNguyenDuong(mangA, soPhanTuA);
	printf("Nhap mang B:\n");
	nhapMangNguyenDuong(mangB, soPhanTuB);

	printf("Mang A: ");
	xuatMangNguyenDuong(mangA, soPhanTuA);
	printf("\nMang B: ");
	xuatMangNguyenDuong(mangB, soPhanTuB);

	taoSoLonNhatVaBeNhat(mangA, soPhanTuA, mangB, soPhanTuB, mangC, mangD);
	
	printf("\nMang C la so lon nhat tao thanh tu A va B: ");
	xuatMangNguyenDuong(mangC, soPhanTuA + soPhanTuB);	
	
	printf("\nMang D la so be nhat tao thanh tu A va B: ");
	xuatMangNguyenDuong(mangD, soPhanTuA + soPhanTuB);

	return 0;
}

void tongHopMangGiamDan(unsigned int mangA[], unsigned int soPhanTuA, unsigned int mangB[], unsigned int soPhanTuB,
	unsigned int mangC[], unsigned int& soPhanTuC)
{
	unsigned int i = 0, j = 0;
	soPhanTuC = 0;

	while (i < soPhanTuA && j < soPhanTuB)
		if (mangA[i] >= mangB[j])
			mangC[soPhanTuC++] = mangA[i++];
		else
			mangC[soPhanTuC++] = mangB[j++];

	while (i < soPhanTuA)
		mangC[soPhanTuC++] = mangA[i++];

	while (j < soPhanTuB)
		mangC[soPhanTuC++] = mangB[j++];
}

void tongHopMangTangDan(unsigned int mangA[], unsigned int soPhanTuA, unsigned int mangB[], unsigned int soPhanTuB,
	unsigned int mangD[], unsigned int& soPhanTuD)
{
	unsigned int i = 0, j = 0;
	soPhanTuD = 0;

	while (i < soPhanTuA && j < soPhanTuB)
		if (mangA[i] <= mangB[j])
			mangD[soPhanTuD++] = mangA[i++];
		else
			mangD[soPhanTuD++] = mangB[j++];

	while (i < soPhanTuA)
		mangD[soPhanTuD++] = mangA[i++];

	while (j < soPhanTuB)
		mangD[soPhanTuD++] = mangB[j++];
}

void taoSoLonNhatVaBeNhat(unsigned int mangA[], unsigned int soPhanTuA, unsigned int mangB[], unsigned int soPhanTuB,
	unsigned int mangC[], unsigned int mangD[])
{
	unsigned int soPhanTuTam = 0;
	tongHopMangGiamDan(mangA, soPhanTuA, mangB, soPhanTuB, mangC, soPhanTuTam);
	tongHopMangTangDan(mangA, soPhanTuA, mangB, soPhanTuB, mangD, soPhanTuTam);
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

void nhapMangNguyenDuong(unsigned int mangNguyenDuong[], unsigned int& soPhanTu)
{
	nhapSoPhanTu(soPhanTu);

	for (unsigned int i = 0; i < soPhanTu; i++)
		scanf_s("%u", &mangNguyenDuong[i]);
}

void xuatMangNguyenDuong(unsigned int mangNguyenDuong[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		printf("%u", mangNguyenDuong[i]);
}