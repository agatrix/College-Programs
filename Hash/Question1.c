#include<stdio.h>

typedef struct{
    int x, y;
    int status;
}Ponto;

int Hash(int x, int y);
void inicializa(Ponto *tabela);
void insere(Ponto *tabela, int x, int y);
int busca(Ponto *tabela, int x, int y);
void remover(Ponto *tabela, int x, int y);
int main(){
    int x, y;    
    
    Ponto tabela[10];    
    
    inicializa(tabela);
    for(int i=0;i<3;i++){
    scanf("%d%d",&x,&y);
    insere(tabela,x,y);
    }
    busca(tabela,x,y);
    remover(tabela,x,y);
    insere(tabela,2,2);
    for(int i=0; i<10;i++){
        printf("%d\n",tabela[i].status);
    }
    return 0;
}

int Hash(int x, int y){
    return (x+y)%10;
}

void inicializa(Ponto *tabela){
    
    for(int i=0;i<10;i++){
        tabela[i].status=0;
    }
}

void insere(Ponto *tabela, int x, int y){
    int pos = Hash(x,y);
    int count = 0;
    while(count!=10){
        if(tabela[pos].status != 1){
            tabela[pos].x = x;
            tabela[pos].y = y;
            tabela[pos].status = 1;
            return;
        }
    pos = Hash(pos,1);
    count++;
    }
}

int busca(Ponto *tabela, int x, int y){
    int count = 0;
    int pos = Hash(x,y);
    while(count!=10){
        if(tabela[pos].status == 0) return 1000;
        if(tabela[pos].x == x && tabela[pos].y == y){
            printf("%d %d\n",tabela[pos].x, tabela[pos].y);
            return pos;
        }
        count++;
    }
    return 1000;
}

void remover(Ponto *tabela, int x, int y){
    int pos = busca(tabela,x,y);
    if(pos!=1000){
        tabela[pos].status = 2;
        return;
    }
    return;
}
