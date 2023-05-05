#include "pharmacy.h"

typedef struct medicamento Med;

Med* med_insere(Pharm * ph ,Med *p, char name[50], char dose[50], char data[10], float preco, char recomendacao[50]);
Med *med_busca(Med *l, char nome[50]);
Med *med_retira(Med *l, char v[50]);
void med_imprime(Med *l);
int contador();
void combsort(char lista[20][100], int n);