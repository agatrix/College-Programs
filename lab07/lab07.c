#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*STRUCTS*/
typedef struct aux{
    struct aux * pai;
    struct aux * esq;
    struct aux * dir;
    int resultado;
    char op[50];
}No_Arv;      //Nó das Arvores
typedef No_Arv * Arvore;

typedef struct no_aux {
    No_Arv * a;
    struct no_aux * topo;
}No; //Nó que entrará na pilha
typedef No * Pilha;


/*FUNÇÕES*/
void Inicializa_Pilha(Pilha * p);

Arvore Cria_No_Arv(char y[], int x, bool ehop);

void Empilha(Pilha *p, Arvore X);

void Desempilha(Pilha *p);

int Prioridade(char y[]);

/*MAIN*/
int main(){

    int x; char y[50]; //x = inteiros; y = Caracter das Operações
    Pilha p;
    Inicializa_Pilha(&p);
    int prio = 0;

    scanf("%d",&x);
    Empilha(&p,Cria_No_Arv(y,x,false));
    while(scanf("%s%d",y,&x)>1){
        if(prio < Prioridade(y)){
            prio = Prioridade(y);
            Empilha(&p,Cria_No_Arv(y,x,true));
            Empilha(&p,Cria_No_Arv(y,x,false));
            Desempilha(&p);     
            Desempilha(&p);       
        }
    }   
    
    return 0;
}

void Inicializa_Pilha(Pilha * p){
    Pilha cab = (Pilha)malloc(sizeof(No));
    (*p) = cab;
    cab->topo = NULL;
    return;
}
Arvore Cria_No_Arv(char y[], int x, bool ehop){
    Arvore novo = (Arvore)malloc(sizeof(No_Arv));
    novo->pai = NULL; 
    novo->esq = NULL; 
    novo->dir = NULL; 
    if(ehop){
        novo->op[0] = *y;
        return novo;
    }
    novo->op[0] = '.';
    novo->resultado = x;
    return novo;
}

void Empilha(Pilha *p, Arvore X){
    Pilha novo = (Pilha)malloc(sizeof(No));
    novo->a = X;
    if(*p == NULL){
        novo->topo = NULL;
    }else{
        novo->topo = *p;
    }
    *p = novo;
}

void Desempilha(Pilha *p){
    if(*p == NULL) return; //Caso a pilha esteja vazia

    Pilha remove = *p;
    *p = (*p)->topo;
    if(remove->a->op[0] == '.')
        printf("%d ",remove->a->resultado);
    else 
        printf("%s ",remove->a->op);
    free(remove);
    return;
}

int Prioridade(char y[]){
    if(y[0] == '*' || y[0] == '/') return 3;
    if(y[0] == '+' || y[0] == '-') return 2;
    if(y[0] == '%') return 1;
}
