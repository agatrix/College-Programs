#include<stdio.h>
#include<stdlib.h>

//This program is a presentation problems about recursion.

float Potenzialiation(float base, int exponent){
    
    if(exponent == 0)
        return 1;
    if(exponent>0)
        return (base * Potenzialiation(base,exponent-1));

    return(1/base * Potenzialiation(base,exponent+1));   
}

int Factorial(int number){

    if(number == 1)
        return 1;

    return (number*Factorial(number-1));
}


float Sum(float array[],int number){

    if(number==0)
        return array[number];

    return array[number]+Sum(array,number-1);


}

float Avarege(float array[],int number, int i){

    if(i==0){
        return array[i]/number;
    }

    return (array[i]/number)+Avarege(array,number,i-1);
}

void Swap(float vector[], int i, int j){ 
    int ass; 
    ass = vector[i];
    vector[i] = vector[j];
    vector[j] = ass;
}

void Order(float vector[], int left, int right){ 

    int i, j, mv; 
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
        Order(vector,i,right);

    if(j > left)
        Order(vector,left,j);
}

int main(){
    int choice;
    float base;
    int number, exponent;
    float *array;


    do{
        printf("\n\nChoose a question:\n");
        printf("1 = Potenzialiation\n");
        printf("2 = Factorial\n");
        printf("3 = Several Numbers\n");
        printf("0 = Exit\n");
        scanf("%d",&choice);


        switch(choice){
            case 0:
                //system("cls");
                system("clear");
                printf("Thanks for the use my program!\n");
                break;

            case 1:
                //system("cls");
                system("clear");

                printf("Type it the base: ");
                scanf("%f",&base);
                printf("Type it the exponent: ");
                scanf("%d",&exponent);

                printf("Result: %.2f",Potenzialiation(base,exponent));

                break;

            case 2:
                //system("cls");
                system("clear");

                printf("which number you want find the factorial?\n");
                scanf("%d",&number);
                printf("The factorial this number is %d\n",Factorial(number));
                break;

            case 3:
                //system("cls");
                system("clear");

                printf("Type it how many numbers you want: ");
                scanf("%d",&number);

                array = (float *) malloc (number*sizeof(float));

                printf("Type it the numbers:\n");
                for(int i=0;i<number;i++)
                    scanf("%f",&array[i]);

                //system("cls");
                system("clear");
                Order(array,0,number-1);
                printf("Array ordered:\n");
                for(int i=0;i<number;i++)
                    printf("%.2f ",array[i]);
                printf("\nSum of the numbers: %.2f\n",Sum(array,number));
                printf("Average of  the numbers: %.2f\n",Avarege(array,number,number));

                break;

            default:
                //system("cls");
                system("clear");

                printf("Question not found!!!");
                break;
        }
    }while(choice!=0);

    return 0;
}