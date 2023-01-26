//Update Success:
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define cls() system("cls");
struct bank
{ char nam[30];
  int acno,bal;
  }calbr;

int main()
{
  cls();
  FILE *fp;
  int x,ac,flg=0,pos,rn=0;
  char chos='n';
 fp=fopen("bi_file.dat","rb+");
 printf("Enter the A/c number ");
 scanf("%d",&ac);
 do
 {
    x=fread(&calbr,sizeof(calbr),1,fp);
      if(x==0)
	 break;
      else
	rn++;
    if(ac==calbr.acno)
    {
    printf("\nName: %s ",calbr.nam);
    printf("\nA/c number : %d ",calbr.acno);
    printf("\n Balance amount : %d ",calbr.bal);
    flg=1;
    pos=ftell(fp);
    printf("\nfile position %d, record number %d",pos,rn);
    fflush(stdin);
    printf("\nDelete Record Y/N :");
    scanf("%c",&chos);
    if (chos=='Y' || chos=='y')
    {
        strcpy(calbr.nam,"");
        calbr.acno=-1;
        calbr.bal=-1;
        printf("Success");

    }
    fseek(fp,-(long)sizeof(calbr),1);
    pos=ftell(fp);
    //printf("\nfile position %d",pos);

    fwrite(&calbr,sizeof(calbr),1,fp);
    }

 }while(1);
 fclose(fp);
 if(flg==0)
   printf("A/c no %d not found",ac);
 //getch();
 return 0;

}
