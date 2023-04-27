#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pharmacy.h"
#include <ctype.h>

struct medicamento{
char nome[50];
int dosagem;
char data;
float preco;
char recomendacao[50];
};
typedef struct medicamento Med;