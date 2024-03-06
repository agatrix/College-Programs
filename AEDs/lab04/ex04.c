#include<stdio.h>
#include<stdlib.h>

void cria_mask(int mask[], int q_conj);
void comp_mask(int mask[], int uni, int mask_mask, int q_conj,int n);
void imprime(int mask_mask, int q_conj, int mask[], int n);

int main(){

	int n, q_conj, q_elem,valor;
	
	//n = Num do intervalo; q_conj = Quantidade de Conjuntos; q_elem = Quantidade de Elementos

	scanf("%d%d",&n,&q_conj);
	int masc_bit[q_conj];
    int universo, masc_masc=0;

    universo = (1<<n)-1; //Cria a variavel com todos os bits igual a 1 

    cria_mask(masc_bit,q_conj);  
    comp_mask(masc_bit, universo, masc_masc, q_conj,n);

   // printf("%d",masc_bit[0]);
	return 0;
}

void cria_mask(int * mask, int q_conj){
	int q_elem, valor;
    for(int i=0; i<q_conj; i++){
        mask[i] = 0;
		scanf("%d",&q_elem);

		for(int j=0;j<q_elem;j++){
			scanf("%d",&valor);
			mask[i] =mask[i] | (1<<valor);
		}
	}
}

void imprime(int mask_mask, int q_conj, int mask[],int n){
    int count=0;

    for(int i=0;i<q_conj;i++){
        if((mask_mask&(1<<i))!=0){
            count++;
        }
    }
    printf("%d\n",count);

    for(int i=0;i<q_conj;i++){
        count = 0;
        if((mask_mask&(1<<i))!=0){
          for(int z=0;z<n;z++){
               if((mask[i]&(1<<z))!=0){
                  count++;
               }
           }
           printf("%d ",count);
           for(int j=0;j<n;j++){
                if((mask[i]&(1<<j))!=0){
                    count--;
                    if(count!=0){
                        printf("%d ",j);
                    }else{
                        printf("%d",j);
                    }
                }
           }
           printf("\n");
        }
    }
}

void comp_mask(int mask[], int universo, int mask_mask, int q_conj,int n){
    int uniao;
 
    for(int i=0; i<q_conj;i++){
        uniao = 0;
        mask_mask = 0;
        for(int j = 0; j<q_conj; j++){
            if((((mask[i]&mask[j])) == 0)&&((mask[j]&uniao)==0)){
                uniao = uniao|mask[i]|mask[j];
                mask_mask = mask_mask | (1<<i) | (1<<j);
            }
        }
        if((universo & uniao) == universo){
            imprime(mask_mask,q_conj,mask,n);
            return;
        }
    }
    printf("Insoluvel\n");
}


