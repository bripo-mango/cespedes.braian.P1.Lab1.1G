#include "eBicicleta.h"
#include "Funciones_Genericas.h"

void InitBicicleta(eBicicleta *listaBicileta, int tam)
{
	if(listaBicileta != NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			listaBicileta[i].isEmpty = TRUE;
		}
	}
}

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
                 todoOk = 1;
                 break;
            }
        }
    }
    return todoOk;
}

void ForceBicicleta(eBicicleta *listBici, int tam, int *pId, int *pFlag)
{
	int id = 1;
	char marca[][TAMA] = {"Daylight", "Monster", "Loude", "Hank"};
	int idTipo[] = {1000, 1003, 1001, 1002};
	int idColor[] = {5001, 5002, 5003, 5004};
	char material[] = {'c', 'a', 'c', 'a'};
	int rodado[] = {23, 25, 20, 35};

	if(listBici != NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(listBici[i].isEmpty == TRUE)
			{
				listBici[i].id = id;
				strcpy(listBici[i].marca, marca[i]);
				listBici[i].idTipo = idTipo[i];
				listBici[i].idColor = idColor[i];
				listBici[i].material = material[i];
				listBici[i].rodado = rodado[i];
				listBici[i].isEmpty = FALSE;
				*pId = id;
				id++;
			}
		}
	}
	*pFlag = 1;
}

void PrintOnlyOneBicicleta(eBicicleta *listaBicileta)
{
	printf("\n* %2d %12s %9d %10d %9c %10d\n\n",  listaBicileta->id,
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

int ListarBicicletasPorId(eBicicleta *listBici, int tam)
{
    int todoOk = 0;
    eBicicleta auxBici;

    if(listBici != NULL && tam > 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {
            	if(listBici[i].isEmpty == FALSE && listBici[j].isEmpty == FALSE)
            	{
            	/*
                if( strcmp(vec[i].nombre, vec[j].nombre) > 0 )
                {
                    auxEmpleado = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxEmpleado;
                }
                */
            		if(listBici[i].id > listBici[j].id)
            		{
            			auxBici = listBici[i];
            			listBici[i] = listBici[j];
            	      	listBici[j] = auxBici;
            		}
            	}
            }
        }
        todoOk = 1;
    }
    return todoOk;
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
