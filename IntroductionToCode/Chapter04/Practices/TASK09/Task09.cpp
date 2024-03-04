#include <math.h>
#include <stdio.h>

double tinhPhanSo(double tu, double mau);
double tinhLuyThua(double coSo, double luyThua, bool& laSoHopLe);
double tinhS(double p, double q, unsigned int m, unsigned int n, bool& laSoHopLe);

int main()
{
	double q = 0, p = 0, S = 0;
	unsigned int m = 2, n = 3;
	bool laSoHopLe = false;

	printf("Nhap p: ");		scanf_s("%lf", &p);
	printf("Nhap q: ");		scanf_s("%lf", &q);

	S = tinhS(p, q, m, n, laSoHopLe);

	if (laSoHopLe) printf("Ket qua bieu thuc = %lf", S);
	else printf("Cap so %lf va %lf khong hop le", p, q);

	return 0;
}

double tinhPhanSo(double tu, double mau)
{
	double phanSo = tu;
	phanSo /= mau;

	return phanSo;
}

double tinhLuyThua(double coSo, int soMu, bool& laSoHopLe, bool coNghichDao)
{
	double luyThua = 1;
	double phanSo = tinhPhanSo(1, soMu);

	if (!coNghichDao && 
			(soMu > 0 || (soMu < 0 && coSo != 0)))
	{
		laSoHopLe = true;
		luyThua = pow(coSo, soMu);
	}
	else if (coSo >= 0)
	{
		laSoHopLe = true;
		luyThua = pow(coSo, phanSo);
	}
	else if (soMu % 2 != 0)
	{
		laSoHopLe = true;
		luyThua = -pow(-coSo, phanSo);
	}

	return luyThua;
}

double tinhS(double p, double q, unsigned int m, unsigned int n, bool& laSoHopLe)
{
	double pn = 0, qm = 0, pnn = 0, qmm = 0;
	double h = 0, A = 0, B = 0, S = 0;

	pn = tinhPhanSo(p, n);
	qm = tinhPhanSo(q, m);
	pnn = tinhLuyThua(pn, n, laSoHopLe, false);
	qmm = tinhLuyThua(qm, m, laSoHopLe, false);

	h = tinhLuyThua(pnn + qmm, m, laSoHopLe, true);
	A = tinhLuyThua(-qm + h, n, laSoHopLe, true);
	B = tinhLuyThua(-qm - h, n, laSoHopLe, true);
	S = A + B;

	return S;
}