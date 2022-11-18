#include<stdio.h>
//This program has the intention at make a binary search in a vector.

void OrganizedVector(float vector[], int vs){
//this function server for organize the vector. Here I utilize the Bubble Sort, but has a method best which is the QuickSort.
//You can find the algorithm of Quick Sort in this repository.

int largest=0, smaller=0;
float ass;

for (smaller=0;smaller<vs;smaller++){
    for(largest=smaller+1;largest<vs;largest++){
        if(vector[smaller]>vector[largest]){
            ass = vector[smaller];
            vector[smaller] = vector[largest];
            vector[largest] = ass;
        }
    }
}

}

int BinarySearch(float vector[], float search, int start, int finish){  
//the variables start and finish are the vector startpoint and endpoint; search is the wanted number at the user 
    int middle;

    middle = (start+finish)/2;  //variable for definition of the middle
    
    if (start > finish)
        return -1;

    if (vector[middle] == search)
        return middle+1;

    if (vector[middle] > search)
        BinarySearch(vector,search,start,middle-1);
        else
            BinarySearch(vector,search,middle+1,finish);
}

int main(){
    int vs, position;             //sv = Vector Size
    float *vector, sn;  //sn = Search Number 

    printf("Which is vector size?\n");
    scanf("%d",&vs);
    vector = (float *)calloc(vs,sizeof(float));

    for(int i=0;i<vs;i++)
        scanf("%f",&vector[i]);

    OrganizedVector(vector,vs);
    printf("Vector organized:");
    for(int i=0;i<vs;i++)
        printf(" %.2f",vector[i]);


    printf("\nWhat is wanted number?\n");
    scanf("%f",&sn);

    position = BinarySearch(vector,sn,0,vs);
    if(position == -1)
        printf("Number not found in vector.");
    else
        printf("Position of the number wanted: %d",position);

    free(vector);   

    return 0;
}