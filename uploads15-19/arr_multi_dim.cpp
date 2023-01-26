#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define cls() system("cls");
int main()
{
int age;
cls();
//system("cls");
int mat[3][4]={1,2,9,4,5,12,7,8,9,10,11,12};
int (*pa)[4],i,j;
pa=mat;

for(i=0;i<3;i++)
{
 for(j=0;j<4;j++)
  {
    printf(" %u",&mat[i][j]);
  }
  printf("\n");
  }

printf("\n%d",*pa);

for(i=0;i<3;i++)
{
  for(j=0;j<4;j++)
   {
     printf(" %u ",*(*(pa+i)+j));
  }
  printf("\n");
  }
return EXIT_SUCCESS;
}
