#include <stdio.h>
#include <string.h>

#define TOI_DA 100
typedef double MATRAN_THUC[TOI_DA][TOI_DA];

void sapXepMaTranBangMangPhu(MATRAN_THUC maTran, unsigned int soDong, unsigned int soCot);
void duaMaTranRaMang(MATRAN_THUC maTran, unsigned int soDong, unsigned int soCot, double mang[]);
void duaMangVaoMaTran(MATRAN_THUC maTran, unsigned int soDong, unsigned int soCot, double mang[]);
void sapXepChen(double mang[], unsigned int& soPhanTu, double phanTuChen);
void nhapMaTranThuc(MATRAN_THUC maTran, unsigned int& soDong, unsigned int& soCot);
void xuatMaTranThuc(MATRAN_THUC maTran, unsigned int soDong, unsigned int soCot);
bool kiemTraGiaTriLaSoNguyenDuong(char giaTri[]);
bool kiemTraGiaTriLaSoThuc(char giaTri[]);
unsigned int chuyenChuoiThanhSoNguyenDuong(char giaTri[]);
double chuyenChuoiThanhSoThuc(char giaTri[]);

int main()
{
	MATRAN_THUC maTran{ 0 };
	unsigned int soDong = 0, soCot = 0;

	nhapMaTranThuc(maTran, soDong, soCot);

	printf("Ma tran da nhap la:\n");
	xuatMaTranThuc(maTran, soDong, soCot);

	sapXepMaTranBangMangPhu(maTran, soDong, soCot);

	printf("Ma tran sau khi sap xep:\n");
	xuatMaTranThuc(maTran, soDong, soCot);

	return 0;
}

void nhapMaTranThuc(MATRAN_THUC maTran, unsigned int& soDong, unsigned int& soCot)
{
	char giaTri[20 + 1] = "";

	printf("Nhap so dong cua ma tran: ");
	scanf_s("%s", &giaTri, 20);
	while (!kiemTraGiaTriLaSoNguyenDuong(giaTri))
	{
		printf("Gia tri khong hop le. Vui long nhap so nguyen duong: ");
		scanf_s("%s", &giaTri, 20);
	}
	soDong = chuyenChuoiThanhSoNguyenDuong(giaTri);

	printf("Nhap so cot cua ma tran: ");
	scanf_s("%s", &giaTri, 20);
	while (!kiemTraGiaTriLaSoNguyenDuong(giaTri))
	{
		printf("Gia tri khong hop le. Vui long nhap so nguyen duong: ");
		scanf_s("%s", &giaTri, 20);
	}
	soCot = chuyenChuoiThanhSoNguyenDuong(giaTri);

	printf("Nhap noi dung ma tran:\n");

	for (unsigned int i = 0; i < soDong; i++)
		for (unsigned int j = 0; j < soCot; j++)
		{
			printf("Phan tu [%d][%d]: ", i, j);
			scanf_s("%s", &giaTri, 20);
			while (!kiemTraGiaTriLaSoThuc(giaTri))
			{
				printf("Gia tri khong hop le. Vui long nhap so thuc: ");
				scanf_s("%s", &giaTri, 20);
			}
			maTran[i][j] = chuyenChuoiThanhSoThuc(giaTri);
		}
}

void xuatMaTranThuc(MATRAN_THUC maTran, unsigned int soDong, unsigned int soCot)
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

void sapXepMaTranBangMangPhu(MATRAN_THUC maTran, unsigned int soDong, unsigned int soCot)
{
	double mangPhu[TOI_DA * TOI_DA];
	duaMaTranRaMang(maTran, soDong, soCot, mangPhu);
	duaMangVaoMaTran(maTran, soDong, soCot, mangPhu);
}

void duaMaTranRaMang(MATRAN_THUC maTran, unsigned int soDong, unsigned int soCot, double mang[])
{
	unsigned int soPhanTu = 0;
	for (unsigned int i = 0; i < soDong; i++)
		for (unsigned int j = 0; j < soCot; j++)
			sapXepChen(mang, soPhanTu, maTran[i][j]);
}

void duaMangVaoMaTran(MATRAN_THUC maTran, unsigned int soDong, unsigned int soCot, double mang[])
{
	for (unsigned int i = 0; i < soDong * soCot; i++)
		maTran[i / soCot][i % soCot] = mang[i];
}

void sapXepChen(double mang[], unsigned int& soPhanTu, double phanTuChen)
{
	int viTri = soPhanTu - 1;

	for (viTri; viTri >= 0; viTri--)
		if (mang[viTri] > phanTuChen)
			break;
		else
			mang[viTri + 1] = mang[viTri];

	mang[viTri + 1] = phanTuChen;
	soPhanTu++;
}