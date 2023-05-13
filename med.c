#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "med.h"
#include <ctype.h>

struct medicamento
{
    char nome[50];
    char dosagem[50];
    char data[10];
    float preco;
    char recomendacao[50];
    Med *anti;
    Med *proxi;
};

// void combsort_med(char lista[20][100], int n)
// {
//     FILE *abrir;
//     int lacuna = n;
//     int trocado = 1;
//     int i, j;
//     char temp[100];
//     int controle = 0;

//     while (lacuna > 1 || trocado == 1)
//     { // c5*n
//         lacuna = lacuna / 1.3;
//         if (lacuna < 1)
//         {
//             lacuna = 1;
//         }

//         trocado = 0;
//         for (i = 0, j = i + lacuna; j < n; i++, j++)
//         { // n*n
//             if (strcmp(lista[i], lista[j]) > 0)
//             {
//                 strcpy(temp, lista[i]);
//                 strcpy(lista[i], lista[j]);
//                 strcpy(lista[j], temp);
//                 trocado = 1;
//             }
//         }
//     }

//     // abrir = fopen("pharmacy.txt", "wt");

//     // while (controle < n)
//     // {
//     //     fprintf(abrir, "%s", lista[controle]);
//     //     controle++;
//     // }

//     // fclose(abrir);
// }

// int contador_med()
// {

//     FILE *abre;
//     char linha[100];
//     int numLinhas = 0;

//     abre = fopen("pharmacy.txt", "rt");
//     if (abre == NULL)
//     {
//         printf("ERRO ao abrir o arquivo!");
//         exit(1);
//     }

//     while (fgets(linha, 100, abre) != NULL)
//     {
//         numLinhas++;
//     }

//     fclose(abre);

//     return (numLinhas);
// }

Med *med_insere(Med *p, char name[50], char dose[50], char data[10], float preco, char recomendacao[50])
{

    Med *new = (Med *)malloc(sizeof(Med));
    if (new == NULL)
    {
        printf("erro, por favor tente novamente!");
        exit(1);
    }

    strcpy(new->nome, name);
    strcpy(new->dosagem, dose);
    strcpy(new->data, data);
    new->preco = preco;
    strcpy(new->recomendacao, recomendacao);
    new->proxi = p;
    new->anti = NULL;
    if (p != NULL)
    {
        new->anti = new;
    }

    FILE *pharmacy_txt;

    pharmacy_txt = fopen("Pharmacy.txt", "at");

    fprintf(pharmacy_txt, "\tNome: %s\tdosagem: %s\tdata: %s\tpreco: %f\trecomendacao: %s\n", new->nome, new->dosagem, new->data, new->preco, new->recomendacao);

    fclose(pharmacy_txt);

    return new;
}

void med_imprime(Med *p)
{
    Med *l;
    for (l = p; l != NULL; l = l->proxi)
    {

        printf(" Nome do remedio: %s \n", p->nome);
        printf(" Dosagem:  %s \n", p->dosagem);
        printf(" Validade: %s \n", p->data);
        printf(" Preco: %f \n", p->preco);
        printf(" Recomendacao: %s \n", p->recomendacao);
    }
}

Med *med_busca(Med *l, char nome[50])
{
    Med *p;
    for (p = l; p != NULL; p = p->proxi)
    {
        if (strcmp(p->nome, nome) == 0)
            return p;
    }
    return NULL;
}

Med *med_retira(Med *l, char v[50])
{
    Med *p = med_busca(l, v);

    if (p->proxi != NULL)
        p->proxi->anti = p->anti;
    if (l == NULL)
        return l;
    if (p == l)
        l = p->proxi;
    else
        p->anti->proxi = p->proxi;
    return l;
    free(l);
}

void med_remove(Med **lista, Med *med)
{
    if (*lista == NULL)
    {
        return;
    }
    if (*lista == med)
    {
        *lista = med->proxi;
        if (*lista != NULL)
        {
            (*lista)->anti = NULL;
        }
    }
    else
    {
        Med *anterior = med->anti;
        if (anterior != NULL)
        {
            anterior->proxi = med->proxi;
        }

        Med *seguinte = med->proxi;
        if (seguinte != NULL)
        {
            seguinte->anti = med->anti;
        }
    }

    free(med);
}

void leitura_med(Med *c)
{
    char recebe_linhas[500];
    FILE *abre;
    abre = fopen("pharmacy.txt", "rt");
    while (fgets(recebe_linhas, 500, abre) != NULL)
    {
        sscanf(recebe_linhas, "Nome: %s dosagem: %s data: %s    preco: %f   recomendacao: %s", c->nome, c->dosagem, c->data, c->preco, c->recomendacao);
    }
}