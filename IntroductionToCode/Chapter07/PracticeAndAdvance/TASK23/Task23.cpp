#include <stdio.h>
#include <string.h>

#define TOI_DA 1000
#define KICH_THUOC 3
#define SO_VI_TRI 4

int CAC_VI_TRI[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};


typedef int MANG2D_THUC[TOI_DA][KICH_THUOC * KICH_THUOC];
typedef int XEPHINH[KICH_THUOC][KICH_THUOC];

void nhapHinh(XEPHINH maTran);
void xuatMaTranThuc(XEPHINH maTran, unsigned int soDong, unsigned int soCot);
bool kiemTraGiaTriLaSoNguyenDuong(char giaTri[]);
bool kiemTraGiaTriLaSoThuc(char giaTri[]);
unsigned int chuyenChuoiThanhSoNguyenDuong(char giaTri[]);
int chuyenChuoiThanhSoThuc(char giaTri[]);

void xepHinh(XEPHINH maTranNguon, XEPHINH maTranDich);
void doiViTri(XEPHINH maTran, int viTriSo0, int viTriDoi);

bool laMaTranHopLe(XEPHINH maTran, MANG2D_THUC maTranDaDuyet, unsigned int soMaTranDaDuyet);
int tinhSaiBiet(XEPHINH maTran, XEPHINH maTranDich);
int timViTriSo0(XEPHINH maTran);

void epDayMaTran(XEPHINH maTran, MANG2D_THUC dayMaTran, unsigned int& soMaTranTrongDay);
void tuDayThanhMaTran(XEPHINH maTran, MANG2D_THUC dayMaTran, unsigned int viTriDay);

void saoChepMaTran(XEPHINH maTranNguon, XEPHINH maTranDich);
void xepMaTranVaoHangCho(MANG2D_THUC hangChoTam, MANG2D_THUC hangCho, unsigned int soBuocTiepTheo, unsigned int& tongMaTranCho, unsigned int soTrangThaiDaDuyet, int mangCachBietTam[]);

int main()
{
	XEPHINH maTranNguon;
	XEPHINH maTranDich = { {1,2,3}, {4,5,6}, {7,8,0} };

	printf("Ma tran nguon:\n");
	nhapHinh(maTranNguon);
	xuatMaTranThuc(maTranNguon, KICH_THUOC, KICH_THUOC);

	printf("Ma tran dich:\n");
	nhapHinh(maTranDich);
	xuatMaTranThuc(maTranDich, KICH_THUOC, KICH_THUOC);

	printf("------Bat dau xep hinh------\n");
	xepHinh(maTranNguon, maTranDich);


	return 0;
}

void nhapHinh(XEPHINH maTran)
{
	char giaTri[20 + 1] = "";
	int mangKiemTra[KICH_THUOC * KICH_THUOC] = { 0 };

	printf("Nhap noi dung ma tran:\n");

	for (unsigned int i = 0; i < KICH_THUOC; i++)
		for (unsigned int j = 0; j < KICH_THUOC; j++)
		{
			printf("Phan tu [%d][%d]: ", i, j);
			scanf_s("%s", &giaTri, 20);
			while (!kiemTraGiaTriLaSoThuc(giaTri) 
				|| chuyenChuoiThanhSoThuc(giaTri) < 0 || chuyenChuoiThanhSoThuc(giaTri) > 8
				|| mangKiemTra[chuyenChuoiThanhSoThuc(giaTri)] > 0)
			{
				printf("Gia tri khong hop le. Vui long nhap so nguyen tu 0 toi 8: ");
				scanf_s("%s", &giaTri, 20);
			}
			maTran[i][j] = chuyenChuoiThanhSoThuc(giaTri);
			mangKiemTra[maTran[i][j]]++;
		}
}

void xuatMaTranThuc(XEPHINH maTran, unsigned int soDong, unsigned int soCot)
{
	for (unsigned int i = 0; i < soDong; i++)
	{
		for (unsigned int j = 0; j < soCot; j++)
			printf("\t%d", maTran[i][j]);

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

int chuyenChuoiThanhSoThuc(char giaTri[])
{
	int so = 0, soThapPhan = 0;
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
		soThapPhan = (giaTri[i] - '0') / hangThapPhan;
		so += soThapPhan;
		hangThapPhan *= 10;
	}

	if (laSoAm) so *= -1;

	return so;
}

bool laMaTranHopLe(XEPHINH maTran, MANG2D_THUC maTranDaDuyet, unsigned int soMaTranDaDuyet) {
	for (int i = 0; i < soMaTranDaDuyet; i++) {
		bool hopLe = false;
		for (int j = 0; j < KICH_THUOC; j++) {
			for (int k = 0; k < KICH_THUOC; k++) {
				if (maTran[j][k] != maTranDaDuyet[i][j * KICH_THUOC + k]) {
					hopLe = true;
					break;
				}
			}
		}

		if (!hopLe) return false;
	}

	return true;
}

int tinhSaiBiet(XEPHINH maTran, XEPHINH maTranDich) {
	int saiBiet = 0;

	for (int i = 0; i < KICH_THUOC; i++) {
		for (int j = 0; j < KICH_THUOC; j++) {
			if (maTran[i][j] != maTranDich[i][j] && maTranDich[i][j] != 0) {
				int saiBietDong = (maTran[i][j] / KICH_THUOC) - (maTranDich[i][j] / KICH_THUOC);
				if (saiBietDong < 0) saiBietDong = -saiBietDong;

				int saiBietCot = (maTran[i][j] % KICH_THUOC) - (maTranDich[i][j] % KICH_THUOC);
				if (saiBietCot < 0) saiBietCot = -saiBietCot;
				
				saiBiet += (saiBietDong + saiBietCot);
			}
		}
	}

	return saiBiet;
}


void xepHinh(XEPHINH maTranNguon, XEPHINH maTranDich) {

	unsigned int soTrangThaiDaDuyet = 0;
	MANG2D_THUC maTranDaDuyet;

	unsigned int soBuocTiepTheo[TOI_DA] = { 0 };

	MANG2D_THUC hangChoMaTran;
	MANG2D_THUC hangChoTamMaTran;

	int mangCachBietTam[KICH_THUOC] = { 0 };

	unsigned int tongMaTranCho = 0;

	do {
		xuatMaTranThuc(maTranNguon, KICH_THUOC, KICH_THUOC);
		printf("| \n| \n");

		if (tinhSaiBiet(maTranNguon, maTranDich) == 0) {
			printf("Da xep hinh thanh cong!\n");
			return;
		}

		epDayMaTran(maTranNguon, maTranDaDuyet, soTrangThaiDaDuyet);
		int viTriSo0 = timViTriSo0(maTranNguon);

		for (int i = 0; i < SO_VI_TRI; i++) {
			int viTriDongSo0 = viTriSo0 / KICH_THUOC;
			int viTriCotSo0 = viTriSo0 % KICH_THUOC;

			int dongDoi = viTriDongSo0 + CAC_VI_TRI[i][0];
			int cotDoi = viTriCotSo0 + CAC_VI_TRI[i][1];

			if (dongDoi < 0 || dongDoi >= KICH_THUOC || cotDoi < 0 || cotDoi >= KICH_THUOC)
				continue;

			int viTriDoi = dongDoi * KICH_THUOC + cotDoi;

			XEPHINH maTranTam;
			saoChepMaTran(maTranNguon, maTranTam);

			doiViTri(maTranTam, viTriSo0, viTriDoi);

			if (laMaTranHopLe(maTranTam, maTranDaDuyet, soTrangThaiDaDuyet)) {
				mangCachBietTam[soBuocTiepTheo[soTrangThaiDaDuyet - 1]] = tinhSaiBiet(maTranTam, maTranDich);

				epDayMaTran(maTranTam, hangChoTamMaTran, soBuocTiepTheo[soTrangThaiDaDuyet - 1]);
			}
		}

		if (soBuocTiepTheo[soTrangThaiDaDuyet - 1] > 0) {
			xepMaTranVaoHangCho(hangChoTamMaTran, hangChoMaTran, soBuocTiepTheo[soTrangThaiDaDuyet - 1], tongMaTranCho, soTrangThaiDaDuyet, mangCachBietTam);

			tuDayThanhMaTran(maTranNguon, hangChoMaTran, tongMaTranCho - 1);
			tongMaTranCho--;
		} 
		else {
			tuDayThanhMaTran(maTranNguon, hangChoMaTran, tongMaTranCho - 2);
			tongMaTranCho -= 2;
			soTrangThaiDaDuyet--;
		}

	} while (tongMaTranCho > 0 && soTrangThaiDaDuyet < TOI_DA);

	printf("Khong the xep hinh thanh cong!\n");
}

void epDayMaTran(XEPHINH maTran, MANG2D_THUC dayMaTran, unsigned int& soMaTranTrongDay) {
	for (unsigned int i = 0; i < KICH_THUOC; i++) {
		for (unsigned int j = 0; j < KICH_THUOC; j++) {
			dayMaTran[soMaTranTrongDay][i * KICH_THUOC + j] = maTran[i][j];
		}
	}

	soMaTranTrongDay++;
}

int timViTriSo0(XEPHINH maTran) {
	for (unsigned int i = 0; i < KICH_THUOC; i++) {
		for (unsigned int j = 0; j < KICH_THUOC; j++) {
			if (maTran[i][j] == 0) {
				return i * KICH_THUOC + j;
			}
		}
	}
	return -1; // Khong tim thay so 0
}

void doiViTri(XEPHINH maTran, int viTriSo0, int viTriDoi) {
	int dongSo0 = viTriSo0 / KICH_THUOC;
	int cotSo0 = viTriSo0 % KICH_THUOC;

	int dongDoi = viTriDoi / KICH_THUOC;
	int cotDoi = viTriDoi % KICH_THUOC;

	int temp = maTran[dongSo0][cotSo0];
	maTran[dongSo0][cotSo0] = maTran[dongDoi][cotDoi];
	maTran[dongDoi][cotDoi] = temp;
}

void saoChepMaTran(XEPHINH maTranNguon, XEPHINH maTranDich) {
	for (unsigned int i = 0; i < KICH_THUOC; i++) {
		for (unsigned int j = 0; j < KICH_THUOC; j++) {
			maTranDich[i][j] = maTranNguon[i][j];
		}
	}
}

void xepMaTranVaoHangCho(MANG2D_THUC hangChoTam, MANG2D_THUC hangCho, unsigned int soBuocTiepTheo, unsigned int& tongMaTranCho, unsigned int soTrangThaiDaDuyet, int mangCachBietTam[]) {
	for (int i = 0; i < soBuocTiepTheo; i++) {
		unsigned int cachBietLonNhatTrongDay = 0;
		int viTriLonNhat = -1;

		for (int j = 0; j < soBuocTiepTheo; j++) {
			if (mangCachBietTam[j] >= 0 && mangCachBietTam[j] >= cachBietLonNhatTrongDay) {
				cachBietLonNhatTrongDay = mangCachBietTam[j];
				viTriLonNhat = j;
			}
		}

		if (viTriLonNhat != -1) {
			for (unsigned int j = 0; j < KICH_THUOC * KICH_THUOC; j++) {
				hangCho[tongMaTranCho][j] = hangChoTam[viTriLonNhat][j];
			}

			tongMaTranCho++;

			mangCachBietTam[viTriLonNhat] = -1; 
		}
	}
}

void tuDayThanhMaTran(XEPHINH maTran, MANG2D_THUC dayMaTran, unsigned int viTriDay) {
	for (unsigned int i = 0; i < KICH_THUOC; i++) {
		for (unsigned int j = 0; j < KICH_THUOC; j++) {
			maTran[i][j] = dayMaTran[viTriDay][i * KICH_THUOC + j];
		}
	}
}