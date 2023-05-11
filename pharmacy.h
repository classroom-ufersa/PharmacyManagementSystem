typedef struct pharmacy Pharm;
Pharm* pharm_insere(Pharm *p, char name[50], int cod, char loc[50], char horario[50]);
Pharm *pharm_busca(Pharm *far, int cod);
Pharm *Pharm_retira(Pharm *l, int v);
void pharm_imprime(Pharm *l);
int Contador_ph(char nome[50]);
void combsort_ph(char lista[20][500], int n, char nome[50]);
char *concate(char nome[50]);
