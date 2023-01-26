#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define cls() system("cls");



 int main()
 {
 cls();
 int a;
 int *p,**q;
 printf("Enter 1 number :");
 scanf("%d",&a);
 p=&a;     // pointer to an integer
 q=&p;     // pointer to pointer to an integer
 printf("\nThe given value %d",p);
 printf("\nThe given value using pointer %d  %d",q,*p);

// printf("\nThe given value %d ",*(&a));
// printf("\n\nThe given value %d ",*p);
// printf("\nThe Address of value %u ",p);

 //getch();
 return EXIT_SUCCESS;
 
 }
