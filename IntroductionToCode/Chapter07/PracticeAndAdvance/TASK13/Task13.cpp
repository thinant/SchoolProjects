#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

#define HANG 5
#define COT 8
typedef int CHU_SO[HANG][COT];

CHU_SO KHONG = { {0,0,1,1,1,1,0,0}, {1,1,0,0,0,0,1,1}, {1,1,0,0,0,0,1,1}, {1,1,0,0,0,0,1,1}, {0,0,1,1,1,1,0,0} };
CHU_SO MOT = { {0,0,0,1,1,0,0,0}, {0,0,0,1,1,0,0,0}, {0,0,0,1,1,0,0,0}, {0,0,0,1,1,0,0,0}, {0,0,0,1,1,0,0,0} };
CHU_SO HAI = { {1,1,1,1,1,1,1,1}, {0,0,0,0,0,0,1,1}, {1,1,1,1,1,1,1,1}, {1,1,0,0,0,0,0,0}, {1,1,1,1,1,1,1,1} };
CHU_SO BA = { {1,1,1,1,1,1,1,1}, {0,0,0,0,0,0,1,1}, {1,1,1,1,1,1,1,1}, {0,0,0,0,0,0,1,1}, {1,1,1,1,1,1,1,1} };
CHU_SO BON = { {1,1,0,0,0,0,1,1}, {1,1,0,0,0,0,1,1}, {1,1,1,1,1,1,1,1}, {0,0,0,0,0,0,1,1}, {0,0,0,0,0,0,1,1} };
CHU_SO NAM = { {1,1,1,1,1,1,1,1}, {1,1,0,0,0,0,0,0}, {1,1,1,1,1,1,1,1}, {0,0,0,0,0,0,1,1}, {1,1,1,1,1,1,1,1} };
CHU_SO SAU = { {1,1,1,1,1,1,1,1}, {1,1,0,0,0,0,0,0}, {1,1,1,1,1,1,1,1}, {1,1,0,0,0,0,1,1}, {1,1,1,1,1,1,1,1} };
CHU_SO BAY = { {1,1,1,1,1,1,1,1}, {0,0,0,0,0,0,1,1}, {0,0,0,0,0,0,1,1}, {0,0,0,0,0,0,1,1}, {0,0,0,0,0,0,1,1} };
CHU_SO TAM = { {1,1,1,1,1,1,1,1}, {1,1,0,0,0,0,1,1}, {1,1,1,1,1,1,1,1}, {1,1,0,0,0,0,1,1}, {1,1,1,1,1,1,1,1} };
CHU_SO CHIN = { {1,1,1,1,1,1,1,1}, {1,1,0,0,0,0,1,1}, {1,1,1,1,1,1,1,1}, {0,0,0,0,0,0,1,1}, {1,1,1,1,1,1,1,1} };

int HAI_CHAM[5][2] = { {0, 0}, {1, 1}, {0, 0}, {1, 1}, {0, 0} };

void hienThiGio();
void veSo(CHU_SO khung, int so);

int main() {
	hienThiGio();

	return 0;
}



void hienThiGio() {
	CHU_SO gioChuc, gioDonVi, phutChuc, phutDonVi;
	struct tm gioCu;
	time_t now = time(0);
	localtime_s(&gioCu, &now);
	bool lanDau = true;

	while (true) {
		struct tm gioMoi;
		time_t now = time(0);
		localtime_s(&gioMoi, &now);;
		

		if ((gioMoi.tm_min != gioCu.tm_min) || lanDau) {
			veSo(phutDonVi, gioMoi.tm_min % 10);

			if ((gioMoi.tm_min / 10) != (gioCu.tm_min / 10) || lanDau) {
				veSo(phutChuc, gioMoi.tm_min / 10);

				if ((gioMoi.tm_hour) != (gioCu.tm_hour) || lanDau) {
					veSo(gioDonVi, gioMoi.tm_hour % 10);

					if ((gioMoi.tm_hour / 10) != (gioCu.tm_hour / 10) || lanDau)
						veSo(gioChuc, gioMoi.tm_hour / 10);
				}
			}

			system("cls");

			for (int i = 0; i < HANG; i++) {
				for (int j1 = 0; j1 < COT; j1++) {
					if (gioChuc[i][j1] == 1)
						printf("%d", gioChuc[i][j1]);
				else printf(" ");
				}

				printf(" ");

				for (int j1 = 0; j1 < COT; j1++) {
					if (gioDonVi[i][j1] == 1)
						printf("%d", gioDonVi[i][j1]);
					else printf(" ");
				}

				printf(" ");

				for (int j1 = 0; j1 < 2; j1++) {
					if (HAI_CHAM[i][j1] == 1)
						printf("%d", HAI_CHAM[i][j1]);
					else printf(" ");
				}

				printf(" ");

				for (int j1 = 0; j1 < COT; j1++) {
					if (phutChuc[i][j1] == 1)
						printf("%d", phutChuc[i][j1]);
					else printf(" ");
				}

				printf(" ");

				for (int j1 = 0; j1 < COT; j1++) {
					if (phutDonVi[i][j1] == 1)
						printf("%d", phutDonVi[i][j1]);
					else printf(" ");
				}

				printf("\n");
			}

			gioCu = gioMoi;
			lanDau = false;
			printf("Nhap phim bat ky de dung lai: ");
		}

		if (_kbhit())
			break;
	}
}

void veSo(CHU_SO khung, int so) {

	switch (so) {
	case 0:
		for (int i = 0; i < HANG; i++)
			for (int j = 0; j < COT; j++)
				khung[i][j] = KHONG[i][j];
		break;
	case 1:
		for (int i = 0; i < HANG; i++)
			for (int j = 0; j < COT; j++)
				khung[i][j] = MOT[i][j];
		break;
	case 2:
		for (int i = 0; i < HANG; i++)
			for (int j = 0; j < COT; j++)
				khung[i][j] = HAI[i][j];
		break;
	case 3:
		for (int i = 0; i < HANG; i++)
			for (int j = 0; j < COT; j++)
				khung[i][j] = BA[i][j];
		break;
	case 4:
		for (int i = 0; i < HANG; i++)
			for (int j = 0; j < COT; j++)
				khung[i][j] = BON[i][j];
		break;
	case 5:
		for (int i = 0; i < HANG; i++)
			for (int j = 0; j < COT; j++)
				khung[i][j] = NAM[i][j];
		break;
	case 6:
		for (int i = 0; i < HANG; i++)
			for (int j = 0; j < COT; j++)
				khung[i][j] = SAU[i][j];
		break;
	case 7:
		for (int i = 0; i < HANG; i++)
			for (int j = 0; j < COT; j++)
				khung[i][j] = BAY[i][j];
		break;
	case 8:
		for (int i = 0; i < HANG; i++)
			for (int j = 0; j < COT; j++)
				khung[i][j] = TAM[i][j];
		break;
	case 9:
		for (int i = 0; i < HANG; i++)
			for (int j = 0; j < COT; j++)
				khung[i][j] = CHIN[i][j];
		break;
	}
}