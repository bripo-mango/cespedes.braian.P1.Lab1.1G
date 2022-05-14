

#ifndef ETIPO_H_
#define ETIPO_H_

typedef struct
{
	int idStatus;
	char description[TAMA];
	int isEmpty;
}eTipo;

void InitSTipo(eTipo *listTipo, int tam);
void ForceTipo(eTipo *listTipo, int tam);
void PrintAllTipo(eTipo *listTipo, int tam);
int FindTipo(eTipo *listTipo, int tam, int id, int* pIndex);
void PrintOneTipo(eTipo *listTipo);

#endif /* ETIPO_H_ */
