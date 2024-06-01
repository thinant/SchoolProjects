#include <stdio.h>

const unsigned int TOI_DA = 100;
const unsigned int TOI_THIEU = 1;
const unsigned int TONG = 101;
const unsigned int HIEU = 100;
const unsigned int THUONG = 100;
const unsigned int TICH = 10000;

void nhapSoPhanTu(unsigned int& n, unsigned int gioiHanTrai, unsigned int gioiHanPhai);
void nhapMangNguyen(unsigned int mangNguyen[], unsigned int& soPhanTu, unsigned int gioiHanTrai, unsigned int gioiHanPhai);
void xuatMangNguyen(unsigned int mangNguyen[], unsigned int soPhanTu);
int soSanh(unsigned int soA[], unsigned int soChuSoA, unsigned int soB[], unsigned int soChuSoB);
void tinhTong(unsigned int soA[], unsigned int soChuSoA, unsigned int soB[], unsigned int soChuSoB, unsigned int tong[], unsigned int& kichCoTong);
void tinhHieu(unsigned int soA[], unsigned int soChuSoA, unsigned int soB[], unsigned int soChuSoB, unsigned int hieu[], unsigned int& kichCoHieu);
void tinhTich(unsigned int soA[], unsigned int soChuSoA, unsigned int soB[], unsigned int soChuSoB, unsigned int tich[], unsigned int& kichCoTich);
void tinhThuong(unsigned int soA[], unsigned int soChuSoA, unsigned int soB[], unsigned int soChuSoB, unsigned int thuong[], unsigned int& kichCoThuong);
void gan(unsigned int soA[], unsigned int& soChuSoA, unsigned int soB[], unsigned int soChuSoB);
void xoaXPhanTuDau(unsigned int x, unsigned int mang[], unsigned int& soPhanTu);

int main()
{
	
	unsigned int soA[TOI_DA]{};
	unsigned int soB[TOI_DA]{};
	unsigned int tong[TONG]{};
	unsigned int hieu[HIEU]{};
	unsigned int tich[TICH]{};
	unsigned int thuong[THUONG]{};
	unsigned int soChuSoA, soChuSoB = 0, kichCoTong = 0, kichCoHieu = 0, kichCoTich = 0, kichCoThuong = 0;

	nhapMangNguyen(soA, soChuSoA, TOI_THIEU, TOI_DA);
	printf("So A: ");
	xuatMangNguyen(soA, soChuSoA);

	printf("\n");

	nhapMangNguyen(soB, soChuSoB, TOI_THIEU, TOI_DA);
	printf("So B: ");
	xuatMangNguyen(soB, soChuSoB);

	tinhTong(soA, soChuSoA, soB, soChuSoB, tong, kichCoTong);
	printf("\nTONG: ");
	xuatMangNguyen(tong, kichCoTong);

	tinhHieu(soA, soChuSoA, soB, soChuSoB, hieu, kichCoHieu);
	printf("\nHIEU: ");
	xuatMangNguyen(hieu, kichCoHieu);

	tinhTich(soA, soChuSoA, soB, soChuSoB, tich, kichCoTich);
	printf("\nTICH: ");
	xuatMangNguyen(tich, kichCoTich);

	tinhThuong(soA, soChuSoA, soB, soChuSoB, thuong, kichCoThuong);
	printf("\nTHUONG: ");
	xuatMangNguyen(thuong, kichCoThuong);

	return 0;
}

int soSanh(unsigned int soA[], unsigned int soChuSoA, unsigned int soB[], unsigned int soChuSoB)
{
	if (soChuSoA > soChuSoB) return 1; //A > B
	if (soChuSoA < soChuSoB) return -1; // A < B

	for (int i = soChuSoA - 1; i >= 0; i--)
		if (soA[i] > soB[i]) return 1;
		else if (soA[i] < soB[i]) return -1;

	return 0; //A = B
}
void tinhTong(unsigned int soA[], unsigned int soChuSoA, unsigned int soB[], unsigned int soChuSoB, unsigned int tong[], unsigned int& kichCoTong)
{
	unsigned int giaTri = 0, nho = 0;
	kichCoTong = 0;

	for (unsigned int i = 0; i < soChuSoA || i < soChuSoB; i++)
	{
		if (i >= soChuSoA) soA[i] = 0;
		if (i >= soChuSoB) soB[i] = 0;
		giaTri = soA[i] + soB[i] + nho;
		tong[kichCoTong++] = giaTri % 10;
		nho = giaTri / 10;
	}

	if (nho != 0) tong[kichCoTong++] = nho;
	
}

void tinhHieu(unsigned int soA[], unsigned int soChuSoA, unsigned int soB[], unsigned int soChuSoB, unsigned int hieu[], unsigned int& kichCoHieu)
{
	unsigned int nho = 0;
	kichCoHieu = 0;
	int giaTri = 0, soSanhAB = soSanh(soA, soChuSoA, soB, soChuSoB);

	if (soSanhAB == 1)
		for (unsigned int i = 0; i < soChuSoA; i++)
		{

			giaTri = soA[i] - soB[i] - nho;
			nho = 0;
			if (giaTri < 0)
			{
				giaTri += 10;
				nho = 1;
			}

			hieu[kichCoHieu++] = giaTri;
		}
	else if (soSanhAB == -1)
		for (unsigned int i = 0; i < soChuSoB; i++)
		{
			giaTri = soB[i] - soA[i] - nho;
			nho = 0;
			if (giaTri < 0)
			{
				giaTri += 10;
				nho = 1;
			}

			hieu[kichCoHieu++] = giaTri;
		}
	else
		hieu[kichCoHieu++] = 0;

	while (kichCoHieu > 1 && hieu[kichCoHieu - 1] == 0) 
		kichCoHieu--;
}
void tinhTich(unsigned int soA[], unsigned int soChuSoA, unsigned int soB[], unsigned int soChuSoB, unsigned int tich[], unsigned int& kichCoTich)
{
	unsigned int  tichTam[TOI_DA + 1]{};
	kichCoTich =  0;
	tich[kichCoTich++] = 0;

	if ((soChuSoA == 1 && soA[0] == 0) || (soChuSoB == 1 && soB[0] == 0)) 
		return;

	for (unsigned int i = 0; i < soChuSoA; i++)
	{
		unsigned int kichCoTichTam = 0, nho = 0, giaTri = 0;

		//nhan voi tung chu so
		for (unsigned int j = 0; j < soChuSoB; j++)
		{
			giaTri = soA[i] * soB[j] + nho;
			tichTam[kichCoTichTam++] = giaTri % 10;
			nho = giaTri / 10;
		}

		if (nho != 0) tichTam[kichCoTichTam++] = nho;

		//cong cac phep tich tung chu so
		tinhTong(tich + i, kichCoTich, tichTam, kichCoTichTam, tich + i, kichCoTich);
	}

	kichCoTich += soChuSoA - 1;
	if (kichCoTich > 1 && tich[kichCoTich - 1] == 0) kichCoTich--;

}
void tinhThuong(unsigned int soA[], unsigned int soChuSoA, unsigned int soB[], unsigned int soChuSoB, unsigned int thuong[], unsigned int& kichCoThuong)
{
	unsigned int soBiChia[TOI_DA]{}, tichTam[TOI_DA + 1]{}, thuongTam[1] = {0};
	unsigned int soChuSoBiChia = 0, soBiBat = 0, kichCoTichTam = 0, nho = 0, kichCoTruoc = 0;
	kichCoThuong = 0;
	int soSanhAB = soSanh(soA, soChuSoA, soB, soChuSoB);

	if ((soChuSoA == 1 && soA[0] == 0) || (soChuSoB == 1 && soB[0] == 0))
	{
		thuong[kichCoThuong++] = 0;
		return;
	}

	
	if (soSanhAB == 1)
	{

		gan(soBiChia, soChuSoBiChia, soA, soChuSoA);

		while (soSanh(soBiChia, soChuSoBiChia, soB, soChuSoB) >= 0)
		{
			thuongTam[0] = 0;
			soBiBat = 0;

			for (unsigned int i = 1; soBiBat < soB[soChuSoB - 1]; i++)
				soBiBat = soBiBat * 10 + soBiChia[soChuSoBiChia - i];

			thuongTam[0] = soBiBat / soB[soChuSoB - 1] + 1;
			unsigned int chuSoPhu = 0;

			do
			{
				thuongTam[0]--;
				tinhTich(thuongTam, 1, soB, soChuSoB, tichTam, kichCoTichTam);

				if (soSanh(soB, soChuSoB, soBiChia + soChuSoBiChia - kichCoTichTam, kichCoTichTam) == 1)
					chuSoPhu++;
			} while (soSanh(tichTam, kichCoTichTam, soBiChia + (soChuSoBiChia - kichCoTichTam - chuSoPhu), kichCoTichTam + chuSoPhu) == 1);

			for (int i = 1; nho > 0 && kichCoTichTam > kichCoTruoc && i <= kichCoTichTam - kichCoTruoc; i++)
				thuong[soChuSoA - ++kichCoThuong] = 0;
			nho = 0;

			thuong[soChuSoA - ++kichCoThuong] = thuongTam[0];

			kichCoTruoc = kichCoTichTam;
			unsigned int kichCoSoBiChiaMoi = kichCoTichTam;
			tinhHieu(soBiChia + (soChuSoBiChia - kichCoTichTam - chuSoPhu), kichCoTichTam + chuSoPhu,
				tichTam, kichCoTichTam, soBiChia + (soChuSoBiChia - kichCoTichTam - chuSoPhu), kichCoSoBiChiaMoi);

			nho = chuSoPhu + (kichCoTichTam - kichCoSoBiChiaMoi);
			soChuSoBiChia = soChuSoBiChia - nho;
		}

		xoaXPhanTuDau(soChuSoA - kichCoThuong, thuong, soChuSoA);
	}
	else if (soSanhAB == -1)
	{
		gan(soBiChia, soChuSoBiChia, soB, soChuSoB);

		while (soSanh(soBiChia, soChuSoBiChia, soA, soChuSoA) >= 0)
		{
			thuongTam[0] = 0;
			soBiBat = 0;

			for (unsigned int i = soChuSoBiChia - 1; soBiBat < soA[soChuSoA - 1]; i--)
				soBiBat = soBiBat * 10 + soBiChia[i];

			thuongTam[0] = soBiBat / soA[soChuSoA - 1] + 1;
			unsigned int chuSoPhu = 0;

			do
			{
				thuongTam[0]--;
				tinhTich(thuongTam, 1, soA, soChuSoA, tichTam, kichCoTichTam);

				if (soSanh(soA, soChuSoA, soBiChia + soChuSoBiChia - kichCoTichTam, kichCoTichTam) == 1)
					chuSoPhu++;
			} while (soSanh(tichTam, kichCoTichTam, soBiChia + (soChuSoBiChia - kichCoTichTam - chuSoPhu), kichCoTichTam + chuSoPhu) == 1);

			for (int i = 1; nho > 0 && kichCoTichTam > kichCoTruoc && i <= kichCoTichTam - kichCoTruoc; i++)
				thuong[soChuSoB - ++kichCoThuong] = 0;
			nho = 0;

			thuong[soChuSoB - ++kichCoThuong] = thuongTam[0];

			kichCoTruoc = kichCoTichTam;
			unsigned int kichCoSoBiChiaMoi = kichCoTichTam;
			tinhHieu(soBiChia + (soChuSoBiChia - kichCoTichTam - chuSoPhu), kichCoTichTam + chuSoPhu,
				tichTam, kichCoTichTam, soBiChia + (soChuSoBiChia - kichCoTichTam - chuSoPhu), kichCoSoBiChiaMoi);

			nho = chuSoPhu + (kichCoTichTam - kichCoSoBiChiaMoi);
			soChuSoBiChia = soChuSoBiChia - nho;
		}

		xoaXPhanTuDau(soChuSoB - kichCoThuong, thuong, soChuSoB);
	}
	else
		thuong[kichCoThuong++] = 1;
}

void gan(unsigned int soA[], unsigned int& soChuSoA, unsigned int soB[], unsigned int soChuSoB)
{
	soChuSoA = soChuSoB;

	for(int i = soChuSoA - 1; i >= 0; i--)
		soA[i] = soB[i];
}


void nhapSoPhanTu(unsigned int& soPhanTu, unsigned int gioiHanTrai, unsigned int gioiHanPhai)
{
	printf("Nhap so chu so: ");	scanf_s("%u", &soPhanTu);

	while (soPhanTu < gioiHanTrai || soPhanTu > gioiHanPhai)
	{
		printf("So phan tu khong hop le. Vui long nhap lai: ");
		scanf_s("%u", &soPhanTu);
	}
}

void nhapMangNguyen(unsigned int mangNguyen[], unsigned int& soPhanTu, unsigned int gioiHanTrai, unsigned int gioiHanPhai)
{
	nhapSoPhanTu(soPhanTu, gioiHanTrai, gioiHanPhai);

	for (int i = soPhanTu - 1; i >= 0; i--)
		scanf_s("%u", &mangNguyen[i]);

}

void xuatMangNguyen(unsigned int mangNguyen[], unsigned int soPhanTu)
{
	for (int i = soPhanTu - 1; i >= 0; i--)
		printf("%u", mangNguyen[i]);
}

void xoaXPhanTuDau(unsigned int x, unsigned int mang[], unsigned int& soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu - x; i++)
		mang[i] = mang[i + x];
	
	soPhanTu -= x;
}