#include "Anexo_Struct.h"
#include "Funciones_Genericas.h"


void InitTrabajo(eTrabajo *listTrabajo, int tam)
{
	int i;

	if(listTrabajo != NULL && tam > 0)
	{
		for(i=0; i<tam; i++)
		{
			listTrabajo[i].isEmpty = TRUE;
		}
	}
}

/*
void ForceTrabajo(eTrabajo *listTrabajo, int tam)
{
	char description[][TAMA] = {"Rutera", "Carrera", "Mountain", "BMX"};
	int id[] = {0,1,2};

	if(listTrabajo != NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(listTrabajo[i].isEmpty == TRUE && listTrabajo != NULL)
			{
				listTrabajo[i].idStatus = eGen_ObtenerID(999);
				strcpy(listTipo[i].description, description[i]);
				listTipo[i].isEmpty = FALSE;
			}
		}
	}
}*/


int FindTrabajo(eTrabajo *listTrabajo, int tam, int id, int* pIndex)
{
    int todoOk = 0;

    if(listTrabajo != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(!listTrabajo[i].isEmpty && listTrabajo[i].id == id)
            {
                *pIndex = i;
                 break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int FindFreeIndexeTrabajo(eTrabajo *listaTrabajo, int tam)
{
	int i;
	int index = -1;

	if(listaTrabajo != NULL && tam > 0)
	{
		for(i=0; i<tam; i++)
		{
			if(listaTrabajo[i].isEmpty == TRUE && listaTrabajo != NULL && tam > 0)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}
