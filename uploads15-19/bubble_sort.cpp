#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define cls() system("cls");

void sort(int aa[])
{
  int i,j,tmp;
  for(i=0;i<4;i++)
  {
    for(j=0;j<4-i;j++)
    {
       if(aa[j]>aa[j+1])
       {
	          tmp=aa[j];
	          aa[j]=aa[j+1];
	          aa[j+1]=tmp;
       }
    }
  }
}
/*
void sort(int *aa)
{
  int i,j,tmp;
  for(i=0;i<4;i++)
  {
    for(j=0;j<4-i;j++)
    {
       if((aa+j)>(aa+j+1))
       {
	   tmp=*(aa+j);
	   (aa+j)=(aa+j+1);
	   *(aa+j+1)=tmp;
       }
    }
  }
}
*/
int main()
{
int ar[5],i;
cls();
printf("Enter the array elements ");
for(i=0;i<5;i++)
{
scanf("%d",&ar[i]);
}
sort(ar);
printf("\nThe sorted array elements \n");
for(i=0;i<5;i++)
{
  printf("%d  ",ar[i]);
}
return 0;
//getch();
}
