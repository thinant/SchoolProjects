#include <stdio.h>

#define TOI_DA 100

int chenSauPhanTuChan(int mangNguyen[], unsigned int& soPhanTu, float x);
void nhapSoPhanTu(unsigned int& n);
void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu);
void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu);

int main()
{
	int mangNguyen[TOI_DA], x = 0;
	unsigned int soPhanTu = 0;
	int maLoi = 0;
	nhapMangNguyen(mangNguyen, soPhanTu);
	printf("Nhap x: ");
	scanf_s("%d", &x);

	printf("Mang ban dau:\n");
	xuatMangNguyen(mangNguyen, soPhanTu);

	maLoi = chenSauPhanTuChan(mangNguyen, soPhanTu, x);

	if (maLoi == -1)
		printf("\n\nMang da dat kich thuoc toi da, khong the mo rong.");
	else
	{
		printf("\n\nMang sau khi chen %d:\n", x);
		xuatMangNguyen(mangNguyen, soPhanTu);
	}

	return 0;
}

int chenSauPhanTuChan(int mangNguyen[], unsigned int& soPhanTu, float x)
{
	unsigned int soPhanTuMoi = soPhanTu;
	int chiSo = -1, hangDoi[TOI_DA];
	bool laViTriChen = false;

	

	for (unsigned int i = 0; i < soPhanTuMoi && soPhanTuMoi < TOI_DA; i++)
	{
		if (i < soPhanTu)
			hangDoi[i] = mangNguyen[i]; //dua cac phan tu ban dau cua mang vao hang doi

		if (laViTriChen)
		{
			mangNguyen[i] = x; //chen x vao vi tri chen
			laViTriChen = false; //set lai bien kiem tra
		}
		else
		{
			if (chiSo != -1) //neu da bat dau chen x vao => mang thieu phan tu so voi mang ban dau
			{
				mangNguyen[i] = hangDoi[chiSo]; //chiSo la phan tu tiep theo can duoc dua vao mang
				chiSo++; //sau khi chen xong thi bo phan tu do khoi hang doi
			}
			
			if (mangNguyen[i] % 2 == 0)
			{
				laViTriChen = true; //vi tri tiep theo la vi tri chen x
				if (chiSo == -1) //neu tu luc bat dau mang chua chen x => chua bi thieu hut phan tu
					chiSo = i + 1; //=> vi tri tiep theo se la vi tri bi hut so voi ban dau
				soPhanTuMoi++; //tang kich thuoc mang
			}
		}

	}

	if (soPhanTuMoi == TOI_DA)
		return -1; //ma loi -1: kich thuoc mang toi da

	if (soPhanTu == soPhanTuMoi)
		return -2; //ma loi -2: mang khong co phan tu chan

	soPhanTu = soPhanTuMoi;

	return 0; //ma loi 0: khong co loi
}

void nhapSoPhanTu(unsigned int& soPhanTu)
{
	printf("Nhap so phan tu: ");	scanf_s("%u", &soPhanTu);

	while (soPhanTu == 0 || soPhanTu > TOI_DA)
	{
		printf("So phan tu khong hop le. Vui long nhap lai: ");
		scanf_s("%u", &soPhanTu);
	}
}

void nhapMangNguyen(int mangNguyen[], unsigned int& soPhanTu)
{
	nhapSoPhanTu(soPhanTu);

	for (unsigned int i = 0; i < soPhanTu; i++)
	{
		printf("Nhap phan tu thu %u: ", i);
		scanf_s("%d", &mangNguyen[i]);
	}
}

void xuatMangNguyen(int mangNguyen[], unsigned int soPhanTu)
{
	for (unsigned int i = 0; i < soPhanTu; i++)
		printf("%d ", mangNguyen[i]);
}