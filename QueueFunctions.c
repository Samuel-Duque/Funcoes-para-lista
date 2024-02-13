#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct no{
    int numero;
    struct no *prox;
}No;

typedef struct fila{
    No *inicio;
    No *fim;
}Fila;

Fila *criaFila(){
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void insereFila(Fila *f, int numero){
    No *novo = (No*)malloc(sizeof(No));
    novo->numero = numero;
    novo->prox = NULL;
    if(f->inicio == NULL){
        f->inicio = novo;
        f->fim = novo;
    }else{
        f->fim->prox = novo;
        f->fim = novo;
    }
}

int removeFila(Fila *f){
    No *aux = f->inicio;
    int numero = aux->numero;
    f->inicio = f->inicio->prox;
    free(aux);
    return numero;
}

void imprimeFila(Fila *f){
    No *aux = f->inicio;
    while(aux != NULL){
        printf("%d ", aux->numero);
        aux = aux->prox;
    }
    printf("\n");
}

int filaVazia(Fila *f){
    return f->inicio == NULL;
}

int tamanhoFila(Fila *f){
    No *aux = f->inicio;
    int cont = 0;
    while(aux != NULL){
        cont++;
        aux = aux->prox;
    }
    return cont;
}


void CompararFilas(Fila *f1, Fila *f2){

    if (tamanhoFila(f1) == tamanhoFila(f2)){
        printf("O tamanho das filas eh igual\n");
    }
    else{
        printf("As filas tem tamanhos diferentes\n");
        printf("Fila 1: %d\n", tamanhoFila(f1));
        printf("Fila 2: %d\n", tamanhoFila(f2));
        printf("A maior fila eh a \'%d\'\n", (tamanhoFila(f1) > tamanhoFila(f2)) ? 1 : 2);
    }
    
}

void TransferirFila(Fila *f1, Fila *f2){
    
    while(!filaVazia(f1)){
        insereFila(f2, removeFila(f1));
    }

}

void MaiorMenorMedia(Fila *f){
    if (f->inicio == NULL){
        printf("A fila esta vazia");
        return;
    }
    No *aux = f->inicio;
    int media = 0;
    int cont = 0;
    int maior = aux->numero;
    int menor = aux->numero;

    while (aux != NULL){
        if (aux->numero > maior){
            maior = aux->numero;
        }
        if(aux->numero < menor){
            menor = aux->numero;
        }
        media += aux->numero;
        cont++;
        aux = aux->prox;
    }
    media = media/cont;
    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    printf("Media: %d\n", media);
}

int VerificaImpares(Fila *f){
    No *aux = f->inicio;
    int cont = 0;
    while (aux != NULL)
    {
        if(aux->numero % 2 != 0)
            cont++;

        aux = aux->prox;
    }

    return cont;
}

int VerificaPares(Fila *f){
    No *aux = f->inicio;
    int cont = 0;
    while (aux != NULL)
    {
        if(aux->numero % 2 == 0)
            cont++;
        
        aux = aux->prox;
    }

    return cont;
}


int main(){
    srand(time(NULL));
    
    Fila f1 = *criaFila();
    Fila f2 = *criaFila();
    int opcao;

    criaFila(&f1);
    criaFila(&f2);

    for(int i = 0; i < rand()%20; i++){
        insereFila(&f1, rand()%100);
    }
    for(int i = 0; i < rand()%20; i++){
        insereFila(&f2, rand()%100);
    }

    while (opcao != 0){


        printf("\nFila 1:");
        imprimeFila(&f1);
        printf("Fila 2:");
        imprimeFila(&f2);
        
        printf("\n\nDigite a opcao desejada\n");
        printf("1 - Transferir elementos da fila 1 para a fila 2\n");
        printf("2 - Comparar filas\n");
        printf("3 - Maior/Menor/Media da fila\n");
        printf("4 - Numero de impares na fila\n");
        printf("5 - Numero de pares na fila\n");
        printf("0 - Sair\n");

        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)

        {
        case 1:

            TransferirFila(&f1, &f2);
            printf("Fila 1:");
            imprimeFila(&f1);
            printf("Fila 2:");
            imprimeFila(&f2);
            break;
        case 2:
            CompararFilas(&f1,&f2);
            break;
        case 3:
            printf("\nFila 1:\n");
            MaiorMenorMedia(&f1);
            printf("\nFila 2:\n");
            MaiorMenorMedia(&f2);
            break;
        case 4:
            printf("\nImpares na fila 1: %d\n", VerificaImpares(&f1));
            printf("Impares na fila 2: %d\n", VerificaImpares(&f2));
            break;

        case 5:
            printf("\nPares na fila 1: %d\n", VerificaPares(&f1));
            printf("Pares na fila 2: %d\n", VerificaPares(&f2));
            break;

        default:
            break;
        }
        
        }
    return 0;
}