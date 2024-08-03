#include <stdio.h>
#include <string.h>

#define TOI_DA 100
typedef unsigned int MANG2D_NGUYEN_DUONG[TOI_DA][TOI_DA];

void nhapMaTranNguyenDuong(MANG2D_NGUYEN_DUONG maTran, unsigned int& soDong, unsigned int& soCot);
void xuatMaTranNguyenDuong(MANG2D_NGUYEN_DUONG maTran, unsigned int soDong, unsigned int soCot);

int main()
{
	MANG2D_NGUYEN_DUONG maTran{ 0 };
	unsigned int soDong = 0, soCot = 0;

	nhapMaTranNguyenDuong(maTran, soDong, soCot);

	printf("Ma tran:\n");
	xuatMaTranNguyenDuong(maTran, soDong, soCot);

	return 0;
}

void nhapMaTranNguyenDuong(MANG2D_NGUYEN_DUONG maTran, unsigned int& soDong, unsigned int& soCot)
{
	soDong = 9, soCot = 14;

	for (unsigned int i = 0; i < soDong; i++)
		for (unsigned int j = 0; j < soCot; j++)
		{
			maTran[i][j] = i * j;
		}
}

void xuatMaTranNguyenDuong(MANG2D_NGUYEN_DUONG maTran, unsigned int soDong, unsigned int soCot)
{
	for (unsigned int i = 0; i < soDong; i++)
	{
		for (unsigned int j = 0; j < soCot; j++)
			printf("\t%u", maTran[i][j]);

		printf("\n");
	}

}