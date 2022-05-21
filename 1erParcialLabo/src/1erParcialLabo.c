#include <stdio.h>
#include <stdlib.h>

#include "Anexo_Struct.h"

int main(void)
{
	setbuf(stdout,NULL);

		int seguir;
		int continuar;
		int Flag = 0;
		int idIncremental = 0;
		int idIncrementalTrabajo = 99;

		eBicicleta listBicicleta[SIZE];
		eServicio listServicio[SIZE];
		eTipo listTipo[SIZE];
		eColor listColor[SIZE];
		eTrabajo listTrabajo[SIZE];

		InitBicicleta(listBicicleta, SIZE);
		InitServicio(listServicio, SIZE);
		InitSTipo(listTipo, SIZE);
		InitColor(listColor, SIZE);
		InitTrabajo(listTrabajo, SIZE);

		ForceColor(listColor, 5);
		ForceServicio(listServicio, 4);
		ForceTipo(listTipo, 4);
		ForceBicicleta(listBicicleta, 4, &idIncremental, &Flag);

		do
			{
				system("cls");
				printf("#### Menu de Ingresos ###");
				printf("\n\n1-Ingreso nuevas bicicletas.\n");
				printf("2-Modificar bicicletas existentes.\n");
				printf("3-Eliminar bicicletas existentes.\n");
				printf("4-Menu listados.\n");
				printf("5-Cargar Trabajo.\n");
				printf("6-Salir.\n");
				fflush(stdin);
				seguir = GetIntRange("\nIngrese una opcion ", "\nOpcion incorrecta, reingrese ", 1, 6);

				switch(seguir)
				{
					case 1:
						system("cls");
						addOneBicicletas(listBicicleta, SIZE, eGen_ObtenerID(idIncremental), listTipo, 4, listColor, 5);
						Flag = 1;
						idIncremental++;

					    	break;

					case 2:

						if(Flag != 0)
						{
							ModifyBicicletas(listBicicleta, SIZE, listTipo, 4, listColor, 5);
							system("cls");
						}
						else
						{
							printf("\nTiene que existir una bicicleta cargada para poder acceder a esta opcion.\n\n");
							system("pause");
							system("cls");
						}
					    	break;

					case 3:

						if(Flag != 0)
						{
							system("cls");
							DeleteBicicletas(listBicicleta, SIZE, listTipo, 4, listColor, 5);
							system("cls");
						}
						else
						{
							printf("\nTiene que existir una bicicleta cargada para poder acceder a esta opcion.\n\n");
							system("pause");
							system("cls");
						}
					    	break;

					case 4:

					if(Flag != 0)
					{
						continuar = SecondayMenu(listBicicleta, SIZE, listTipo, 4, listColor, 5, listServicio, 4, listTrabajo, SIZE);

						if(continuar == -1)
						{
							printf("\nSera redireccionado al menu principal\n\n");
							system("pause");
							system("cls");
						}
					}
					else
					{
						printf("\nTiene que existir una bicicleta cargada para poder acceder a esta opcion.\n\n");
						system("pause");
						system("cls");
					}
				    	break;

					case 5:

					if(Flag != 0)
					{
						AddOneTrabajo(listTrabajo, SIZE_STRING, listBicicleta, SIZE_STRING, eGen_ObtenerID(idIncrementalTrabajo), listServicio, 4, listTipo, 4, listColor, 5);
						idIncrementalTrabajo++;
						system("cls");
					}
					else
					{
						printf("\nTiene que existir una bicicleta cargada para poder acceder a esta opcion.\n\n");
						system("pause");
						system("cls");
					}
			            break;
				}
			}while(seguir != 6);
}
