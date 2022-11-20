#include<stdio.h>
#include<stdlib.h>
//This program has the basics about dynamic allocation. (malloc, realloc, free...)

void allocation(int vector[], int size){    
    int i;

    for(i=0;i<size;i++)
        scanf("%d",&vector[i]);         //attributed valour to vector
}

void reallocation(int vector[],int size){
    int i, increase;

    printf("\nSize of reallocation vector: ");  
    scanf("%d",&increase);  //If "increase" = 0 only reallocation. else >0 increasing vector
    //realloc: reallocation the vector in the memory or increasing the vector.
    vector = (int *)realloc(vector,(size+increase)*sizeof(int));  

    for(i=size;i<size+increase;i++)
        scanf("%d",&vector[i]);

    printf("Your allocated vector: ");
    for(i=0;i<size+increase;i++)
        printf("%d ",vector[i]);

}

int main(){
    int *pointer;
    int size, i;

    printf("Write size of vector: ");
    scanf("%d",&size);                         

    pointer = (int *)calloc(size,sizeof(int)); //create vector dynamically allocated
    allocation(pointer,size);

    printf("Your vector: ");
    for(i=0;i<size;i++)
        printf("%d ",pointer[i]);

    reallocation(pointer,size);

    
    free(pointer); //free: espace liberation in the memory
    return 0;
}