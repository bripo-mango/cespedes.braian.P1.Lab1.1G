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
						if(listBicicleta[i].isEmpty == FALSE && listBicicleta[i].idColor == listColor[j].idStatus)
						{
							PrintOneBicicletaTipoColor(&listBicicleta[i], &listTipo[j], &listColor[k]);
						}
					}
				}
			}
		}
	}
}

void PrintOneBicicletaTipoColor(eBicicleta *listBicicleta, eTipo *listTipo, eColor *listColor)
{

		printf("\n*%2d %12s %12s %12s %2c %4d\n\n", listBicicleta->id,
													listBicicleta->marca,
													listTipo->description,
													listColor->description,
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
		PrintAllTipo(listTipo, tamTipo);
		auxType = GetInt("\nIngrese el codigo del tipo : ", "\nIngrese el codigo de nuevamente (solo caracteres numericos enteros): ");

		while(!FindTipo(listTipo, tamTipo, auxType, &auxIndex))
		{
			printf("/nERROR!!! No se ha encontrado el codigo ingresado.");
			PrintAllTipo(listTipo, tamTipo);
			auxType = GetInt("\nReigrese el codigo del estado de vuelo: ", "\nIngrese el codigo de tipo nuevamente (solo caracteres numericos enteros): ");
		}

		AddedBicicletas.idTipo = auxType;

		PrintAlleColor(listColor, tamColor);
		auxColor = GetInt("\nIngrese el codigo del COLOR : ", "\nIngrese el codigo de color nuevamente (solo caracteres numericos enteros): ");

		while(!FindeColor(listColor, tamColor, auxType, &auxIndexColor))
		{
			printf("/nERROR!!! No se ha encontrado el codigo ingresado.");
			PrintAlleColor(listColor, tamColor);
			auxColor = GetInt("\nReigrese el codigo: ", "\nIngrese el codigo de color nuevamente (solo caracteres numericos enteros): ");
		}

		AddedBicicletas.idColor = auxColor;

		AddedBicicletas.material = GetChar("Ingrese el material Carbono(c)/Aluminio(a)", "Error, reingrese el material Carbono(c)/Aluminio(a)");

		AddedBicicletas.id = idBicicleta;

		AddedBicicletas.rodado = GetIntRange("Ingrese el rodado 20 hasta 40", "Reigrese el rodado 20 hasta 40", 11, 29);

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
		printf("\n\n###### Listado de pasajeros encontrados ######\n");
		printf("\n%5s %9s %13s %11s %17s %14s %10s","Codigo", "Nombre", "Apellido", "Precio", "Estado Vuelo", "Codigo Vuelo", "Tipo\n");
		PrintAllBicicletas(listBicicleta, tam, listTipo, tamTipo, listColor, tamColor);
		idUser = GetInt("\nIngrese el codigo de bicicleta de la siguiente lista: ", "Codigo no encontrado, Reingrese el codigo nuevamente: ");
		while(!FindBicicleta(listBicicleta, tam, idUser, &indexBici))
			{
				printf("/nERROR!!! No se encontro el ID ingresado.");
				PrintAllBicicletas(listBicicleta, tam, listTipo, tamTipo, listColor, tamColor);
				idUser = GetInt("\nIngrese el codigo de pasajero de la siguiente lista", "Codigo no encontrado, Reingrese el codigo nuevamente: ");
			}

		if(indexBici != -1)
		{
		  system("cls");
		  printf("\n%5s %9s %13s %11s %17s %14s %10s","Codigo", "Nombre", "Apellido", "Precio", "Estado Vuelo", "Codigo Vuelo", "Tipo\n");
		  PrintOnlyOneBicicleta(&listBicicleta[indexBici]);

		  option = GetIntRange("\nSe ha encontrado la Id ingresada !!\n\nQue desea modificar? \n\n1-Tipo\n\n2-Rodado\n\n\n3-Salir\n\nIngrese una opcion: ", "Usted ha ingresado una opcion incorrecta, reingrese: ", 1, 3);
		  switch(option)
			{
				case 1:

					PrintAllTipo(listTipo, tamTipo);
					auxType = GetInt("\nIngrese el codigo del tipo : ", "\nIngrese el codigo de nuevamente (solo caracteres numericos enteros): ");

					while(!FindTipo(listTipo, tamTipo, auxType, &auxIndexTipo))
					{
						printf("/nERROR!!! No se ha encontrado el codigo ingresado.");
						PrintAllTipo(listTipo, tamTipo);
						auxType = GetInt("\nReigrese el codigo del estado de vuelo: ", "\nIngrese el codigo de tipo nuevamente (solo caracteres numericos enteros): ");
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

					auxRodado = GetIntRange("\nIngrese el tipo de pasajero (0 = Extranjero // 1 = Argentino): ", "\nReingrese el tipo de pasajero (0 = Extranjero // 1 = Argentino): ", 0, 1);

					seguir = GetChar("\nEsta seguro de querer continuar? Ingrese 's' para continuar o 'n' para cancelar: ", "Ingrese 's' para continuar o 'n' para cancelar la modificacion: ");

					 if(seguir == 's')
					 {
						 listBicicleta[indexBici].rodado = auxRodado;
						printf("\nEl rodado se ha modificado con exito\n");
						system("pause");
						system("cls");
					 }
					 else
					 {
						printf("\nSe ha cancelado la modificacion del tipo de rodado\n");
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
		printf("\n\n### Pasajeros encontrados ###\n");
		printf("\n%5s %9s %13s %11s %17s %14s %10s","Codigo", "Nombre", "Apellido", "Precio", "Estado Vuelo", "Codigo Vuelo", "Tipo\n");
		PrintAllBicicletas(listBicicleta, tam, listTipo, tamTipo, listColor, tamColor);
		idToDelete = GetInt("\nIngrese el codigo del pasajero a elminiar: ", "Ingrese el codigo de nuevamente (solo caracteres numericos enteros): ");

		while(!FindBicicleta(listBicicleta, tam, idToDelete, &indexBici))
		{
			printf("/nERROR!!! No se encontro el codigo ingresado.");
			PrintAllBicicletas(listBicicleta, tam, listTipo, tamTipo, listColor, tamColor);
			idToDelete = GetInt("\nIngrese el codigo del pasajero a eliminar: ", "Ingrese el codigo de nuevamente (solo caracteres numericos enteros): ");
		}

		if(idToDelete != -1)
		{
			system("cls");

			printf("\n\nBici encontrada\n");
			printf("\n%5s %9s %13s %11s %17s %14s %10s","Codigo", "Nombre", "Apellido", "Precio", "Estado Vuelo", "Codigo Vuelo", "Tipo\n");
			PrintOnlyOneBicicleta(&listBicicleta[indexBici]);
			seguir = GetChar("\nSe ha encontrado la id ingresada, esta seguro de querer continuar con la baja? Ingrese s(si) o n(no): ", "\nReingrese s(si) o n(no): ");

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

	if(listBicicleta != NULL && tam > 0 && listTipo != NULL && tamTipo > 0)
	{

		do
			{
				system("cls");
				printf("#### Menu Segundario Bicicletas ###");
				printf("\n\n1-Listado de bicicletas ordenadas por tipo y rodado.\n");
				printf("2-Listado de tipos.\n");
				printf("3-Listado de colores.\n");
				printf("4-Listado de servicios.\n");
				printf("5-Listado de trabajos.\n");
				printf("6-Salir.\n");

				userResponse = GetIntRange("\nIngrese opcion: ", "Opcion invalida reingrese: \n", 1, 6);

					switch(userResponse)
						{

							case 2:
								system("cls");
								printf("Listado de tipos encontrados\n");
								printf("\n%5s %9s %13s %11s %17s %14s %10s","Codigo", "Nombre", "Apellido", "Precio", "Estado Vuelo", "Codigo Vuelo", "Tipo\n");
								PrintAllTipo(listTipo, tam);
								system("pause");
								system("cls");
								break;

							case 3:
								system("cls");
								printf("Listado de colores encontrados\n");
								printf("\n%5s %9s %13s %11s %17s %14s %10s","Codigo", "Nombre", "Apellido", "Precio", "Estado Vuelo", "Codigo Vuelo", "Tipo\n");
								PrintAlleColor(listColor, tam);
								system("pause");
								system("cls");
								break;

							case 4:
								system("cls");
								printf("Listado de servicios encontrados\n");
								PrintAlleServicio(listServicio, tamServicio);
								break;

							case 5:
								system("cls");
								printf("Listado de trabajos encontrados\n");
								PrintAllTrabajo(listTrabajo, tamTrabajo, listBicicleta, tam, listServicio, tamServicio);
								break;
						}
		}while(userResponse !=4);

		if(userResponse == 3 || userResponse > 3)
			userResponse = -1;
	}

	return userResponse;
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
				else
				{
					if(strcmp(listPassenger[i].lastName, listPassenger[j].lastName)>0)
							{
								auxPassenger = listPassenger[i];
								listPassenger[i] = listPassenger[j];
								listPassenger[j] = auxPassenger;

							}
							else
							{
								if((strcmp(listPassenger[i].lastName, listPassenger[j].lastName)>0) && (listPassenger[i].typePassenger > listPassenger[j].typePassenger))
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


void addOneTrabajo(eTrabajo *listTrabajo, int tam, eBicicleta *listBicicleta, int tamBici, int idTrabajo, eServicio *listServicio, int tamServicio, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor)
{
		int i;
		i = FindFreeIndexeTrabajo(listTrabajo, tam);

		if(i != -1 && listBicicleta != NULL && listServicio != NULL && tam > 0 && tamServicio > 0)
		{
			listTrabajo[i] = AddTrabajos(idTrabajo, listBicicleta, tamBici, listServicio, tamServicio, listTipo, tamTipo, listColor, tamColor);
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

eTrabajo AddTrabajos(int idTrabajo, eBicicleta *listBicicleta, int tamBici, eServicio *listServicio, int tamServicio, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor)
{
	eTrabajo AddedTrabajo;
	int auxBici;
	int auxServi;
	int auxIndex;
	int auxIndexServi;

	if(listBicicleta != NULL && tamBici > 0)
	{
		PrintAllBicicletas(listBicicleta, tamBici, listTipo, tamTipo, listColor, tamColor);
		auxBici = GetInt("\nIngrese el codigo de bicicleta : ", "\nIngrese el codigo de nuevamente (solo caracteres numericos enteros): ");

		while(!FindBicicleta(listBicicleta, tamBici, auxBici, &auxIndex))
		{
			printf("/nERROR!!! No se ha encontrado el codigo ingresado.");
			PrintAllTipo(listTipo, tamTipo);
			auxBici = GetInt("\nReigrese el codigo de bicicleta : ", "\nIngrese el codigo de bicicleta nuevamente (solo caracteres numericos enteros): ");
		}

		AddedTrabajo.idBicicleta = auxBici;

		PrintAlleServicio(listServicio, tamServicio);
		auxServi = GetInt("\nIngrese el codigo del servicio : ", "\nIngrese el codigo de servicio nuevamente (solo caracteres numericos enteros): ");

		while(!FindeServicio(listServicio, tamServicio, auxServi, &auxIndexServi))
		{
			printf("/nERROR!!! No se ha encontrado el servicio ingresado.");
			PrintAlleColor(listColor, tamColor);
			auxServi = GetInt("\nReigrese el codigo: ", "\nIngrese el codigo de color nuevamente (solo caracteres numericos enteros): ");
		}

		AddedTrabajo.fecha.dia = GetIntRange("Ingrese el dia", "Reingrese el dia", 1, 31);
		AddedTrabajo.fecha.mes = GetIntRange("Ingrese el mes", "Reingrese el mes", 1, 12);
		AddedTrabajo.fecha.anio = GetIntRange("Ingrese el anio", "Reingrese el anio", 0, 2021);

		AddedTrabajo.idServicio = auxServi;

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
						if(listTrabajo[i].isEmpty == FALSE && listTrabajo[i].idServicio == listServicio[j].id)
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
		printf("\n*%4d %4d %9s %d/%d/%d\n", listTrabajo->id,
											listBici->id,
											listServicio->descripcion,
											listTrabajo->fecha.dia,
											listTrabajo->fecha.mes,
											listTrabajo->fecha.anio);
	}
}
