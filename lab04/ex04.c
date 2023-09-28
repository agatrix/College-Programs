#include<stdio.h>
#include<stdlib.h>

void cria_mask(int mask[], int q_conj);
void comp_mask(int mask[], int uni, int mask_mask, int q_conj);


int main(){

	int n, q_conj, q_elem,valor;
	
	//n = Num do intervalo; q_conj = Quantidade de Conjuntos; q_elem = Quantidade de Elementos

	scanf("%d%d",&n,&q_conj);
	int masc_bit[q_conj];
    int universo, masc_masc=0;

    universo = (1<<n)-1; //Cria a variavel com todos os bits igual a 1 

    cria_mask(masc_bit,q_conj);  
    comp_mask(masc_bit, universo, masc_masc, q_conj);

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

void comp_mask(int mask[], int universo, int mask_mask, int q_conj){
    int uniao=0;
    
    for(int i=0; i<q_conj;i++){
        if((universo & uniao) == universo){printf("BOM"); break;}
        for(int j = i+1; j<q_conj; j++){
            if((mask[i]&mask[j]) == 0){
                uniao = uniao|mask[i]|mask[j];
                mask_mask = mask_mask | (1<<i) | (1<<j);
                printf("%d",mask_mask);
            }
        }
    }
    printf("UUU %d",uniao);
    printf("UN %d", universo);
}

