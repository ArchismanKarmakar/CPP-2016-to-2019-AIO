#include <stdio.h> 
#include <stdlib.h> // For exit() 
#include<string.h>
#define cls() system("cls");

struct bank
{
    char nam[30];
    int acno,bal;
}calbr;

int main()
{
    cls();
    /* int n;
    struct bank num;*/
    FILE *fptr;
    char ch;

    if ((fptr = fopen("bi_file.dat","rb")) == NULL){
        printf("Error! opening file");

        // Program exits if the file pointer returns NULL.
        exit(1);
    }
printf("All Records:");
    while(!feof(fptr))
    {
        
        fread(&calbr, sizeof(struct bank), 1, fptr); 
        
        printf("\nName: ");
        puts(calbr.nam);
        printf("Account no: %d\tBalance: %d", calbr.acno, calbr.bal);
    }
    fclose(fptr); 
  
    return 0;
}