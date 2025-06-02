#include <stdio.h>
#include <string.h>

#define TOI_DA 8
typedef int MANG2D_THUC[TOI_DA][TOI_DA];


void xuatMaTranThuc(MANG2D_THUC maTran, unsigned int soDong, unsigned int soCot);
void baiToan8Hau(MANG2D_THUC maTran);
bool duongCheoChuaHau(MANG2D_THUC maTran, int viTri_i, int viTri_j);

int main()
{
	MANG2D_THUC maTran = { 0 };

	baiToan8Hau(maTran);

	printf("\nMa tran bai toan 8 hau la:\n");
	xuatMaTranThuc(maTran, TOI_DA, TOI_DA);

	return 0;
}


void xuatMaTranThuc(MANG2D_THUC maTran, unsigned int soDong, unsigned int soCot)
{
	for (unsigned int i = 0; i < soDong; i++)
	{
		for (unsigned int j = 0; j < soCot; j++)
			printf("\t%d", maTran[i][j]);

		printf("\n");
	}

}

void baiToan8Hau(MANG2D_THUC maTran) {
	unsigned int soHau = 0;

	int i = 0, j = 0;

	int viTriChuaHau[TOI_DA] = { -1, -1, -1, -1, -1, -1,-1, -1 };
	int cotChuaHau[TOI_DA] = { 0 };

	while (soHau < TOI_DA) {
		while (j >= TOI_DA) {
			i--;
			soHau--;

			if (i < 0) {
				return false;
			}

			j = viTriChuaHau[i] + 1;

			maTran[i][viTriChuaHau[i]] = 0;

			cotChuaHau[viTriChuaHau[i]] = 0;

			viTriChuaHau[i] = -1;

		}

		if (cotChuaHau[j] || duongCheoChuaHau(maTran, i, j))
			j++;
		else {
			maTran[i][j] = 1;
			viTriChuaHau[i] = j;
			cotChuaHau[j] = 1;
			soHau++;
			i++;
			j = 0;
		}
	}
}

bool duongCheoChuaHau(MANG2D_THUC maTran, int viTri_i, int viTri_j) {
	int i = viTri_i - 1;
	int j = viTri_j - 1;

	while (i >= 0 && j >= 0) {
		if (maTran[i][j] == 1)
			return true;

		i--;
		j--;
	}

	i = viTri_i - 1;
	j = viTri_j + 1;

	while (i >= 0 && j < TOI_DA) {
		if (maTran[i][j] == 1)
			return true;

		i--;
		j++;
	}

	return false;
}