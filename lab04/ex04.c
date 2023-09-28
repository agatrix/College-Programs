#include<stdio.h>
#include<stdlib.h>

int main(){

	int n, q_conj, q_elem,valor;
	
	//n = Num Elementos; q_conj = Quantidade de Conjuntos; q_elem = Quantidade de Elementos

	scanf("%d%d",&n,&q_conj);
	int masc_bit[q_conj];

	for(int i=0; i<q_conj; i++){
		scanf("%d",&q_elem);
		for(int j=0;j<q_elem;j++){
			scanf("%d",&valor);
			masc_bit[i] =masc_bit[i] | (1<<valor);
		}
		printf("%d ",masc_bit[i]);

	}


	return 0;
}
