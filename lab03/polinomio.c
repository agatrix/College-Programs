#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "polinomio.h"

/* Inicializa um polinômio vazio. */
void inicializa_polinomio(Polinomio * ap_pol){
    Polinomio cab = (Polinomio)malloc(sizeof(No));
    (*ap_pol) = cab;
    cab->prox = cab;
    cab->antec = cab;

}
/* Define que o coeficiente de grau grau do polinomio pol eh igual a coef. Deve manter os coeficientes ordenados por grau. */
void define_coeficiente(Polinomio pol, int grau, int coef){
    if(coef==0)
        return;

    Polinomio novo = (Polinomio)malloc(sizeof(No));
    novo->valor.grau = grau;
    novo->valor.coef = coef;
    if(pol==pol->prox){
        pol->prox = novo;
        pol->antec = novo;
        novo->prox = pol;
        novo->antec = pol;
        return;
    }
    Polinomio atual = pol->prox;
    while(atual!=pol){
        if(grau<=atual->valor.grau){
            if(grau==atual->valor.grau){
                atual->valor.coef+=coef;
                if(atual->valor.coef==0){
                    Polinomio aux = atual;
                    atual=atual->prox;
                    atual->antec = aux->antec;
                    aux->antec->prox = atual;
                    free(aux);
                }
                free(novo);
                return; 
            }
            novo->prox = atual;
            novo->antec = atual->antec;
            atual->antec->prox = novo;
            atual->antec = novo;
            return;
        }
        if(atual->prox==pol){
            atual->prox = novo;
            novo->prox = pol;
            novo->antec = atual;
            pol->antec = novo;
            return;
        }
        atual=atual->prox;
    }
}

/* Zera o polinomio, tornando-o um polinomio inicializado, mas igual a zero. Desaloca a memória liberada. */
void zera(Polinomio pol){
    Polinomio aux = pol->prox;

    if(aux==pol)
        return;

    Polinomio f;
    while(aux!=pol){
        f = aux;
        aux = aux->prox;
        free(f);
    }
    aux->prox = aux;
    aux->antec = aux;
    return;
}

/* Computa a soma dos polinomios a e b colocando o resultado em res.
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void soma(Polinomio res, Polinomio a, Polinomio b){
    
    if(res!=res->prox){
        Polinomio aux = res->prox;
        while(aux!=res){
            printf("%d x",aux->valor.grau);
            Polinomio f = aux;
            aux = aux->prox;
            free(f);
        }
        res->prox = res;
        res->antec = res;
    }
    int somado;
    Polinomio atuala = a->prox;
    Polinomio atualb = b->prox;
    while(atuala!=a){
        while(atualb!=b){
            if(atuala->valor.grau == atualb->valor.grau){
                somado = atuala->valor.coef+atualb->valor.coef;
                if(somado!=0)
                    define_coeficiente(res,atuala->valor.grau,somado);
                atuala = atuala->prox;
                atualb = atualb->prox;
                continue;
            }
                if(atuala!=b){
                define_coeficiente(res,atualb->valor.grau,atualb->valor.coef);
                atualb= atualb->prox;
                continue;
            }
        }
        if(atuala!=a){
                define_coeficiente(res,atuala->valor.grau,atuala->valor.coef);
                atuala = atuala->prox;
                continue;
            }

    }
    return;
}

/* Computa a subtracao dos polinomios a e b colocando o resultado em res.
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void subtrai(Polinomio res, Polinomio a, Polinomio b){

    if(res!=res->prox){
        Polinomio aux = res->prox;
        while(aux!=res){
            printf("%d x",aux->valor.grau);
            Polinomio f = aux;
            aux = aux->prox;
            free(f);
        }
        res->prox = res;
        res->antec = res;
    }
    int sub;
    Polinomio atuala = a->prox;
    Polinomio atualb = b->prox;
    while(atuala!=a){
        while(atualb!=b){
            if(atuala->valor.grau == atualb->valor.grau){
                sub = atuala->valor.coef-atualb->valor.coef;
                if(sub!=0){
                    define_coeficiente(res,atuala->valor.grau,sub);
                }
                atuala = atuala->prox;
                atualb = atualb->prox;
                continue;
            }
                if(atuala!=b){
                define_coeficiente(res,atualb->valor.grau,-atualb->valor.coef);
                atualb = atualb->prox;
                continue;
            }
        }
        if(atuala!=a){
                define_coeficiente(res,atuala->valor.grau,atuala->valor.coef);
                atuala = atuala->prox;
                continue;
        }

    }
    return;

}


/* Imprime o polinomio pol no formato do exemplo abaixo
 * [(0,2),(3,-2),(10,5)]
 * onde este polinomio tem 3 coeficientes, o de grau 0 com valor 2, o de grau 3 com valor -2 e o de
 * grau 10 com valor 5.
 */
void imprime(Polinomio pol){
    if(pol->prox==pol){
        printf("[]\n");
        return;
    }
    Polinomio atual = pol->prox;
    printf("[");
    while(atual->prox!=pol){
        printf("(%d,%d),",atual->valor.grau, atual->valor.coef);
        atual=atual->prox;
    }
    printf("(%d,%d)]\n",atual->valor.grau, atual->valor.coef);
    return;
}

/* Desaloca toda a memória alocada da lista. */
void desaloca_polinomio(Polinomio *ap_pol){
    Polinomio aux = (*ap_pol)->prox;
    Polinomio f;
    while(aux!=(*ap_pol)){
        f = aux;
        aux = (aux)->prox;
        free(f);
    }
    free(aux);
    return;
}

