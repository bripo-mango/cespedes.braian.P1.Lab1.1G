
#ifndef ANEXO_STRUCT_H_
#define ANEXO_STRUCT_H_

#define TRUE 1
#define FALSE 0
#define TAMA 70
#define SIZE 2000
#define STATUS_SIZE 3
#define SIZE_STRING 20

#include "eTipo.h"
#include "eBicicleta.h"
#include "Funciones_Genericas.h"
#include "eTipo.h"
#include "eServicio.h"
#include "eTrabajo.h"
#include "eColor.h"

void PrintAllBicicletas(eBicicleta *listBicicleta, int tam, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor);
void PrintOneBicicletaTipoColor(eBicicleta *listBicicleta, eTipo *listTipo, eColor *listColor);
//void PrintPassengersByStatusActive(eBicicleta *listBicicleta, int tam, eStatus *listStatus, int tamStatus);
void addOneBicicletas(eBicicleta *listBicicleta, int tam, int idBicicleta, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor);
eBicicleta AddBicicletas(int idPassenger, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor);
void ModifyBicicletas(eBicicleta *listBicicleta, int tam, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor);
void DeleteBicicletas(eBicicleta *listBicicleta, int tam, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor);
//void SortPassengersByCodeStatus(eBicicleta *listBicicleta, int tam, eStatus listStatus[], int tamStatus);
int SecondayMenu(eBicicleta *listBicicleta, int tam, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor, eServicio *listServicio, int tamServicio, eTrabajo *listTrabajo, int tamTrabajo);
//void SortPassengersByCode(eBicicleta *listBicicleta, int tam, int response, eStatus listStatus[], int tamStatus);

void addOneTrabajo(eTrabajo *listTrabajo, int tam, eBicicleta *listBicicleta, int tamBici, int idTrabajo, eServicio *listServicio, int tamServicio, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor);
eTrabajo AddTrabajos(int idTrabajo, eBicicleta *listBicicleta, int tamBici, eServicio *listServicio, int tamServicio, eTipo *listTipo, int tamTipo, eColor *listColor, int tamColor);
void PrintOneTrabajo(eTrabajo *listTrabajo, eBicicleta *listBici, eServicio *listServicio);
void PrintAllTrabajo(eTrabajo *listTrabajo, int tam, eBicicleta *listBici, int tamBici, eServicio *listServicio, int tamServicio);



#endif /* ANEXO_STRUCT_H_ */
