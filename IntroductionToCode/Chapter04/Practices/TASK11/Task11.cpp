#include <stdio.h>

void nhapSoThuc(double&, char);
int giaiHePhuongTrinh(double&, double&, double, double, double, double, double, double);
void xuatNghiemHePhuongTrinh(double, double, int);

int main()
{
    double a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    double x = 0, y = 0;
    int maNghiem = 0;

    nhapSoThuc(a, 'a');
    nhapSoThuc(b, 'b');
    nhapSoThuc(c, 'c');
    nhapSoThuc(d, 'd');
    nhapSoThuc(e, 'e');
    nhapSoThuc(f, 'f');

    printf("He phuong trinh:\n");
    printf("%lf * x + %lf * y = %lf\n", a, b, c);
    printf("%lf * x + %lf * y = %lf\n", d, e, f);

    maNghiem = giaiHePhuongTrinh(x, y, a, b, c, d, e, f);
    xuatNghiemHePhuongTrinh(x, y, maNghiem);

    return 0;
}

void nhapSoThuc(double& a, char c)
{
    printf("Nhap %c: ", c);
    scanf_s("%lf", &a);
}

int giaiHePhuongTrinh(double& x, double& y, double a, double b, double c, double d, double e, double f)
{
    int maNghiem = 0;                       //2 nghiem
    double tiLe = a * e - b * d;

    if (tiLe == 0)
        if (c * d == a * f && c * e == f * b) maNghiem = 1;   //vo so nghiem
        else maNghiem = -1;                 //vo nghiem
    else
    {
        x = (c * e - f * b) / tiLe;
        y = (f * a - c * d) / tiLe;
    }

    return maNghiem;
}

void xuatNghiemHePhuongTrinh(double x, double y, int maNghiem)
{
    if (maNghiem == 1) printf("He phuong trinh co vo so nghiem");
    else if (maNghiem == -1) printf("He phuong trinh vo nghiem");
    else printf("x = %lf\ny = %lf", x, y);
}