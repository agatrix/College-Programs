#include<stdio.h>
#include<stdlib.h>

//This program is a presentation problems about recursion.

float potenzialiation(float base, int exponent){
    
    if(exponent == 0)
        return 1;
    if(exponent>0)
        return (base * potenzialiation(base,exponent-1));
        
    return(1/base * potenzialiation(base,exponent+1));   
}

int factorial(int number){

    if(number == 1)
        return 1;

    return (number*factorial(number-1));
}


int main(){
    int choice;
    float base;
    int number, exponent;


    do{
        printf("\n\nChoose a question:\n");
        printf("1 = Potenzialiation\n");
        printf("2 = Factorial\n");
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

                printf("Result: %.2f",potenzialiation(base,exponent));

                break;

            case 2:
                //system("cls");
                system("clear");
                printf("which number you want find the factorial?\n");
                scanf("%d",&number);
                printf("The factorial this number is %d\n",factorial(number));
                break;

            case 3:
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