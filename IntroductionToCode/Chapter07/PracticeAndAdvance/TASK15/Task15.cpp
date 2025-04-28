#include <stdio.h>
#include <random>

#define KICHTHUOC_TOIDA 10
#define KICHTHUOC_TOITHIEU 1
#define GIATRI_TOIDA 50
#define GIATRI_TOITHIEU 0
typedef int MANG2D_NGUYEN[KICHTHUOC_TOIDA][KICHTHUOC_TOIDA];

int sinhSoNguyenNgauNhien(int toiThieu, int toiDa);
void sinhMaTranNguyen(MANG2D_NGUYEN maTran, unsigned int& soDong, unsigned int& soCot);
void xuatMaTranNguyen(MANG2D_NGUYEN maTran, unsigned int soDong, unsigned int soCot);
void timCucDaiMaTran(MANG2D_NGUYEN maTran, unsigned int soDong, unsigned int soCot, MANG2D_NGUYEN maTranCucTri, unsigned int& soCucTri);
int main()
{
	MANG2D_NGUYEN maTran;
	int maTranCucTri[KICHTHUOC_TOIDA][KICHTHUOC_TOIDA] = { 0 };
	unsigned int soDong = 0, soCot = 0, soCucTri = 0;

	sinhMaTranNguyen(maTran, soDong, soCot);

	printf("\nMa tran cho truoc:\n");
	xuatMaTranNguyen(maTran, soDong, soCot);

	timCucDaiMaTran(maTran, soDong, soCot, maTranCucTri, soCucTri);

	printf("Co %d cuc tri trong ma tran:\n", soCucTri);

	for (unsigned int i = 0; i < soDong; i++)
		for (unsigned int j = 0; j < soCot; j++)
			if (maTranCucTri[i][j] == 1)
				printf("Phan tu [%d][%d]: %d\n", i, j, maTran[i][j]);


	return 0;
}

int sinhSoNguyenNgauNhien(int toiThieu, int toiDa) {

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(toiThieu, toiDa);

	return distrib(gen);
}

void sinhMaTranNguyen(MANG2D_NGUYEN maTran, unsigned int& soDong, unsigned int& soCot) {

	soDong = sinhSoNguyenNgauNhien(KICHTHUOC_TOITHIEU, KICHTHUOC_TOIDA);
	soCot = sinhSoNguyenNgauNhien(KICHTHUOC_TOITHIEU, KICHTHUOC_TOIDA);

	for (unsigned int i = 0; i < soDong; i++)
		for (unsigned int j = 0; j < soCot; j++)
			maTran[i][j] = sinhSoNguyenNgauNhien(GIATRI_TOITHIEU, GIATRI_TOIDA);
}

void xuatMaTranNguyen(MANG2D_NGUYEN maTran, unsigned int soDong, unsigned int soCot)
{
	for (unsigned int i = 0; i < soDong; i++)
	{
		for (unsigned int j = 0; j < soCot; j++)
			printf("\t%d", maTran[i][j]);

		printf("\n");
	}

}

void timCucDaiMaTran(MANG2D_NGUYEN maTran, unsigned int soDong, unsigned int soCot, MANG2D_NGUYEN maTranCucTri, unsigned int& soCucTri) {

	soCucTri = 0;
	bool laCucTri = true;

	for (int i = 0; i < soDong; i++) 
		for (int j = 0; j < soCot; j++) {
			laCucTri = true;
			for (int x = -1; x <= 1; x++) {
				if (i + x < 0 || i + x >= soDong)
					continue;

				if (!laCucTri)
					break;

				for (int y = -1; y <= 1; y++) {
					if (j + y < 0 || j + y >= soCot || (x == 0 && y == 0))
						continue;

					if (maTran[i + x][j + y] >= maTran[i][j]) {
						laCucTri = false;
						break;
					}

				}
			}

			if (laCucTri) {
				soCucTri++;

				maTranCucTri[i][j] = 1;
			}
		}
}
