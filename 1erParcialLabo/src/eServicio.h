

#ifndef ESERVICIO_H_
#define ESERVICIO_H_

typedef struct
{
	int id;
	char descripcion[SIZE_STRING];
	float precio;
	int isEmpty;
}eServicio;

void InitServicio(eServicio *listServicio, int tam);
void ForceServicio(eServicio *listServicio, int tam);
void PrintAlleServicio(eServicio *listServicio, int tam);
int FindeServicio(eServicio *listServicio, int tam, int id, int* pIndex);
void PrintOneServicio(eServicio *listServicio);

#endif /* ESERVICIO_H_ */
