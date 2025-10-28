#include <stdio.h>

typedef struct{
    int id;
    char marca[30];
    char modelo[30];
    int ano;
    float tanque;
    float consumo;
}carro;

carro cadastrar(void){
    carro c;
    printf("\nID: ");
    scanf("%d", &c.id);
    printf("\nMarca: ");
    scanf("%29s", &c.marca);
    printf("\nModelo: ");
    scanf("%29s", &c.modelo);
    printf("\nAno: ");
    scanf("%d", &c.ano);
    printf("\nTanque: ");
    scanf("%f", &c.tanque);
    printf("\nConsumo (km/l): ");
    scanf("%f", &c.consumo);
    return c;
}
void imprimir(carro c){
    printf("\nID: %d \nMarca: %s \nModelo: %s \nAno: %d ", c.id, c.marca, c.modelo, c.ano);
    printf("Tanque: %1.f \nConsumo(kml/l): %1.f \nAutonomia: %1.f\n", c.tanque, c.consumo, c.tanque*c.consumo);
}

int main(void){
    int n;
    printf("Quantos carros serão cadastrados?\n ");
    scanf("%d", &n);
    carro veiculos[n];
    for(int i=0; i<n; i++){
    printf("\n=============== Cadastro do %d° Carro ==================", i+1);
        veiculos[i] = cadastrar();
    }
    printf("\n============ Lista de Carros de Autonomia ==============");
    for(int i=0; i<n; i++){
        imprimir(veiculos[i]);
    }
    return 0;
}