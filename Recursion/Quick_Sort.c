#include<stdio.h>

void Swap(int vector[], int i, int j){ //Function for Swap of vector position
    int ass; //ass = assistance
    ass = vector[i];
    vector[i] = vector[j];
    vector[j] = ass;
}

void QuickSort(int vector[], int left, int right){ 
//the variables left and right are the vector startpoint and endpoint 
    int i, j, mv; //mv = middle of the vector
    i = left;
    j = right;
    mv = vector[(i+j)/2];

    do{
        while(mv > vector[i])
            i++;
        while(mv < vector[j])
            j--;
        if(i <= j){
            Swap(vector,i,j);
            i++;
            j--;
        }
    }while(i <= j);

    if(i < right)
        QuickSort(vector,i,right);

    if(j > left)
        QuickSort(vector,left,j);
}

int main(){
    int vector[10];

    for(int i=0;i<10;i++)
        scanf("%d",&vector[i]);

    QuickSort(vector,0,10);

    for(int i=0;i<10;i++)
        printf("%d ",vector[i]);

    return 0;
}