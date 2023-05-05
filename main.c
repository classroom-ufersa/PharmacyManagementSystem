#include "pharmacy.c"

int main(void)
{
    int opc = 0, x = 0;
    Pharm *farmacia;
    Med *medicamento = 0;
    FILE *teste;
    char pharmacy[20][100];
    int qnt_linhas; // Pharm* pharm_insere(Pharm *p, char name[50], int cod, char loc[50], char horario[50]);
    char nome[50];
    char codigo[50];
    char localizacao[50];
    char horario[50];

    char code[50];

    char nome_med[50];
            char dosagem[50];
            char data_validade[10];
            float preco_med;
            char recomendacao[50];

            Pharm * farm_p_med;

    while (x != 1)
    {

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
            

            printf("informe o codigo da farmacia que deseja adicionar o medicamento:\n");
            scanf(" %[^\n]", code);
            farm_p_med = pharm_busca(farm_p_med, code);

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

            med_insere(farm_p_med, medicamento, nome_med, dosagem, data_validade, preco_med, recomendacao);
            }
            else
            {
                printf("Não foi possivel acessar a farmacia! \n\n");
            }
            

            break;

        case 4: // to botando na 4 só para testar
            fflush(stdin);
            printf("informe o codigo da farmacia que deseja verificar:\n");
            scanf(" %[^\n]", code);
            farmacia = pharm_busca(farmacia, code);
            pharm_imprime(farmacia);
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
}char nome_med[50];
            char dosagem[50];
            char data_validade[10];
            float preco_med;
            char recomendacao[50];

            Pharm * farm_p_med;