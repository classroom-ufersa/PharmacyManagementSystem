typedef struct pharmacy Pharm;
Pharm* pharm_insere(Pharm *p, char name[50], char cod[50], char loc[50], char horario[50]);
Pharm *pharm_busca(Pharm *l, char cod[50]);
Pharm *Pharm_retira(Pharm *l, char v[50]);
void pharm_imprime(Pharm *l);
int Contador_ph(char nome[50]);
void combsort_ph(char lista[20][100], int n, char nome[50]);
char *concate(char nome[50]);
