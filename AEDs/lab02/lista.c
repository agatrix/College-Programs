#include<stdio.h>
#include<stdlib.h>
#include "lista.h"
    
/* Inicializa a lista como lista vazia. */
void inicializa_lista(Lista * ap_lista){
    Lista cab = (Lista)malloc(sizeof(No));
    (*ap_lista) = cab;
    cab->prox = cab;
    cab->antec = cab;
}

/* Insere valor no fim da lista apontada por ap_lista. ap_lista aponta para o no cabeca da lista. */
void insere_fim(Lista ap_lista, TipoDado valor){
    Lista novo = (Lista)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = ap_lista;

    if(ap_lista->antec == ap_lista){
        novo->antec = ap_lista;
        ap_lista->prox = novo;
        ap_lista->antec = novo;
        return;
    }
    
    novo->antec = ap_lista->antec;
    (ap_lista->antec)->prox = novo;
    ap_lista->antec = novo;
    return;

}

/* Insere valor no inicio da lista apontada por ap_lista. ap_lista aponta para o no cabeca da lista. */
void insere_inicio(Lista ap_lista, TipoDado valor){
    
    Lista novo = (Lista)malloc(sizeof(No));
    novo->valor = valor;
    novo->antec = ap_lista;

    if(ap_lista->prox == ap_lista){
        ap_lista->prox = novo;
        ap_lista->antec = novo;
        novo->prox = ap_lista;  
        return;
    }
    novo->prox = ap_lista->prox;
    (ap_lista->prox)->antec = novo;
    ap_lista->prox = novo;
    return;
}

/* Remove valor do fim da lista apontada por ap_lista e retorna este valor. */
TipoDado remove_fim(Lista ap_lista){
    if(ap_lista->prox == ap_lista)
        return ap_lista->valor;
        

    Lista ult = ap_lista->antec;
    ap_lista->antec = ult->antec;
    ult->antec->prox = ap_lista;
    TipoDado val = ult->valor;
    free(ult);
    return val;
}

/* Remove valor do inicio da lista apontada por ap_lista e retorna este valor. */
TipoDado remove_inicio(Lista ap_lista){
    if(ap_lista == ap_lista->prox)
        return ap_lista->valor;

    Lista prim = ap_lista->prox;
    ap_lista->prox = prim->prox;
    prim->prox->antec = ap_lista;
    TipoDado val = prim->valor;
    free(prim);
    return val;
}

/* Remove todas as ocorrencias de valor da lista apontada por ap_lista. 
 * Retorna o numero de ocorrencias removidas. */
int remove_ocorrencias(Lista ap_lista, TipoDado valor){
    if(ap_lista==ap_lista->prox)
        return 0;

    int removidos = 0;
    Lista atual = ap_lista->prox;
    Lista remove;
    while((atual!=ap_lista)){
        if((atual->valor.coef==valor.coef)&&(atual->valor.grau==valor.grau)){
            remove = atual;
            atual->antec->prox = atual->prox;
            atual->prox->antec = atual->antec;
            atual = atual->prox;
            free(remove);
            removidos++;
        }else{
            atual = atual->prox;
        }
    }
    return removidos;
}

/* Busca elemento valor na lista. 
   Retorna a posição da primeira ocorrencia de valor na lista, comecando de 0=primeira posicao.
   Retorna -1 caso nao encontrado. */
int busca(Lista lista, TipoDado valor){
    if(lista==lista->prox)
        return -1;
    
    int pos = 0;
    Lista atual = lista->prox;
    while((atual!=lista)&&((atual->valor.coef!=valor.coef)||(atual->valor.grau!=valor.grau))){
        atual=atual->prox;
        pos++;
    }
    
    if(atual==lista)
        return -1;
    return pos;

}

/* Retorna o campo coef do primeiro no que contenha grau igual ao parametro grau, 
   e 0 (zero) caso nao encontre um tal no.  */
int coeficiente_do_grau(Lista lista, int grau){
    if(lista==lista->prox)
        return 0;

    Lista atual = lista->prox;
    while((atual!=lista)&&(atual->valor.grau!=grau))
        atual=atual->prox;

    if(atual==lista)
        return 0;
    return atual->valor.coef;
}

/* Imprime a lista na saida padrao, no formato:
   [(1,3),(2,3),(4,2),(3,1),(4,17)]
   em uma linha separada. */
void imprime(Lista lista){
    if(lista==lista->prox){
        printf("[]\n");
        return;
    }
    Lista atual = lista->prox;
    printf("[");
    while(atual->prox!=lista){
        printf("(%d,%d),",(atual->valor).grau,(atual->valor).coef);
        atual=atual->prox;
    }
    printf("(%d,%d)]\n",(atual->valor).grau,(atual->valor).coef);   
    return;
}

/* Desaloca toda a memória alocada da lista.
 */
void desaloca_lista(Lista *ap_lista){
    if((*ap_lista)->prox==(*ap_lista)){
        free(*ap_lista);
        return;
    }
    Lista atual = (*ap_lista)->prox;
    Lista f;
    while(atual!=(*ap_lista)){
        f = atual;
        atual = atual->prox;
        free(f);
    }
    free(atual);
    return;

    
    
}

