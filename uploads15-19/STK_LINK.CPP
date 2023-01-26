// Stack using Link
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#define cls() system("cls");
struct node
{ int vl;
  node *lnk;
}*top;

void push()
{
  node *ptr;
  ptr=(node *) malloc(sizeof(node));

  if(ptr==NULL)
    { printf("\nStack full ");
      return;
    }

  int n;
  printf("Enter the value ");
  scanf("%d",&n);
   ptr->vl=n;
   ptr->lnk=top;
   top=ptr;
   printf("\nPush success");
   getch();
   return;
}

void pop()
{
   if(top==NULL)
    {  printf("\nEmpty stack");
       return;
    }
    node *ptr;

    int x=top->vl;
    ptr=top;
    top=top->lnk;
    printf("%d has been popped ",x);
    free(ptr);
    getch();
    return;
}
void display()
{
   if (top==NULL)
      {  printf("Empty stack ");
	 return;
      }
    node *ptr;
    ptr=top;
    printf("\n Stack status \n");
    do
    {
      printf("%d ",ptr->vl);

      ptr=ptr->lnk;
    } while(ptr!=NULL);
    getch();
   return;
}
int main()
{
top=NULL;
int ch;
do{
cls();
printf("\n1. Push \n2. Pop \n 3. View \n 4.Exit");
printf("\nEnter your choice ");
scanf("%d",&ch);
switch(ch)
{
	case 1:
	  push();
	  break;
	case 2:
	  pop();
	  break;
	case 3:
	  display();
	  break;
	case 4:
	    printf("\nThank you...");
	    break;
	default:
	    printf("\nWrong choice ");
}
//getch();
} while(ch!=4);
return EXIT_SUCCESS;
}