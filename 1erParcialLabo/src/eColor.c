#include "Anexo_Struct.h"
#include "Funciones_Genericas.h"

void InitColor(eColor *listColor, int tam)
{
	int i;

	if(listColor != NULL && tam > 0)
	{
		for(i=0; i<tam; i++)
		{
			listColor[i].isEmpty = TRUE;
		}
	}
}

void ForceColor(eColor *listColor, int tam)
{
	char description[][TAMA] = {"Gris", "Blanco", "Azul", "Negro", "Rojo"};
	int id = 5000;
	if(listColor != NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(listColor[i].isEmpty == TRUE && listColor != NULL)
			{
				listColor[i].idStatus = id;
				strcpy(listColor[i].description, description[i]);
				listColor[i].isEmpty = FALSE;
				id++;
			}
		}
	}
}

void PrintAlleColor(eColor *listColor, int tam)
{
	if(listColor != NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(listColor[i].isEmpty == FALSE)
			{
				PrintOneeColor(&listColor[i]);
			}
		}
	}
}

int FindeColor(eColor *listColor, int tam, int id, int* pIndex)
{
    int todoOk = 0;

    if(listColor != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(!listColor[i].isEmpty && listColor[i].idStatus == id)
            {
                *pIndex = i;
                 todoOk = 1;
                 break;
            }
        }
    }
    return todoOk;
}

void PrintOneeColor(eColor *listColor)
{
	if(listColor != NULL)
	{
		printf("\n* %4d %13s\n", listColor->idStatus,
							    listColor->description);
	}
}

