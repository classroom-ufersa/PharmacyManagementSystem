#include "pharmacy.c"

int main(void)
{
    int opc = 0, x = 0;
    Pharm *farmacia;
    Med *medicamento = 0;
    FILE *teste;
    char pharmacy[20][50];
    int qnt_linhas;//Pharm* pharm_insere(Pharm *p, char name[50], int cod, char loc[50], char horario[50]);
    char nome[50];
    int codigo;
    char localizacao[50];
    char horario[50];

    int code; 

    while (x != 1)
    {

        printf("\nSistema de Gerenciamento de farmacia de medicamentos\n1. Adicionar farmacia\n2. Adicionar medicamento;\n3. Remover medicamento;\n4. Listar medicamentos cadastrados;\n5. Buscar medicamentos;\n6. Editar medicamento;\n7. Consultar medicamento em uma dada farmacia;\n8. consultar quantitativo de farmacia;\n9. sair\n");
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
        case 4://to botando na 4 só para testar
            fflush(stdin);
            printf("informe o codigo da farmacia que deseja verificar:\n");
            scanf("%d", &code);
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

    return 0;
}