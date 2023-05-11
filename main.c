#include "pharmacy.c"
#include "med.c"

int main(void)
{
    int opc = 0, x = 0;
    Pharm *farmacia;
    Med *medicamento;
    FILE *teste;
    char pharmacy[20][100];
    int qnt_linhas; // Pharm* pharm_insere(Pharm *p, char name[50], int cod, char loc[50], char horario[50]);
    char nome[50];
    char codigo[50];
    char localizacao[50];
    char horario[50];

    char code[50];
    char code_pm[50];

    char nome_med[50];
    char dosagem[50];
    char data_validade[10];
    float preco_med;
    char recomendacao[50];

    while (x != 1)
    {

        // Pharm *farm_p_med;

        printf("\nSistema de Gerenciamento de farmacia de medicamentos\n\n1. Adicionar farmacia\n2. Adicionar medicamento;\n3. Remover medicamento;\n4. Listar medicamentos cadastrados;\n5. Buscar medicamentos;\n6. Editar medicamento;\n7. Consultar medicamento em uma dada farmacia;\n8. consultar quantitativo de farmacia;\n9. sair\n");
        scanf("%d", &opc);
        switch (opc)

        {
        case 1:
            printf("Para cadastra uma farmacia no sistema:\ninfome o nome da farmacia:\n");
            scanf(" %[^\n]", nome);
            printf("Informe o codigo da farmacia:\n");
            scanf(" %[^\n]", codigo);
            printf("Informe a localizacao:\n");
            scanf(" %[^\n]", localizacao);
            printf("Informe o horario de funcionamento:\n");
            scanf(" %[^\n]", horario);
            farmacia = pharm_insere(farmacia, nome, codigo, localizacao, horario);

            break;

        case 2:
            // fflush(stdin);
            printf("informe o codigo da farmacia que deseja adicionar o medicamento:\n");
            scanf(" %[^\n]", code_pm);
            farmacia = pharm_busca(farmacia, code_pm);

            if (farmacia != NULL)
            {
                printf("Para cadastra um medicamento no sistema:\ninfome o nome do medicamento:\n");
                scanf(" %[^\n]", nome_med);
                printf("Informe a dosagem do medicamento:\n");
                scanf(" %[^\n]", dosagem);
                printf("Informe a validade do medicamento:\n");
                scanf(" %[^\n]", data_validade);
                printf("Informe o preço do medicamento:\n");
                scanf("%f", &preco_med);
                printf("Informe a recomendacao do medicamento:\n");
                scanf(" %[^\n]", recomendacao);

                medicamento = med_insere(medicamento, nome_med, dosagem, data_validade, preco_med, recomendacao);

                farmacia->num_med += 1;
            }
            else
            {
                printf("Nao foi possivel acessar a farmacia! \n\n");
            }

            break;
        case 3:
            fflush(stdin);
            char rem[50];
            Pharm *rascunho1;
            Med *med;
            med = medicamento;
            rascunho1 = farmacia;
            printf("informe o codigo da farmacia que deseja verificar:\n");
            scanf(" %[^\n]", code);
            printf("informe o nome do remedio que deseja remover");
            scanf(" %[^\n]", rem);
            rascunho1 = pharm_busca(rascunho1, code);
            med = med_busca(med, rem);
            med_retira(med,rem);
            break;

        case 4:
            system("cls");
            fflush(stdin);
            Pharm *rascunho;
            rascunho = farmacia;
            printf("informe o codigo da farmacia que deseja verificar:\n");
            scanf(" %[^\n]", code);
            rascunho = pharm_busca(rascunho, code);
            if (rascunho == NULL)
            {
                printf("nao foi possivel acessar a farmacia");
                break;
            }

            pharm_imprime(rascunho);
            break;
        case 8:
            system("cls");
            fflush(stdin);
            Pharm *rasc;
            rasc = farmacia;
            printf("informe o codigo da farmacia que deseja verificar:\n");
            scanf(" %[^\n]", code);
            rasc = pharm_busca(rasc, code);
            printf("a farmacia possui %d medicamentos",rasc->num_med);
            break;
        case 9:
            free(farmacia);

            x = 1;
            break;
        default:
            system("cls");
            printf("\ninforme um valor valido!\n\n");
            break;
        }
    }
    qnt_linhas = Contador_ph();

    int i = 0;

    teste = fopen("Pharmacy.txt", "rt");

    while (i < qnt_linhas)
    {
        fgets(pharmacy[i], 100, teste);
        i++;
    }

    combsort_ph(pharmacy, qnt_linhas);
    return 0;
}