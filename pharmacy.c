#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pharmacy.h"
#include "med.c"
#include <ctype.h>

struct pharmacy {
char nome[50];
int codigo;
char localizacao[50];
int num_med;
char horario[50];
Med * med;
Pharm * ant;
Pharm * prox;
};
typedef struct pharmacy Pharm;



void combSort(char lista[][50], int n)
{
    FILE *abrir;
    int lacuna = n;
    int trocado = 1;
    int i, j;
    char temp[50];
    int controle = 0;

    while (lacuna > 1 || trocado == 1)
    { // c5*n
        lacuna = lacuna / 1.3;
        if (lacuna < 1)
        {
            lacuna = 1;
        }

        trocado = 0;
        for (i = 0, j = i + lacuna; j < n; i++, j++)
        { // n*n
            if (strcmp(lista[i], lista[j]) > 0)
            {
                strcpy(temp, lista[i]);
                strcpy(lista[i], lista[j]);
                strcpy(lista[j], temp);
                trocado = 1;
            }
        }
    }

abrir = fopen("pharmacy.txt", "wt");

    while (controle < n)
    {
        fprintf(abrir, "%s", lista[controle]);
        controle++;
    }

    fclose(abrir);
}

int contador()
{

    FILE *abre;
    char linha[100];
    int numLinhas = 0;

    abre = fopen("pharmacy.txt", "rt");
    if (abre == NULL)
    {
        printf("ERRO ao abrir o arquivo!");
        exit(1);
    }

    while (fgets(linha, 100, abre) != NULL)
    {
        numLinhas++;
    }

    fclose(abre);

    return (numLinhas);
}

Pharm* lst_insere(Pharm *p, char name[50], int cod, char loc[50], char horario[50]){

    Pharm* novo = (Pharm*) malloc(sizeof(Pharm));
    *novo->nome = name;
    novo->codigo = cod;
    *novo->localizacao = loc;
    novo->num_med = 0;
    *novo->horario = horario;
    novo->prox = p;
    novo->ant = NULL;
    if(p!=NULL)
        p->ant = novo;
    return novo;
}


void lst_imprime(Lista2*l){
	Lista2*p;
	for(p=l; p!=NULL; p=p->prox){
		printf(" Info = %d \n", p->info);
	}

}

Lista2* lst_busca(Lista2 *l, int v){

    Lista2 *p;
    for(p=l; p!=NULL; p=p->prox){
        if(p->info ==v)
			return p;
    }
    return NULL;

}

Lista2* lst_retira(Lista2 *l, int v){
    Lista2* p = lst_busca(l,v);

    if(p->prox!=NULL)
        p->prox->ant=p->ant;
    if(l==NULL)
        return l;
    if(p==l)
        l=p->prox;
    else
        p->ant->prox = p->prox;
    return l;

}