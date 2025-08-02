#include <stdio.h>

typedef struct {
	int tu;
	int mau;
} MyFraction;

void nhapPhanSo(MyFraction& f);
void xuatPhanSo(MyFraction f);

bool laPhanSoHopLe(MyFraction f);

MyFraction tongPhanSo(MyFraction f1, MyFraction f2);
MyFraction hieuPhanSo(MyFraction f1, MyFraction f2);
MyFraction tichPhanSo(MyFraction f1, MyFraction f2);
MyFraction thuongPhanSo(MyFraction f1, MyFraction f2);

MyFraction rutGonPhanSo(MyFraction f);
int timUCLN(int a, int b);

void quyDongPhanSo(MyFraction &f1, MyFraction &f2);
int soSanhPhanSo(MyFraction f1, MyFraction f2);

int main() {
	MyFraction f1, f2, tong, hieu, tich, thuong;
	printf("\nNhap phan so 1:\n");
	nhapPhanSo(f1);
	printf("\nPhan so 1 da nhap la: ");
	xuatPhanSo(f1);

	printf("\nNhap phan so 2:\n");
	nhapPhanSo(f2);
	printf("\nPhan so 2 da nhap la: ");
	xuatPhanSo(f2);

	int ketQuaSoSanh = soSanhPhanSo(f1, f2);

	if (ketQuaSoSanh > 0)
		printf("\n\nPhan so 1 lon hon phan so 2.\n");
	else if (ketQuaSoSanh == 0)
		printf("\n\nPhan so 1 bang phan so 2.\n");
	else
		printf("\n\nPhan so 1 nho hon phan so 2.\n");

	tong = tongPhanSo(f1, f2);
	printf("\nTong hai phan so la: ");
	xuatPhanSo(tong);

	hieu = hieuPhanSo(f1, f2);
	printf("\n\nHieu hai phan so la: ");
	xuatPhanSo(hieu);

	tich = tichPhanSo(f1, f2);
	printf("\n\nTich hai phan so la: ");
	xuatPhanSo(tich);

	thuong = thuongPhanSo(f1, f2);
	if (thuong.mau != 0) {
		printf("\n\nThuong hai phan so la: ");
		xuatPhanSo(thuong);
	}

	quyDongPhanSo(f1, f2);

	printf("\n\nPhan so 1 sau khi quy dong voi phan so 2 la: ");
	xuatPhanSo(f1);

	printf("\n\nPhan so 2 sau khi quy dong voi phan so 1 la: ");
	xuatPhanSo(f2);

	return 0;
}


void nhapPhanSo(MyFraction& f) {
	do {
		printf("\nNhap tu so: ");
		scanf_s("%d", &f.tu);
		printf("\nNhap mau so: ");
		scanf_s("%d", &f.mau);
		if (laPhanSoHopLe(f))
			break;

		printf("\nPhan so khong hop le. Vui long nhap lai!\n");
	} while (true);
}

void xuatPhanSo(MyFraction f) {
	if (f.tu == 0 || f.mau == 1) {
		printf("%d", f.tu);
	} else {
		printf("%d / %d", f.tu, f.mau);
	}
}

bool laPhanSoHopLe(MyFraction f) {
	return f.mau != 0;
}

MyFraction tongPhanSo(MyFraction f1, MyFraction f2) {
	MyFraction tong;

	tong.tu = f1.tu * f2.mau + f2.tu * f1.mau;
	tong.mau = f1.mau * f2.mau;

	tong = rutGonPhanSo(tong);

	return tong;
}

MyFraction hieuPhanSo(MyFraction f1, MyFraction f2) {
	MyFraction hieu;

	hieu.tu = f1.tu * f2.mau - f2.tu * f1.mau;
	hieu.mau = f1.mau * f2.mau;

	hieu = rutGonPhanSo(hieu);

	return hieu;
}

MyFraction tichPhanSo(MyFraction f1, MyFraction f2) {
	MyFraction tich;

	tich.tu = f1.tu * f2.tu;
	tich.mau = f1.mau * f2.mau;

	tich = rutGonPhanSo(tich);

	return tich;
}

MyFraction thuongPhanSo(MyFraction f1, MyFraction f2) {
	MyFraction thuong;
	thuong.tu = 0;
	thuong.mau = 0;

	if (f2.tu == 0) {
		printf("\nKhong the chia cho phan so 0.\n");
		return thuong; 
	}

	thuong.tu = f1.tu * f2.mau;
	thuong.mau = f1.mau * f2.tu;

	thuong = rutGonPhanSo(thuong);

	return thuong;
}

MyFraction rutGonPhanSo(MyFraction f) {
	if (f.tu == 0 || f.mau == 1) {
		return f; 
	}

	MyFraction ketQua;

	int ucln = timUCLN(f.tu, f.mau);

	ketQua.tu = f.tu / ucln;
	ketQua.mau = f.mau / ucln;

	if (ketQua.mau < 0) {
		ketQua.tu = -ketQua.tu;
		ketQua.mau = -ketQua.mau;
	}

	return ketQua;
}

int timUCLN(int a, int b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;

	while (a != 0 && b != 0) {
		if (a > b) {
			a = a % b;
		} else {
			b = b % a;
		}
	}

	if (a != 0) return a;

	return b;
}

void quyDongPhanSo(MyFraction &f1, MyFraction &f2) {
	f1 = rutGonPhanSo(f1);
	f2 = rutGonPhanSo(f2);

	int ucln = timUCLN(f1.mau, f2.mau);
	
	int mauChung = (f1.mau * f2.mau) / ucln;

	f1.tu *= (mauChung / f1.mau);
	f1.mau = mauChung;

	f2.tu *= (mauChung / f2.mau);
	f2.mau = mauChung;

}

int soSanhPhanSo(MyFraction f1, MyFraction f2) {
	int ketQua = f1.tu * f2.mau - f2.tu * f1.mau;

	if (ketQua > 0) {
		return 1; 
	} else if (ketQua < 0) {
		return -1; 
	} else {
		return 0; 
	}
}