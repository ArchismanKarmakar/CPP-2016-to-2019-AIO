// Queue using Link    FIFO ( First In First Out )

#include<stdio.h>
#include<conio.h>
//#include<alloc.h>
#include<stdlib.h>


#define cls() system("cls");


struct node
{  int val;
   node *link;
   } *front,*rear;

void insert()       // insert
{
  node *ptr;
  ptr=(node *)malloc(sizeof(node));

  if(ptr==NULL)
    { printf("\nQueue full ");
      return;
    }
  int n;
  printf("Enter the value ");
  scanf("%d",&n);

  ptr->val=n;
  ptr->link=NULL;

  if (rear==NULL)
  {  front=ptr;
     rear=ptr;
  }
  else
  {
    rear->link=ptr;
    rear=rear->link;
  }
   printf("\nInsert success");
   return;
}

void del()        // delete
{
   node *ptr;

   if(front==NULL)
    {  printf("\nEmpty Queue");
       return;
    }
    int x=front->val;
    ptr=front;
    if(front==rear)
    { rear=NULL;
      front=NULL;
    }
    else
	front=front->link;

    printf("%d has been deleted ",x);
    free(ptr);
    return;
}

void display()
{
   if (rear==NULL)
      {  printf("Empty Queue ");
	 return;
      }
    node *ptr;
    ptr=front;
    printf("\nQueue status \n");
    do
    {
       printf("%d ",ptr->val);
       ptr=ptr->link;
    } while(ptr!=NULL);
   return;
}

int main()
{
front=NULL;
rear=NULL;

int ch;
do{
cls();
printf("\n1. Insert \n2. Delete \n 3. Traversal \n 4.Exit");
printf("\nEnter your choice ");
scanf("%d",&ch);
switch(ch)
{
	case 1:
	  insert();
	  break;
	case 2:
	  del();
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
getch();
} while(ch!=4);
return EXIT_SUCCESS;
}
