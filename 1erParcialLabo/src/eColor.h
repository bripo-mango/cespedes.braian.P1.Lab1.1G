
#ifndef ECOLOR_H_
#define ECOLOR_H_

#endif /* ECOLOR_H_ */

typedef struct
{
	int idStatus;
	char description[SIZE_STRING];
	int isEmpty;
}eColor;

void InitColor(eColor *listColor, int tam);
void ForceColor(eColor *listColor, int tam);
void PrintAlleColor(eColor *listColor, int tam);
int FindeColor(eColor *listColor, int tam, int id, int* pIndex);
void PrintOneeColor(eColor *listColor);
