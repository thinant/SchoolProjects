#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

void nhapVanBanTrucTiep();
void diChuyenConTro(int x, int y);
void xoaKyTu();

int main()
{
    printf("Nhap van ban va su dung phim mui ten de di chuyen, phim ESC de thoat:\n");

    nhapVanBanTrucTiep();

    return 0;
}

void nhapVanBanTrucTiep()
{
    int x = 1, y = 1;
    char kiTu = '\0';
    
    diChuyenConTro(x, y);

    while (true)
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
                    y--;
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
                x++;
                diChuyenConTro(x, y);
                xoaKyTu();
                x--;
                diChuyenConTro(x, y);
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
            xoaKyTu();
            x--;
            diChuyenConTro(x, y);
        }
        else if (kiTu == '\n' || kiTu == '\r')
        {
            x = 1;
            y++;
        }
        else if (kiTu >= 32 && kiTu <= 126)
        {
            putchar(kiTu);

            if (x <= 1000)
                x++;
            else
            {
                x = 1;
                y++;
            }
        }
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

void xoaKyTu()
{
    printf("\b \b");
}