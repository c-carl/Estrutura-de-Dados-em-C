#include <stdio.h>
#include <stdlib.h>

typedef struct dupla{
    int dado;
    struct dupla *elink, *dlink;
} no;

no *crialde(int n){
    no *ini = NULL, *p, *aux = NULL;
    int valor;
    
    for (int i = 1; i <= n; i++){
        printf("\nDigite o valor %d da lista: ", i);
        scanf("%d", &valor);
        p = (no*) malloc(sizeof(no));
        p->dado = valor;
        p->elink = NULL;
        p->dlink = ini;
        if (ini != NULL)
            ini->elink=p;
        else
            aux = p;
        ini = p;
    }
    return aux;
}

void escrevelista(no *p){
    printf("\nLista:\n");
    while (p != NULL){
        printf("%d\t", p->dado * p->dado);
        p = p->elink;
    }
    printf("\n");
}

int main(){
    no *primeira;
    int n;
    printf("Criando uma lista encadeada\n");
    do {
        printf("\nEntre com o número de nós: ");
        scanf("%d", &n);
    }while (n<0);
    primeira = crialde(n);
    if (primeira != NULL){
        printf("\nLista Original:");
        escrevelista(primeira);
    } else {
        printf("\nLista Vazia");
    }
    return 0;
}