#include <stdio.h>
#include <stdlib.h>

#define TAM 6

typedef struct{
    int vet[TAM];
    int F, R;
}filavet;

void enfileirar(int valor, filavet *p){
    if (p -> R == TAM-1){
        printf("\nFila Cheia!");
        exit(0);
    }
    p->R++;
    p->vet[p -> R] = valor;
}

int desenfileirar(filavet *p){
    int aux;
    if (p -> F == TAM){
        printf("\nFila Vazia");
        exit(1);
    }
    aux = p->vet[p->F];
    p->F++;
    return aux;
}

int main(){
    int opc;
        filavet fila;
        int valor;
        fila.R = -1;
        fila.F = 0;
        
        for (int i = 0; i<TAM; i++){
            printf("Digite o valor: ");
            scanf("%d", &valor);
            enfileirar(valor, &fila);
        }
        for (int i = 0; i<TAM; i++){
            printf("\nFileira %d: %d", i+1, desenfileirar(&fila));
        }
    
}