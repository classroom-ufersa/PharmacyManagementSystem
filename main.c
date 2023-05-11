#include "pharmacy.c"
#include "med.c"

int main(void)
{
    int i;
    char abrearquivo[50];
    int opc = 0, x = 0;
    Pharm *farmacia;
    Pharm *rascunho;
    FILE *abre;
    char pharmacy[20][500];
    int qnt_linhas; // Pharm* pharm_insere(Pharm *p, char name[50], int cod, char loc[50], char horario[50]);
    char nome[50];
    int codigo;
    char localizacao[50];
    char horario[50];

    int code;
    int code_pm;

    char nome_med[50];
    char dosagem[50];
    char data_validade[10];
    float preco_med;
    char recomendacao[50];

    while (x != 1)
    {

        printf("\nSistema de Gerenciamento de farmacia de medicamentos\n\n1. Adicionar farmacia\n2. Adicionar medicamento;\n3. Remover medicamento;\n4. Listar medicamentos cadastrados;\n5. Listar farmacias\n6. Buscar medicamentos;\n7. Editar medicamento;\n8. Consultar medicamento em uma dada farmacia;\n9. consultar quantitativo de farmacia;\n0. sair\n");
        scanf("%d", &opc);
        switch (opc)

        {
        case 1:
            printf("Para cadastra uma farmacia no sistema:\ninfome o nome da farmacia:\n");
            scanf(" %[^\n]", nome);
            printf("Informe o codigo da farmacia:\n");
            scanf("%d", &codigo);
            printf("Informe a localizacao:\n");
            scanf(" %[^\n]", localizacao);
            printf("Informe o horario de funcionamento:\n");
            scanf(" %[^\n]", horario);
            farmacia = pharm_insere(farmacia, nome, codigo, localizacao, horario);

            break;

        case 2:
            rascunho = farmacia;
            //fflush(stdin);
            printf("informe o codigo da farmacia que deseja adicionar o medicamento:\n");
            scanf("%d", &code_pm);
            rascunho = pharm_busca(rascunho, code_pm);

            if (rascunho == NULL)
            {
                printf("Nao foi possivel acessar a farmacia! \n\n");
                break;
            }
            else
            {
                printf("Para cadastra um medicamento no sistema:\ninforme o nome do medicamento:\n");
                scanf(" %[^\n]", nome_med);
                printf("Informe a dosagem do medicamento:\n");
                scanf(" %[^\n]", dosagem);
                printf("Informe a validade do medicamento:\n");
                scanf(" %[^\n]", data_validade);
                printf("Informe o preço do medicamento:\n");
                scanf("%f", &preco_med);
                printf("Informe a recomendacao do medicamento:\n");
                scanf(" %[^\n]", recomendacao);

                strcpy(abrearquivo, farmacia->nome);
                strcat(abrearquivo, ".txt");
                abre = fopen(abrearquivo, "at");
                fprintf(abre, "medicamento: %s", nome_med);
                abre = fopen(abrearquivo, "rt");
                rascunho->med = med_insere(rascunho->med, nome_med, dosagem, data_validade, preco_med, recomendacao);
                farmacia->num_med += 1;
                qnt_linhas = Contador_ph(farmacia->nome);
                i = 2;
                while (i < qnt_linhas)
                {
                    fgets(pharmacy[i], 500, abre);
                    i++;
                }
                combsort_ph(pharmacy, qnt_linhas, farmacia->nome);

            }

            break;

        case 4:
            system("cls");
            fflush(stdin);
            printf("informe o codigo da farmacia que:\n");
            scanf("%d", &code);
            farmacia = pharm_busca(farmacia, code);
            if (farmacia == NULL)
            {
                system("cls");
                printf("\n\n farmacia nao encontrada\n");
                break;
            }
            pharm_imprime(farmacia);
            break;
        case 5:
            system("cls");
            fflush(stdin);
            printf("informe o codigo da farmacia que deseja verificar:\n");
            scanf("%d", &code);
            farmacia = pharm_busca(farmacia, code);
            if (farmacia == NULL)
            {
                system("cls");
                printf("\n\n farmacia nao encontrada\n");
                break;
            }
            pharm_imprime(farmacia);
            break;

        case 0:
            free(farmacia);

            x = 1;
            break;
        default:
            system("cls");
            printf("\ninforme um valor valido!\n\n");
            break;
        }
    }
    // qnt_linhas = Contador_ph(farmacia->nome);
    // i = 1;
    // char nome_farm[50];
    // strcpy(nome_farm, farmacia->nome);
    // strcat(nome_farm, ".txt");
    // teste = fopen(nome_farm, "rt");
    // while (i < qnt_linhas)
    // {
    //     fgets(pharmacy[i], 100, teste);
    //     i++;
    // }
    // combsort_ph(pharmacy, qnt_linhas, farmacia->nome);
    return 0;
}