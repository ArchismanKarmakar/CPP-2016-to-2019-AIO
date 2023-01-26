#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define cls() system("cls");

int main(){
    int loop=1;
    char s[50];
    while(loop>0)
    {
        fflush(stdin);

        printf("windows@admin$ ");
        fflush(stdin);
        gets(s);
        printf("%s --$admin--$$success\n",s);
        if((strcmp(s,"00x0000"))==0)
        {
            exit(0);
        }
         if((strcmp(s,"cls"))==0)
        {
            cls();
        }
        
        
        return EXIT_SUCCESS;
}

