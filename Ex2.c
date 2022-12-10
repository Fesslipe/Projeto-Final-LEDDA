#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No * proximo;
}No;

typedef struct Queue {
    No * comeco;
    No * fim; 
    int max_items;
    int qty;
} queue;

int isFull(queue fila){
  if(fila.qty == fila.max_items){
    return 1;
  }
  return 0;
}

int quantidadequeue(queue fila){
  return fila.qty;
}

int isEmpty(queue fila){
  if(fila.qty == 0){
    return 1;
  }
  return 0;
}

int contem (queue fila, int number)
{
  No * atual = fila.comeco;

  for(int i = 0; i<fila.qty ; i++){
    if(atual->valor == number){
      return 1;
    }
    else{
      atual = atual->proximo;
    }
  }
    return 0;
}

void mostarqueue(queue fila)
{
    No * atual = fila.comeco;
    for(int i = 0; i<fila.qty; i++){
      printf("%d\n", atual->valor);
      atual = atual->proximo;
    }
}

void enqueue (int valor, queue * fila)
{
    if(fila->max_items == fila->qty && fila->qty != 0){
        printf("Fila está cheia");
        return ;
    }
    No * atual = (No *) malloc(sizeof(No));
    if(fila->qty == 0){
    atual->valor = valor;
    fila->fim = atual;
    fila->qty++;
    printf("VALOR %d ADICIONADO AO FINAL DA FILA\n", fila->tail->number);
    }else{
    atual = fila->fim;
    No * novo = (No *) malloc(sizeof(No));
    novo->valor = valor;
    atual->proximo = novo;
    fila->fim = novo;
    fila->qty++;
    }
}

int dequeue(queue * fila)
{
    No * atual = fila->comeco;
    int valor = atual->valor;
    fila->comeco = atual->proximo;
    fila->qty--;

    free(atual);
    return valor;
}

int main(void) {
  queue myQueue;
  myQueue.qty = 0;
  myQueue.max_items = 10;

  return 0;
}