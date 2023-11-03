#include<stdio.h>

int main(){
    
    int n, M;
    scanf("%d%d",&n,&M);;
    int pesoAcum, mask,  valorAcum, maskFin, count, countFin, pesoFin;
    int peso[n], valor[n];
    int valorFin = 0;
    

    for(int i=0; i<n; i++){
        scanf("%d%d",&peso[i],&valor[i]);
    }
   
    for(int j=0;j<(1<<n);j++){
        count = 0;
        mask = 0;
        valorAcum = 0;
        pesoAcum = 0;
        for(int k=0; k<n; k++){
            if((j&(1<<k))!=0){
                if(pesoAcum+peso[k]<=M){
                    pesoAcum += peso[k];
                    valorAcum += valor[k];
                    mask = mask | (1<<k);
                    count++;
                }
            }
        }
        if(valorAcum > valorFin){
            valorFin = valorAcum;
            maskFin = mask;
            pesoFin = pesoAcum;
            countFin = count;
        }
    }
    printf("%d %d\n%d ", pesoFin, valorFin, countFin);
    
    for(int i=0;i<n;i++){
        if((maskFin&(1<<i))!=0){
            if(countFin!=1){
                printf("%d ",i);
                countFin--;
            }else{
                printf("%d\n",i);
            }
        }
    }

    return 0;
}
