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

void Percorre_Pre(Arvore raiz, int x);
void Percorre_Pos(Arvore raiz, int x);
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
        while (prio >= Prioridade(y))
        {
            Arvore direita = Desempilha(&p);
            Arvore meio = Desempilha(&p);
            Arvore esquerda = Desempilha(&p);
            Empilha(&p, Add_Arv(esquerda, meio, direita));
            raiz = meio;
            if (p->topo->topo != NULL)               // Checa se possui mais operações, se true
                prio = Prioridade((p)->topo->a->op); // Armazena a prioridade do sinal
            else
                break; // se false, é o último elemento, então sai do while
        }
        // vai sair do while,no caso da prio do sinal atual for maior que a prio do sinal na pilha
        Empilha(&p, Cria_No_Arv(y, x, true));
        Empilha(&p, Cria_No_Arv(y, x, false));
        prio = Prioridade(y);
    }

    while ((p)->topo->topo != NULL)
    {
        Arvore direita = Desempilha(&p);
        Arvore meio = Desempilha(&p);
        Arvore esquerda = Desempilha(&p);
        Empilha(&p, Add_Arv(esquerda, meio, direita));
        raiz = meio;
    }

    Percorre_Pre(raiz, 0);
    printf("\n");
    Percorre_Pos(raiz, 0);
    printf("\n");
    printf("%d\n", raiz->resultado);

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

// Printa Raiz, depois Nó_Esq e por último Nó_Dir
void Percorre_Pre(Arvore raiz, int x)
{

    if (raiz == NULL)
        return;
    if (raiz->op[0] != '.')
        if (x != 0)
            printf(" %s", raiz->op);
        else
            printf("%s", raiz->op);
    else
        printf(" %d", raiz->resultado);

    Percorre_Pre(raiz->esq, 1);
    Percorre_Pre(raiz->dir, 1);
}

// Printa Nó_Esq, Nó_Dir e por último a Raiz
void Percorre_Pos(Arvore raiz, int x)
{
    if (raiz == NULL)
    {
        return;
    }
    Percorre_Pos(raiz->esq, 1);
    Percorre_Pos(raiz->dir, 1);

    if (x == 1)
        if (raiz->op[0] != '.')
            printf("%s ", raiz->op);
        else
            printf("%d ", raiz->resultado);
    else
        printf("%s", raiz->op);
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
