#include<stdio.h>
#include<conio.h>
struct bank
{ char nam[30];
  int acno,bal;
  }calbr;
int main()
{ FILE *fp;
  char ch='y';
 fp=fopen("bi_file.dat","ab");
 do{
 printf("Enter name, a/c number, balance: \n");
 fflush(stdin);
 gets(calbr.nam);
 scanf("%d%d",&calbr.acno,&calbr.bal);
 fwrite(&calbr,sizeof(calbr),1,fp);
 fflush(stdin);
 printf("Success!\n");
 printf("Do you want to continue y/n: ");
 scanf("%c",&ch);
 } while(ch=='Y' || ch=='y');
 fclose(fp);
 //getch();
 return 0;
}
