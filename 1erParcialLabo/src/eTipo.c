
#include "Funciones_Genericas.h"
#include "Anexo_Struct.h"

void InitSTipo(eTipo *listTipo, int tam){
	int i;

	if(listTipo != NULL && tam > 0)
	{
		for(i=0; i<tam; i++)
		{
			listTipo[i].isEmpty = TRUE;
		}
	}
}

void ForceTipo(eTipo *listTipo, int tam)
{
	char description[][TAMA] = {"Rutera", "Carrera", "Mountain", "BMX"};
	int id = 999;

	if(listTipo != NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(listTipo[i].isEmpty == TRUE && listTipo != NULL)
			{
				listTipo[i].idStatus = eGen_ObtenerID(id);
				strcpy(listTipo[i].description, description[i]);
				listTipo[i].isEmpty = FALSE;
				id++;
			}
		}
	}
}

void PrintAllTipo(eTipo *listTipo, int tam)
{
	if(listTipo != NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			if(listTipo[i].isEmpty == FALSE)
			{
				PrintOneTipo(&listTipo[i]);
			}
		}
	}
}

int FindTipo(eTipo *listTipo, int tam, int id, int* pIndex)
{
    int todoOk = 0;

    if(listTipo != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(!listTipo[i].isEmpty && listTipo[i].idStatus == id)
            {
                *pIndex = i;
                 todoOk = 1;
                 break;
            }
        }
    }
    return todoOk;
}

void PrintOneTipo(eTipo *listTipo)
{
	if(listTipo != NULL)
	{
		printf("\n* %4d %13s\n", listTipo->idStatus,
							   listTipo->description);
	}
}
