#include <stdio.h>
#include <math.h>

int main()
{
	int shape = 0;
	float a = 0, b = 0, c = 0;	//hinh tam giac
	float hv = 0;				//hinh vuong
	float d = 0, r = 0;			//hinh chu nhat
	float R = 0;				//hinh tron
	float P = 0, S = 0;
	bool isLegit = true;

	//menu
	printf("Chon so tuong ung voi hinh can tinh toan:\n");
	printf("1. Hinh tam giac.\n");
	printf("2. Hinh vuong.\n");
	printf("3. Hinh chu nhat.\n");
	printf("4. Hinh tron.\n");
	printf("Nhap so ban chon: ");	scanf_s("%d", &shape);

	switch (shape)
	{
	case 1:
		printf("Nhap so do 3 canh, ngan cach bang khoang trang: ");	scanf_s("%f %f %f", &a, &b, &c);
		P = a + b + c;
		S = sqrt(P / 2 * (P / 2 - a) * (P / 2 - b) * (P / 2 - c));
		break;
	case 2:
		printf("Nhap vao so do canh: "); scanf_s("%f", &hv);
		P = 4 * hv;
		S = hv * hv;
		break;
	case 3:
		printf("Nhap vao so do chieu dai va chieu rong, ngan cach bang khoang trang: "); scanf_s("%f %f", &d, &r);
		P = (d + r) * 2;
		S = d * r;
		break;
	case 4:
		printf("Nhap vao ban kinh: ");	scanf_s("%f", &R);
		P = 2 * 3.14 * R;
		S = R * R * 3.14;
		break;
	default:
		printf("Lua chon khong hop le.");
		isLegit = false;
	}

	if (isLegit)
	{
		printf("Chu vi = %f\n", P);
		printf("Dien tich = %f\n", S);
	}

	return 0;
}