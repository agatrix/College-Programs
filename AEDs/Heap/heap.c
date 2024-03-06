#include<stdio.h>
#include<stdlib.h>

void troca(int vetor[], int i, int im);
void desce(int vetor[], int tam, int i);
void sobe(int vetor[], int tam, int i);
void insere(int vetor[], int *n, int x);
void printa(int vetor[],int tam);
void rem(int vetor[],int *n);

int main(){
    int tam = 5;
    int d = 0;
    int x;
    int *vetor = (int *)malloc(tam*sizeof(int));

    for(int i = 0; i < tam; i++){
        scanf("%d",&vetor[i]);
    }
    printa(vetor,tam);

    desce(vetor,tam,0);
    printf("Inserir? ");
    scanf("%d",&d);
    while(d==1){
        scanf("%d",&x);
        insere(vetor, &tam, x);
        printf("Inserir? ");
        scanf("%d",&d);
    }
    printa(vetor,tam);
    rem(vetor,&tam);
    printa(vetor,tam);
    

    return 0;
}   

void troca(int vetor[], int i, int im){
    int aux = vetor[im];
    vetor[im] = vetor[i];
    vetor[i] = aux;
    return;
}

void desce(int vetor[], int tam, int i){
    int fe = (2*i)+1;
    int fd = (2*i)+2;

    if(fe >= tam) return;
    int im = i;

    if(vetor[im] < vetor[fe]) im = fe;
    if((fd < tam) && (vetor[im]<vetor[fd])) im = fd;

    if(i!=im){
        troca(vetor,i,im);
        desce(vetor,tam,im);
    }
    desce(vetor,tam,i+1);
}

void sobe(int vetor[], int tam, int i){
    if(i==0) return;
    int pai = (i-1)/2;

    if(vetor[pai] < vetor[i]){
        troca(vetor,pai,i);
        sobe(vetor,tam,pai);
    }
}

void insere(int vetor[], int *n, int x){
    int *novo = (int *)realloc(vetor,1*sizeof(int));
    vetor = novo;

    vetor[*n] = x;
    (*n)++;
    sobe(vetor,*n,(*n)-1);
}

void printa(int vetor[],int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ",vetor[i]);
    }
    printf("\n");
}

void rem(int vetor[],int *n){
    if((*n)==0){
        free(vetor);
        return;
    }

    vetor[0] = vetor[(*n)-1];
    (*n)--;
    desce(vetor,*n,0);
}