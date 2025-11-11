#include <stdio.h>

typedef struct{
    char nome[40];
    int idade;
    float renda;
}contribuintes;

int main(){
    int n;
    printf("============== Formulário ==============");
    printf("\nDigite a quantidade de contribuintes: ");
    scanf("%d", &n);
    contribuintes pessoas[n];
    
    int menor = 0;
    int isentas = 0;
    
    for (int i=0; i<n; i++){
        printf("\nNome: ");
        scanf(" %39[^\n]", pessoas[i].nome);
        printf("ldade: ");
        scanf("%d", &pessoas[i].idade);
        printf("Renda Anual: ");
        scanf("%f", &pessoas[i].renda);
        
        if(pessoas[i].idade<18)
            menor++;
        if(pessoas[i].renda<=28559.70)
            isentas++;
    }
    
    printf("\n============== Resultados ==============");
    printf("\n%d pessoas são menores que 18 anos", menor);
    printf("\n%d pessoas são isentas de impostos\n", isentas);
    printf("\n================ Usuário ===============");
    for(int i=0; i<n; i++){
        printf("\nNome: %s", pessoas[i].nome);
        printf("\nIdade: %d", pessoas[i].idade);
        printf("\nRenda Anual: %1.f", pessoas[i].renda);
        printf("\n========================================");
    }
}