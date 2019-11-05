#include <stdio.h>
#define tamanho 3
int indicador = tamanho;
int encontrado = 0;
int i, j;
int end = 0;
char vetor[tamanho];
char valor, valor2;
int inserir(void) {
    printf("digite o char \n");
    scanf(" %c", &valor);
    if (end == tamanho)
        printf("Lista cheia \n");
    else {
        vetor[end] = valor;
        end++;
    }
    if(indicador<tamanho)
        indicador++;
}
int consulta(void){
    encontrado = 0;
    printf("Informe o char para a consulta \n");
    scanf(" %c", &valor);
    for(i=0; i<tamanho; i++ ){
        if(vetor[i] == valor){
            printf("\n O char %c esta na posicao %d \n", valor, i+1);
            encontrado = 1;
        }
    }
    if(encontrado == 0)
        printf("char nao encontrado\n");
}
int remover(void){
    encontrado = 0;
    printf("Informe o char para a remocao \n");
    scanf(" %c", &valor);
    for(i=0; i<tamanho; i++ ){
        if(vetor[i] == valor){
            encontrado = 1;
            for(j = i; j<tamanho; j++){
                vetor[j] = vetor[j+1];
            }
        }
    }
    if(encontrado == 0) {
        printf("char nao encontrado\n");
    }
    vetor[indicador-1] = {};
    indicador--;
}
int atualizar(void){
    encontrado = 0;
    printf("Informe o char que sera atualizado \n");
    scanf(" %c", &valor);
    printf("Informe o novo char para %c \n", valor);
    scanf(" %c", &valor2);
    for(i=0; i<tamanho; i++ ){
        if(vetor[i] == valor){
            encontrado = 1;
            vetor[i] = valor2;
        }
    }
    if(encontrado == 0)
        printf("char nao encontrado\n");
}
int main(void){
    int opcao;
    do {
        printf("digite 0 para sair \n");
        printf("digite 1 para inserir \n");
        printf("digite 2 para consultar \n");
        printf("digite 3 para remover \n");
        printf("digite 4 para atualizar \n");
        scanf(" %d", &opcao);
        if (opcao == 1) {
            inserir();
        } else if(opcao == 2){
            consulta();
        }else if(opcao == 3){
            remover();
        }else if(opcao == 4){
            atualizar();
        }
    }while(opcao != 0);
    return 0;
}
