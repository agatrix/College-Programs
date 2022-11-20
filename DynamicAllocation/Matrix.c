#include<stdio.h>
#include<stdlib.h>
//this program has dynamic allocation matrix application. 

float ** AllocateMatrix(int line, int columns){ 
    int i;
    float **matrix;

    matrix = (float **)calloc(line,sizeof(float));

    for(i=0;i<line;i++)
        matrix[i] = (float *)calloc(columns,sizeof(float));

    return matrix;
}

void FreeMemory(int line,float **matrix){
    int i;

    for(i=0;i<line;i++){
        free(matrix[i]);
    }

    free(matrix);

}


int main(){
    int line, columns, i, j;
    float **matrix;
    
    scanf("%d%d",&line,&columns);

    matrix = AllocateMatrix(line,columns);

    for(i=0;i<line;i++){
        for(j=0;j<columns;j++){
            scanf("%f",&matrix[i][j]);
        }
    }

    for(i=0;i<line;i++){
        for(j=0;j<columns;j++){
            printf("%.2f ",matrix[i][j]);
        }
        printf("\n");
    }
    
    FreeMemory(line,matrix);    //function for free memory
    return 0;
}