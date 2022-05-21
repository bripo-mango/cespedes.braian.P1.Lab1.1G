
#ifndef EBICICLETA_H_
#define EBICICLETA_H_

#define TRUE 1
#define FALSE 0
#define TAMA 70
#define SIZE 2000
#define STATUS_SIZE 3
#define SIZE_STRING 20

typedef struct
{
	int id;
	char marca[SIZE_STRING];
	char material;
	int idColor;
	int idTipo;
	int idCliente;
	int rodado;
	int isEmpty;
}eBicicleta;

void InitBicicleta(eBicicleta *listaBicileta, int tam);
void ForceBicicleta(eBicicleta *listaBicileta, int tam, int *pId, int *pFlag);

void PrintOnlyOneBicicleta(eBicicleta *listaBicileta);
int FindBicicleta(eBicicleta *listaBicileta, int tam, int id, int* pIndex);
int FindBicicletaId(eBicicleta *listaBicileta, int tam, int id);
int FindFreeIndexeBicicleta(eBicicleta *listaBicileta, int tam);
void RemoveBicicleta(eBicicleta *listaBicileta, int tam, int index, char *mensaje);
int ListarBicicletasPorId(eBicicleta *listBici, int tam);

/*
float PricesPlus(eBicicleta *listaBicileta, int tam);
float AveragePrice(eBicicleta *listaBicileta, int tam);
int CountPassenger(eBicicleta *listaBicileta, int tam);
int ShowAveragePassenger(eBicicleta *listaBicileta, int tam);
*/

#endif /* EBICICLETA_H_ */
