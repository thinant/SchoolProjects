#include <stdio.h>
#include <string.h>

#define TOI_DA 100
typedef double MANG2D_THUC[TOI_DA][TOI_DA];

void taoMaTranThuc(MANG2D_THUC maTran, unsigned int& soDong, unsigned int& soCot);
void xuatMaTranThuc(MANG2D_THUC maTran, unsigned int soDong, unsigned int soCot);
bool kiemTraGiaTriLaSoNguyenDuong(char giaTri[]);
bool kiemTraGiaTriLaSoThuc(char giaTri[]);
unsigned int chuyenChuoiThanhSoNguyenDuong(char giaTri[]);
double chuyenChuoiThanhSoThuc(char giaTri[]);
void taoMaPhuong(MANG2D_THUC maTran, unsigned int soDong, unsigned int soCot);
void taoMaPhuongLe(MANG2D_THUC maTran, unsigned int soDong, unsigned int soCot);
void taoMaPhuongBoi4(MANG2D_THUC maTran, unsigned int soDong, unsigned int soCot);
void diMaTranL(MANG2D_THUC maTran, unsigned int khoi_i, unsigned int khoi_j, int& giaTri);
void diMaTranU(MANG2D_THUC maTran, unsigned int khoi_i, unsigned int khoi_j, int& giaTri);
void diMaTranX(MANG2D_THUC maTran, unsigned int khoi_i, unsigned int khoi_j, int& giaTri);

int main()
{
	MANG2D_THUC maTran = { 0 };
	unsigned int soDong = 0, soCot = 0, soCucTri = 0;

	printf("Ma tran:\n");
	taoMaTranThuc(maTran, soDong, soCot);

	taoMaPhuong(maTran, soDong, soCot);

	printf("\nMa tran da nhap la:\n");
	xuatMaTranThuc(maTran, soDong, soCot);

	return 0;
}

void taoMaTranThuc(MANG2D_THUC maTran, unsigned int& soDong, unsigned int& soCot)
{
	char giaTri[20 + 1] = "";

	printf("Nhap so dong cua ma tran: ");
	scanf_s("%s", &giaTri, 20);
	soDong = 0;

	while (!kiemTraGiaTriLaSoNguyenDuong(giaTri))
		{
			printf("Gia tri khong hop le. Vui long nhap so nguyen duong: ");
			scanf_s("%s", &giaTri, 20);
		}

		soDong = chuyenChuoiThanhSoNguyenDuong(giaTri);
		soCot = soDong;

	while (soDong <= 2 || soCot <= 2 ) {
		printf("Gia tri khong hop le. Vui long nhap so nguyen duong lon hon 2: ");
		scanf_s("%s", &giaTri, 20);
		if (kiemTraGiaTriLaSoNguyenDuong(giaTri))
		{
			soDong = chuyenChuoiThanhSoNguyenDuong(giaTri);
			soCot = soDong;
		}
	}
}

void xuatMaTranThuc(MANG2D_THUC maTran, unsigned int soDong, unsigned int soCot)
{
	for (unsigned int i = 0; i < soDong; i++)
	{
		for (unsigned int j = 0; j < soCot; j++)
			printf("\t%lf", maTran[i][j]);

		printf("\n");
	}

}

bool kiemTraGiaTriLaSoNguyenDuong(char giaTri[])
{
	for (unsigned int i = 0; i < strlen(giaTri); i++)
		if (giaTri[i] < '0' || giaTri[i] > '9')
			return false;

	if (chuyenChuoiThanhSoNguyenDuong(giaTri) >= 10)
		return false;

	return true;
}

bool kiemTraGiaTriLaSoThuc(char giaTri[])
{
	bool laPhanThapPhan = false;
	for (unsigned int i = 0; i < strlen(giaTri); i++)
		if (giaTri[i] == '-')
		{
			if (i != 0)
				return false;
		}
		else if (giaTri[i] == '.')
			if (i == 0 || laPhanThapPhan)
				return false;
			else
				laPhanThapPhan = true;
		else if (giaTri[i] < '0' || giaTri[i] > '9')
			return false;

	return true;
}

unsigned int chuyenChuoiThanhSoNguyenDuong(char giaTri[])
{
	unsigned int so = 0;

	for (unsigned int i = 0; i < strlen(giaTri); i++)
	{
		so *= 10;
		so += (giaTri[i] - '0');
	}

	return so;
}

double chuyenChuoiThanhSoThuc(char giaTri[])
{
	double so = 0, soThapPhan = 0;
	unsigned int hangThapPhan = 10, i = 0;
	bool laSoAm = false;

	for (i = 0; i < strlen(giaTri) && giaTri[i] != '.'; i++)
	{
		if (giaTri[i] == '-')
		{
			laSoAm = true;
			continue;
		}
		so *= 10;
		so += (giaTri[i] - '0');
	}

	for (i; i < strlen(giaTri); i++)
	{
		if (giaTri[i] == '.')
			continue;
		soThapPhan = (double)(giaTri[i] - '0') / hangThapPhan;
		so += soThapPhan;
		hangThapPhan *= 10;
	}

	if (laSoAm) so *= -1;

	return so;
}

void taoMaPhuong(MANG2D_THUC maTran, unsigned int soDong, unsigned int soCot) {
	if (soDong % 2 != 0) {
		taoMaPhuongLe(maTran, soDong, soCot);
	}
	else if (soDong % 4 == 0) {
		taoMaPhuongBoi4(maTran, soDong, soCot);
	}
	else {
		const int VITRI_L = soDong / 4 + 1;
		const int VITRI_U = VITRI_L + 1;
		const int VITRI_X = soDong / 2;
		int giaTri = 1;

		int khoi_i = 1;
		int khoi_j = soCot / 4 + 1;


		while (giaTri <= soDong * soCot) {
			if (khoi_i <= VITRI_L) {
				if (khoi_i <= VITRI_L - 1 || khoi_j != soCot / 4 + 1) {
					diMaTranL(maTran, khoi_i, khoi_j, giaTri);
				}
				else {
					diMaTranU(maTran, khoi_i, khoi_j, giaTri);
				}
			}
			else if (khoi_i <= VITRI_U) {
				if (khoi_j == soCot / 4 + 1) {
					diMaTranL(maTran, khoi_i, khoi_j, giaTri);
				}
				else {
					diMaTranU(maTran, khoi_i, khoi_j, giaTri);
				}
			}
			else {
				diMaTranX(maTran, khoi_i, khoi_j, giaTri);
			}

			int khoi_i_truoc = khoi_i;
			int khoi_j_truoc = khoi_j;

			khoi_i--;
			khoi_j++;

			if (khoi_i <= 0)
				khoi_i = soDong / 2;
			if (khoi_j > soCot / 2)
				khoi_j = 1;
			if (maTran[(khoi_i - 1) * 2][(khoi_j -1) * 2] != 0) {
				khoi_i = khoi_i_truoc + 1;
				khoi_j = khoi_j_truoc;
			}
		}
	}
}

void taoMaPhuongLe(MANG2D_THUC maTran, unsigned int soDong, unsigned int soCot)
{
	int i = 0, i_truoc = 0;
	int j = soDong / 2, j_truoc = 0;
	int giaTri = 1;

	while (giaTri <= soDong * soCot) {
		maTran[i][j] = giaTri;
		giaTri++;

		i_truoc = i;
		j_truoc = j;

		i--;
		j++;

		if (i < 0)
			i = soDong - 1;
		if (j >= soCot)
			j = 0;
		if (maTran[i][j] != 0) {
			i = i_truoc + 1;
			j = j_truoc;
		}
	}
}

void taoMaPhuongBoi4(MANG2D_THUC maTran, unsigned int soDong, unsigned int soCot) {
	int giaTri = 1;

	for (unsigned int i = 0; i < soDong; i++) {
		unsigned int soDu1 = 0;
		unsigned int soDu2 = 3;

		if (i % 2 != 0)
			soDu1 = 2;

		for (unsigned int j = 0; j < soCot; j++) {
			if ((i + j) % 4 == soDu1 || (i + j) % 4 == soDu2)
				maTran[i][j] = giaTri;

			giaTri++;
		}
	}

	giaTri = 1;

	for (int i = soDong - 1; i >= 0; i--)
		for (int j = soCot - 1; j >= 0; j--) {

			if (maTran[i][j] == 0)
				maTran[i][j] = giaTri;

			giaTri++;
		}
}

void diMaTranL(MANG2D_THUC maTran, unsigned int khoi_i, unsigned int khoi_j, int& giaTri) {
	int i = (khoi_i - 1) * 2;
	int j = (khoi_j - 1) * 2;

	maTran[i][j + 1] = giaTri;
	giaTri++;

	maTran[i + 1][j] = giaTri;
	giaTri++;

	maTran[i + 1][j + 1] = giaTri;
	giaTri++;

	maTran[i][j] = giaTri;
	giaTri++;
}

void diMaTranU(MANG2D_THUC maTran, unsigned int khoi_i, unsigned int khoi_j, int& giaTri) {
	int i = (khoi_i - 1) * 2;
	int j = (khoi_j - 1) * 2;

	maTran[i][j] = giaTri;
	giaTri++;

	maTran[i + 1][j] = giaTri;
	giaTri++;

	maTran[i + 1][j + 1] = giaTri;
	giaTri++;

	maTran[i][j + 1] = giaTri;
	giaTri++;
}

void diMaTranX(MANG2D_THUC maTran, unsigned int khoi_i, unsigned int khoi_j, int& giaTri) {
	int i = (khoi_i - 1) * 2;
	int j = (khoi_j - 1) * 2;

	maTran[i][j] = giaTri;
	giaTri++;

	maTran[i + 1][j + 1] = giaTri;
	giaTri++;

	maTran[i + 1][j] = giaTri;
	giaTri++;

	maTran[i][j + 1] = giaTri;
	giaTri++;
}
