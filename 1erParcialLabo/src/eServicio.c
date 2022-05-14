#include "Anexo_Struct.h"
#include "Funciones_Genericas.h"

void InitServicio(eServicio *listServicio, int tam)
{
	int i;

	if(listServicio != NULL && tam > 0)
	{
		for(i=0; i<tam; i++)
		{
			listServicio[i].isEmpty = TRUE;
		}
	}
}

void ForceServicio(eServicio *listServicio, int tam)
{

	char description[][TAMA] = {"Limpieza", "Parche", "Centrado", "Cadena"};
	float precio[] = {30, 400, 500, 450};

	if(listServicio != NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(listServicio[i].isEmpty == TRUE && listServicio != NULL)
			{
				listServicio[i].id = eGen_ObtenerID(4999);
				strcpy(listServicio[i].descripcion, description[i]);
				listServicio[i].precio = precio[i];
				listServicio[i].isEmpty = FALSE;
			}
		}
	}
}

void PrintAlleServicio(eServicio *listServicio, int tam)
{
	if(listServicio != NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(listServicio[i].isEmpty == FALSE)
			{
				PrintOneServicio(&listServicio[i]);
			}
		}
	}
}

int FindeServicio(eServicio *listServicio, int tam, int id, int* pIndex)
{
    int todoOk = 0;

    if(listServicio != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(!listServicio[i].isEmpty && listServicio[i].id == id)
            {
                *pIndex = i;
                 break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

void PrintOneServicio(eServicio *listServicio)
{
	if(listServicio != NULL)
	{
		printf("\n*%4d %9s\n", listServicio->id,
							   listServicio->descripcion);
	}
}

