#include <stdio.h>
#include "cp_data1.h"
#include <math.h>

int menu;
int zast = 1;
int hvstup, mvstup;

void cestovnyporiadok(int zast)
{
	int cas = PRVY_SPOJ_M + DELTA *(zast-1);      // ZADEFINOVANY POSUN VSTUP MAM NATO ABY SOM VEDEL NA AKEJ ZASTAVKE SA NACHADZAM A O KOLKO MA BYT POSUNUTY PRVY SPOJ
	int interval;
	int h = PRVY_SPOJ_H;
	int i = PRVY_SPOJ_H;
	int j = POSLED_SPOJ_H;
	int r_s = RANO_START;
	int r_e = RANO_END;
	int p_s = POOBEDE_START;
	int p_e = POOBEDE_END;
	printf("0%i| ", h);
	for (h = i; h <= j;)
	{
		if (cas < 10)
			printf("0");
		else if (cas >= 60)                  // PODMIENKA AK MINUTY SU VACSIE AKO 60 ALEBO PRIDAT 0 AK JE MENEJ AKO 10
		{
			h++;
			if (h == 24)
				break;
			cas = cas - 60;
			printf("\n");
			if (h < 10)
				printf("0%i| ", h);				// TATO PODMIENKA JE LEN NATO ABY KED JE MENEJ AKO 10 HODIN NECH TO JE PEKNE ZAROVNO
			else
				printf("%i| ", h);
			if(cas <10)
				printf("0");
			
		}
		
		
		
		if (h >= r_s && h <= r_e)
		{
			interval = INTERVAL_RANO;
			printf("%i ", cas);
			cas = cas + interval;                                // MENIM INTERVALY PODLA TOHO KOLKO JE HODIN A AKA JE PREMAVKA
		}
		else if (h >= p_s && h <= p_e)
		{
			interval = INTERVAL_POOBEDE;
			printf("%i ", cas);
			cas = cas + interval;
			
		}
		else
		{
			interval = INTERVAL_NORMAL;
			printf("%i ", cas);
			cas = cas + interval;
		
			
		}
	}
	printf("\n");
}

void najblizsispoj(zast)
{
	
	int cas = PRVY_SPOJ_M + DELTA * (zast - 1);
	int interval;
	int h = PRVY_SPOJ_H;
	int i = PRVY_SPOJ_H;
	int j = POSLED_SPOJ_H;
	int r_s = RANO_START;
	int r_e = RANO_END;
	int p_s = POOBEDE_START;
	int p_e = POOBEDE_END;
	int o = 1;
	printf("Zadaj hodinu:");
	scanf_s("%i", &hvstup);
	printf("\nZadaj minutu:");
	scanf_s("%i", &mvstup);
	while (1 == 1 )
	{
		
		if (h >= r_s && h <= r_e)
		{
			interval = INTERVAL_RANO;
			cas = cas + interval;                                // MENIM INTERVALY PODLA TOHO KOLKO JE HODIN A AKA JE PREMAVKA
		}
		else if (h >= p_s && h <= p_e)
		{
			interval = INTERVAL_POOBEDE;
			cas = cas + interval;

		}
		else
		{
			interval = INTERVAL_NORMAL;
			cas = cas + interval;


		}
		if (cas > 60)
		{
			if (hvstup == h)
			{
				cas = cas - 60;
				hvstup++;
				
				break;
			}
			else
			{
				cas = cas - 60;
				h++;
			}
		}
		if (hvstup == h && cas > mvstup)
		{
			break;
		}
		
	}
	
	printf("Najblizsi spoj: %d:%.2d\n", hvstup, cas);
	printf("_______________________\n");
	
}

void vypisovanie(int z)
{
	printf("1.Vyber zastavky\n");
	printf("2.Cestovny poriadok\n");
	printf("3.Najblizsi spoj\n");
	printf("Aktualna zastavka: %i\n", zast);
	scanf_s("%i", &menu);
	printf("_______________________\n");
}

void main()
{
	vypisovanie(zast);
	while (1 == 1)
	switch (menu)
	{
	case 1:
		{
			
			printf("Vyber si zastavku :");
			scanf_s("%i", &zast);
			vypisovanie(zast);
			break;
		}
	case 2:
		{
			cestovnyporiadok(zast);                                    //urobim si switch na menu podla vstupu
			vypisovanie(zast);
			break;
		}
	case 3:
		{
			najblizsispoj(zast);
			vypisovanie(zast);
			break;
		}
	}
	scanf_s("%i", &menu);
	
	
}