#include "pharmacy.c"
#include "med.c"

int main(void)
{
    int opc = 0, x = 0;
    Pharm *farmacia;
    FILE *teste;
    char pharmacy[20][100];
    int qnt_linhas; 
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
    farmacia = (Pharm*)malloc(sizeof(Pharm));
    
    leitura(farmacia);
    while (x != 1)
    {

        

        printf("\nSistema de Gerenciamento de farmacia de medicamentos\n\n1. Adicionar farmacia\n2. Adicionar medicamento;\n3. Remover medicamento;\n4. Listar medicamentos cadastrados;\n5. Buscar medicamentos;\n6. Editar medicamento;\n7. Consultar medicamento em uma dada farmacia;\n8. consultar quantitativo de farmacia;\n9. sair\n");
        scanf("%d", &opc);
        switch (opc)

        {
        case 1:
            printf("Para cadastra uma farmacia no sistema:\ninforme o nome da farmacia:\n");
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
            Pharm *rsc;
            rsc = farmacia;
            rsc = pharm_busca(rsc, code_pm);

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

                farmacia->med = med_insere(rsc->med, nome_med, dosagem, data_validade, preco_med, recomendacao);

                rsc->num_med += 1;
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
            Med *med, *medremol;
            med = rsc->med;
            rascunho1 = rsc;
            printf("informe o codigo da farmacia que deseja verificar:\n");
            scanf(" %[^\n]", code);
            printf("informe o nome do remedio que deseja remover\n");
            scanf(" %[^\n]", rem);
            rascunho1 = pharm_busca(rascunho1, code);
            medremol = med_busca(med, rem);
            med_remove(&med,medremol);
            break;

        case 4:
            system("cls");
            fflush(stdin);
            Pharm *rascunho;
            Med *remedy;
            rascunho = rsc;
            printf("informe o codigo da farmacia que deseja verificar:\n");
            scanf(" %[^\n]", code);
            rascunho = pharm_busca(rascunho, code);
            remedy = rascunho->med;
            if (rascunho == NULL)
            {
                printf("nao foi possivel acessar a farmacia");
                break;
            }
            med_imprime(remedy);
            break;
        case 7:
            
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