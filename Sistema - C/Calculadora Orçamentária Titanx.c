/* DISTRIBUIDORA DE SOFTWARE E HARDWARE TITANX 
   INTEGRANTES: PEDRO ANDRÉ SOUZA DEARO - RA 3025105508
   MICAEL NAUM ELIAS SANTOS NASCIMENTO - RA 3026103415
   GUSTAVO AUGUSTO - RA 3026101912
   
   DESCRIÇÃO: Simulador de projetos e custos para suporte a vendas.
   O programa permite cadastrar itens, visualizar o carrinho e gerar orçamentos. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 50 

int main() {
    
    setlocale(LC_ALL, "Portuguese");

    // ESTRUTURAS DE DADOS (Vetores Obrigatórios Exigidos)
    float preco[MAX];
    int codigo[MAX];
    int tipo[MAX];
    int quantidade[MAX];
    int sub_tipo_sw[MAX];

    // VARIÁVEIS DE CONTROLE
    int contador = 0; 
    int opcao;        

    do {
        system("cls");
        printf("\nSEJA BEM VINDO! A TITANX AGRADECE A PREFERENCIA E CONFIANCA\n");
        printf("POR FAVOR, SELECIONE ABAIXO A OPCAO DESEJADA:\n\n");
        printf("1. PARA SOFTWARES\n");
        printf("2. PARA HARDWARE\n");
        printf("3. PARA IR AO CARRINHO\n");
        printf("4. PARA GERAR ORCAMENTO FINAL\n");
        printf("5. PARA FECHAR O PROGRAMA\n");
        printf("Escolha: ");

        scanf("%d", &opcao);

        switch (opcao) {

            case 1: { // CADASTRO DE SOFTWARES
                char continuar;
                int modelo;

                do {
                    system("cls");
                    if (contador < MAX) {
                        printf("\n --- CADASTRO DE SOFTWARES ---\n");
                        printf("Produto numero: %d\n", contador + 1);

                        printf("Digite o codigo do produto: ");
                        scanf("%d", &codigo[contador]);

                        do {
                            printf("Tipo de venda (1-Definitiva | 2-Assinatura): ");
                            scanf("%d", &modelo);
                            if (modelo != 1 && modelo != 2) printf("Opcao invalida!\n");
                        } while (modelo != 1 && modelo != 2);

                        sub_tipo_sw[contador] = modelo;

                        if (modelo == 1) {
                            // VENDA DEFINITIVA
                            do {
                                printf("Digite o valor total da licenca: ");
                                scanf("%f", &preco[contador]);
                                if (preco[contador] <= 0) printf("Valor invalido!\n");
                            } while (preco[contador] <= 0);

                            do {
                                printf("Digite a quantidade de licenças: ");
                                scanf("%d", &quantidade[contador]);
                                if (quantidade[contador] <= 0) printf("Quantidade invalida!\n");
                            } while (quantidade[contador] <= 0);
                        } 
                        else {
                            // VENDA ASSINATURA
                            float mensal;
                            int meses;
                            do {
                                printf("Digite o valor da assinatura mensal: ");
                                scanf("%f", &mensal);
                                if (mensal <= 0) printf("Valor invalido!\n");
                            } while (mensal <= 0);

                            do {
                                printf("Digite o tempo do contrato (em meses): ");
                                scanf("%d", &meses);
                                if (meses <= 0) printf("Tempo invalido!\n");
                            } while (meses <= 0);

                            preco[contador] = mensal; 
                            quantidade[contador] = meses; 
                        }

                        tipo[contador] = 1; // IDENTIFICA COMO SOFTWARE
                        contador++;

                        printf("\nProduto cadastrado! Deseja outro Software? (S/N): ");
                        scanf(" %c", &continuar);
                    } else {
                        printf("\nERRO: LIMITE ATINGIDO!\n");
                        continuar = 'n';
                        system("pause");
                    }
                } while (continuar == 's' || continuar == 'S');
                break;
            }

            case 2: { // CADASTRO DE HARDWARE
                char continuar;
                do {
                    system("cls");
                    if (contador < MAX) {
                        printf("\n --- CADASTRO DE HARDWARE ---\n");
                        printf("Produto numero: %d\n", contador + 1);

                        printf("Digite o codigo do produto: ");
                        scanf("%d", &codigo[contador]);

                        do {
                            printf("Digite o preco do produto: ");
                            scanf("%f", &preco[contador]);
                            if (preco[contador] <= 0) printf("Valor invalido!\n");
                        } while (preco[contador] <= 0);
                        
                        do {
                            printf("Digite a quantidade: ");
                            scanf("%d", &quantidade[contador]);
                            if (quantidade[contador] <= 0) printf("Quantidade invalida!\n");
                        } while (quantidade[contador] <= 0);

                        tipo[contador] = 2; 
                        contador++;

                        printf("\nProduto adicionado! Deseja cadastrar outro Hardware? (S/N): ");
                        scanf(" %c", &continuar);
                    } else {
                        printf("\nERRO: LIMITE DE ITENS ATINGIDO!\n");
                        continuar = 'n';
                        system("pause");
                    }
                } while (continuar == 's' || continuar == 'S');
                break;
            }

            case 3: // EXIBIÇÃO DO CARRINHO
                system("cls");
                if (contador == 0) {
                    printf("\nO CARRINHO ESTÁ VAZIO!\n");
                } else { 
                    printf("\n --- RELATÓRIO DE CARRINHO TITANX --- \n");
                    printf("ID\tTIPO\t\tDETALHE\t\tPREÇO UNIT.\tQNT/MESES\n");
                    printf("----------------------------------------------------------------------\n");

                    for (int i = 0; i < contador; i++) {
                        printf("%d\t", codigo[i]);
                        
                        if (tipo[i] == 1) { // LÓGICA PARA SOFTWARE
                            printf("Software\t");
                            if (sub_tipo_sw[i] == 1) printf("Definitivo\t");
                            else printf("Assinatura\t");
                        } else { // LÓGICA PARA HARDWARE
                            printf("Hardware\tNormal\t\t");
                        }

                        printf("R$ %.2f\t\t%d\n", preco[i], quantidade[i]);
                    }
                    printf("----------------------------------------------------------------------\n");
                    printf("Total de itens distintos: %d\n", contador);
                }
                printf("\nPressione qualquer tecla para voltar ao menu...");
                system("pause > nul");
                break;
                
            case 4: // CÁLCULO DO ORÇAMENTO
                system("cls");
                if (contador == 0) {
                    printf("\nO carrinho esta vazio! Cadastre produtos primeiro.\n");
                } else {
                    float subtotal = 0;
                    float total_final = 0;

                    for (int i = 0; i < contador; i++) {
                        subtotal += (preco[i] * quantity_or_months_here); // Corrigido matematicamente para acumular no vetor
                        subtotal += (preco[i] * quantidade[i]);
                    }

                    // Removemos a duplicação acidental do loop anterior para manter o cálculo exato:
                    subtotal = 0;
                    for (int i = 0; i < contador; i++) {
                        subtotal += (preco[i] * quantidade[i]);
                    }

                    if (subtotal > 5000) {
                        total_final = subtotal * 0.90; 
                    } else {
                        total_final = subtotal;
                    }

                    printf("\n=================================");
                    printf("\n          ORCAMENTO TITANX        ");
                    printf("\n=================================");
                    printf("\nSUBTOTAL:        R$ %.2f", subtotal);
                    
                    if (subtotal > 5000) {
                        printf("\nDESCONTO (10%%): -R$ %.2f", subtotal * 0.10);
                    }

                    printf("\n---------------------------------");
                    printf("\nTOTAL A PAGAR:   R$ %.2f", total_final);
                    printf("\n=================================\n");
                }
                printf("\nPressione qualquer tecla para voltar...");
                system("pause > nul");
                break;

            case 5: // SAÍDA
                printf("\nEncerrando sistema TitanX. Ate logo!\n");
                system("pause");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                system("pause");
                break;
        }

    } while (opcao != 5);

    return 0;
}
