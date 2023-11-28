#include<stdio.h>
#include<stdbool.h>

typedef enum{
    SOMA,
    SUB,
    MULT,
    DIV,
    MOD
}op_tipo;

typedef struct no_aux{
    struct no_aux * esq;
    struct no_aux * dir;
    bool op_; //Define se esse nó é de um tipo de operação ou um valor
    op_tipo op;
    int valor;
}No;

No * cria_valor(int x);
No * cria_op(op_tipo y, No * e, No * d);

int main(){
    char y[50]; int x;
 
    scanf("%d",&x);
    printf("%d ",x);
    while(scanf("%s%d",y,&x)>1){
        printf("%s %d ",y,x); 
    }
    printf("a");
    return 0;
}

/*No * cria_valor(int x){
    No * novo = malloc(sizeof(No));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->valor = x;
    novo->op_ = false;
    return novo;
}

No * cria_op(op_tipo y, No * e, No * d){
    No * novo = malloc(sizeof(No));
    novo->esq = e;
    novo->dir = d;
    novo->op_ = true;
    novo->op = y;
    return novo;
} */
