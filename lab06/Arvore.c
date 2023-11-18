#include "Arvore.h"
#include<stdio.h>
#include<stdlib.h>

int maximo(No *ap_arv){
    if(ap_arv->dir == NULL)
        return (ap_arv)->valor;
    
    return maximo((ap_arv)->dir);
}

/** Insere valor x na árvore de busca binária */
bool insere(Arvore* ap_arv, int x) {
     if((*ap_arv) == NULL){
       Arvore novo = (Arvore)malloc(sizeof(No));
       novo->valor = x;
       novo->esq = NULL;
       novo->dir = NULL;
       (*ap_arv) = novo;
       return true;
    }
    if(x==(*ap_arv)->valor) return false;    
    if(x<(*ap_arv)->valor){
        return insere(&(*ap_arv)->esq,x);
       
    }
    return insere(&(*ap_arv)->dir,x);
}


/** Remove valor x da árvore de busca binária. Em caso de nó com dois filhos, deve-se trocar de posição com o antecessor do nó removido e o remover então.  */
bool remove_(Arvore* ap_arv, int x){
    if((*ap_arv) == NULL) return false;

    if(x<(*ap_arv)->valor)
        return remove_(&(*ap_arv)->esq,x);

    if((*ap_arv)->valor<x)
        return remove_(&(*ap_arv)->dir,x);

    if((*ap_arv)->esq==NULL && (*ap_arv)->dir==NULL){
        //FOlha
        free(*ap_arv);
        *ap_arv = NULL;
        return true;
    }

    if((*ap_arv)->esq == NULL || (*ap_arv)->dir==NULL){
        No * Filho = ((*ap_arv)->esq == NULL ? (*ap_arv)->dir : (*ap_arv)->esq);
        No * rem = (*ap_arv);

        (*ap_arv) = Filho;
        free(rem);
        return true;
    }

    (*ap_arv)->valor = maximo((*ap_arv)->esq);
    remove_(&(*ap_arv)->esq,(*ap_arv)->valor);
}

/** Busca valor x na árvore de busca binária */
bool busca(Arvore arv, int x){
    if(arv == NULL) return false;

    if(arv->valor == x) return true;

    if(x<arv->valor){
       return busca((arv->esq),x);
    }
    
    return busca((arv->dir),x);
}

void imprime_rec(Arvore arv) {
  if (arv == NULL) {
    printf(".");
    return;
  }
  printf("[%d:e=", arv->valor);
  imprime_rec(arv->esq);
  printf(",d=");
  imprime_rec(arv->dir);
  printf("]");
}
/** Imprime a árvore de busca binária */
void imprime(Arvore arv) {
  imprime_rec(arv);
  printf("\n");
}
