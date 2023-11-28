#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*STRUCTS*/
typedef struct aux
{
    struct aux *pai;
    struct aux *esq;
    struct aux *dir;
    int resultado;
    char op[50];
} No_Arv; // Nó das Arvores
typedef No_Arv *Arvore;

typedef struct no_aux
{
    No_Arv *a;
    struct no_aux *topo;
} No; // Nó que entrará na pilha
typedef No *Pilha;

/*FUNÇÕES*/
void Inicializa_Pilha(Pilha *p);

Arvore Cria_No_Arv(char y[], int x, bool ehop);

void Empilha(Pilha *p, Arvore X);

Arvore Desempilha(Pilha *p);

Arvore Add_Arv(Arvore esquerda, Arvore meio, Arvore direita);

void Percorre_Pre(Arvore raiz);
void Percorre_Pos(Arvore raiz);
int Prioridade(char y[]);

/*MAIN*/
int main()
{

    int x;
    char y[50]; // x = inteiros; y = Caracter das Operações
    Pilha p;
    Inicializa_Pilha(&p);
    int prio = 0;

    scanf("%d", &x);
    Arvore raiz = Cria_No_Arv(y, x, false);
    Empilha(&p, raiz);
    while (scanf("%s%d", y, &x) > 1)
    {
        if (prio > Prioridade(y))
        {
            Arvore direita = Desempilha(&p);
            Arvore meio = Desempilha(&p);
            Arvore esquerda = Desempilha(&p);
            Empilha(&p, Add_Arv(esquerda, meio, direita));
            raiz = meio;
        }
        prio = Prioridade(y);
        Empilha(&p, Cria_No_Arv(y, x, true));
        Empilha(&p, Cria_No_Arv(y, x, false));

    }

    while ((p)->topo->topo != NULL)
    {
        Arvore direita = Desempilha(&p);
        Arvore meio = Desempilha(&p);
        Arvore esquerda = Desempilha(&p);
        printf("HHH%sHHH",meio->op);
        Empilha(&p, Add_Arv(esquerda, meio, direita));
        raiz = meio;
    }
    
    Percorre_Pre(raiz);
    printf("\n");
    Percorre_Pos(raiz);
    printf("\n");
    printf("%d ",raiz->resultado);

    return 0;
}

void Inicializa_Pilha(Pilha *p)
{
    Pilha cab = (Pilha)malloc(sizeof(No));
    (*p) = cab;
    cab->topo = NULL;
    return;
}
Arvore Cria_No_Arv(char y[], int x, bool ehop)
{
    Arvore novo = (Arvore)malloc(sizeof(No_Arv));
    novo->pai = NULL;
    novo->esq = NULL;
    novo->dir = NULL;
    if (ehop)
    {
        novo->op[0] = *y;
        return novo;
    }
    novo->op[0] = '.';
    novo->resultado = x;
    return novo;
}

void Empilha(Pilha *p, Arvore X)
{
    Pilha novo = (Pilha)malloc(sizeof(No));
    novo->a = X;
    if (*p == NULL)
    {
        novo->topo = NULL;
    }
    else
    {
        novo->topo = *p;
    }
    *p = novo;
}

Arvore Desempilha(Pilha *p)
{
    if (*p == NULL)
        return NULL; // Caso a pilha esteja vazia

    Pilha remove = *p;
    Arvore no = (*p)->a;
    *p = (*p)->topo;
    /*if (remove->a->op[0] == '.')
        printf("%d ", remove->a->resultado);
    else
        printf("%s ", remove->a->op);*/
    free(remove);
    return no;
}

Arvore Add_Arv(Arvore esquerda, Arvore meio, Arvore direita)
{
    meio->dir = direita;
    meio->esq = esquerda;
    direita->pai = meio;
    esquerda->pai = meio;
    switch (meio->op[0])
    {
    case '+':
        meio->resultado = esquerda->resultado + direita->resultado;
        break;
    case '-':
        meio->resultado = esquerda->resultado - direita->resultado;
        break;
    case '*':
        meio->resultado = esquerda->resultado * direita->resultado;
        break;
    case '/':
        meio->resultado = esquerda->resultado / direita->resultado;
        break;
    case '%':
        meio->resultado = esquerda->resultado % direita->resultado;
        break;
    }

    return meio;
}

void Percorre_Pre(Arvore raiz)
{

    if (raiz == NULL)
        return;
    if (raiz->op[0] != '.')
        printf("%s ", raiz->op);
    else
        printf("%d ", raiz->resultado);

    Percorre_Pre(raiz->esq);
    Percorre_Pre(raiz->dir);
}

void Percorre_Pos(Arvore raiz)
{
    if (raiz == NULL)
        return;
    Percorre_Pos(raiz->esq);
    Percorre_Pos(raiz->dir);
    
    if (raiz->op[0] != '.')
        printf("%s ", raiz->op);
    else
        printf("%d ", raiz->resultado);
}

int Prioridade(char y[])
{
    if (y[0] == '*' || y[0] == '/')
        return 3;
    if (y[0] == '+' || y[0] == '-')
        return 2;
    if (y[0] == '%')
        return 1;
}
