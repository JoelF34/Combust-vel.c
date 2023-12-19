#include <stdio.h>
#include <string.h>

#define MAX_ABASTECIMENTOS 100


struct Abastecimento {
    int dia, mes, ano;
    char combustivel[50];
    char tipoDeCombustivel[50];
    float qtdLitros, precoLitro;
};


void adicionarAbastecimento(struct Abastecimento abastecimentos[], int *totalAbastecimentos);
void listarAbastecimentos(struct Abastecimento abastecimentos[], int totalAbastecimentos);
void listarAbastecimentosPorData(struct Abastecimento abastecimentos[], int totalAbastecimentos);
void alterarAbastecimento(struct Abastecimento abastecimentos[], int totalAbastecimentos);
void apagarAbastecimento(struct Abastecimento abastecimentos[], int *totalAbastecimentos);

int main() {
    struct Abastecimento abastecimentos[MAX_ABASTECIMENTOS];
    int totalAbastecimentos = 0;
    int opcao;

    do {
        printf("\n===== Menu =====\n");
        printf("1. Adicionar Abastecimento\n");
        printf("2. Listar Abastecimentos\n");
        printf("3. Listar Abastecimentos por Data\n");
        printf("4. Alterar Abastecimento\n");
        printf("5. Apagar Abastecimento\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarAbastecimento(abastecimentos, &totalAbastecimentos);
                break;
            case 2:
                listarAbastecimentos(abastecimentos, totalAbastecimentos);
                break;
            case 3:
                listarAbastecimentosPorData(abastecimentos, totalAbastecimentos);
                break;
            case 4:
                alterarAbastecimento(abastecimentos, totalAbastecimentos);
                break;
            case 5:
                apagarAbastecimento(abastecimentos, &totalAbastecimentos);
                break;
            case 6:
                printf("Saindo do programa. Obrigado!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 6);

    return 0;
}

void adicionarAbastecimento(struct Abastecimento abastecimentos[], int *totalAbastecimentos) {
    
}

void listarAbastecimentos(struct Abastecimento abastecimentos[], int totalAbastecimentos) {
    
}

void listarAbastecimentosPorData(struct Abastecimento abastecimentos[], int totalAbastecimentos) {
    
}

void alterarAbastecimento(struct Abastecimento abastecimentos[], int totalAbastecimentos) {
    if (totalAbastecimentos > 0) {
        int indice;
        printf("\n===== Alterar Abastecimento =====\n");
        printf("Digite o índice do abastecimento a ser alterado (0 a %d): ", totalAbastecimentos - 1);
        scanf("%d", &indice);

        if (indice >= 0 && indice < totalAbastecimentos) {
            // Solicitar ao usuário as novas informações do abastecimento
            printf("Nova Data (dia mês ano): ");
            scanf("%d %d %d", &abastecimentos[indice].dia, &abastecimentos[indice].mes, &abastecimentos[indice].ano);
            printf("Novo Combustível: ");
            scanf("%s", abastecimentos[indice].combustivel);
            printf("Novo Tipo de Combustível: ");
            scanf("%s", abastecimentos[indice].tipoDeCombustivel);
            printf("Nova Quantidade de Litros: ");
            scanf("%f", &abastecimentos[indice].qtdLitros);
            printf("Novo Preço por Litro: ");
            scanf("%f", &abastecimentos[indice].precoLitro);

            printf("Abastecimento alterado com sucesso!\n");
        } else {
            printf("Índice inválido. Nenhum abastecimento alterado.\n");
        }
    } else {
        printf("Nenhum abastecimento cadastrado.\n");
    }
}

void apagarAbastecimento(struct Abastecimento abastecimentos[], int *totalAbastecimentos) {
    if (*totalAbastecimentos > 0) {
        int indice;
        printf("\n===== Apagar Abastecimento =====\n");
        printf("Digite o índice do abastecimento a ser apagado (0 a %d): ", *totalAbastecimentos - 1);
        scanf("%d", &indice);

        if (indice >= 0 && indice < *totalAbastecimentos) {
            
            char confirmacao;
            printf("Tem certeza que deseja apagar este abastecimento? (S/N): ");
            scanf(" %c", &confirmacao);

            if (confirmacao == 'S' || confirmacao == 's') {
                
                for (int i = indice; i < *totalAbastecimentos - 1; ++i) {
                    abastecimentos[i] = abastecimentos[i + 1];
                }

                (*totalAbastecimentos)--;
                printf("Abastecimento apagado com sucesso!\n");
            } else {
                printf("Nenhum abastecimento apagado.\n");
            }
        } else {
            printf("Índice inválido. Nenhum abastecimento apagado.\n");
        }
    } else {
        printf("Nenhum abastecimento cadastrado.\n");
    }
}