#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "med.h"
#include <ctype.h>

struct medicamento{
char nome[50];
char dosagem[50];
char data[10];
float preco;
char recomendacao[50];
Med* ant;
Med * prox;
};

void combsort(char lista[20][100], int n)
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

int Contador()
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

Med *med_insere(Med *p, char name[50], char dose[50], char data[10], float preco[50], char recomendacao[50])
{

    Med *new = (Med *)malloc(sizeof(Med));
    if(novo==NULL){
        printf("erro, por favor tente novamente");
        exit(1);
    }
        
    strcpy(new->nome, name);
    strcpy(new->dosagem, dose);
    strcpy(new->data, data);
    novo->num_med += 1;
    strcpy(new->preco, preco);
    strcpy(new->recomendacao, recomendacao);
    new->prox = p;
    new->ant = NULL;
    if (p != NULL)
    {
        new->ant = novo;
    }

    // FILE *pharmacy_txt;

    // pharmacy_txt = fopen("Pharmacy.txt", "at");

    // fprintf(pharmacy_txt, "Nome: %s\tCodigo: %s\tLocalização: %s\thorario de funcionammento: %s\tEstoque: %d\n", novo->nome, novo->codigo, novo->localizacao, novo->horario, novo->num_med);

    // fclose(pharmacy_txt);

    return novo;
}

void med_imprime(Med *p)
{
        printf(" Nome do remedio: %s \n", p->nome);
        printf(" Dosagem:  %s \n", p->dosagem);
        printf(" Validade: %s \n", p->data);
        printf(" Preco: %d \n", p->preco);
        printf(" Recomendacao: %s \n", p->recomendacao);
}

Pharm *pharm_busca(Pharm *l, char cod[50])
{
    Pharm *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (strcmp(p->codigo, cod) == 0)
            return p;
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