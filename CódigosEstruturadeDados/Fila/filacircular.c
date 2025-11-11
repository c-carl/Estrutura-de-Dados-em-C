#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct{
    int R,F,Q;
    int vet[TAM];
}filacircular;

void enfileirar(int valor, filacircular *p){
    if(p->Q == TAM){
        printf("\nFila Cheia");
        exit(0);
    }
    if(p->R == TAM-1)
        p->R=0;
    else
        p->R++;
    p->vet[p->R]=valor;
    p->Q++;
}

int desenfileirar(filacircular *p){
    int aux;
    if(p-> Q ==0){
        printf("\n Fila vazia!");
        exit(1);
    }
    aux = p -> vet[p->F];
    if(p->F == TAM-1)
        p -> F =0;
    else
        p -> F++;
    p -> Q--;
    return aux;
}

int main(){
    filacircular fila;
    fila.R = -1;
    fila.F = 0;
    fila.Q = 0;
    int valor;
    int opc;
    
    do{
    for(int i =0; i < TAM; i++){
        printf("Digite o valor a ser enfileirado: ");
        scanf("%d",&valor);
        enfileirar(valor,&fila);
    }
    for(int i = 0; i < TAM; i++){
        printf("\nFileira %d: %d", i+1, desenfileirar(&fila));
    }
    
    printf("\n\nDeseja continuar no sistema? (0 = não | 1 = sim) ");
    scanf("%d", &opc);
    
    }while(opc != 0);
}