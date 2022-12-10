#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int valor;
    struct No * proximo;
} No;

typedef struct pilha {
    struct No * topo;
    int max_items;
    int qty;
} pilha;

int isFull(pilha pilha)
{
    if(pilha.qty == pilha.max_items){
        return 1;
    }
    return 0;
}

int Tamanhopilha(pilha pilha)
{
    return pilha.qty;
}

int isEmpty(pilha pilha)
{
    if(pilha.qty == 0){
        return 1;
    }
    return 0;
}

int contem(pilha pilha, int valor)
{
    No * atual = pilha.topo;
    for(int i = 0; i<pilha.qty ; i++){
        if(atual->valor == valor){
            return 1;
        }
        else{
            atual = atual->proximo;
        }
    }
    return 0;
}

void exibirpilha(pilha * pilha)
{
  No * atual = pilha->topo;

  printf("A pilha tem: :\n");
  for(int i = 0; i<pilha->qty; i++){
    printf("%d\n",atual->valor);
    atual = atual->proximo;
  }
}

void push(pilha * pilha, int value)
{
    if(pilha->max_items == pilha->qty && pilha->qty != 0){
        printf("Pilha está cheia\n");
        return ;
    }
    No * atual = (No*) malloc(sizeof(No));
    atual->valor = value;
    atual->proximo = pilha->topo;
    pilha->topo = atual; 
    pilha->qty++;
}

int pop(pilha * pilha)
{
    No * atual = pilha->topo;
    int valor = atual->valor;
    pilha->topo = atual->proximo;
    pilha->qty--;
    free(atual);
    return valor;
}

int main(void){
  pilha pilha;
  pilha.qty = 0;
  pilha.max_items = 10;

}
