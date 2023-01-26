// Stack using Array
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define cls() system("cls");
#define size  5

int top;
void push(int a[])
{
  if(top==size-1)
    { printf("\nStack full ");
      return;
    }
  int n;
  printf("Enter the value ");
  scanf("%d",&n);
   top++;
   a[top]=n;
   printf("\nPush success");
   getch();
   return;
}
void pop(int a[])
{
   if(top==-1)
    {  printf("\nEmpty stack");
       return;
    }
    int x=a[top];
    top--;
    printf("%d has been popped ",x);
    getch();
    return;
}
void display(int a[])
{  int i;
   if (top==-1)
      {  printf("Empty stack ");
	 return;
      }

    printf("\n Stack status \n");
    for(i=top;i>=0;i--)
      printf("%d ",a[i]);
      getch();

   return;
}
int main()
{
//clrscr();
top=-1;
int ar[size];
int ch;
do{
cls();
printf("\n1. Push \n2. Pop \n 3. View \n 4.Exit");
printf("\nEnter your choice ");
scanf("%d",&ch);
switch(ch)
{
	case 1:
	  push(ar);
	  break;
	case 2:
	  pop(ar);
	  break;
	case 3:
	  display(ar);
	  break;
	case 4:
	    printf("\nThank you...");
	    break;
	default:
	    printf("\nWrong choice ");
}
} while(ch!=4);
return EXIT_SUCCESS;
}