#include<stdio.h>

int main(){
    char conj[4] = {'A','B','C','D'};
    int mask = 0;
    int uniao;
    for(mask=0;mask<(1<<4);mask++){
    uniao = 0;
        for(int j=0;j<4;j++){
            if((mask & (1<<j)) != 0){
                uniao = uniao | (1<<j);
            }
        }
        for(int i=0; i<4; i++){
          if((uniao!=11)&&((uniao!=10))){
            if((uniao&(1<<i))!=0){
                printf("%c ",conj[i]);
                }
          }
        }
        printf("\n");
    }


    return 0;
}
