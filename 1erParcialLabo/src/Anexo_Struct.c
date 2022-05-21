#include "Anexo_Struct.h"
#include "Funciones_Genericas.h"

void PrintAllBicicletas(eBicicleta *listBicicleta, int tam, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor)
{
	if(listBicicleta != NULL && listTipo != NULL && tam > 0 && tamTipo > 0)
	{
		for(int i=0; i<tam; i++)
		{
			for(int j=0; j<tamTipo; j++)
			{
				if(listBicicleta[i].isEmpty == FALSE && listBicicleta[i].idTipo == listTipo[j].idStatus)
				{
					for(int k = 0; k< tamColor; k++)
					{
						if(listBicicleta[i].idColor == listColor[k].idStatus)
						{
							PrintOneBicicletaTipoColor(&listBicicleta[i], &listTipo[j], &listColor[k]);
						}
					}
				}
			}
		}
	}
}

void PrintAllBicicletasColor(eBicicleta *listBicicleta, int tam, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor, int ingresoColor)
{
	if(listBicicleta != NULL && listTipo != NULL && tam > 0 && tamTipo > 0)
	{
		for(int i=0; i<tam; i++)
		{
			for(int j=0; j<tamTipo; j++)
			{
				if(listBicicleta[i].isEmpty == FALSE && listBicicleta[i].idTipo == listTipo[j].idStatus)
				{
					for(int k = 0; k< tamColor; k++)
					{
						if(listBicicleta[i].idColor == listColor[k].idStatus && listColor[k].idStatus == ingresoColor)
						{
							PrintOneBicicletaTipoColor(&listBicicleta[i], &listTipo[j], &listColor[k]);
						}
					}
				}
			}
		}
	}
}

void PrintAllBicicletasTipo(eBicicleta *listBicicleta, int tam, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor, int ingresoTipo)
{
	if(listBicicleta != NULL && listTipo != NULL && tam > 0 && tamTipo > 0)
	{
		for(int i=0; i<tam; i++)
		{
			for(int j=0; j<tamTipo; j++)
			{
				if(listBicicleta[i].isEmpty == FALSE && listBicicleta[i].idTipo == listTipo[j].idStatus && listTipo[j].idStatus == ingresoTipo)
				{
					for(int k = 0; k< tamColor; k++)
					{
						if(listBicicleta[i].idColor == listColor[k].idStatus)
						{
							PrintOneBicicletaTipoColor(&listBicicleta[i], &listTipo[j], &listColor[k]);
						}
					}
				}
			}
		}
	}
}

void ContarAllBicicletasTipoColor(eBicicleta *listBicicleta, int tam, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor, int ingresoTipo, int *contadorTipo, int ingresoColor, int *contadorColor)
{
	if(listBicicleta != NULL && listTipo != NULL && tam > 0 && tamTipo > 0)
	{
		for(int i=0; i<tam; i++)
		{
			for(int j=0; j<tamTipo; j++)
			{
				if(listBicicleta[i].isEmpty == FALSE && listBicicleta[i].idTipo == listTipo[j].idStatus && listTipo[j].idStatus == ingresoTipo)
				{
					contadorTipo++;
				}
			}
			for(int k = 0; k< tamColor; k++)
			{
				if(listColor[i].isEmpty == FALSE && listBicicleta[i].idColor == listColor[k].idStatus && listColor[k].idStatus == ingresoColor)
				{
					contadorColor++;
				}
			}
		}
	}
}

int BicicletasPorTipo(eBicicleta *listBicicleta, int tam, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor)
{
    int todoOk = 0;

    if( listBicicleta != NULL && tam > 0 && listTipo != NULL && tamTipo > 0)
    {
        system("cls");

        for(int i=0; i < tamTipo; i++)
        {
        	BicicletasPorIdTipo(listBicicleta, tam, listTipo, tamTipo, listTipo[i].idStatus, listColor, tamColor );
            printf("\n\n");

        }
        system("pause");
        todoOk = 1;
    }
    return todoOk;

}

int BicicletasPorIdTipo(eBicicleta *listBicicleta, int tam, eTipo *listTipo, int tamTipo, int id, eColor *listColor, int tamColor)
{
    int todoOk = 0;

    if( listBicicleta != NULL && tam > 0 && listTipo != NULL && tamTipo > 0)
    {
      for(int j=0; j < tamTipo; j++)
      {

        for(int i=0; i < tam; i++)
        {
            if(!listBicicleta[i].isEmpty  && listBicicleta[i].id == id)
            	{
            		PrintOnlyOneBicicleta(&listBicicleta[i]);
            	}
        }
    }

        todoOk = 1;
    }
    return todoOk;
}

void PrintOneBicicletaTipoColor(eBicicleta *listBicicleta, eTipo *listTipo, eColor *listColor)
{

		printf("\n* %2d %11s %11s %10s %9c %10d\n\n", listBicicleta->id,
													listBicicleta->marca,
													listTipo->description,
													listColor->description,
													listBicicleta->material,
													listBicicleta->rodado);
}

void PrintOneBicicletaTipo(eBicicleta *listBicicleta, eTipo *listTipo)
{

		printf("\n* %2d %12s %12s %2d %2c %4d\n\n", listBicicleta->id,
													listBicicleta->marca,
													listTipo->description,
													listBicicleta->idColor,
													listBicicleta->material,
													listBicicleta->rodado);
}



/*
void PrintPassengersByStatusActive(ePassenger *listPassenger, int tam, eStatus *listStatus, int tamStatus)
{
	if(listPassenger != NULL && tam > 0 && listStatus != NULL && tamStatus > 0)

			for(int i=0; i<tam; i++)
			{
				for(int j=0; j<tamStatus; j++)
				{
					if(listPassenger[i].isEmpty == FALSE && listPassenger[i].typePassenger == listStatus[j].idStatus)
					{
						if(listPassenger[i].statusFlight == 1)
						{
							PrintOnePassengerAndStatus(&listPassenger[i], &listStatus[j]);
						}
					}
				}
			}
}
*/

void addOneBicicletas(eBicicleta *listBicicleta, int tam, int idBicicleta, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor)
{
	int i;
	i = FindFreeIndexeBicicleta(listBicicleta, tam);

	if(i != -1 && listBicicleta != NULL && listTipo != NULL && tam > 0 && tamTipo > 0)
	{
		listBicicleta[i] = AddBicicletas(idBicicleta, listTipo, tamTipo, listColor, tamColor);
		if(listBicicleta[i].isEmpty == FALSE)
		{
			printf("\nBicicleta cargada con exito!!\n\n");
			system("pause");
			system("cls");
		}
	}
	else
	{
		 printf("\nNo existe espacio disponible para la carga de datos\n\n");
		 system("pause");
		 system("cls");
	}
}

eBicicleta AddBicicletas(int idBicicleta,  eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor)
{
	eBicicleta AddedBicicletas;
	int auxType;
	int auxColor;
	int auxIndexColor;
	int auxIndex;

	if(listColor != NULL && tamColor > 0)
	{
		GetString("Ingrese la marca de la bicicleta: ", AddedBicicletas.marca , SIZE_STRING);
		system("cls");

		printf("Listado de tipos\n");
		printf("\n%5s %14s","Codigo", "Nombre\n");
		PrintAllTipo(listTipo, tamTipo);
		auxType = GetInt("\nIngrese el codigo del tipo : ", "\nIngrese el codigo de nuevamente (solo caracteres numericos enteros): ");

		while(!FindTipo(listTipo, tamTipo, auxType, &auxIndex))
		{
			system("cls");
			printf("ERROR!!! No se ha encontrado el codigo ingresado.\n\n");
			printf("Listado de tipos\n");
			printf("\n%5s %14s","Codigo", "Nombre\n");
			PrintAllTipo(listTipo, tamTipo);
			auxType = GetInt("\nReigrese el codigo del tipo: ", "\nIngrese el codigo de tipo nuevamente (solo caracteres numericos enteros): ");
		}
		system("cls");

		AddedBicicletas.idTipo = auxType;

		printf("Listado de colores\n");
		printf("\n%5s %14s","Codigo", "Nombre\n");
		PrintAlleColor(listColor, tamColor);
		auxColor = GetInt("\nIngrese el codigo del COLOR : ", "\nIngrese el codigo de color nuevamente (solo caracteres numericos enteros): ");

		while(!FindeColor(listColor, tamColor, auxColor, &auxIndexColor))
		{
			system("cls");
			printf("ERROR!!! No se ha encontrado el codigo ingresado.\n\n");
			printf("Listado de colores\n");
			printf("\n%5s %14s","Codigo", "Nombre\n");
			PrintAlleColor(listColor, tamColor);
			auxColor = GetInt("\nReigrese el codigo: ", "\nIngrese el codigo de color nuevamente (solo caracteres numericos enteros): ");
		}

		AddedBicicletas.idColor = auxColor;

		AddedBicicletas.material = GetChar("\nIngrese el material Carbono(c)/Aluminio(a): ", "\nError, reingrese el material Carbono(c)/Aluminio(a): ");

		AddedBicicletas.id = idBicicleta;

		AddedBicicletas.rodado = GetIntRange("\nIngrese el rodado 20 hasta 40", "\nReigrese el rodado 20 hasta 40", 20, 40);

		AddedBicicletas.isEmpty = FALSE;
	}
		return AddedBicicletas;
}

void ModifyBicicletas(eBicicleta *listBicicleta, int tam, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor)
{
	int indexBici;
	int auxType;
	int auxRodado;
	int auxIndexTipo;
	int idUser;
	int option;
	char seguir;

	if(listBicicleta != NULL && tam > 0 && listTipo != NULL && tamTipo > 0)
	{
		system("cls");
		printf("\n\n###### Listado de bicicletas ######\n");
		printf("\n%5s %9s %9s %11s %12s %9s","Codigo", "Marca", "Tipo", "Color", "Material", "Rodado\n");
		PrintAllBicicletas(listBicicleta, tam, listTipo, tamTipo, listColor, tamColor);
		idUser = GetInt("\nIngrese el codigo de bicicleta de la siguiente lista: ", "Codigo no encontrado, Reingrese el codigo nuevamente: ");
		while(!FindBicicleta(listBicicleta, tam, idUser, &indexBici))
			{
				printf("/nERROR!!! No se encontro el ID ingresado.");
				printf("\n\n###### Listado de bicicletas encontradas ######\n");
				printf("\n%5s %9s %9s %11s %12s %9s","Codigo", "Marca", "Tipo", "Color", "Material", "Rodado\n");
				PrintAllBicicletas(listBicicleta, tam, listTipo, tamTipo, listColor, tamColor);
				idUser = GetInt("\nIngrese el codigo de pasajero de la siguiente lista", "Codigo no encontrado, Reingrese el codigo nuevamente: ");
			}

		if(indexBici != -1)
		{
		  system("cls");
		  printf("\n\n###### Bicicleta encontrada ######\n");
		  printf("\n%5s %9s %9s %11s %12s %9s","Codigo", "Marca", "Tipo", "Color", "Material", "Rodado\n");
		  PrintOnlyOneBicicleta(&listBicicleta[indexBici]);

		  option = GetIntRange("\nSe ha encontrado la Id ingresada !!\n\nQue desea modificar? \n\n1-Tipo\n\n2-Rodado\n\n\n3-Salir\n\nIngrese una opcion: ", "Usted ha ingresado una opcion incorrecta, reingrese: ", 1, 3);
		  switch(option)
			{
				case 1:
					system("cls");
					printf("Listado de tipos\n");
					printf("\n%5s %14s","Codigo", "Nombre\n");
					PrintAllTipo(listTipo, tamTipo);
					auxType = GetInt("\nIngrese el codigo de tipo : ", "\nIngrese el codigo de nuevamente (solo caracteres numericos enteros): ");

					while(!FindTipo(listTipo, tamTipo, auxType, &auxIndexTipo))
					{
						printf("/nERROR!!! No se ha encontrado el codigo ingresado.");
						system("cls");
						printf("Listado de tipos\n");
						printf("\n%5s %14s","Codigo", "Nombre\n");
						PrintAllTipo(listTipo, tamTipo);
						auxType = GetInt("\nReigrese el codigo de tipo: ", "\nIngrese el codigo nuevamente (solo caracteres numericos enteros): ");
					}

					seguir = GetCharConfirmacion("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Error, reingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					if(seguir == 's')
					{
						listBicicleta[indexBici].idTipo = auxType;
						printf("\nEl Tipo ha sido modificado con exito\n");
						system("pause");
						system("cls");
					}
					else
					{
						printf("\nSe ha cancelado la modificacion del Tipo\n");
						system("pause");
						system("cls");
					}
					break;

				case 2:

					auxRodado = GetIntRange("\nIngrese el nuevo rodado (20 hasta 40): ", "\nReingrese el rodado (20 hasta 40): ", 20, 40);

					seguir = GetCharConfirmacion("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Ingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					 if(seguir == 's')
					 {
						listBicicleta[indexBici].rodado = auxRodado;
						printf("\nEl rodado se ha modificado con exito\n");
						system("pause");
						system("cls");
					 }
					 else
					 {
						printf("\nSe ha cancelado la modificacion del rodado\n");
						system("pause");
						system("cls");
					 }
					 break;

				case 3:
					 printf("\nSe ha cancelado la modificacion de datos\n");
					 system("pause");
					 system("cls");
					break;
			}
		}
		else
		{
			printf("\nNo se ha encontrado la id ingresada\n");
			system("pause");
			system("cls");
		}
	}
}

void DeleteBicicletas(eBicicleta *listBicicleta, int tam, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor)
{
	int idToDelete;
	int indexBici;
	char seguir;

	if(listBicicleta != NULL && tam > 0 && listTipo != NULL && tamTipo > 0)
	{
		system("cls");
		printf("\n\n###### Listado de bicicletas ######\n");
		printf("\n%5s %9s %9s %11s %12s %9s","Codigo", "Marca", "Tipo", "Color", "Material", "Rodado\n");
		PrintAllBicicletas(listBicicleta, tam, listTipo, tamTipo, listColor, tamColor);
		idToDelete = GetInt("\nIngrese el codigo de bicicleta a elminiar: ", "Ingrese el codigo de nuevamente (solo caracteres numericos enteros): ");

		while(!FindBicicleta(listBicicleta, tam, idToDelete, &indexBici))
		{
			printf("/nERROR!!! No se encontro el codigo ingresado.");
			printf("\n\n###### Listado de bicicletas ######\n");
			printf("\n%5s %9s %9s %11s %12s %9s","Codigo", "Marca", "Tipo", "Color", "Material", "Rodado\n");
			PrintAllBicicletas(listBicicleta, tam, listTipo, tamTipo, listColor, tamColor);
			idToDelete = GetInt("\nIngrese el codigo de bicicleta a eliminar: ", "Ingrese el codigo de nuevamente (solo caracteres numericos enteros): ");
		}

		if(idToDelete != -1)
		{
			system("cls");

			printf("\n\n###### Bicicleta encontrada ######\n");
		    printf("\n%5s %9s %9s %11s %12s %9s","Codigo", "Marca", "Tipo", "Color", "Material", "Rodado\n");
			PrintOnlyOneBicicleta(&listBicicleta[indexBici]);
			seguir = GetCharConfirmacion("\nSe ha encontrado la id ingresada, esta seguro de querer continuar con la baja? Ingrese s(si) o n(no): ", "\nReingrese s(si) o n(no): ");

			if(seguir == 's')
			{
				RemoveBicicleta(listBicicleta, tam, indexBici, "\nSe ha eliminado la bicicleta con exito!!!\n");
				system("pause");
			}
			else
			{
				printf("\nUsted ha cancelado la baja de bicicletas\n");
				system("pause");
				system("cls");
			}
		}
	}
}
/*
void SortPassengersByCodeStatus(ePassenger *listPassenger, int tam, eStatus listStatus[], int tamStatus)
{
	ePassenger aux;
	int i;
	int j;

	if(listPassenger != NULL && tam > 0 && listStatus != NULL && tamStatus > 0)
	{
		for(i=0; i<tam-1; i++)
			{
				for(j=i+1; j<tam; j++)
				{
					if(strcmp(listPassenger[i].flyCode, listPassenger[j].flyCode)>0)
					{
						aux = listPassenger[i];
						listPassenger[i] = listPassenger[j];
						listPassenger[j] = aux;
					}
				}
			}
		PrintPassengersByStatusActive(listPassenger, tam, listStatus, tamStatus);
	}
}
*/
int SecondayMenu(eBicicleta *listBicicleta, int tam, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor, eServicio *listServicio, int tamServicio, eTrabajo *listTrabajo, int tamTrabajo)
{
	int userResponse;
	int contadorCarbono = 0;
	int contadorAluminio = 0;
	int contadorTipo = 0;
	int contadorColor = 0;

	if(listBicicleta != NULL && tam > 0 && listTipo != NULL && tamTipo > 0)
	{
		do
			{
				system("cls");
				printf("#### Menu Segundario Listados ###");
				printf("\n\n1-Listado de bicicletas ordenadas por tipo y rodado.\n");
				printf("2-Listado de tipos.\n");
				printf("3-Listado de colores.\n");
				printf("4-Listado de servicios.\n");
				printf("5-Listado de trabajos.\n");
				printf("6-Bicicletas por color ingresado por el usuario.\n");
				printf("7-Bicicletas por tipo ingresado por el usuario.\n");
				printf("8-Mostrar cantidad de bicicletas por mayor material.\n");
				printf("9-Mostrar cantidad de bicicletas por tipo.\n");
				printf("10-Mostrar cantidad de bicicletas por tipo y color.\n");
				printf("12-Salir.\n");

				userResponse = GetIntRange("\nIngrese opcion: ", "Opcion invalida reingrese: \n", 1, 12);

					switch(userResponse)
						{
							case 1:

								system("cls");
								printf("Listado de bicicletas ordenadas por tipo y rodado\n");
								printf("\n%5s %9s %9s %11s %13s %10s","Codigo", "Marca", "Tipo", "Color", "Material", "Rodado\n");
								ListarBicicletasTipoRodado(listBicicleta, tam, listTipo, tamTipo);
								PrintAllBicicletas(listBicicleta, tam, listTipo, tamTipo, listColor, tamColor);
								system("pause");
								system("cls");
								break;

							case 2:
								system("cls");
								printf("Listado de tipos encontrados\n");
								printf("\n%5s %14s","Codigo", "Nombre\n");
								PrintAllTipo(listTipo, tam);
								system("pause");
								system("cls");
								break;

							case 3:
								system("cls");
								printf("Listado de colores encontrados\n");
								printf("\n%5s %14s","Codigo", "Nombre\n");
								PrintAlleColor(listColor, tam);
								system("pause");
								system("cls");
								break;

							case 4:
								system("cls");
								printf("Listado de servicios encontrados\n");
								printf("\n%5s %14s","Codigo", "Nombre\n");
								PrintAlleServicio(listServicio, tamServicio);
								system("pause");
								system("cls");
								break;

							case 5:
								system("cls");
								printf("Listado de trabajos encontrados\n");
								printf("\n%5s %16s %13s %10s","Codigo", "Marca Bicicleta", "Servicio", "Fecha\n");
								PrintAllTrabajo(listTrabajo, tamTrabajo, listBicicleta, tam, listServicio, tamServicio);
								system("pause");
								system("cls");
								break;

							case 6:
								system("cls");
								printf("Bicicletas por color ingresado por el usuario.\n");
								printf("\n%5s %9s %9s %11s %13s %10s","Codigo", "Marca", "Tipo", "Color", "Material", "Rodado\n");
								MostrarBicisColor(listBicicleta, tam, listServicio, tamServicio, listTipo, tamTipo, listColor, tamColor);
								system("pause");
								system("cls");
								break;

							case 7:
								system("cls");
								printf("Listado de trabajos encontrados\n");
								printf("\n%5s %9s %9s %11s %13s %10s","Codigo", "Marca", "Tipo", "Color", "Material", "Rodado\n");
								MostrarBicisTipo(listBicicleta, tam, listServicio, tamServicio, listTipo, tamTipo, listColor, tamColor);
								system("pause");
								system("cls");
								break;

							case 8:
								ContarMaterialBicis(listBicicleta, tam, &contadorCarbono, &contadorAluminio);
								if(contadorCarbono > contadorAluminio)
								{
									printf("Las bicicletas de Carbono son mayoria, siendo un total de: %d\n", contadorCarbono);
									system("pause");
								}
								else if (contadorCarbono < contadorAluminio)
								{
									printf("Las bicicletas de Aluminio son mayoria, siendo un total de: %d\n", contadorAluminio);
									system("pause");
								}
								else
								{
									printf("Existen la misma cantidad de bicicletas tanto de Carbono como de Aluminio:\n");
									system("pause");
								}
								break;

							case 9:
								system("cls");
								printf("Bicicletas por Tipo.\n");
								printf("\n%5s %9s %9s %11s %13s %10s","Codigo", "Marca", "Tipo", "Color", "Material", "Rodado\n");
								BicicletasPorTipo(listBicicleta, tam, listTipo, tamTipo, listColor, tamColor);
								system("pause");
								system("cls");

								break;

							case 10:

								MostrarBicisTipoColor(listBicicleta, tam, listServicio, tamServicio, listTipo, tamTipo, listColor, tamColor, &contadorTipo, &contadorColor);
								printf("La cantidad de bicis tipo encontradas son: %d\n", contadorTipo);
								printf("La cantidad de bicis de color encontradas son: %d\n", contadorColor);
								system("pause");
								break;

							case 11:

								break;

						}
		}while(userResponse !=12);

		if(userResponse == 12 || userResponse > 12)
			userResponse = -1;
	}

	return userResponse;
}

void ListarBicicletasTipoRodado(eBicicleta *listBici, int tam, eTipo *listTipo, int tamStatus)
{
	eBicicleta auxBici;
	int i;
	int j;

	if(listBici != NULL && tam > 0 && listTipo != NULL && tamStatus > 0)
	{
		for(i=0; i<tam-1; i++)
		{
			for(j=i+1; j<tam; j++)
			{
				if(listBici[i].isEmpty == FALSE && listBici[j].isEmpty == FALSE)
				{
					if(listBici[i].idTipo > listBici[j].idTipo)
					{
						auxBici = listBici[i];
						listBici[i] = listBici[j];
						listBici[j] = auxBici;
					}
					else
					{
						if((listBici[i].idTipo > listBici[j].idTipo) && (listBici[i].rodado > listBici[j].rodado))
							{
								auxBici = listBici[i];
								listBici[i] = listBici[j];
								listBici[j] = auxBici;
							}
					}
				}
			}
		}
	}
}

/*
void SortPassengersByCode(ePassenger *listPassenger, int tam, int response, eStatus listStatus[], int tamStatus)
{
	ePassenger auxPassenger;
	int i;
	int j;

	if(listPassenger != NULL && tam > 0 && listStatus != NULL && tamStatus > 0)
	{

		for(i=0; i<tam-1; i++)
		{
			for(j=i+1; j<tam; j++)
			{
				if(response == 1)
				{
					if(strcmp(listPassenger[i].lastName, listPassenger[j].lastName)<0)
					{
						auxPassenger = listPassenger[i];
						listPassenger[i] = listPassenger[j];
						listPassenger[j] = auxPassenger;

					}
					else
					{
						if((strcmp(listPassenger[i].lastName, listPassenger[j].lastName)<0) && (listPassenger[i].typePassenger > listPassenger[j].typePassenger))
							{
								{
									auxPassenger = listPassenger[i];
									listPassenger[i] = listPassenger[j];
									listPassenger[j] = auxPassenger;
								}
							}
					}
				}

			}
		}
		PrintAllPassenger(listPassenger, tam, listStatus, tamStatus);
	}
}
*/

void AddOneTrabajo(eTrabajo *listTrabajo, int tam, eBicicleta *listBicicleta, int tamBici, int idTrabajo, eServicio *listServicio, int tamServicio, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor)
{
		int i;
		i = FindFreeIndexeTrabajo(listTrabajo, tam);

		if(i != -1 && listTrabajo != NULL && listServicio != NULL && tam > 0 && tamServicio > 0)
		{
			listTrabajo[i] = AddTrabajos(idTrabajo, listBicicleta, tamBici, listServicio, tamServicio, listTipo, tamTipo, listColor, tamColor);
			if(listTrabajo[i].isEmpty == FALSE)
			{
				printf("\nTrabajo cargado con exito!!\n\n");
				system("pause");
				system("cls");
			}
		}
		else
		{
			 printf("\nNo existe espacio disponible para la carga de datos\n\n");
			 system("pause");
			 system("cls");
		}
}

eTrabajo AddTrabajos(int idTrabajo, eBicicleta *listBicicleta, int tamBici, eServicio *listServicio, int tamServicio, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor)
{
	eTrabajo AddedTrabajo;
	int auxBici;
	int auxServi;
	int auxIndex;
	int auxIndexServi;

	if(listBicicleta != NULL && tamBici > 0)
	{
		system("cls");
		printf("\n%5s %9s %9s %11s %13s %10s","Codigo", "Marca", "Tipo", "Color", "Material", "Rodado\n");
		ListarBicicletasPorId(listBicicleta, tamBici);
		PrintAllBicicletas(listBicicleta, tamBici, listTipo, tamTipo, listColor, tamColor);
		auxBici = GetInt("\nIngrese el codigo de bicicleta : ", "\nIngrese el codigo de nuevamente (solo caracteres numericos enteros): ");

		while(!FindBicicleta(listBicicleta, tamBici, auxBici, &auxIndex))
		{
			system("cls");
			printf("ERROR!!! No se ha encontrado el codigo ingresado.");
			printf("\n\n###### Bicicletas encontradas ######\n");
			printf("\n%5s %9s %9s %11s %13s %10s","Codigo", "Marca", "Tipo", "Color", "Material", "Rodado\n");
			PrintAllBicicletas(listBicicleta, tamBici, listTipo, tamTipo, listColor, tamColor);
			auxBici = GetInt("\nReingrese el codigo de bicicleta : ", "\nIngrese el codigo de bicicleta nuevamente (solo caracteres numericos enteros): ");
		}
		system("cls");

		AddedTrabajo.idBicicleta = auxBici;

		printf("Listado de servicios\n");
		printf("\n%5s %12s","Codigo", "Nombre\n");
		PrintAlleServicio(listServicio, tamServicio);
		auxServi = GetInt("\nIngrese el codigo del servicio : ", "\nIngrese el codigo de servicio nuevamente (solo caracteres numericos enteros): ");

		while(!FindeServicio(listServicio, tamServicio, auxServi, &auxIndexServi))
		{
			system("cls");
			printf("ERROR!!! No se ha encontrado el servicio ingresado.");
			printf("Listado de servicios\n");
			printf("\n%5s %12s","Codigo", "Nombre\n");
			PrintAlleServicio(listServicio, tamServicio);
			auxServi = GetInt("\nReingrese el codigo: ", "\nIngrese el codigo de servicio nuevamente (solo caracteres numericos enteros): ");
		}
		AddedTrabajo.idServicio = auxServi;
		AddedTrabajo.fecha.dia = GetIntRange("\nIngrese el dia", "Reingrese el dia", 1, 31);
		AddedTrabajo.fecha.mes = GetIntRange("Ingrese el mes", "Reingrese el mes", 1, 12);
		AddedTrabajo.fecha.anio = GetIntRange("Ingrese el anio", "Reingrese el anio", 0, 2021);

		AddedTrabajo.id = idTrabajo;
		AddedTrabajo.isEmpty = FALSE;
	}
		return AddedTrabajo;
}

void PrintAllTrabajo(eTrabajo *listTrabajo, int tam, eBicicleta *listBici, int tamBici, eServicio *listServicio, int tamServicio)
{
	if(listTrabajo != NULL && listBici != NULL && tam > 0 && tamBici > 0)
	{
		for(int i=0; i<tam; i++)
		{
			for(int j=0; j<tamBici; j++)
			{
				if(listTrabajo[i].isEmpty == FALSE && listTrabajo[i].idBicicleta == listBici[j].id)
				{
					for(int k = 0; k< tamServicio; k++)
					{
						if(listBici[j].isEmpty == FALSE && listTrabajo[i].idServicio == listServicio[k].id)
						{
							PrintOneTrabajo(&listTrabajo[i], &listBici[j], &listServicio[k]);
						}
					}
				}
			}
		}
	}
}

void PrintOneTrabajo(eTrabajo *listTrabajo, eBicicleta *listBici, eServicio *listServicio)
{
	if(listTrabajo != NULL)
	{
		printf("\n*%4d %11s %18s %6d/%d/%d\n", listTrabajo->id,
											   listBici->marca,
											   listServicio->descripcion,
											   listTrabajo->fecha.dia,
											   listTrabajo->fecha.mes,
											   listTrabajo->fecha.anio);
	}
}

int MostrarBicisColor(eBicicleta *listBicicleta, int tamBici, eServicio *listServicio, int tamServicio, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor)
{
    int todoOk = 0;
    int auxColor;
    int auxIndexColor;

    if( listBicicleta != NULL && tamBici > 0 && listServicio != NULL && tamServicio > 0)
    {
        system("cls");
        printf("\n%5s %14s","Codigo", "Nombre\n");
        PrintAlleColor(listColor, tamColor);

        // validar si existe ese id sector
        auxColor = GetInt("\nIngrese el codigo del COLOR a mostrar : ", "\nIngrese el codigo de color nuevamente (solo caracteres numericos enteros): ");

        while(!FindeColor(listColor, tamColor, auxColor, &auxIndexColor))
        {
        	system("cls");
        	printf("ERROR!!! No se ha encontrado el codigo ingresado.\n\n");
        	printf("Listado de colores\n");
        	printf("\n%5s %14s","Codigo", "Nombre\n");
        	PrintAlleColor(listColor, tamColor);
        	auxColor = GetInt("\nReigrese el codigo: ", "\nIngrese el codigo de color nuevamente (solo caracteres numericos enteros): ");
        }

        system("cls");
        printf("\n%5s %9s %9s %11s %13s %10s","Codigo", "Marca", "Tipo", "Color", "Material", "Rodado\n");
        PrintAllBicicletasColor(listBicicleta, tamBici, listTipo, tamTipo, listColor, tamColor, auxColor);

        todoOk = 1;
    }
    return todoOk;
}

int MostrarBicisTipo(eBicicleta *listBicicleta, int tamBici, eServicio *listServicio, int tamServicio, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor)
{
    int todoOk = 0;
    int auxTipo;
    int auxIndexTipo;

    if( listBicicleta != NULL && tamBici > 0 && listServicio != NULL && tamServicio > 0)
    {
        system("cls");
        printf("\n%5s %14s","Codigo", "Nombre\n");
        PrintAllTipo(listTipo, tamTipo);

       auxTipo = GetInt("\nIngrese el codigo del TIPO a mostrar : ", "\nIngrese el codigo de TIPO nuevamente (solo caracteres numericos enteros): ");

        while(!FindTipo(listTipo, tamTipo, auxTipo, &auxIndexTipo))
        {
        	system("cls");
        	printf("ERROR!!! No se ha encontrado el codigo ingresado.\n\n");
        	printf("Listado de Tipos\n");
        	printf("\n%5s %14s","Codigo", "Nombre\n");
        	PrintAllTipo(listTipo, tamTipo);
        	auxTipo = GetInt("\nReigrese el codigo: ", "\nIngrese el codigo de color nuevamente (solo caracteres numericos enteros): ");
        }

        system("cls");
        printf("\n%5s %9s %9s %11s %13s %10s","Codigo", "Marca", "Tipo", "Color", "Material", "Rodado\n");
        PrintAllBicicletasTipo(listBicicleta, tamBici, listTipo, tamTipo, listColor, tamColor, auxTipo);

        todoOk = 1;
    }
    return todoOk;
}


void ContarMaterialBicis(eBicicleta *listBicicleta, int tamBici, int *contadorCarbono, int *contadorAluminio)
{
	if(listBicicleta != NULL && tamBici > 0 && contadorCarbono != NULL && contadorAluminio != NULL)
	{
		for(int i; i < tamBici; i++)
		{
			if(listBicicleta[i].material == 'c')
			{
				contadorCarbono++;
			}
			else
			{
				contadorAluminio++;
			}
		}
	}
}


int MostrarBicisTipoColor(eBicicleta *listBicicleta, int tamBici, eServicio *listServicio, int tamServicio, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor, int *contadorTipo, int *contadorColor)
{
    int todoOk = 0;
    int auxTipo;
    int auxIndexTipo;
    int auxColor;
    int auxIndexColor;

    if( listBicicleta != NULL && tamBici > 0 && listServicio != NULL && tamServicio > 0)
    {
        system("cls");
        printf("\n%5s %14s","Codigo", "Nombre\n");
        PrintAllTipo(listTipo, tamTipo);

       auxTipo = GetInt("\nIngrese el codigo del TIPO a mostrar : ", "\nIngrese el codigo de TIPO nuevamente (solo caracteres numericos enteros): ");

        while(!FindTipo(listTipo, tamTipo, auxTipo, &auxIndexTipo))
        {
        	system("cls");
        	printf("ERROR!!! No se ha encontrado el codigo ingresado.\n\n");
        	printf("Listado de Tipos\n");
        	printf("\n%5s %14s","Codigo", "Nombre\n");
        	PrintAllTipo(listTipo, tamTipo);
        	auxTipo = GetInt("\nReigrese el codigo: ", "\nIngrese el codigo de color nuevamente (solo caracteres numericos enteros): ");
        }

        system("cls");
               printf("\n%5s %14s","Codigo", "Nombre\n");
               PrintAlleColor(listColor, tamColor);

               // validar si existe ese id sector
               auxColor = GetInt("\nIngrese el codigo del COLOR a mostrar : ", "\nIngrese el codigo de color nuevamente (solo caracteres numericos enteros): ");

               while(!FindeColor(listColor, tamColor, auxColor, &auxIndexColor))
               {
               	system("cls");
               	printf("ERROR!!! No se ha encontrado el codigo ingresado.\n\n");
               	printf("Listado de colores\n");
               	printf("\n%5s %14s","Codigo", "Nombre\n");
               	PrintAlleColor(listColor, tamColor);
               	auxColor = GetInt("\nReigrese el codigo: ", "\nIngrese el codigo de color nuevamente (solo caracteres numericos enteros): ");
               }

				ContarAllBicicletasTipoColor(listBicicleta, tamBici, listTipo, tamTipo, listColor, tamColor, auxTipo, contadorTipo, auxColor, contadorColor);

        todoOk = 1;
    }
    return todoOk;
}


void MostrarTrabajosPorBicis(eBicicleta *listBicicleta, int tamBici, eServicio *listServicio, int tamServicio, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor)
{
	int auxBici;
	int auxIndex;

	if(listBicicleta != NULL && tamBici > 0)
		{
			system("cls");
			printf("\n%5s %9s %9s %11s %13s %10s","Codigo", "Marca", "Tipo", "Color", "Material", "Rodado\n");
			ListarBicicletasPorId(listBicicleta, tamBici);
			PrintAllBicicletas(listBicicleta, tamBici, listTipo, tamTipo, listColor, tamColor);
			auxBici = GetInt("\nIngrese el codigo de bicicleta : ", "\nIngrese el codigo de nuevamente (solo caracteres numericos enteros): ");

			while(!FindBicicleta(listBicicleta, tamBici, auxBici, &auxIndex))
			{
				system("cls");
				printf("ERROR!!! No se ha encontrado el codigo ingresado.");
				printf("\n\n###### Bicicletas encontradas ######\n");
				printf("\n%5s %9s %9s %11s %13s %10s","Codigo", "Marca", "Tipo", "Color", "Material", "Rodado\n");
				PrintAllBicicletas(listBicicleta, tamBici, listTipo, tamTipo, listColor, tamColor);
				auxBici = GetInt("\nReingrese el codigo de bicicleta : ", "\nIngrese el codigo de bicicleta nuevamente (solo caracteres numericos enteros): ");
			}
			system("cls");
		}
}

