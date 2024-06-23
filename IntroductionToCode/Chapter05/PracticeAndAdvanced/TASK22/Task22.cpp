#include <stdio.h>

#define TOI_DA 100

void nhapSoPhanTu(unsigned int& n);
void nhapMangThuc(float mangThuc[], unsigned int& soPhanTu);
void tongHopMangTangDan(float mangA[], unsigned int soPhanTuA, float mangB[], unsigned int soPhanTuB,
						float mangC[], unsigned int& soPhanTuC);
void themPhanTuVaoViTriTangDan(int mangThuc[], unsigned int& soPhanTu, int x);
void sapXepMang(float mangThuc[], unsigned int soPhanTu);
void hoanVi(float& a, float& b);
void xuatMangThuc(float mangThuc[], unsigned int soPhanTu);

int main()
{
	float mangA[TOI_DA], mangB[TOI_DA], mangC[TOI_DA];
	unsigned int soPhanTuA = 0, soPhanTuB = 0, soPhanTuC = 0;

	printf("Nhap mang A:\n");
	nhapMangThuc(mangA, soPhanTuA);
	printf("Nhap mang B:\n");
	nhapMangThuc(mangB, soPhanTuB);

	tongHopMangTangDan(mangA, soPhanTuA, mangB, soPhanTuB, mangC, soPhanTuC);

	printf("Mang A: ");
	xuatMangThuc(mangA, soPhanTuA);
	printf("Mang B: ");
	xuatMangThuc(mangB, soPhanTuB);
	printf("Mang c tong hop tu 2 mang tren la: ");
	xuatMangThuc(mangC, soPhanTuC);

	return 0;
}

void tongHopMangTangDan(float mangA[], unsigned int soPhanTuA, float mangB[], unsigned int soPhanTuB,
	float mangC[], unsigned int& soPhanTuC)
{
	sapXepMang(mangA, soPhanTuA);
	sapXepMang(mangB, soPhanTuB);

	unsigned int i = 0, j = 0;

	while (i < soPhanTuA && j < soPhanTuB)
		if (mangA[i] <= mangB[j])
			mangC[soPhanTuC++] = mangA[i++];
		else
			mangC[soPhanTuC++] = mangB[j++];

	while (i < soPhanTuA)
		mangC[soPhanTuC++] = mangA[i++];
	
	while (j < soPhanTuB)
		mangC[soPhanTuC++] = mangB[j++];
}

void themPhanTuVaoViTriTangDan(float mangThuc[], unsigned int& soPhanTu, int x)
{
	soPhanTu++;

	for (int i = soPhanTu - 1; i >= 0; i--)
	{
		if (i == 0 || mangThuc[i - 1] <= x)
		{
			mangThuc[i] = x;
			break;
		}

		mangThuc[i] = mangThuc[i - 1];
	}
}

void sapXepMang(float mangThuc[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu - 1; i++)
		for (unsigned j = i + 1; j < soPhanTu; j++)
			if (mangThuc[i] > mangThuc[j])
				hoanVi(mangThuc[i], mangThuc[j]);
}

void hoanVi(float& a, float& b)
{
	float tmp = a;
	a = b;
	b = tmp;
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

void nhapMangThuc(float mangThuc[], unsigned int& soPhanTu)
{
	nhapSoPhanTu(soPhanTu);

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		printf("Nhap phan tu thu %u: ", i);
		scanf_s("%f", &mangThuc[i]);
	}
}

void xuatMangThuc(float mangThuc[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		printf("%.3f ", mangThuc[i]);
}