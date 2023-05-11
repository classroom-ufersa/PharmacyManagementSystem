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
    Med *ant;
    Med *prox;
};

Med *med_insere(Med *p, char name[50], char dose[50], char data[10], float preco, char recomendacao[50])
{

    Med *med = (Med *)malloc(sizeof(Med));
    if (med == NULL)
    {
        printf("erro, por favor tente novamente!");
        exit(1);
    }

    strcpy(med->nome, name);
    strcpy(med->dosagem, dose);
    strcpy(med->data, data);
    med->preco = preco;
    strcpy(med->recomendacao, recomendacao);

    med->prox = p;
    med->ant = NULL;
    if (p != NULL)
    {
        p->ant = med;
    }

    //  FILE *pharmacy_txt;

    //  pharmacy_txt = fopen("Pharmacy.txt", "at");

    //  fprintf(pharmacy_txt, "\tNome: %s\n",new->nome);

    //  fclose(pharmacy_txt);

    return med;
}

void med_imprime(Med *p)
{
    printf(" Nome do remedio: %s \n", p->nome);
    printf(" Dosagem:  %s \n", p->dosagem);
    printf(" Validade: %s \n", p->data);
    printf(" Preco: %f \n", p->preco);
    printf(" Recomendacao: %s \n", p->recomendacao);
}

Med *med_busca(Med *l, char nome[50])
{
    Med *p;
    for (p = l; p != NULL; p = p->prox)
    {
        if (strcmp(p->nome, nome) == 0)
            return p;
    }
    return NULL;
}

Med *busca_med_any(Med *m, Pharm *p, char med[50])
{
    Pharm *p_busca;
    Med *m_busca;
    for (p_busca = p; p_busca != NULL; p_busca = p_busca->prox)
    {
        for (m_busca = m; m_busca != NULL; m_busca = m_busca->prox)
        {
            if(strcmp(m_busca->nome, med) == 0){
                printf("nome da farmácia: %s", p_busca->nome);
                return m_busca;
            }
        }
    }
    return NULL;
}

Med *med_retira(Med *l, char v[50])
{
    Med *p = med_busca(l, v);

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