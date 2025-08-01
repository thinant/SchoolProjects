#include <stdio.h>

typedef struct {
	int ngay;
	int thang;
	int nam;
} MyDate;

void nhapNgayThang(MyDate& t);
void xuatNgayThang(MyDate t);

int ngayTrongThang(int thang, int nam);
bool laNgayThangHopLe(MyDate t);
bool laNamNhuan(int nam);

MyDate khoangCach(MyDate t1, MyDate t2);

int main() {
	MyDate t1, t2, khoangCachNgayThang;

	printf("\nNhap ngay thang 1:\n");
	nhapNgayThang(t1);
	printf("\nNgay thang 1 da nhap la: ");
	xuatNgayThang(t1);

	printf("\nNhap ngay thang 2:\n");
	nhapNgayThang(t2);
	printf("\nNgay thang 2 da nhap la: ");
	xuatNgayThang(t2);

	khoangCachNgayThang = khoangCach(t1, t2);
	printf("\nKhoang cach giua hai ngay thang la: %02d ngay %02d thang %04d nam.", 
		khoangCachNgayThang.ngay, khoangCachNgayThang.thang, khoangCachNgayThang.nam);

	return 0;
}

void nhapNgayThang(MyDate& t) {
	do {
		printf("\nNhap ngay: ");
		scanf_s("%d", &t.ngay);

		printf("\nNhap thang: ");
		scanf_s("%d", &t.thang);

		printf("\nNhap nam: ");
		scanf_s("%d", &t.nam);

		if (laNgayThangHopLe(t))
			break;
		printf("Ngay thang khong hop le. Vui long nhap lai!\n");
	} while (true);
}

void xuatNgayThang(MyDate t) {
	printf("%02d / %02d / %04d\n", t.ngay, t.thang, t.nam);
}

int ngayTrongThang(int thang, int nam) {
	switch (thang) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
		case 2:
			if (laNamNhuan(nam))
				return 29; 
			return 28; 
		default:
			return 30;
	}
}

bool laNgayThangHopLe(MyDate t) {
	return (t.ngay > 0 && t.ngay <= ngayTrongThang(t.thang, t.nam))
		&& (t.thang > 0 && t.thang <= 12)
		&& (t.nam > 0);
}

bool laNamNhuan(int nam) {
	return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

MyDate khoangCach(MyDate t1, MyDate t2) {
	MyDate khoangCach;
	MyDate NgayThangLon = t1, NgayThangNho = t2;

	if (t1.nam < t2.nam 
			|| (t1.nam == t2.nam && (t1.thang < t2.thang 
				|| (t1.thang == t2.thang && t1.ngay < t2.ngay)))) {
		NgayThangLon = t2;
		NgayThangNho = t1;
	}

	if (NgayThangLon.ngay >= NgayThangNho.ngay)
		khoangCach.ngay = NgayThangLon.ngay - NgayThangNho.ngay;
	else {
		khoangCach.ngay = NgayThangLon.ngay + ngayTrongThang(NgayThangNho.thang, NgayThangNho.nam) - NgayThangNho.nam;
		NgayThangLon.thang--;
	}

	if (NgayThangLon.thang >= NgayThangNho.thang)
		khoangCach.thang = NgayThangLon.thang - NgayThangNho.thang;
	else {
		khoangCach.thang = NgayThangLon.thang + 12 - NgayThangNho.thang;
		NgayThangLon.nam--;
	}

	khoangCach.nam = NgayThangLon.nam - NgayThangNho.nam;

	return khoangCach;
}