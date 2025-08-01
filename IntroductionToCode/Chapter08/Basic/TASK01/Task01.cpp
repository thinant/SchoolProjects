#include <stdio.h>

typedef struct {
	int gio;
	int phut;
	int giay;
} MyTime;

void nhapThoiGian(MyTime &t);
void xuatThoiGian(MyTime t);

bool laThoiGianHopLe(MyTime t);
MyTime khoangCach(MyTime t1, MyTime t2);

int main() {
	MyTime t1, t2, khoangCachThoiGian;

	printf("\nNhap thoi gian 1:\n");
	nhapThoiGian(t1);
	printf("\nThoi gian 1 da nhap la: ");
	xuatThoiGian(t1);

	printf("\nNhap thoi gian 2:\n");
	nhapThoiGian(t2);
	printf("\nThoi gian 2 da nhap la: ");
	xuatThoiGian(t2);

	khoangCachThoiGian = khoangCach(t1, t2);
	printf("Khoang cach giua hai thoi gian la: ");
	xuatThoiGian(khoangCachThoiGian);

	return 0;
}

void nhapThoiGian(MyTime& t) {
	do {
		printf("\nNhap gio: ");
		scanf_s("%d", &t.gio);

		printf("\nNhap phut: ");
		scanf_s("%d", &t.phut);

		printf("\nNhap giay: ");
		scanf_s("%d", &t.giay);

		if (laThoiGianHopLe(t))
			break;
		printf("Thoi gian khong hop le. Vui long nhap lai!\n");
	} while (true);
}

void xuatThoiGian(MyTime t) {
	printf("%02d:%02d:%02d\n", t.gio, t.phut, t.giay);
}

bool laThoiGianHopLe(MyTime t) {
	return (t.gio >= 0 && t.gio < 24) 
		&& (t.phut >= 0 && t.phut < 60) 
		&& (t.giay >= 0 && t.giay < 60);
}

MyTime khoangCach(MyTime t1, MyTime t2) {
	MyTime khoangCach;
	MyTime thoiGianLon = t1, thoiGianNho = t2;

	if (t1.gio < t2.gio 
		|| (t1.gio == t2.gio && (t1.phut < t2.phut 
			|| ( t1.phut == t2.phut && t1.giay < t2.giay)))) {
		thoiGianLon = t2;
		thoiGianNho = t1;
	}

	if (thoiGianLon.giay >= thoiGianNho.giay) 
		khoangCach.giay = thoiGianLon.giay - thoiGianNho.giay;
	else {
		khoangCach.giay = thoiGianLon.giay + 60 - thoiGianNho.giay;
		thoiGianLon.phut--;
	}

	if (thoiGianLon.phut >= thoiGianNho.phut) 
		khoangCach.phut = thoiGianLon.phut - thoiGianNho.phut;
	else {
		khoangCach.phut = thoiGianLon.phut + 60 - thoiGianNho.phut;
		thoiGianLon.gio--;
	}

	khoangCach.gio = thoiGianLon.gio - thoiGianNho.gio;

	return khoangCach;
}