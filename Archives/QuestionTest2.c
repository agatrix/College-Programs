#include<stdio.h>
#include<stdlib.h>
//This program has the application in binary files

void Write(FILE *archive){   //function for write in the archive
    char text[100];
    archive = fopen("BinaryArchive.bin","wb");
    printf("Write your text: ");
    scanf("%[^\n]s",text);

    fwrite(&text,sizeof(text),1,archive);
    
    fclose(archive);

    Read(archive,text);
    
}

void Read(FILE *archive, char text[100]){

    archive = fopen("BinaryArchive.bin","rb");
    read(&text,sizeof(text),1,archive);
    printf("%s",text);

    fclose(archive);

}

int main(){

    FILE *archive;

    Write(archive);

    return 0;
}