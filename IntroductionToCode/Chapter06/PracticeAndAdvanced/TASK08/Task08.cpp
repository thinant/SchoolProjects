#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#define TOI_DA 10000

void nhapVanBanTrucTiep();
void diChuyenConTro(int x, int y);
void xoaKyTu(char chuoi[], int viTri);
void chenKyTu(char chuoi[], int viTri, char kyTu);
void chenHang(int doDaiHang[], int& soHang, int viTriHang);
void xoaHang(int doDaiHang[], int& soHang, int viTriHang);

int main()
{
    printf("Nhap van ban va su dung phim mui ten de di chuyen, phim ESC de thoat:\n");

    nhapVanBanTrucTiep();

    return 0;
}

void nhapVanBanTrucTiep()
{
    int x = 0, y = 1, viTri = 0;
    char kiTu = '\0';
    char chuoi[TOI_DA + 1] = "";
    int doDaiHang[1000]{0}, soHang = 1, soKiTuTrenHang = 0;
    
    diChuyenConTro(x, y);

    while (strlen(chuoi) < TOI_DA)
    {
        kiTu = _getch();

        if (kiTu == 27) //ESC
        {
            diChuyenConTro(0, soHang + 1);
            fflush(stdout);
            break;
        }

        if (kiTu == -32)
        {
            kiTu = _getch();
            switch (kiTu)
            {
            case 72: //mui ten len
                if (y > 1)
                {
                    y--;
                    if (doDaiHang[y - 1] < x)
                    {
                        viTri -= (x + 1);
                        x = doDaiHang[y - 1];
                    }
                    else
                        viTri -= (doDaiHang[y - 1] + 1);
                }
                break;
            case 80: //mui ten xuong
                y++;
                if (y > 1)
                {
                    if (doDaiHang[y - 1] < x)
                    {
                        x = doDaiHang[y - 1];
                        viTri += (doDaiHang[y - 1] + 2);
                    }
                    else
                        viTri += (doDaiHang[y - 2] + 1);
                }
                break;
            case 75: //mui ten trai
                if (x > 0)
                    x--;
                else if (y > 1)
                {
                    y--;
                    x = doDaiHang[y - 1];
                }
                else if (y > 1)
                {
                    y--;
                    x = 1;
                }
                viTri--;
                break;
            case 77: //mui ten phai
                if (x < doDaiHang[y - 1])
                {
                    x++;
                    viTri++;
                }
                else if (y < soHang)
                {
                    x = 0;
                    y++;
                    viTri++;
                }
                break;
            case 83: //nut del
                xoaKyTu(chuoi, viTri);
                if (doDaiHang[y - 1] != 0) 
                    doDaiHang[y - 1]--;
                else if (y > 1)
                {
                    x = doDaiHang[y - 2];
                    doDaiHang[y - 2] += doDaiHang[y - 1];
                    xoaHang(doDaiHang, soHang, y - 1);
                    y--;
                }
                break;
            }
        }
        else if (kiTu == '\b')
        {
            if (x == 0)
            {
                if (y >= 2)
                {
                    x = doDaiHang[y - 2];
                    doDaiHang[y - 2] += doDaiHang[y - 1];
                    xoaHang(doDaiHang, soHang, y - 1);
                    y--;
                }
                else
                    continue;
            }
            else
            {
                x--;
                doDaiHang[y - 1]--;
            }

            viTri--;
            xoaKyTu(chuoi, viTri);
            diChuyenConTro(x, y);
        }
        else if (kiTu == '\n' || kiTu == '\r')
        {
            chenKyTu(chuoi, viTri++, '\n');
            chenHang(doDaiHang, soHang, y);
            doDaiHang[y] = doDaiHang[y - 1] - x;
            doDaiHang[y - 1] = x;
            x = 0;
            y++;
        }
        else if (kiTu >= 32 && kiTu <= 126)
        {
            chenKyTu(chuoi, viTri++, kiTu);

            x++;
            doDaiHang[y - 1]++;

            if (x > 1000)
            {
                x = 0;
                y++;

                doDaiHang[y-1] = 0;
                soHang++;

                chenKyTu(chuoi, viTri++, '\n');
            }
        }

        system("cls");

        printf("Nhap van ban va su dung phim mui ten de di chuyen, phim ESC de thoat:\n");
        printf("%s", chuoi);

        diChuyenConTro(x, y);
        fflush(stdout);
    }

    printf("\nDa nhap xong van ban!\n");
}

void diChuyenConTro(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void xoaKyTu(char chuoi[], int viTri)
{
    if (viTri < 0 || viTri >= TOI_DA)
        return;

    int doDaiChuoi = strlen(chuoi);
    for (int i = viTri; i < doDaiChuoi; i++)
        chuoi[i] = chuoi[i + 1];
}

void chenKyTu(char chuoi[], int viTri, char kyTu)
{
    if (viTri < 0 || viTri >= TOI_DA)
        return;

    int doDaiChuoi = strlen(chuoi);
    for (int i = doDaiChuoi + 1; i > viTri; i--)
        chuoi[i] = chuoi[i - 1];

    chuoi[viTri] = kyTu;
}

void chenHang(int doDaiHang[], int& soHang, int viTriHang)
{
    soHang++;
    for (int i = soHang - 1; i > viTriHang; i--)
        doDaiHang[i] = doDaiHang[i - 1];
}

void xoaHang(int doDaiHang[], int& soHang, int viTriHang)
{
    soHang--;
    for (int i = viTriHang; i < soHang; i++)
        doDaiHang[i] = doDaiHang[i + 1];
}