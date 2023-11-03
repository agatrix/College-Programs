#include <stdio.h>
#include "lista.h"
#include <stdlib.h>

/* Inicializa a lista como lista vazia. */
void inicializa_lista(Lista * ap_lista) {
    *ap_lista = NULL;
}

/* Insere valor no fim da lista apontada por ap_lista. ap_lista aponta para o inicio da lista. */
void insere_fim(Lista * ap_lista, int valor) {
    Lista novo = (Lista) malloc (sizeof(No));
    novo -> valor = valor;
    novo -> proximo = NULL;

    if((*ap_lista)==NULL){
        *ap_lista = novo;
        return;
    }

    Lista atual = *ap_lista;
    while(atual->proximo !=NULL)
        atual = atual -> proximo;

    atual -> proximo = novo;
}

/* Insere valor no inicio da lista apontada por ap_lista. */
void insere_inicio(Lista * ap_lista, int valor){
    Lista novo = (Lista)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = (*ap_lista);
    *ap_lista = novo;
    return;
}

/* Remove valor do fim da lista apontada por ap_lista e retorna este valor. */
int remove_fim(Lista * ap_lista){
    if((*ap_lista==NULL))
        return -1;

    Lista *atual = ap_lista;
    while((*atual)->proximo!=NULL)
        atual = &((*atual)->proximo);

    int val = (*atual)->valor;
    free(*atual);
    *atual = NULL;
    return val;
}

/* Remove valor do inicio da lista apontada por ap_lista e retorna este valor. */
int remove_inicio(Lista * ap_lista) {
    if((*ap_lista)==NULL)
        return -1;

    Lista primeiro = *ap_lista;
    *ap_lista = primeiro->proximo;
    int val = primeiro->valor;
    free(primeiro);
    return val;
}

/* Remove todas as ocorrencias de valor da lista apontada por ap_lista. 
 * Retorna o numero de ocorrencias removidas.
 */
int remove_ocorrencias(Lista *ap_lista, int valor){
    if(*ap_lista==NULL)
        return 0;

    int cont = 0;
    Lista remove;
    Lista atual = *ap_lista;
    
    while((*ap_lista)!=NULL&&(*ap_lista)->valor == valor){
        *ap_lista=(*ap_lista)->proximo;
        free(atual);
        atual = (*ap_lista);
        cont++;
    }

    if((*ap_lista)==NULL)
        return cont;

    while(atual->proximo!=NULL){
        if(atual->proximo->valor == valor){
            remove=atual->proximo;
            atual->proximo=atual->proximo->proximo;
            free(remove);
            cont++;
        }else{
            atual=atual->proximo;
        }
    }
    return cont;
}

/* Busca elemento valor na lista. 
   Retorna a posição na lista, comecando de 0=primeira posicao.
   Retorna -1 caso nao encontrado.
*/
int busca(Lista lista, int valor) {
    if(lista==NULL)
        return -1;

    int cont = 0;
    while((lista->proximo!=NULL)&&(lista->valor!=valor)){
        cont++;
        lista=lista->proximo;
    }

    if((lista->proximo==NULL)&&(lista->valor!=valor))
        return -1;
    return cont;
}

/* Imprime a lista na saida padrao, no formato:
   (1,3,2,3,4,2,3,1,4)
   em uma linha separada.
 */
void imprime(Lista lista){
    if(lista==NULL){
            printf("()\n");
        return;
    }
    printf("(");
    while(lista->proximo!=NULL){
        printf("%d,",lista->valor);
        lista = lista->proximo;
    }
    printf("%d)\n",lista->valor);
    return;
}

/* Desaloca toda a memória alocada da lista.
 */
void desaloca_lista(Lista *ap_lista) {
    if((*ap_lista)==NULL)
        return;

    Lista atual = *ap_lista;
    while((*ap_lista)!=NULL){
        atual = *ap_lista;
        *ap_lista = (*ap_lista)->proximo;
        free(atual);
    }
    //*ap_lista=NULL;
    return;
}


/* Remove o i-ésimo elemento da lista, caso ele exista. Retorna se o elemento 
foi removido. As posições são contadas a partir de 1, sendo 1 a primeira posição. */
bool remove_i_esimo(Lista * ap_lista, int i) {
    if((*ap_lista)==NULL)
        return false;
    
    int cont = 1;
    Lista *atual = ap_lista;
    while(((*atual)->proximo!=NULL)&&(cont!=i)){
        atual = &((*atual)->proximo);
        cont++;
    }
    
    if(((*atual)->proximo==NULL)&&(cont!=i))
        return false;

    Lista remove = *atual;
    *atual = remove->proximo;
    free(remove);
    return true;
}

/* Retorna o valor do i-ésimo elemento da lista, caso ele exista. 
Retorna -1 caso contrário. As posições são contadas a partir de 1, sendo 1 a primeira posição. */
int recupera_i_esimo(Lista lista, int i) {
    if(lista==NULL)
        return -1;
    
    int cont=1;
    while((lista->proximo!=NULL)&&(cont!=i)){
        lista=lista->proximo;
        cont=cont+1;
    }

    if((lista->proximo==NULL)&&(cont!=i))
        return -1;
    return lista->valor;

}

/* Retorna o tamanho da lista. */
int tamanho(Lista lista) {
    if(lista==NULL)
        return 0;
    int i=1;
    while(lista->proximo!=NULL){
        i++;    
        lista=lista->proximo;
    }
    return i;
}

