#include <stdio.h>
#include <string.h>

#define TOI_DA 8
int HUONGDI_DOC[TOI_DA] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int HUONGDI_NGANG[TOI_DA] = { -1, 1, 2, 2, 1, -1, -2, -2 };

typedef int MANG2D[TOI_DA][TOI_DA];

void xuatDuongDi(int lichSuDong[], int lichSuCot[]);
void baiToanMaDiTuan(MANG2D maTran, int lichSuDong[], int lichSuCot[]);
int cachDiTiepTheo(MANG2D maTran, int i, int j);
int tinhSoDuongDi(MANG2D maTran, int i, int j);
int main()
{
	MANG2D maTran = { 0 };
	int lichSuDong[TOI_DA * TOI_DA] = { 0 };
	int lichSuCot[TOI_DA * TOI_DA] = { 0 };

	baiToanMaDiTuan(maTran, lichSuDong, lichSuCot);

	printf("Cach giai bai toan ma di tuan:\n");
	xuatDuongDi(lichSuDong, lichSuCot);

	return 0;
}


void xuatDuongDi(int lichSuDong[], int lichSuCot[]) {
	for (unsigned int i = 0; i < TOI_DA * TOI_DA; i++) {
		printf("(%d, %d)\t", lichSuDong[i], lichSuCot[i]);

		if (i % 8 == 7)
			printf("\n");
	}
}

void baiToanMaDiTuan(MANG2D maTran, int lichSuDong[], int lichSuCot[]) {
	unsigned int soODaDi = 0;

	int i = 0, j = 0;

	while (soODaDi < TOI_DA*TOI_DA) {
		lichSuDong[soODaDi] = i;
		lichSuCot[soODaDi] = j;

		maTran[i][j] = 1;
		soODaDi++;

		int cachDi = cachDiTiepTheo(maTran, i, j);

		i += HUONGDI_DOC[cachDi];
		j += HUONGDI_NGANG[cachDi];
	}
}

int cachDiTiepTheo(MANG2D maTran, int i, int j) {
	int huongDi_i = 0;
	int huongDi_j = 0;
	int soDuongDiNhoNhat = 0;
	int viTriNhoNhat = -1;

	for (int viTri = 0; viTri < TOI_DA; viTri++) {
		huongDi_i = i + HUONGDI_DOC[viTri];
		huongDi_j = j + HUONGDI_NGANG[viTri];

		if (huongDi_i < 0 || huongDi_i >= TOI_DA || huongDi_j < 0 || huongDi_j >= TOI_DA || maTran[huongDi_i][huongDi_j] != 0)
			continue;

		int soDuongDi = tinhSoDuongDi(maTran, huongDi_i, huongDi_j);

		if (viTriNhoNhat == -1 || soDuongDiNhoNhat == 0 || soDuongDi < soDuongDiNhoNhat) {
			viTriNhoNhat = viTri;
			soDuongDiNhoNhat = soDuongDi;

		}
	}

	return viTriNhoNhat;
}

int tinhSoDuongDi(MANG2D maTran, int i, int j) {
	int soDuongDi = 0;

	for (unsigned int viTri = 0; viTri < TOI_DA; viTri++)
		if (i + HUONGDI_DOC[viTri] >= 0 && i + HUONGDI_DOC[viTri] < TOI_DA &&
			j + HUONGDI_NGANG[viTri] >= 0 && j + HUONGDI_NGANG[viTri] < TOI_DA &&
			maTran[i + HUONGDI_DOC[viTri]][j + HUONGDI_NGANG[viTri]] == 0)
			soDuongDi++;

	return soDuongDi;
}