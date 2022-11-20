#include<stdio.h>
#include<string.h>
#include<ctype.h>
//Program for learn Archives and Structs. Based in a user's cadastrar interface

typedef struct {
   char name[50];
   int year;
   char description[200];
}Users;

void Registration(Users user, FILE *archive){
    system("cls");
    archive = fopen("UserArchive.bin","ab");
    printf("Name: ");
    scanf("%[^\n]%*c",&user.name);
    printf("Years: ");
    scanf("%d%*c",&user.year);
    printf("Description: ");
    scanf("%[^\n]%*c",&user.description);    
    fwrite(&user,sizeof(Users),1,archive);

    fclose(archive);
    return;
}

void List(Users user, FILE *archive){

    archive = fopen("UserArchive.bin","rb");
    system("cls");
    while(fread(&user,sizeof(Users),1,archive)){
        printf("\nName: %s\n",user.name);
        printf("Year: %d\n",user.year);
        printf("Description: %s\n\n",user.description);
    }

    fclose(archive);
    return;
}

void Alteration(Users user, FILE *archive){
    char name[50];
    int control=0, found=0;
    system("cls");
    archive = fopen("UserArchive.bin","r+b");
    printf("Name for alteration: ");
    scanf("%[^\n]%*c",&name);

    while(fread(&user,sizeof(Users),1,archive)){
        if(strcmp(name,user.name) == 0){
           found = 1; 
           break;
        }
        control++;
    }

    if(found){
        scanf("%[^\n]%*c",&user.name);
        scanf("%d%*c",&user.year);
        scanf("%[^\n]%*c",&user.description);

        fseek(archive,(control)*sizeof(Users),SEEK_SET);

        fwrite(&user,sizeof(Users),1,archive);

        fclose(archive);
        return;

    }else{
        printf("not found.\n");
        return;

    }
}

int main(){

    FILE *archive;
    Users user;
    int choise;

    while(1){
        
        printf("*********************************************\n");
        printf("Register=1 /Listing=2 /Alteration=3 /Exit=4\n");
        printf("*********************************************\n");
        scanf("%d%*c",&choise);
        
        switch(choise){
            case 1:
                Registration(user,archive);
                system("cls");
                break;
            case 2:
                system("cls");
                List(user,archive);
                break;
            case 3:
                Alteration(user,archive);
                system("cls");
                break;
            default:
                return 0;
        }
    }
}