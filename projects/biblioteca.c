// ==========================================================================
// PRÁTICA: SISTEMA DE BIBLIOTECA - PARTE 1
//
// OBJETIVO DESTA PARTE:
// Implementar o cadastro e a listagem de livros usando um array estátivo.
// Foco em structs, entrada/saída de dados e organização básica.
//
//
// ==========================================================================

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> // Para strcpn()

// --- Constantes Globais ---
#define MAX_LIVROS 50
#define TAM_STRING 100

// --- Definição da Estrutura (struct) ---
struct Livro {
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};

// --- Função para limpar o buffer de entrada ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Função Principal (main) ---
int main(){
    struct Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    // --- Laço Principal do Menu ---
    do {

        // Exibe o menu de opções.
        printf("==========================================\n");
        printf("      BIBLIOTECA - PARTE 1\n");
        printf("==========================================\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("0 - Sair\n");
        printf("------------------------------------------\n");
        printf("Escolha uma opção: ");

        // Lê a opção do usuário.
        scanf("%d", &opcao);
        limparBufferEntrada(); //Limpa o '\n' deixado pelo scanf.

        // --- Processamento da Opção ---
        switch (opcao) {
            case 1: // CADASTRO DE LIVRO
                printf("\n--- Cadastro de Novo Livro ---\n\n");

                if (totalLivros < MAX_LIVROS) {
                    printf("Digite o nome do livro: ");
                    fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

                    printf("Digite o autor: ");
                    fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

                    printf("Digite a editora: ");
                    fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

                    biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
                    biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
                    biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

                    printf("Digite a edicao: ");
                    scanf("%d", &biblioteca[totalLivros].edicao);
                    limparBufferEntrada();

                    totalLivros++;
                    // total livros = totalLivros +1;

                    printf("\nLivro cadastrado com sucesso! \n");
                } else {
                    printf("Biblioteca cheia! Nao é possivel cadastrar mais livros. \n");
                }

                printf("\nPressione Entrar para continuar...");
                getchar(); // Pausa para o usuário ler a mensagem antes de voltar ao menu.
                break;
            
            case 2: //LISTAGEM DE LIVROS
                printf("\n=== Lista de Livros Cadastrados ===\n");

                if (totalLivros == 0){
                    printf("\nNenhum livro cadastrado ainda. \n");
                } else {
                    for (int i=0; i < totalLivros; i++){
                        printf("======================================\n");
                        printf("LIVRO %d\n", i + 1);
                        printf("Nome: %s\n", biblioteca[i].nome);
                        printf("Autor: %s\n", biblioteca[i].autor);
                        printf("Editora: %s\n", biblioteca[i].editora);
                        printf("Edicao: %d\n", biblioteca[i].edicao);
                    }
                     printf("=========================================\n");
                }


                // A pausa é crucial para que o usuário veja a lista antes
                // do problema loop limpar tela.
                printf("\nPressione Enter para continuar...");
                getchar();
                break;

            case 0: //SAIR
                printf("\nSaindo do sistema");
                break;

            default: //OPÇÃO INVÁLIDA
                printf("\nOpcao invalida! Tente novamente. ");
                printf("\nPressione Enter para continuar... ");
                getchar();
                break;
        }

    } while (opcao != 0);

    return 0; //Fim do programa

}