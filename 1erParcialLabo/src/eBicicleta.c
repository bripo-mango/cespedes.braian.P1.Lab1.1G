#include "eBicicleta.h"
#include "Funciones_Genericas.h"

void InitBicicleta(eBicicleta *listaBicileta, int tam)
{
	int i;

	if(listaBicileta != NULL && tam > 0)
	{
		for(i=0; i<tam; i++)
		{
			listaBicileta[i].isEmpty = TRUE;
		}
	}
}

/*
void ForceBicicleta(eBicicleta *listaBicileta, int *idPassenger, int tam, int *pFlag)
{
	char name[][TAMA] = {"Juan", "Mario", "Pedro", "Cristian"};
	char lastName[][TAMA] = {"Lopez", "Caastanieda", "Responde", "Saliba"};
	float price[] = {450,100,900,500};
	char flyCode[][TAMA] = {"PLF1","RNT2","H4TJ","Q2R6"};
	int type[] = {0,1,0,1};
	int status[] = {1,1,0,2};

	if(listaBicileta != NULL && tam > 0 && idPassenger != NULL)
	{
		for(int i=0; i<tam; i++)
		{
			if(listaBicileta[i].isEmpty == TRUE && idPassenger != NULL && listaBicileta != NULL)
			{
				listaBicileta[i].id = eGen_ObtenerID(*idPassenger);
				strcpy(listaBicileta[i].marca, name[i]);
				strcpy(listaBicileta[i].lastName, lastName[i]);
				listPassenger[i].price = price[i];
				strcpy(listPassenger[i].flyCode, flyCode[i]);
				listPassenger[i].typePassenger = type[i];
				listPassenger[i].statusFlight = status[i];
				listPassenger[i].isEmpty = FALSE;
				*idPassenger = listPassenger[i].id;
			}
		}
	}
	*pFlag = 1;
}

*/
int FindBicicleta(eBicicleta *listaBicileta, int tam, int id, int* pIndex)
{
    int todoOk = 0;

    if(listaBicileta != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(!listaBicileta[i].isEmpty && listaBicileta[i].id == id)
            {
                *pIndex = i;
                 break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

void PrintOnlyOneBicicleta(eBicicleta *listaBicileta)
{
	printf("\n*%2d %12s %2d %2d %2c %4d\n\n",  listaBicileta->id,
														 listaBicileta->marca,
														 listaBicileta->idColor,
														 listaBicileta->idTipo,
														 listaBicileta->material,
														 listaBicileta->rodado);
}


int FindBicicletaId(eBicicleta *listaBicileta, int tam, int id)
{
	int i;
	int index = -1;

	if(listaBicileta != NULL && tam > 0)
	{
		for(i=0; i<tam; i++)
		{
			if(listaBicileta[i].id == id && listaBicileta != NULL && tam > 0)
			{
				index = i;
				break;
			}
		}
	}
		return index;
}

int FindFreeIndexeBicicleta(eBicicleta *listaBicileta, int tam)
{
	int i;
	int index = -1;

	if(listaBicileta != NULL && tam > 0)
	{
		for(i=0; i<tam; i++)
		{
			if(listaBicileta[i].isEmpty == TRUE && listaBicileta != NULL && tam > 0)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}


void RemoveBicicleta(eBicicleta *listaBicileta, int tam, int index, char *mensaje)
{
	if(listaBicileta != NULL && tam > 0 && mensaje != NULL)
	{
		for(int i=0; i<tam; i++)
		{
			if(i == index)
			{
				printf("%s", mensaje);
				listaBicileta[i].isEmpty = TRUE;
				break;
			}
		}
	}
}


/*
float PricesPlus(ePassenger *listPassenger, int tam)
{
    int i;
    float countPrices = 0;

    for(i=0; i<tam; i++)
    {
        if(listPassenger[i].isEmpty == FALSE)
        {
        	countPrices += listPassenger[i].price;
        }
    }
    return countPrices;
}

float AveragePrice(ePassenger *listPassenger, int tam)
{
    int i;
    float averagePrices = 0;

    for(i=0; i<tam; i++)
    {
        if(listPassenger[i].isEmpty == FALSE)
        {
        	averagePrices = PricesPlus(listPassenger, tam) / CountPassenger(listPassenger, tam);
        }
    }
    return averagePrices;
}


int CountPassenger(ePassenger *listPassenger, int tam)
{
    int i;
    int countPassengers = 0;

    for(i=0; i<tam; i++)
    {
        if(listPassenger[i].isEmpty == FALSE)
        {
        	countPassengers++;
        }
    }
    return countPassengers;
}


int ShowAveragePassenger(ePassenger *listPassenger, int tam)
{
    int i;
    float Promedio;
    int pasajerosMayorSueldo = 0;
    Promedio = AveragePrice(listPassenger, tam);

    for(i=0; i<tam; i++)
    {
        if(listPassenger[i].isEmpty == FALSE && listPassenger[i].price > Promedio)
        {
        	pasajerosMayorSueldo++;
        }
    }
    return pasajerosMayorSueldo;
}


*/

