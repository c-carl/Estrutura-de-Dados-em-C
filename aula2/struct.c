#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int mat;
    char nome[40];
    float nota;
}aluno;

int main(void){
    aluno ed[3];
    aluno java[3];
    printf("==============================================");
    printf("\n|          Turma de Estrutura de Dados       |\n");
    printf("==============================================");
    for(int i=0; i<3; i++){
        printf("\n");
        printf("\nDigite a matricula do %d° aluno: ", i+1);
        scanf("%d", &ed[i].mat);
        printf("\nDigite a nota do %d° aluno: ", i+1);
        scanf("%f", &ed[i].nota);
        getchar();
        printf("\nDigite o nome do %d° aluno: ", i+1);
        fgets(ed[i].nome, sizeof(ed[i].nome), stdin);
        ed[i].nome[strcspn(ed[i].nome, "\n")] = '\0';
        printf("\n");
        printf("==============================================");
    }printf("\n");
    printf("\n==============================================");
    printf("\n|                Turma de Java               |");
    printf("\n==============================================");
    for(int i=0; i<3; i++){
        printf("\n");
        printf("\nDigite a matrciula do %d° aluno: ", i+1);
        scanf("%d", &java[i].mat);
        printf("\nDigite a nota do %d° aluno: ", i+1);
        scanf("%f", &java[i].nota);
        getchar();
        printf("\nDigite o nome do %d° aluno: ", i+1);
        fgets(java[i].nome, sizeof(java[i].nome), stdin);
        java[i].nome[strcspn(java[i].nome, "\n")] = '\0';
        printf("\n");
        printf("==============================================");
    }
    
    printf("\n==============================================");
    printf("\n| Informações da Turma de Estrutura de Dados |\n");
    printf("==============================================\n");
    for (int i = 0; i < 3; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("  Nome: %s\n", ed[i].nome);
        printf("  Matrícula: %d\n", ed[i].mat);
        printf("  Nota: %.2f\n\n", ed[i].nota);
    }
    
    printf("==============================================\n");
    printf("|         Informações da Turma de Java       |\n");
    printf("==============================================\n");
    for (int i = 0; i < 3; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("  Nome: %s\n", java[i].nome);
        printf("  Matrícula: %d\n", java[i].mat);
        printf("  Nota: %.2f\n\n", java[i].nota);
    }
    
    printf("==============================================\n");
    printf("|       Alunos presentes nas duas turmas     |\n");
    printf("==============================================\n");
    int encontrados = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (ed[i].mat == java[j].mat) {
                printf("  %s (Matrícula: %d)\n", ed[i].nome, ed[i].mat);
                encontrados++;
            }
        }
    }

    if (encontrados == 0) {
        printf("  Nenhum aluno está nas duas turmas.\n");
    }

    return 0;
}