
#ifndef ETRABAJO_H_
#define ETRABAJO_H_
#define SIZE_STRING 20

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int id;
	int idBicicleta;
	int idServicio;
	eFecha fecha;
	int isEmpty;

}eTrabajo;



void InitTrabajo(eTrabajo *listTrabajo, int tam);
void ForceTrabajo(eTrabajo *listTrabajo, int tam);
int FindTrabajo(eTrabajo *listTrabajo, int tam, int id, int* pIndex);
int FindFreeIndexeTrabajo(eTrabajo *listaTrabajo, int tam);

#endif /* ETRABAJO_H_ */
