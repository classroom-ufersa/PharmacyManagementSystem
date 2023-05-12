#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pharmacy.h"
#include "med.h"
#include <ctype.h>

struct pharmacy
{
    char codigo[50];
    char nome[50];
    char localizacao[50];
    int num_med;
    char horario[50];
    Med *med;
    Pharm *ant;
    Pharm *prox;
};

void combsort_ph(char lista[20][100], int n)
{
    FILE *abrir;
    int lacuna = n;
    int trocado = 1;
    int i, j;
    char temp[100];
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

int Contador_ph(void)
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

Pharm *pharm_insere(Pharm *p, char name[50], char cod[50], char loc[50], char horario[50])
{

    Pharm *novo = (Pharm *)malloc(sizeof(Pharm));
    if (novo == NULL)
    {
        printf("erro, por favor tente novamente");
        exit(1);
    }

    strcpy(novo->nome, name);
    strcpy(novo->codigo, cod);
    strcpy(novo->localizacao, loc);
    novo->num_med = 0;
    strcpy(novo->horario, horario);

    novo->prox = p;
    novo->ant = NULL;
    novo->med = NULL;
    if (p != NULL)
    {
        p->ant = novo;
    }

    FILE *pharmacy_txt;

    pharmacy_txt = fopen("Pharmacy.txt", "at");

    fprintf(pharmacy_txt, "Nome: %s\tCodigo: %s\tLocalização: %s\thorario de funcionammento: %s\tEstoque: %d\n", novo->nome, novo->codigo, novo->localizacao, novo->horario, novo->num_med);

    fclose(pharmacy_txt);

    return novo;
}

void pharm_imprime(Pharm *p)
{
    printf(" Codigo da farmacia = %s \n", p->codigo);
    printf(" Nome da farmacia = %s \n", p->nome);
    printf(" Localizacao da farmacia = %s \n", p->localizacao);
    printf(" Estoque da farmacia = %d \n", p->num_med);
    printf(" Horario de funcionamento = %s \n", p->horario);
}

// void pharm_buscain(Pharm *l, char cod[50])
// {
//     Pharm *p;
//     Med *m;
//     for (p = l; p != NULL; p = p->prox)
//     {
//         for (m = p->med; m != NULL; p = m->prox)
//         {
//             if (strcmp(m->nome, cod) == 0)
//             {
//                 printf("farmacia: %s\tremedio: %s\n", p->nome, m->nome);
//             }
//         }
//     }
// }

Pharm *pharm_busca(Pharm *l, char cod[50])
{
    Pharm *p;
    if(l->codigo!=NULL){
    
    for (p = l; p != NULL; p = p->prox)
    {
        if (strcmp(p->codigo, cod) == 0)
        {
            return p;
        }
        
    }
    }
    return NULL;
}

Pharm *Pharm_retira(Pharm *l, char v[50])
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

void leitura(Pharm *c)
{
    char recebe_linhas[500];
    int iterarnaslinhas=0;
    FILE *abre;
    abre = fopen("pharmacy.txt", "rt");
    while (fgets(recebe_linhas, 500, abre) != NULL)
    {
        sscanf(recebe_linhas, "Nome: %s	Codigo: %s	Localização: %s	horario de funcionammento: %s	Estoque: %d", c->nome, c->codigo, c->localizacao, c->horario, &c->num_med);
        
        iterarnaslinhas++;
    }
}