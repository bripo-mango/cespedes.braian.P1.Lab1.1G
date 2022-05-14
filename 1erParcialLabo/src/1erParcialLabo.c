#include <stdio.h>
#include <stdlib.h>

#include "Anexo_Struct.h"

int main(void)
{
	setbuf(stdout,NULL);

		int seguir;
		int continuar;
		int Flag = 0;


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

		//ForcePassengers(listPassenger, &IdPassenger, 4, pFlag);
		do
			{
				system("cls");
				printf("#### Menu de Ingresos ###");
				printf("\n\n1-Ingreso nuevas bicicletas.\n");
				printf("2-Modificar bicis existentes.\n");
				printf("3-Eliminar bicis existentes.\n");
				printf("4-Informar bicis existentes.\n");
				printf("5-Cargar Trabajo.\n");
				printf("6-Salir.\n");
				fflush(stdin);
				seguir = GetIntRange("\nIngrese una opcion ", "\nOpcion incorrecta, reingrese ", 1, 6);

				switch(seguir)
				{
					case 1:
						system("cls");
						addOneBicicletas(listBicicleta, SIZE, eGen_ObtenerID(0), listTipo, 4, listColor, 4);
						Flag = 1;

					    	break;

					case 2:

						if(Flag != 0)
						{
							ModifyBicicletas(listBicicleta, SIZE, listTipo, 4, listColor, 4);
							system("cls");
						}
						else
						{
							printf("\nTiene que haber una bicicleta cargada para poder acceder a esta opcion.\n\n");
							system("pause");
							system("cls");
						}
					    	break;

					case 3:

						if(Flag != 0)
						{
							system("cls");
							DeleteBicicletas(listBicicleta, SIZE, listTipo, 4, listColor, 4);
							system("cls");
						}
						else
						{
							printf("\nTiene que haber un pasajero registrado para poder acceder a esta opcion.\n\n");
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
						printf("\nTiene que haber un pasajero registrado para poder acceder a esta opcion.\n\n");
						system("pause");
						system("cls");
					}
				    	break;

					case 5:
						AddTrabajos(eGen_ObtenerID(99), listBicicleta, SIZE, listServicio, 4, listTipo, 4, listColor, 5);
						system("cls");
			            break;
				}
			}while(seguir != 6);
}
