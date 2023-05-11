#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pharmacy.h"
#include "med.h"
#include <ctype.h>

struct pharmacy
{
    int codigo;
    char nome[50];
    char localizacao[50];
    int num_med;
    char horario[50];
    Med *med;
    Pharm *ant;
    Pharm *prox;
};

void combsort_ph(char lista[20][500], int n, char nome[50])
{
    FILE *abrir;
    int lacuna = n;
    int trocado = 1;
    int i, j;
    char temp[500];
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
    strcat(nome, ".txt");
    abrir = fopen(nome, "wt");

    while (controle < n)
    {
        fprintf(abrir, "%s", lista[controle]);
        controle++;
    }

    fclose(abrir);
}

int Contador_ph(char nome[50])
{

    FILE *abre;
    char linha[500];
    int numLinhas = 0;

    strcat(nome, ".txt");
    printf("%s", nome);
    abre = fopen(nome, "rt");
    if (abre == NULL)
    {
        printf("ERRO ao abrir o arquivo!");
        exit(1);
    }

    while (fgets(linha, 500, abre) != NULL)
    {
        numLinhas++;
    }

    fclose(abre);

    return (numLinhas);
}

Pharm *pharm_insere(Pharm *p, char name[50], int cod, char loc[50], char horario[50])
{

    Pharm *novo = (Pharm *)malloc(sizeof(Pharm));
    if (novo == NULL)
    {
        printf("erro, por favor tente novamente");
        exit(1);
    }

    strcpy(novo->nome, name);
    novo->codigo = cod;
    strcpy(novo->localizacao, loc);
    novo->num_med = 0;
    strcpy(novo->horario, horario);
    novo->med = NULL;

    novo->prox = p;
    novo->ant = NULL;
    if (p != NULL)
    {
        p->ant = novo;
    }

    FILE *pharmacy_txt;

    char name2[50];
    strcpy(name2, name);
    strcat(name2, ".txt");

    pharmacy_txt = fopen(name2, "wt");

    fprintf(pharmacy_txt, "%i\t|nome: %s\tLocalização: %s\thorario de funcionammento: %s\n\n", novo->codigo, novo->nome, novo->localizacao, novo->horario);

    fclose(pharmacy_txt);

    return novo;
}

void pharm_imprime(Pharm *p)
{
    printf(" Codigo da farmacia = %i \n", p->codigo);
    printf(" Nome da farmacia = %s \n", p->nome);
    printf(" Localizacao da farmacia = %s \n", p->localizacao);
    printf(" Estoque da farmacia = %d \n", p->num_med);
    printf(" Horario de funcionamento = %s \n", p->horario);
}

Pharm *pharm_busca(Pharm *far, int cod)
{
    //Pharm *p;
    // for (p = far; p != NULL; p = p->prox)
    do
    {
        if (far->codigo == cod)
        {
            return far;
        }
        far = far->prox;
    } while (far != NULL);
    return NULL;
}

Pharm *Pharm_retira(Pharm *l, int v)
{
    Pharm *p = pharm_busca(l, v);

    if (p->prox != NULL)
        p->prox->ant = p->ant;
    if (l == NULL)
        return l;
    if (p == l)
        l = p->prox;
    else
        p->ant->prox = p->prox;
    return l;
}