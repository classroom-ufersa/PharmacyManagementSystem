typedef struct medicamento Med;
typedef struct pharmacy Pharm;
Pharm* pharm_insere(Pharm *p, char name[50], int cod, char loc[50], char horario[50]);
int contador();
void combSort(char lista[][50], int n);