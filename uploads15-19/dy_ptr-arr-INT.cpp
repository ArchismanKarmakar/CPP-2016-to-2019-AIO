// pointer to an integer array with dynamical array elements
#include<stdio.h>
#include<conio.h>
//#include<alloc.h>
#include<stdlib.h>
#define cls() system("cls");

void main()
{
int *ar,n,i;
cls();
printf("Enter the array size ");
scanf("%d",&n);   // size of array

ar= (int *) malloc (n * sizeof(int) );  // allocation of array(pointer)

printf("Enter the array elements ");
for(i=0;i<n;i++)
{
 scanf("%d",(ar+i));
}
printf("\nThe given array is :");
for(i=0;i<n;i++)
{
  printf("%d  ",*(ar+i));
}
getch();
}
