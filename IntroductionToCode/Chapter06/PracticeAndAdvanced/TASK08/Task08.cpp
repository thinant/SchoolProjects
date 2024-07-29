#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#define TOI_DA 10000

void nhapVanBanTrucTiep();
void diChuyenConTro(int x, int y);
void xoaKyTu(char chuoi[], int x, int y);

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
    int doDaiHang[1000], soHang = 0, soKiTuTrenHang = 0;
    
    diChuyenConTro(x, y);

    while (strlen(chuoi) < TOI_DA)
    {
        kiTu = _getch();

        if (kiTu == 27) //ESC
            break;

        if (kiTu == -32)
        {
            kiTu = _getch();
            switch (kiTu)
            {
            case 72: //mui ten len
                if (y > 1)
                {
                    y--;
                    viTri -= doDaiHang[y];
                }
                break;
            case 80: //mui ten xuong
                y++;
                break;
            case 75: //mui ten trai
                if (x > 1)
                    x--;
                else if (y > 1)
                {
                    y--;
                    x = 1;
                }
                break;
            case 77: //mui ten phai
                if (x <= 1000)
                    x++;
                else
                {
                    x = 1;
                    y++;
                }
                break;
            case 83: //nut del
                xoaKyTu(chuoi, x, y);
                break;
            }
        }
        else if (kiTu == '\b')
        {
            if (x == 1)
            {
                x = 1000;
                y--;
            }
            else 
                x--;

            xoaKyTu(chuoi, x, y);
            diChuyenConTro(x, y);
        }
        else if (kiTu == '\n' || kiTu == '\r')
        {
            x = 0;
            y++;
            
            doDaiHang[soHang++] = soKiTuTrenHang;
            soKiTuTrenHang = 0;

            chuoi[viTri++] = '\n';
            chuoi[viTri] = '\0';
        }
        else if (kiTu >= 32 && kiTu <= 126)
        {
            chuoi[viTri++] = kiTu;
            chuoi[viTri] = '\0';

            x++;
            soKiTuTrenHang++;

            if (x > 1000)
            {
                x = 0;
                y++;

                doDaiHang[soHang++] = soKiTuTrenHang;
                soKiTuTrenHang = 0;

                chuoi[viTri++] = '\n';
                chuoi[viTri] = '\0';
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

void xoaKyTu(char chuoi[], int x, int y)
{
    if (!(x > 0 && y > 0 && x + (y-1) * 1000 < TOI_DA))
        return;

    int doDaiChuoi = strlen(chuoi);
    for (int i = x + (y - 1) * 1000; i < doDaiChuoi; i++)
        chuoi[i] = chuoi[i + 1];
}