#include<stdio.h>
#include<conio.h>
void main()
{
int age;
clrscr();
int mat[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
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

for(i=0;i<3;i++)
{
  for(j=0;j<4;j++)
   {
     printf(" %u ",*(*(pa+i)+j));
  }
  printf("\n");
  }
getch();
}