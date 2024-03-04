#include <stdio.h>

int main()
{
	float km = 0;
	int roundKm = 0;
	long int price = 0;
	
	printf("Nhap km: ");	scanf_s("%f", &km);

	if (km > 30)
	{
		roundKm = (int)(km - 30);

		if ((km - 30) > roundKm)	roundKm++;

		price += (roundKm * 3000);
		km = 30;
	}

	if (km > 1)
	{
		roundKm = (int)((km - 1) / 0.2);

		if ((km - 1) / 0.2 > roundKm)	roundKm++;

		price += roundKm * 1000;
		km = 1;
	}
	
	if (km > 0)
	{
		price += 5000;
	}

	printf("So tien phai tra la: %ld", price);

	return 0;
}