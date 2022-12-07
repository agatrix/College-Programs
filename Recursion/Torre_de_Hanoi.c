#include<stdio.h>

//This program utilizing the logic of tower of hanoi in recursion form.
//Logic developed with help Luigi Eliabe.

int torre(int discos){

    if(discos == 1){
        return 1;
    }
    
    return 2 * torre(discos-1) + 1;

}

int main(){
    int discos;

    scanf("%d",&discos);

    printf("%d",torre(discos));
}